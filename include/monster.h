#ifndef _MONSTER
#define _MONSTER

#define MAX_MONSTER         6
#define MAX_MONSTER_SHOT    3

#define MT_KNIGHT           0
#define MT_BAT              1
#define MT_REAPER           2
#define MT_SPIDER           3
#define MT_SKELETON         4

extern const unsigned char level1_1_data[];
extern const unsigned char level1_2_data[];
extern const unsigned char level1_3_data[];

extern const unsigned char level2_1_data[];
extern const unsigned char level2_2_data[];
extern const unsigned char level2_3_data[];

extern const unsigned char level3_1_data[];
extern const unsigned char level3_2_data[];
extern const unsigned char level3_3_data[];

//monster
extern UBYTE monster_act[MAX_MONSTER];
extern UBYTE monster_x[MAX_MONSTER];
extern UBYTE monster_y[MAX_MONSTER];
extern UBYTE monster_spr0[MAX_MONSTER];
extern UBYTE monster_spr1[MAX_MONSTER];
extern UBYTE monster_typ[MAX_MONSTER];
extern BYTE monster_dir[MAX_MONSTER];
extern UBYTE monster_ani[MAX_MONSTER];
extern UBYTE monster_dmg[MAX_MONSTER];
extern UBYTE monster_lif[MAX_MONSTER];
extern UBYTE monster_cnt[MAX_MONSTER];
extern UBYTE monster_pos[MAX_MONSTER];

//monster shot
extern UBYTE monster_shot_act[MAX_MONSTER_SHOT];
extern UBYTE monster_shot_x[MAX_MONSTER_SHOT];
extern UBYTE monster_shot_y[MAX_MONSTER_SHOT];
extern UBYTE monster_shot_spr[MAX_MONSTER_SHOT];
extern BYTE monster_shot_dir[MAX_MONSTER_SHOT];

void new_monster_shot(UBYTE x, UBYTE y) BANKED;
void update_monster_shot() BANKED;
void new_monster(UBYTE x, UBYTE y, UBYTE type) BANKED;
void update_monster() BANKED;

#endif