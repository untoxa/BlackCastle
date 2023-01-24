#ifndef _PLAYER
#define _PLAYER

#define MAX_PLAYER_SHOT 3

#define PST_SWORD       0
#define PST_AXE         1
#define PST_MACE        2

//player
extern UBYTE player_x;
extern UBYTE player_y;
extern UBYTE player_spr0;
extern UBYTE player_spr1;
extern UBYTE player_ani;
extern BYTE player_dir;
extern BYTE player_vel;
extern UBYTE player_jmp;
extern UBYTE player_att;
extern UBYTE player_sht;
extern UBYTE player_dmg;
extern UBYTE player_lif;
extern UBYTE player_prp;
extern UWORD player_score;

//player shot
extern UBYTE player_shot_act[MAX_PLAYER_SHOT];
extern UBYTE player_shot_x[MAX_PLAYER_SHOT];
extern UBYTE player_shot_y[MAX_PLAYER_SHOT];
extern UBYTE player_shot_spr[MAX_PLAYER_SHOT];
extern UBYTE player_shot_typ[MAX_PLAYER_SHOT];
extern BYTE player_shot_dir[MAX_PLAYER_SHOT];
extern BYTE player_shot_vel[MAX_PLAYER_SHOT];
extern UBYTE player_shot_ani[MAX_PLAYER_SHOT];

void update_player_shot() BANKED;
void update_player() BANKED;

#endif