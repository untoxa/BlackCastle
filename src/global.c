#include <gbdk/platform.h>
#include <gbdk/incbin.h>

#include "global.h"

//game state
UBYTE game_state;

//input
UBYTE input = 0;
UBYTE old_input;

//bank
UBYTE old_bank = 1;

//background
BYTE scroll;
UWORD scroll_pos;
UBYTE scroll_pos_with_shake;
UBYTE tile_cnt;
UBYTE tile_pos;
UBYTE shake;

// Rolling buffer storing 32 columns of the level
UBYTE buf[512];

//level
const unsigned char *level_data;
UBYTE level_pos;
UBYTE level_ani;
UBYTE level_maj;
UBYTE level_min;
UBYTE level_len;

//game over
UBYTE game_over_spr0;
UBYTE game_over_spr1;
UBYTE game_over_spr2;
UBYTE game_over_spr3;

//high score
UWORD high_score;

// Global map pointer and map bank, used by update_column
UBYTE* g_meta_lookup_tl;
UBYTE* g_meta_lookup_tr;
UBYTE* g_meta_lookup_bl;
UBYTE* g_meta_lookup_br;
UBYTE* g_current_map;
UBYTE g_current_map_bank;

UBYTE g_num_clipping_sprites;

const state_handler_t state_handlers[] = {
    enter_title, enter_level, enter_end
};

#define OBJ_CRYSTAL             0
#define OBJ_HEART               1
#define OBJ_SWORD               2
#define OBJ_AXE                 3
#define OBJ_MACE                4
#define OBJ_FALLING_PLATFORM    5
#define OBJ_UPDOWN_PLATFORM     6
#define OBJ_LEFTRIGHT_PLATFORM  7
#define OBJ_KNIGHT              8
#define OBJ_BAT                 9
#define OBJ_REAPER              10
#define OBJ_SPIDER              11
#define OBJ_SKELETON            12

extern const unsigned char sprite_tiles_game_over[];
INCBIN(sprite_tiles_game_over, "res/sprite_tiles_game_over.chr")

const level_t levels[] = {
    {
        .bank_tiles = BANK(level1_tiles),
        .tiles = level1_tiles,
        .bank_sprites = BANK(sprite_tiles),
        .sprites = sprite_tiles,
        .bank_sprites_noflip = BANK(sprite_tiles_noflip),
        .sprites_noflip = sprite_tiles_noflip,
        .bank_sprites_bosses = BANK(sprite_tiles_bosses),
        .sprites_bosses = sprite_tiles_bosses,
        .bank_hud = BANK(hud_tiles),
        .hud_tiles = hud_tiles,
        .hud_map = hud_map,
        .meta_lookup_tl = level1_meta_lookup_tl,
        .meta_lookup_tr = level1_meta_lookup_tr,
        .meta_lookup_bl = level1_meta_lookup_bl,
        .meta_lookup_br = level1_meta_lookup_br,
        .minor = {
            {
                .bank_map = BANK(level1_1_map),
                .map = level1_1_map,
                .data = level1_1_data,
                .len = 236,
                .music = LEVEL1_MUSIC,
                .boss_typ = BT_NONE
            },{
                .bank_map = BANK(level1_2_map),
                .map = level1_2_map,
                .data = level1_2_data,
                .len = 236,
                .music = LEVEL1_MUSIC,
                .boss_typ = BT_NONE
            },{
                .bank_map = BANK(level1_3_map),
                .map = level1_3_map,
                .data = level1_3_data,
                .len = 236,
                .music = LEVEL1_MUSIC,
                .boss_typ = BT_NONE
            },{
                .bank_map = BANK(level1_4_map),
                .map = level1_4_map,
                .data = NULL,
                .len = 0,
                .music = BOSS_MUSIC,
                .boss_x = 76, .boss_y = 72,
                .boss_typ = BT_BAT
            }
        }
    },{
        .bank_tiles = BANK(level2_tiles),
        .tiles = level2_tiles,
        .bank_sprites = BANK(sprite_tiles),
        .sprites = sprite_tiles,
        .bank_sprites_noflip = BANK(sprite_tiles_noflip),
        .sprites_noflip = sprite_tiles_noflip,
        .bank_sprites_bosses = BANK(sprite_tiles_bosses),
        .sprites_bosses = sprite_tiles_bosses,
        .bank_hud = BANK(hud_tiles),
        .hud_tiles = hud_tiles,
        .hud_map = hud_map,
        .meta_lookup_tl = level2_meta_lookup_tl,
        .meta_lookup_tr = level2_meta_lookup_tr,
        .meta_lookup_bl = level2_meta_lookup_bl,
        .meta_lookup_br = level2_meta_lookup_br,
        .minor = {
            {
                .bank_map = BANK(level2_1_map),
                .map = level2_1_map,
                .data = level2_1_data,
                .len = 236,
                .music = LEVEL2_MUSIC,
                .boss_typ = BT_NONE
            },{
                .bank_map = BANK(level2_2_map),
                .map = level2_2_map,
                .data = level2_2_data,
                .len = 236,
                .music = LEVEL2_MUSIC,
                .boss_typ = BT_NONE
            },{
                .bank_map = BANK(level2_3_map),
                .map = level2_3_map,
                .data = level2_3_data,
                .len = 236,
                .music = LEVEL2_MUSIC,
                .boss_typ = BT_NONE
            },{
                .bank_map = BANK(level2_4_map),
                .map = level2_4_map,
                .data = NULL,
                .len = 0,
                .music = BOSS_MUSIC,
                .boss_x = 76, .boss_y = 105,
                .boss_typ = BT_MINOTAUR
            }
        }
    }, {
        .bank_tiles = BANK(level3_tiles),
        .tiles = level3_tiles,
        .bank_sprites = BANK(sprite_tiles),
        .sprites = sprite_tiles,
        .bank_sprites_noflip = BANK(sprite_tiles_noflip),
        .sprites_noflip = sprite_tiles_noflip,
        .bank_sprites_bosses = BANK(sprite_tiles_bosses),
        .sprites_bosses = sprite_tiles_bosses,
        .bank_hud = BANK(hud_tiles),
        .hud_tiles = hud_tiles,
        .hud_map = hud_map,
        .meta_lookup_tl = level3_meta_lookup_tl,
        .meta_lookup_tr = level3_meta_lookup_tr,
        .meta_lookup_bl = level3_meta_lookup_bl,
        .meta_lookup_br = level3_meta_lookup_br,
        .minor = {
            {
                .bank_map = BANK(level3_1_map),
                .map = level3_1_map,
                .data = level3_1_data,
                .len = 236,
                .music = LEVEL3_MUSIC,
                .boss_typ = BT_NONE
            },{
                .bank_map = BANK(level3_2_map),
                .map = level3_2_map,
                .data = level3_2_data,
                .len = 236,
                .music = LEVEL3_MUSIC,
                .boss_typ = BT_NONE
            },{
                .bank_map = BANK(level3_3_map),
                .map = level3_3_map,
                .data = level3_3_data,
                .len = 236,
                .music = LEVEL3_MUSIC,
                .boss_typ = BT_NONE
            },{
                .bank_map = BANK(level3_4_map),
                .map = level3_4_map,
                .data = NULL,
                .len = 0,
                .music = BOSS_MUSIC,
                .boss_x = 80, .boss_y = 76,
                .boss_typ = BT_REAPER
            }
        }
    }
};

void copy_map_column_to_buf(UBYTE pos)
{
    UBYTE j;
    UBYTE i = pos;
    UWORD w = i << 4;
    UWORD wmod = w & 0x1E0;
    for(j = 0; j < 8; j++)
    {
        UBYTE metaidx = g_current_map[((i >> 1) << 3) + j];
        buf[wmod +  0 + 2*j+0] = g_meta_lookup_tl[metaidx];
        buf[wmod +  0 + 2*j+1] = g_meta_lookup_bl[metaidx];
        buf[wmod + 16 + 2*j+0] = g_meta_lookup_tr[metaidx];
        buf[wmod + 16 + 2*j+1] = g_meta_lookup_br[metaidx];
    }
}

void init_title(void)
{
    UBYTE i,j;
    UWORD w;

    clear_all();
    fill_bkg_rect(DEVICE_SCREEN_X_OFFSET, DEVICE_SCREEN_Y_OFFSET, DEVICE_SCREEN_WIDTH, DEVICE_SCREEN_HEIGHT, 0);

    sound_cnt_ch1 = 0;
    sound_cnt_ch4 = 0;

    //player
    player_sht = PST_SWORD;
    //player_sht = PST_AXE;
    //player_sht = PST_MACE;
    player_lif = 4;
    player_score = 0;

    //level
    level_maj = 1;
    level_min = 1;

    //background
    SET_BANK(BANK(title_tiles));
    set_bkg_data(0,177, title_tiles);
    w = 0;
    for( i = 0; i != 20; i++ )
    {
        set_bkg_tiles(VIEWPORT_X_OFS + i, VIEWPORT_Y_OFS, 1, 18, &title_map[w]);
        w += 18;
    }
    move_bkg(0,0);
    RESTORE_BANK();

    //set high score
    for( i = 0; i != 4; i++ )
    {
        j = (high_score >> (i<<2)) & 0x0F;
        set_bkg_tiles(VIEWPORT_X_OFS + 10-i, VIEWPORT_Y_OFS + 17,1,1,&title_numbers[j]);
    }

}

void enter_title(void)
{
    UBYTE i;

    init_title();

    set_music(TITLE_MUSIC);

    SHOW_BKG;
    DISPLAY_ON;

    fade_from_white();

    while( game_state == GS_TITLE )
    {
        UPDATE_KEYS();

        if( KEY_TICKED(J_START) )
        {
            stop_music();
            set_sound(SND_START);

            for( i = 0; i != 4; i++ )
            {
                play_sound();
                wait_vbl_done();
            }

            fade_to_white();
            DISPLAY_OFF;
            game_state = GS_LEVEL;
        }

        play_music();
        wait_vbl_done();
    }
}

//
// Function that adds blank sprites on wider-screen systems (NES/SMS)
// * Hides sprites / scrolling seam on left side of viewport with 8 sprites
// * Hides sprites / scrolling seam on right side of viewport with 8 sprites
// * Hides sprites scrolling off lower edge of screen with 15 sprites
//
inline UBYTE add_clipping_sprites(void)
{
    UBYTE i = 0, spr_idx = 0;
#if defined(CLIP_SPRITES_X)
    // Hiding of right scroll seam (only on non-boss levels)
    if(level_min != 4)
    {
        for(i = 0; i < 8; i++, spr_idx++)
        {
            get_sprite();
            set_sprite_tile(spr_idx, SPRITE_MASK_TILE_INDEX + ST_OFFSET);
            move_sprite(spr_idx, (VIEWPORT_X_OFS + VIEWPORT_WIDTH + 0) << 3, (i << 4) + ((2 + VIEWPORT_Y_OFS) << 3) - 1);
        }
    }
#endif
    // Hiding of sprites below GB screen
    // Only 8 are needed on NES/Famicom. But the AVS's 15-sprite mode might require up to 15.
#if defined(CLIP_SPRITES_Y)
    for(i = 0; i < 15; i++, spr_idx++)
    {
        get_sprite();
        set_sprite_tile(spr_idx, SPRITE_MASK_TILE_INDEX + ST_OFFSET);
        move_sprite(spr_idx, (VIEWPORT_X_OFS + i) << 3, ((VIEWPORT_Y_OFS + VIEWPORT_HEIGHT) << 3) - 1);
    }
#endif
#if defined(CLIP_SPRITES_X)
    // Hiding of left scroll seam (only on non-boss levels)
    if(level_min != 4)
    {
        for(i = 0; i < 8; i++, spr_idx++)
        {
            get_sprite();
            set_sprite_tile(spr_idx, SPRITE_MASK_TILE_INDEX + ST_OFFSET);
            move_sprite(spr_idx, (VIEWPORT_X_OFS - 1) << 3, (i << 4) + ((2 + VIEWPORT_Y_OFS) << 3) - 1);
        }
    }
#endif
    return spr_idx;
}

void init_level(void)
{
    UBYTE i;
    UWORD w;

    const level_t * current_level = &levels[level_maj - 1];
    const level_minor_t * current_stage = &(current_level->minor[level_min - 1]);
    g_current_map = current_stage->map;
    g_meta_lookup_tl = current_level->meta_lookup_tl;
    g_meta_lookup_tr = current_level->meta_lookup_tr;
    g_meta_lookup_bl = current_level->meta_lookup_bl;
    g_meta_lookup_br = current_level->meta_lookup_br;
    g_current_map_bank = current_stage->bank_map;

    fill_bkg_rect(DEVICE_SCREEN_X_OFFSET, DEVICE_SCREEN_Y_OFFSET + VIEWPORT_Y_OFS, DEVICE_SCREEN_WIDTH, DEVICE_SCREEN_HEIGHT, 0);

    //sprites
    SET_BANK(current_level->bank_sprites);
#ifdef SEGA
    set_2bpp_palette(COMPAT_PALETTE(0,1,4,3));
#endif
    // Player/player shots/monsters which can flip
    set_sprite_data(0, ST_NUM_FLIP, current_level->sprites);
#ifdef SEGA
    // Mirror sprite tiles in SW in second half of tile table, as we lack sprite flipping in HW
    set_sprite_data_flipx(ST_NUM_FLIP, ST_NUM_FLIP, current_level->sprites);
#endif
    // These sprite tiles don't need mirroring
    // Leave gap of 2 8x16 tiles to avoid boss tiles overwriting them
    set_sprite_data(2*ST_NUM_FLIP + 4, ST_NUM_NOFLIP, current_level->sprites_noflip);

    if(level_min == 4)
    {
        // Boss sprite tiles (no flipping needed - overwrite monster tiles)
        set_sprite_data(ST_BOSS_BAT0 & 0xFE, ST_NUM_BOSS, current_level->sprites_bosses);
    }

#if defined(CLIP_SPRITES_X) || defined(CLIP_SPRITES_Y)
    set_sprite_data(SPRITE_MASK_TILE_INDEX, 2, scroll_seam_hide_tile);
#endif

    clear_all();

#if defined(CLIP_SPRITES_X) || defined(CLIP_SPRITES_Y)
    g_num_clipping_sprites = add_clipping_sprites();
#else
    g_num_clipping_sprites = 0;
#endif

    //player
    player_x = 32;
    player_y = 112;
    player_ani = 0;
    player_dir = 1;
    player_vel = 0;
    player_jmp = 0;
    player_att = 0;
    player_dmg = 0;
    player_prp = 0;

    player_spr0 = get_sprite();
    player_spr1 = get_sprite();

    set_sprite_tile(player_spr0,ST_PLAYER_IDLE0);
    set_sprite_tile(player_spr1,ST_PLAYER_IDLE1);

    move_sprite_clip(player_spr0,    SPRITE_OFS_X + player_x,    SPRITE_OFS_Y + player_y+16);
    move_sprite_clip(player_spr1,    SPRITE_OFS_X + player_x+8,  SPRITE_OFS_Y + player_y+16);

    //hud
    SET_BANK(current_level->bank_hud);
#ifdef SEGA
    set_2bpp_palette(COMPAT_PALETTE(0,1,2,3));
#endif
    set_bkg_data(32,51, current_level->hud_tiles);
    w = 0;
    for( i = 0; i != 20; i++ )
    {
        set_bkg_tiles(VIEWPORT_X_OFS + i,
                      VIEWPORT_Y_OFS,
                      1,
                      2,
                      &(current_level->hud_map[w]));
        w += 2;
    }
    update_hud(HUD_LIFE);
    update_hud(HUD_SCORE);
    update_hud(HUD_WEAPON);
    update_hud(HUD_LEVEL);

    // level tiles
    SET_BANK(current_level->bank_tiles);
    set_bkg_data(0, 32, current_level->tiles);

    // level stage maps, data and settings
    SET_BANK(current_stage->bank_map);
    level_data = current_stage->data;
    level_len = current_stage->len;

    if (current_stage->boss_typ) {
        new_boss(current_stage->boss_x, current_stage->boss_y, current_stage->boss_typ);
    }

    set_music(current_stage->music);

    //background
    for( i = 0; i != VIEWPORT_WIDTH+1 + BUF_PRELOAD_WIDTH; i++ )
    {
        SET_BANK(g_current_map_bank);
        copy_map_column_to_buf(i);
        RESTORE_BANK();
    }
    w = 0;
    for( i = 0; i != VIEWPORT_WIDTH+1; i++ )
    {
        set_bkg_tiles((VIEWPORT_X_OFS + i) & (DEVICE_SCREEN_BUFFER_WIDTH - 1),
                      2 + VIEWPORT_Y_OFS,
                      1,
                      16,
                      &buf[w]);
        w += 16;
    }
    if(VIEWPORT_X_OFS != 0)
    {
        fill_bkg_rect(VIEWPORT_X_OFS - 1,
                      2 + VIEWPORT_Y_OFS,
                      1,
                      16,
                      0);
    }
    move_bkg(0,0);
    scroll_pos = 0;
    scroll = 0;
    tile_cnt = 0;
    tile_pos = 0;
    shake = 0;

    //level
    level_pos = 0;
    level_ani = 0;
}

void update_level(void)
{
    UBYTE i,j,type,y;

    scroll = 0;

    update_player();

    update_platform();

    update_player_shot();

    update_item();

    update_monster();

    update_boss();

    update_monster_shot();

    update_explosion();

    update_stone();

    //candel
    level_ani++;
    if( (level_ani & 8) == 0 )
    {
        set_bkg_data(13,1,candle_tiles);
    } else {
        set_bkg_data(13,1,candle_tiles + 16);
    }

    SET_BANK(BANK(monster_data));
    //update level
    if( scroll != 0 )
    {
        scroll_pos += scroll;
        tile_cnt += scroll;
        if( (tile_cnt & 8) == 8 )
        {
            tile_cnt -= 8;
            tile_pos++;
            if( tile_pos < 236 )
            {
                SET_BANK(g_current_map_bank);
                copy_map_column_to_buf(tile_pos + VIEWPORT_WIDTH + BUF_PRELOAD_WIDTH);
                RESTORE_BANK();
                update_screen_column_from_buf(tile_pos + VIEWPORT_WIDTH);
            }
#if defined(MASTERSYSTEM) || defined(NINTENDO_NES)
            if(VIEWPORT_X_OFS != 0)
            {
                fill_bkg_rect(((tile_pos + VIEWPORT_X_OFS - 1) & 31), 2 + VIEWPORT_Y_OFS,1,16,0);
            }
#endif
            if( level_min != 4)
            {
                i = tile_pos + VIEWPORT_WIDTH+1;
                j = level_data[level_pos];
                while( i == j )
                {
                    y = (level_data[++level_pos] + 2) << 3;
                    type = level_data[++level_pos];

                    switch( type )
                    {
                        case OBJ_CRYSTAL:
                            new_item( ENEMY_SPAWN_POS_X, y, IT_CRYSTAL );
                            break;
                        case OBJ_HEART:
                            new_item( ENEMY_SPAWN_POS_X, y, IT_HEART );
                            break;
                        case OBJ_SWORD:
                            new_item( ENEMY_SPAWN_POS_X, y, IT_SWORD );
                            break;
                        case OBJ_AXE:
                            new_item( ENEMY_SPAWN_POS_X, y, IT_AXE );
                            break;
                        case OBJ_MACE:
                            new_item( ENEMY_SPAWN_POS_X, y, IT_MACE );
                            break;
                        case OBJ_FALLING_PLATFORM:
                            new_platform( ENEMY_SPAWN_POS_X, y, PT_FALLING_PLATFORM );
                            break;
                        case OBJ_UPDOWN_PLATFORM:
                            new_platform( ENEMY_SPAWN_POS_X, y, PT_UPDOWN_PLATFORM );
                            break;
                        case OBJ_LEFTRIGHT_PLATFORM:
                            new_platform( ENEMY_SPAWN_POS_X, y, PT_LEFTRIGHT_PLATFORM );
                            break;
                        case OBJ_KNIGHT:
                            new_monster( ENEMY_SPAWN_POS_X, y, MT_KNIGHT );
                            break;
                        case OBJ_BAT:
                            new_monster( ENEMY_SPAWN_POS_X, y, MT_BAT );
                            break;
                        case OBJ_REAPER:
                            new_monster( ENEMY_SPAWN_POS_X, y, MT_REAPER );
                            break;
                        case OBJ_SPIDER:
                            new_monster( ENEMY_SPAWN_POS_X, y, MT_SPIDER );
                            break;
                        case OBJ_SKELETON:
                            new_monster( ENEMY_SPAWN_POS_X, y, MT_SKELETON );
                            break;
                    }

                    j = level_data[++level_pos];
                }
            }
        }
    }
}

void draw_level(void)
{
    UBYTE i;
    //player
    if( (player_dmg & 2) == 0 )
    {
        move_sprite_clip(player_spr0,    SPRITE_OFS_X + player_x,    SPRITE_OFS_Y + player_y + 16);
        move_sprite_clip(player_spr1,    SPRITE_OFS_X + player_x+8,  SPRITE_OFS_Y + player_y + 16);
    } else {
        hide_sprite(player_spr0);
        hide_sprite(player_spr1);
    }
    if( player_dmg != 0 )
    {
        player_dmg--;
    }

    //player shot
    for( i = 0; i != MAX_PLAYER_SHOT; i++ )
    {
        if( player_shot_act[i] == TRUE )
        {
            move_sprite_clip(player_shot_spr[i], SPRITE_OFS_X + player_shot_x[i],    SPRITE_OFS_Y + player_shot_y[i] + 16);
        }
    }

    //item
    for( i = 0; i != MAX_ITEM; i++ )
    {
        if( item_act[i] == TRUE )
        {
            move_sprite_clip(item_spr[i],    SPRITE_OFS_X + item_x[i],   SPRITE_OFS_Y + item_y[i] + 16);
        }
    }

    //platform
    for( i = 0; i != MAX_PLATFORM; i++ )
    {
        if( platform_act[i] == TRUE )
        {
            move_sprite_clip(platform_spr0[i],   SPRITE_OFS_X + platform_x[i],   SPRITE_OFS_Y + platform_y[i] + 16);
            move_sprite_clip(platform_spr1[i],   SPRITE_OFS_X + platform_x[i]+8, SPRITE_OFS_Y + platform_y[i] + 16);
        }
    }

    //monster
    for( i = 0; i != MAX_MONSTER; i++ )
    {
        if( monster_act[i] == TRUE )
        {
            if( (monster_dmg[i] & 2) == 0 )
            {
                move_sprite_clip(monster_spr0[i],    SPRITE_OFS_X + monster_x[i],        SPRITE_OFS_Y + monster_y[i] + 16);
                move_sprite_clip(monster_spr1[i],    SPRITE_OFS_X + monster_x[i] + 8,    SPRITE_OFS_Y + monster_y[i] + 16);
            } else {
                hide_sprite(monster_spr0[i]);
                hide_sprite(monster_spr1[i]);
            }
        }
    }

    //boss
    if( boss_act == TRUE )
    {
        if( (boss_dmg & 2) == 0 )
        {
            switch( boss_typ )
            {
                case BT_BAT:
                    move_sprite_clip(boss_spr0,  SPRITE_OFS_X + boss_x,      SPRITE_OFS_Y + boss_y + 16);
                    move_sprite_clip(boss_spr1,  SPRITE_OFS_X + boss_x + 8,  SPRITE_OFS_Y + boss_y + 16);
                    move_sprite_clip(boss_spr2,  SPRITE_OFS_X + boss_x + 16, SPRITE_OFS_Y + boss_y + 16);
                    break;
                case BT_MINOTAUR:
                    move_sprite_clip(boss_spr0,  SPRITE_OFS_X + boss_x,      SPRITE_OFS_Y + boss_y + 16);
                    move_sprite_clip(boss_spr1,  SPRITE_OFS_X + boss_x + 8,  SPRITE_OFS_Y + boss_y + 16);
                    move_sprite_clip(boss_spr2,  SPRITE_OFS_X + boss_x + 16, SPRITE_OFS_Y + boss_y + 16);
                    move_sprite_clip(boss_spr3,  SPRITE_OFS_X + boss_x,      SPRITE_OFS_Y + boss_y + 32);
                    move_sprite_clip(boss_spr4,  SPRITE_OFS_X + boss_x + 8,  SPRITE_OFS_Y + boss_y + 32);
                    move_sprite_clip(boss_spr5,  SPRITE_OFS_X + boss_x + 16, SPRITE_OFS_Y + boss_y + 32);
                    break;
                case BT_REAPER:
                    move_sprite_clip(boss_spr0,  SPRITE_OFS_X + boss_x,      SPRITE_OFS_Y + boss_y + 16);
                    move_sprite_clip(boss_spr1,  SPRITE_OFS_X + boss_x + 8,  SPRITE_OFS_Y + boss_y + 16);
                    move_sprite_clip(boss_spr2,  SPRITE_OFS_X + boss_x,      SPRITE_OFS_Y + boss_y + 32);
                    move_sprite_clip(boss_spr3,  SPRITE_OFS_X + boss_x + 8,  SPRITE_OFS_Y + boss_y + 32);
                    break;
            }


        } else {
            switch( boss_typ )
            {
                case BT_BAT:
                    hide_sprite(boss_spr0);
                    hide_sprite(boss_spr1);
                    hide_sprite(boss_spr2);
                    break;
                case BT_MINOTAUR:
                    hide_sprite(boss_spr0);
                    hide_sprite(boss_spr1);
                    hide_sprite(boss_spr2);
                    hide_sprite(boss_spr3);
                    hide_sprite(boss_spr4);
                    hide_sprite(boss_spr5);
                    break;
                case BT_REAPER:
                    hide_sprite(boss_spr0);
                    hide_sprite(boss_spr1);
                    hide_sprite(boss_spr2);
                    hide_sprite(boss_spr3);
                    break;
            }
        }
    }

    //monster shot
    for( i = 0; i != MAX_MONSTER_SHOT; i++ )
    {
        if( monster_shot_act[i] == TRUE )
        {
            move_sprite_clip(monster_shot_spr[i],    SPRITE_OFS_X + monster_shot_x[i],   SPRITE_OFS_Y + monster_shot_y[i] + 16);
        }
    }

    //explosion
    for( i = 0; i != MAX_EXPLOSION; i++ )
    {
        if( explosion_act[i] == TRUE )
        {
            move_sprite_clip(explosion_spr0[i],  SPRITE_OFS_X + explosion_x[i],      SPRITE_OFS_Y + explosion_y[i] + 16);
            move_sprite_clip(explosion_spr1[i],  SPRITE_OFS_X + explosion_x[i]+8,    SPRITE_OFS_Y + explosion_y[i] + 16);
        }
    }

    //stone
    for( i = 0; i != MAX_STONE; i++ )
    {
        if( stone_act[i] == TRUE )
        {
            move_sprite_clip(stone_spr[i],   SPRITE_OFS_X + stone_x[i],  SPRITE_OFS_Y + stone_y[i] + 16);
        }
    }
}

void lcd_isr(void);

void enter_level(void)
{
    UBYTE i;

    initrand(RAND_SOURCE);
    init_level();

//  SHOW_SPRITES;   // set in the LCD ISR
    DISPLAY_ON;

    add_LCD(lcd_isr);

    fade_from_white();

    while( game_state == GS_LEVEL )
    {
        UPDATE_KEYS();

        update_level();
        draw_level();

        play_sound();

        play_music();

#ifndef MASTERSYSTEM
        //pause
        if(KEY_TICKED(J_START))
        {
            stop_music();
            set_sound(SND_PAUSE);
            do
            {
                UPDATE_KEYS();
                play_sound();
                wait_vbl_done();
            } while(!KEY_TICKED(J_START));
            restart_music();
        }
#endif
        //next level
        if( (level_min != 4) && (player_x > 152) )
        {
            stop_music();
            fade_to_white();
            DISPLAY_OFF;
            level_min++;
            break;
        }

        //boss defeated
        if( (level_min == 4) && (boss_act == FALSE) )
        {
            stop_music();
            for( i = 0; i != 64; i++ )
            {
                wait_vbl_done();
            }
            while( player_lif != 4 )
            {
                player_lif++;
                update_hud(HUD_LIFE);
                set_sound(SND_HEART);
                for( i = 0; i != 24; i++ )
                {
                    play_sound();
                    wait_vbl_done();
                }
            }

            for( i = 0; i != 64; i++ )
            {
                wait_vbl_done();
            }

            fade_to_white();
            DISPLAY_OFF;
            level_maj++;
            level_min = 1;
            if( level_maj == 4 )
            {
                game_state = GS_END;
            }
            break;
        }

        //game over
        if( player_lif == 0 )
        {
            stop_music();
            player_vel = -20;
            while( player_y < 144 )
            {
                if( player_dir == 1 )
                {
                    set_sprite_tile(player_spr0,ST_PLAYER_DROP0);
                    set_sprite_tile(player_spr1,ST_PLAYER_DROP1);
                } else {
                    set_sprite_tile(player_spr0,ST_PLAYER_DROP1);
                    set_sprite_tile(player_spr1,ST_PLAYER_DROP0);
                }

                if( player_vel != 25 )
                {
                    player_vel++;
                }
                player_y += (player_vel >> 3);

                move_sprite_clip(player_spr0,    SPRITE_OFS_X + player_x,    SPRITE_OFS_Y + player_y + 16);
                move_sprite_clip(player_spr1,    SPRITE_OFS_X + player_x+8,  SPRITE_OFS_Y + player_y + 16);

                play_sound();

                wait_vbl_done();
            }

            for( i = 0; i != 64; i++ )
            {
                wait_vbl_done();
            }

            clear_sprites(g_num_clipping_sprites);
            clear_all_objects();

            // Upload "GAME OVER" tiles (replaces gameplay tiles which are now inactive)
            set_sprite_data(0, ST_GAME_OVER_NUM_TILES, sprite_tiles_game_over);

            //gameover sprite
            game_over_spr0 = get_sprite();
            game_over_spr1 = get_sprite();
            game_over_spr2 = get_sprite();
            game_over_spr3 = get_sprite();

            set_sprite_tile(game_over_spr0,ST_GAME_OVER0);
            set_sprite_tile(game_over_spr1,ST_GAME_OVER1);
            set_sprite_tile(game_over_spr2,ST_GAME_OVER2);
            set_sprite_tile(game_over_spr3,ST_GAME_OVER3);

            move_sprite_clip(game_over_spr0, SPRITE_OFS_X + 72,  SPRITE_OFS_Y + 88);
            move_sprite_clip(game_over_spr1, SPRITE_OFS_X + 80,  SPRITE_OFS_Y + 88);
            move_sprite_clip(game_over_spr2, SPRITE_OFS_X + 88,  SPRITE_OFS_Y + 88);
            move_sprite_clip(game_over_spr3, SPRITE_OFS_X + 96,  SPRITE_OFS_Y + 88);

            set_music(GAME_OVER_MUSIC);

            while(!KEY_TICKED(J_START))
            {
                UPDATE_KEYS();
                play_music();
                wait_vbl_done();
            }
            stop_music();

            if( player_score > high_score )
            {
                high_score = player_score;
            }

            fade_to_white();
            DISPLAY_OFF;
            game_state = GS_TITLE;
        }

        wait_vbl_done();
    }
    remove_LCD(lcd_isr);
}

void enter_end(void)
{
    UBYTE i,j;
    UWORD w;

    clear_all();
    fill_bkg_rect(DEVICE_SCREEN_X_OFFSET, DEVICE_SCREEN_Y_OFFSET, DEVICE_SCREEN_WIDTH, DEVICE_SCREEN_HEIGHT, 0);

    w = 0;
    for( i = 0; i != 20; i++ )
    {
        set_bkg_tiles(VIEWPORT_X_OFS + i,VIEWPORT_Y_OFS,1,18,&end_map[w]);
        w += 18;
    }
    move_bkg(0,0);

    //set score
    for( i = 0; i != 4; i++ )
    {
        j = (player_score >> (i<<2)) & 0x0F;
        set_bkg_tiles(VIEWPORT_X_OFS + 10-i,14 + VIEWPORT_Y_OFS,1,1,&hud_data[14+j]);
    }

    if( player_score > high_score )
    {
        high_score = player_score;
    }

    set_music(END_MUSIC);

    SHOW_BKG;
    DISPLAY_ON;

    fade_from_white();

    while( game_state == GS_END )
    {
        UPDATE_KEYS();

        if( KEY_TICKED(J_START) )
        {
            stop_music();

            fade_to_white();
            DISPLAY_OFF;
            game_state = GS_TITLE;
        }

        play_music();
        wait_vbl_done();
    }
}

void move_sprite_clip(uint8_t nb, uint8_t x, uint8_t y)
{
#ifdef CLIP_SPRITES_X
    if(x >= (8 * VIEWPORT_X_OFS - 8) && x < (8 * (VIEWPORT_X_OFS + VIEWPORT_WIDTH + 0)) && y < (8 * (VIEWPORT_Y_OFS + VIEWPORT_HEIGHT)))
        move_sprite(nb, x, y);      // inside viewport - show
    else
        move_sprite(nb, x, 240);    // outside viewport - hide
#else
    move_sprite(nb, x, y);
#endif
}
