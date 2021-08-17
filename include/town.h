/*
** EPITECH PROJECT, 2020
** town_h
** File description:
** town_h
*/

#ifndef TOWN_H
#define TOWN_H
#include "my.h"
#include "hero_stat.h"
#include "graphic.h"
#include <time.h>
#include <stdlib.h>
#include <SFML/Audio.h>

typedef struct texture_s
{
    int pos;
    char *txt;
} texture_t;

enum clock {
    CLOCK_GATE_OPEN,
    CLOCK_MONSTER,
    CLOCK_MOVE_MONSTER,
    CLOCK_SPAWN_MONSTER,
    CLOCK_MOUVEMENT_PLAYER,
    WRITE_DIALOGUE,
    JUMP,
    CLOCK_ZONE,
    CLOCK
};

sfClock *tab_clock[CLOCK];

enum rectangle {
    RECT_DIALOGUE,
    NIQUE,
    RECTANGLE
};

sfRectangleShape *tab_rect[RECTANGLE];

enum text {
    DIALOGUE,
    RESPONSES,
    QUEST,
    STATS,
    TALK_POSS,
    STACKS,
    TEXT
};

sfText *text_tab[TEXT];

enum font {
    FONT_1,
    FONT
};

static const texture_t FONT_TAB[FONT] = {
    {FONT_1, "texture_pack/assets/menu_font.otf"}
};

sfFont *tab_font[FONT];

enum collision {
    LEFT,
    RIGHT,
    UP,
    DOWN,
    COLLISION
};

int collision_tab[COLLISION];

enum lock_or_delock {
    OPEN_QUEST_DIALOGUE,
    NEXT_DIALOGUE,
    CAN_TALK,
    OPEN_RESPONSES,
    VALID_RESPONSE,
    SAY_YES_NO,
    OPEN_MENU_QUEST,
    INVENTORY,
    DROP,
    INCR_QUEST,
    OPEN_CHEST,
    NEXTO_CHEST,
    TOWN_SCENE,
    WORLD_SCENE,
    GATE_CAN_BE_OPEN,
    OPEN_DOOR,
    GO_IN_CASTLE,
    CINE_Y,
    CINE_X,
    LOCK
};

int int_tab[LOCK];

enum save_options {
    OPEN_MENU_SAVE,
    START,
    SAVE,
    LOAD,
    EXIT,
    SAVE_SLOT_ONE,
    SAVE_SLOT_TWO,
    SAVE_SLOT_THREE,
    LOAD_SLOT_ONE,
    LOAD_SLOT_TWO,
    LOAD_SLOT_THREE,
    BACK_LOAD,
    BACK_SAVE,
    LOAD_MENU1,
    LOAD_MENU2,
    LOAD_MENU3,
    PANEL2,
    END
};

int save_tab[END];

enum stat_type {
    LIFE,
    XP_BAR,
    XP_LVL,
    GAME_OVER,
    GAME_OVER_RESTART,
    GAME_OVER_QUIT,
    LOAD_GO,
    PANEL_TWO,
    ATTACK,
    RUN,
    LAST_ACTION,
    ZONE_DRAW,
    SHIELD,
    DMG,
    LAST
};

int stat_tab[LAST];

enum pngg {
    PNG_1,
    PNG_2,
    PNG_QU
};

static const texture_t PNG_QUEST_QU[PNG_QU] = {
    {PNG_1, "texture_pack/pnj_girl.png"},
    {PNG_2, "texture_pack/pnj_guy.png"}
};

sfTexture *png_quest_qu[PNG_QU];

enum game_over {
    GO_LOAD,
    GO_QUIT,
    GO_LOAD1,
    GO_LOAD2,
    GO_LOAD3,
    GO
};

static const texture_t GAME_OVER_TAB[GO] = {
    {GO_LOAD, "texture_pack/stats/game_over_restart.png"},
    {GO_QUIT, "texture_pack/stats/game_over_quit.png"},
    {GO_LOAD1, "texture_pack/stats/game_over_restart_load1.png"},
    {GO_LOAD2, "texture_pack/stats/game_over_restart_load2.png"},
    {GO_LOAD3, "texture_pack/stats/game_over_restart_load3.png"}
};

sfTexture *text_game_over[GO];

enum monster {
    SNAKE,
    BAT,
    PARCHEMIN,
    BOSS,
    MONSTER
};

static const texture_t MONSTER_TAB[MONSTER] = {
    {SNAKE, "texture_pack/monster/Quetzalcoatl.png"},
    {BAT, "texture_pack/medium_obj/none.png"},
    {BOSS, "texture_pack/medium_obj/none.png"},
    {PARCHEMIN, "texture_pack/Save_folder/bg_opacity.png"}
};

sfTexture *text_monster[MONSTER];

enum quest {
    BANNIERE,
    QUEST_INV,
    QUEST_ENUM
};

static const texture_t QUEST_TAB[QUEST_ENUM] = {
    {BANNIERE, "texture_pack/quest/banniere.png"},
    {QUEST_INV, "texture_pack/quest/quest_menu.png"}
};

sfTexture *text_quest[QUEST_ENUM];

enum inventory {
    TXT_INV,
    POTION,
    HELMET,
    ARMURE1,
    CASQUE1,
    CASQUE2,
    OR,
    POMME,
    POTION_BLEUE,
    POTION_ORANGE,
    KEY,
    INV
};

static const texture_t INVENTORY_TAB[INV] = {
    {TXT_INV, "texture_pack/inventory/inventaire.png"},
    {POTION, "texture_pack/object_spr/potion.png"},
    {HELMET, "texture_pack/object_spr/helmet.png"},
    {ARMURE1, "texture_pack/object_spr/armure1.png"},
    {CASQUE1, "texture_pack/object_spr/casque1.png"},
    {CASQUE2, "texture_pack/object_spr/casque2.png"},
    {OR, "texture_pack/object_spr/or.png"},
    {POMME, "texture_pack/object_spr/pomme.png"},
    {POTION_BLEUE, "texture_pack/object_spr/potion_bleue.png"},
    {POTION_ORANGE, "texture_pack/object_spr/potion_orange.png"},
    {KEY, "texture_pack/object_spr/key.png"}
};

sfTexture *inventory_tab[INV];

enum sprite {
    SPRITE_OBJ,
    SPRITE_MAP,
    SPRITE_DISP_OBJ,
    SPRITE_MONSTER,
    PNG_QUEST,
    MENU_QUEST,
    INVENTORY_SPR,
    SAVE_SPRITE,
    STAT_SPRITE,
    ZONE_SPRITE,
    SPR_GATE_KEY,
    SPR_GATE_K,
    SPRITE
};

sfSprite *spr_tab[SPRITE];

enum gate_key {
    GATE_K_CLOSE,
    GATE_K_OPEN,
    WALL_K,
    GATE_K
};

static const texture_t GATE_K_TAB[GATE_K] = {
    {GATE_K_CLOSE, "texture_pack/medium_obj/DoorCurved1-0.png"},
    {GATE_K_CLOSE, "texture_pack/medium_obj/DoorCurved2-0.png"},
    {GATE_K_CLOSE, "texture_pack/medium_obj/WoodenWall4-1.png"},
};

sfTexture *tab_gate_k[GATE_K];

enum stat_txt {
    FULL_L,
    SC_L,
    MID_L,
    QUART_L,
    FULL_X,
    SC_X,
    MID_X,
    QUART_X,
    EMPTY_X,
    ZONE_PARS,
    ZONE_WORLD,
    ZONE_CASTLE,
    STAT_TXT
};

static const texture_t TEXTURE_STAT[STAT_TXT] = {
    {FULL_L, "texture_pack/stats/life_full.png"},
    {SC_L, "texture_pack/stats/life_sc.png"},
    {MID_L, "texture_pack/stats/life_half.png"},
    {QUART_L, "texture_pack/stats/life_quarteur.png"},
    {FULL_X, "texture_pack/stats/xp_full.png"},
    {SC_X, "texture_pack/stats/xp_sc.png"},
    {MID_X, "texture_pack/stats/xp_half.png"},
    {QUART_X, "texture_pack/stats/xp_quarteur.png"},
    {EMPTY_X, "texture_pack/stats/xp_empty.png"},
    {ZONE_PARS, "texture_pack/stats/zone_pars.png"},
    {ZONE_WORLD, "texture_pack/stats/zone_world.png"},
    {ZONE_CASTLE, "texture_pack/stats/zone_castle.png"}
};

sfTexture *texture_stat[STAT_TXT];

enum save_txt {
    BG_OPACITY,
    TXT_MENU1,
    BG_MENU,
    SAVE_TXT
};

static const texture_t TEXTURE_SAVE[SAVE_TXT] = {
    {BG_OPACITY, "texture_pack/Save_folder/bg_opacity.png"},
    {TXT_MENU1, "texture_pack/Save_folder/load_menu.png"},
    {BG_MENU, "texture_pack/assets/main_menu.png"}
};

sfTexture *texture_save[SAVE_TXT];

enum tileset {
    GRASS,
    GRASS_1,
    PAVING,
    DIRT,
    TILESET
};

static const texture_t TEXTURE_MAP[TILESET] = {
    {GRASS, "texture_pack/grass1.png"},
    {GRASS_1, "texture_pack/grass1.png"},
    {PAVING, "texture_pack/grass1.png"},
    {DIRT, "texture_pack/grass1.png"}
};

sfTexture *tab_tilset[TILESET];

enum texture_obj {
    BLUE_HOUSE1,
    BLUE_HOUSE2,
    BLUE_HOUSE3,
    BLUE_HOUSE4,
    BROWN_HOUSE1,
    BROWN_HOUSE2,
    BROWN_HOUSE3,
    BROWN_HOUSE4,
    GREEN_HOUSE1,
    GREEN_HOUSE2,
    GREEN_HOUSE3,
    GREEN_HOUSE4,
    RED_HOUSE1,
    RED_HOUSE2,
    RED_HOUSE3,
    RED_HOUSE4,
    BASIC_BLUE_HOUSE1,
    BASIC_BLUE_HOUSE2,
    BASIC_BLUE_HOUSE3,
    BASIC_BLUE_HOUSE4,
    BASIC_BROWN_HOUSE1,
    BASIC_BROWN_HOUSE2,
    BASIC_BROWN_HOUSE3,
    BASIC_BROWN_HOUSE4,
    BASIC_GREEN_HOUSE1,
    BASIC_GREEN_HOUSE2,
    BASIC_GREEN_HOUSE3,
    BASIC_GREEN_HOUSE4,
    BASIC_RED_HOUSE1,
    BASIC_RED_HOUSE2,
    BASIC_RED_HOUSE3,
    BASIC_RED_HOUSE4,
    NORMAL_HOUSE_1,
    NORMAL_HOUSE_2,
    NORMAL_HOUSE_3,
    NORMAL_HOUSE_4,
    NORMAL_HOUSE_5,
    NORMAL_HOUSE_6,
    NORMAL_HOUSE_7,
    NORMAL_HOUSE_8,
    POOR_HOUSE_1,
    POOR_HOUSE_2,
    POOR_HOUSE_3,
    POOR_HOUSE_4,
    POOR_HOUSE_5,
    POOR_HOUSE_6,
    POOR_HOUSE_7,
    POOR_HOUSE_8,
    CASTLE_TILE_RIGHT,
    CASTLE_TILE_DOWN,
    CASTLE_TILE_LEFT,
    CASTLE_TILE_FACE,
    CASTLE_TILE_RIGHT2,
    CASTLE_TILE_DOWN2,
    CASTLE_TILE_LEFT2,
    CASTLE_TILE_FACE2,
    TOWER_1,
    TOWER_2,
    TOWER_3,
    TOWER_4,
    TOWER_5,
    TOWER_6,
    TOWER_7,
    TOWER_8,
    TOWER_9,
    TOWER_10,
    TOWER_11,
    TOWER_12,
    TOWER_13,
    TEXTURE
};

static const texture_t TEXTURE_OBJ[TEXTURE] = {
    {BLUE_HOUSE1, "texture_pack/medium_obj/house6-0.png"},
    {BLUE_HOUSE2, "texture_pack/medium_obj/house6-1.png"},
    {BLUE_HOUSE3, "texture_pack/medium_obj/house6-2.png"},
    {BLUE_HOUSE4, "texture_pack/medium_obj/house6-1.png"},
    {BROWN_HOUSE1, "texture_pack/medium_obj/house6-0.png"},
    {BROWN_HOUSE2, "texture_pack/medium_obj/house6-1.png"},
    {BROWN_HOUSE3, "texture_pack/medium_obj/house6-2.png"},
    {BROWN_HOUSE4, "texture_pack/medium_obj/house6-1.png"},
    {GREEN_HOUSE1, "texture_pack/medium_obj/house6-0.png"},
    {GREEN_HOUSE2, "texture_pack/medium_obj/house6-1.png"},
    {GREEN_HOUSE3, "texture_pack/medium_obj/house6-2.png"},
    {GREEN_HOUSE4, "texture_pack/medium_obj/house6-1.png"},
    {RED_HOUSE1, "texture_pack/medium_obj/house6-0.png"},
    {RED_HOUSE2, "texture_pack/medium_obj/house6-1.png"},
    {RED_HOUSE3, "texture_pack/medium_obj/house6-2.png"},
    {RED_HOUSE4, "texture_pack/medium_obj/house6-1.png"},
    {BASIC_BLUE_HOUSE1, "texture_pack/medium_obj/house6-0.png"},
    {BASIC_BLUE_HOUSE2, "texture_pack/medium_obj/house6-1.png"},
    {BASIC_BLUE_HOUSE3, "texture_pack/medium_obj/house6-2.png"},
    {BASIC_BLUE_HOUSE4, "texture_pack/medium_obj/house6-1.png"},
    {BASIC_BROWN_HOUSE1, "texture_pack/medium_obj/house6-0.png"},
    {BASIC_BROWN_HOUSE2, "texture_pack/medium_obj/house6-1.png"},
    {BASIC_BROWN_HOUSE3, "texture_pack/medium_obj/house6-2.png"},
    {BASIC_BROWN_HOUSE4, "texture_pack/medium_obj/house6-1.png"},
    {BASIC_GREEN_HOUSE1, "texture_pack/medium_obj/house6-0.png"},
    {BASIC_GREEN_HOUSE2, "texture_pack/medium_obj/house6-1.png"},
    {BASIC_GREEN_HOUSE3, "texture_pack/medium_obj/house6-2.png"},
    {BASIC_GREEN_HOUSE4, "texture_pack/medium_obj/house6-1.png"},
    {BASIC_RED_HOUSE1, "texture_pack/medium_obj/house6-0.png"},
    {BASIC_RED_HOUSE2, "texture_pack/medium_obj/house6-1.png"},
    {BASIC_RED_HOUSE3, "texture_pack/medium_obj/house6-2.png"},
    {BASIC_RED_HOUSE4, "texture_pack/medium_obj/house6-1.png"},
    {NORMAL_HOUSE_1, "texture_pack/medium_obj/house6-0.png"},
    {NORMAL_HOUSE_2, "texture_pack/medium_obj/house6-1.png"},
    {NORMAL_HOUSE_3, "texture_pack/medium_obj/house6-2.png"},
    {NORMAL_HOUSE_4, "texture_pack/medium_obj/house6-1.png"},
    {NORMAL_HOUSE_5, "texture_pack/medium_obj/house6-0.png"},
    {NORMAL_HOUSE_6, "texture_pack/medium_obj/house6-1.png"},
    {NORMAL_HOUSE_7, "texture_pack/medium_obj/house6-2.png"},
    {NORMAL_HOUSE_8, "texture_pack/medium_obj/house6-1.png"},
    {POOR_HOUSE_1, "texture_pack/medium_obj/house6-0.png"},
    {POOR_HOUSE_2, "texture_pack/medium_obj/house6-1.png"},
    {POOR_HOUSE_3, "texture_pack/medium_obj/house6-2.png"},
    {POOR_HOUSE_4, "texture_pack/medium_obj/house6-1.png"},
    {POOR_HOUSE_5, "texture_pack/medium_obj/house6-0.png"},
    {POOR_HOUSE_6, "texture_pack/medium_obj/house6-1.png"},
    {POOR_HOUSE_7, "texture_pack/medium_obj/house6-2.png"},
    {POOR_HOUSE_8, "texture_pack/medium_obj/house6-1.png"},
    {CASTLE_TILE_RIGHT, "texture_pack/medium_obj/castleTileLong-0.png"},
    {CASTLE_TILE_DOWN, "texture_pack/medium_obj/castleTileLong-1.png"},
    {CASTLE_TILE_LEFT, "texture_pack/medium_obj/castleTileLong-0.png"},
    {CASTLE_TILE_FACE, "texture_pack/medium_obj/castleTileLong-1.png"},
    {CASTLE_TILE_RIGHT2, "texture_pack/medium_obj/none.png"},
    {CASTLE_TILE_DOWN2, "texture_pack/medium_obj/none.png"},
    {CASTLE_TILE_LEFT2, "texture_pack/medium_obj/none.png"},
    {CASTLE_TILE_FACE2, "texture_pack/medium_obj/none.png"},
    {TOWER_1, "texture_pack/medium_obj/castleTowerConnect-0.png"},
    {TOWER_2, "texture_pack/medium_obj/castleTowerConnect-0.png"},
    {TOWER_3, "texture_pack/medium_obj/castleTowerConnect-0.png"},
    {TOWER_4, "texture_pack/medium_obj/castleTowerConnect-0.png"},
    {TOWER_5, "texture_pack/medium_obj/castleTowerConnect-0.png"},
    {TOWER_6, "texture_pack/medium_obj/castleTowerConnect-0.png"},
    {TOWER_7, "texture_pack/medium_obj/castleTowerConnect-0.png"},
    {TOWER_8, "texture_pack/medium_obj/castleTowerConnect-0.png"},
    {TOWER_9, "texture_pack/medium_obj/castleTowerConnect-0.png"},
    {TOWER_10, "texture_pack/medium_obj/castleTowerConnect-0.png"},
    {TOWER_11, "texture_pack/medium_obj/castleTowerConnect-0.png"},
    {TOWER_12, "texture_pack/medium_obj/castleTowerConnect-0.png"},
    {TOWER_13, "texture_pack/medium_obj/castleTowerConnect-0.png"}
};

sfTexture *tab_txt[TEXTURE];

enum texture_mvt {
    GATE_OPEN1,
    GATE_OPEN2,
    GATE_OPEN3,
    GATE_OPEN4,
    GATE_CLOSE1,
    GATE_CLOSE2,
    GATE_CLOSE3,
    GATE_CLOSE4,
    CAMPFIRE1,
    CAMPFIRE2,
    CAMPFIRE3,
    TEXTURE_MVT
};

static const texture_t TEXTURE_MOUV[TEXTURE_MVT] = {
    {GATE_OPEN1, "texture_pack/medium_obj/Animation/gate1(1).png"},
    {GATE_OPEN2, "texture_pack/medium_obj/Animation/gate1(2).png"},
    {GATE_OPEN3, "texture_pack/medium_obj/Animation/gate1(3).png"},
    {GATE_OPEN4, "texture_pack/medium_obj/Animation/gate1(4).png"},
    {GATE_CLOSE1, "texture_pack/medium_obj/Animation/gate1(4).png"},
    {GATE_CLOSE2, "texture_pack/medium_obj/Animation/gate1(3).png"},
    {GATE_CLOSE3, "texture_pack/medium_obj/Animation/gate1(2).png"},
    {GATE_CLOSE4, "texture_pack/medium_obj/Animation/gate1(1).png"},
    {CAMPFIRE1, "texture_pack/medium_obj/campfire1-0.png"},
    {CAMPFIRE2, "texture_pack/medium_obj/campfire1-0.png"},
    {CAMPFIRE3, "texture_pack/medium_obj/campfire1-0.png"}
};

sfTexture *texture_mouv[TEXTURE_MVT];

typedef struct object_s
{
    int begin_x;
    int begin_y;
    int x_min;
    int y_min;
    float x;
    float y;
    int nbr_tab;
    int nbr_texture;
    int nbr_obj;
    int state;
} object_t;

typedef struct parser_s
{
    char **quest_parser;
    char **quest_world;
    char **tab_pars;
    char **world_parser;
    char **quest;
    char **object;
    char **castle;
    char **down;
} parser_t;

typedef struct quest_s
{
    int nbr_obj_to_find;
    int obj_to_find;
    int txt_obj;
    int tab_to_fill;
    int nb_texture;
    int line;
    int dialogue_nb;
    sfVector2f coor;
    sfTexture *texture;
    int first_line;
    int last_line;
    int nbr_quest;
    int state;
} quest_t;

typedef struct map_s
{
    int collision;
    sfIntRect rect;
    sfVector2f coor;
    float offset_left;
    float max_offset_left;
    float min_offset_left;
    int txt;
    int live;
    float time;
    float direction_time;
    int alea;
    int aggro;

    int life;
    int life_save;
    int attack;
    int xp_gain;
    sfVector2f hit_box_x;
    sfVector2f hit_box_y;
    sfVector2f coor_x;
    sfVector2f coor_y;
    sfTexture *texture;
} map_t;

typedef struct game_s {
    sfRenderWindow *window;
    sfView *view;
    sfVector2f pos_screen;
    sfTexture *bg_tx;
    sfSprite *bg_sp;
    sfVector2f blockpos;
    sfVector2f value_middle;
    sfVector2f value_view;
} game_t;

typedef struct window_size_s
{
    sfVector2f size;
    sfVector2f size_screen;
} window_size_t;

typedef struct window_s
{
    sfVideoMode video_mode;
    sfRenderWindow *window;
    sfColor color;
} window_t;

typedef struct allsnd
{
    sfMusic **zik;
    sfSound **snd;
    float volume;
} allsnd_t;

typedef struct main_town_s {
    window_t window;
    window_size_t size;
    game_t p;
    parser_t parser;
    png_t png;
    allsnd_t music;
} main_town_t;

//all
int norme_on_quest_monitor(main_town_t *town, quest_t quest);
void norme_for_dialogue2(main_town_t *town, char *str);
void norme_for_dialogue(main_town_t *town, char **tab,
    int dialogue, char *str);
void draw_png_for_the_quest(main_town_t *town, quest_t quest);
float get_elapsed_time(sfClock *clock);
void draw_spr_chosen(main_town_t *town, sfSprite *spr);
void free_all(main_town_t *town);
void draw_png(main_town_t *town, sfVector2f pos, sfSprite *spr);
void draw_sprite(main_town_t *town, sfVector2f pos,
    sfVector2f size_spr, sfSprite *spr);
void draw_door_open_close(map_t map, main_town_t *town, sfTexture *text,
    float delta);
char **actualise_gate_open(char **tab, map_t map, int i);
void draw_text_choose(main_town_t *town, map_t map, char *str);
int check_inventory_key(main_town_t *town);
void decide_what_fulfill2(map_t *map, char *str, int count);
char **gate_open_with_key(map_t map, main_town_t *town, int i, char **tab);
int start_load_game(main_town_t *town, char **path, sfEvent *event);
int error_env(char **env);
char **chest_obj(map_t map, main_town_t *town, int i, char **tab);
void fulfill_the_chest(map_t *map, char *str);
char **chest_option(char **tab_pars, int i, main_town_t *town);
void block_the_player(int);
int collision_png(main_town_t *town, sfVector2f coor, sfSprite *spr);
void get_the_aggro(main_town_t *town, map_t *monster);
int aggro_monster(main_town_t *town, map_t *monster);
char **actualise_monster(map_t map, int i, char **tab);
char **monster_animation(map_t monster, main_town_t *town, int i, char **tab);
void analyse_event(sfEvent *event, main_town_t *town);
char **str_to_tab(char *str);
char *get_the_buff(char *str);
char **get_obj_pos(main_town_t *town, char **tab_pars, int dim);
void get_the_scale(sfVector2u scale, main_town_t *town);
map_t parse_and_call_map(char *str, int count);
void display_map(map_t map, main_town_t *town);
void display_object(map_t map, main_town_t *town);
void view_event(main_town_t *town, sfEvent *event);
void view_event2(main_town_t *town, sfEvent *event, int speed);
void view_event1(main_town_t *town, sfEvent *event, int speed);
void save_event(main_town_t *town, sfEvent *event);
char *load_event(main_town_t *town, sfEvent *event);
void other_stuff(char **tab_pars, int i, main_town_t *town);
void fulfill_stuff(map_t *map, char *str);
void fulfill_nature(map_t *map, char *str);
void fulfill_rock(map_t *map, char *str);
void fulfill_wooden(map_t *map, char *str);
void set_olivier(void);
void draw_sprite(main_town_t *town, sfVector2f pos,
sfVector2f size_spr, sfSprite *spr);
sfVector2f calcul_x_y_min(main_town_t *town, sfVector2f size_map);
sfVector2f calcul_x_y_max(main_town_t *town, sfVector2f size_map);
void display_obj_as_map(map_t map, main_town_t *town);
void other_stuff(char **tab_pars, int i, main_town_t *town);
void fulfill_stuff(map_t *map, char *str);
void fulfill_nature(map_t *map, char *str);
void fulfill_rocks(map_t *map, char *str);
void fulfill_wooden(map_t *map, char *str);
void set_olivier(void);
void gate_open(map_t map, main_town_t *town);
void draw_png(main_town_t *town, sfVector2f pos, sfSprite *spr);
void png_quest(quest_t quest, char **tab, main_town_t *town);
quest_t parse_the_quest(char *str, char **tab_pars, int line);
void actualise_quest(quest_t quest, main_town_t *town);
void quest_monitor(quest_t quest, main_town_t *town);
void display_menu_quest(main_town_t *town);
void inventory_monitor(main_town_t *town);
void actualise_object(object_t object, main_town_t *town, int count);
void actualise_obj_position(object_t object,
main_town_t *town, int count, sfVector2i coor);
void pars_object(char *str, object_t *object);
void actualise_object_parser(main_town_t *town, int nbr_texture);
void make_a_jump(main_town_t *town);
void inventory_monitor(main_town_t *town);
int inventory_management(main_town_t *town, int count);
int draw_object(main_town_t *town, int count, object_t fl);
void put_obj_in_inventory(main_town_t *town, int nbr_texture, int type_of_obj);
void actualise_obj_when_put_in_inventory(main_town_t *town,
    sfVector2i coor, int nbr_texture, int);
void reset_delta_time(main_town_t *town);

//event function :
void inventory_event(sfEvent *event);
void restart_all(void);
void menu_pause_game_event(sfEvent *event,
sfRenderWindow *window, allsnd_t *music);
int clock_process(int display_time, sfTime time);
void cinematic_event(main_town_t *town);

//parser function :
void fulfill_the_monster(map_t *map, char *str);
int set_pos2(int i, main_town_t *town, char **tab_pars);
int set_pos3(int i, main_town_t *town, char **tab_pars);
char **set_pos4(int i, main_town_t *town, char **tab_par);
int choose_map(main_town_t *town);

//inventory function :
void pars_first_line(char *str, object_t *object);
int inventory_management(main_town_t *town, int count);
void drop_normal(main_town_t *town, object_t *object, object_t fl);
char *actualise_good_line2(object_t *object);
void actualise_scd_tab(main_town_t *town, object_t *object, int count);
int decide_what_case_fulfill(main_town_t *town);
int actualise_special_case1(main_town_t *town, object_t *object, int count);
void actualise_good_line(main_town_t *town, object_t *object, char *beg);
int check_empty_special_case(main_town_t *town, char *str);
int scdn_tab_to_special_case(main_town_t *town,
    object_t *object, int count);
int drop_special_case(main_town_t *town, object_t *object,
object_t fl, int count);
void draw_stack(main_town_t *town, object_t obj, sfVector2f coor);
int check_if_obj_exist(char *str, int nbr_texture);
int **fullfil_the_int_tab(int **tab, char *str);
void put_obj_in_second_line(main_town_t *town, int nbr_texture,
int type_of_block);
int get_the_part_want(char *str, int count);
void actualise_when_more_than_one_object(main_town_t *town, int i);
int check_if_case_is_empty(main_town_t *town, sfVector2i coor, object_t fl);
void send_rect(object_t *object, char *str);
void pars_object(char *str, object_t *object);
sfVector2i get_the_position_in_tab(char *str);
int take_obj_or_drop(main_town_t *town, object_t fl, int count,
    object_t object);
sfVector2f grab_object(main_town_t *town);

//monster function
int get_zone_for_monster(map_t *monster, main_town_t *town);
void monster_attack_position(map_t *monster,
    sfVector2f player, main_town_t *town);
void monster_attack_damages(map_t *monster,
    sfVector2f player, main_town_t *town);
void monster_hurt_actions(map_t *monster, main_town_t *town);
void monster_get_hurt_actions(map_t *monster);
char **monster_state(map_t *monster, main_town_t *town, int i, char **tab_pars);
int get_random_coor(map_t *monster);

//quest function
void display_poss_of_talk(main_town_t *town, quest_t quest);
void write_responses2(quest_t quest, char **tab, main_town_t *town,
    int dialogue);
void write_responses(quest_t quest, char **tab, main_town_t *town,
    int dialogue);
void positive_response(quest_t quest, main_town_t *town);
int validate_or_not_the_response(quest_t quest, main_town_t *town);
void possibilities_of_dialogs(quest_t quest, char **tab, int dialogue);
char *get_the_str(int i, int lock, char **tab, int dialogue);
int clock_write_dialogue(int i);
sfText *draw_lock_0(char *str, main_town_t *town, int pos);
sfText *draw_lock_1(char **tab, main_town_t *town, int dialogue);
void beautiful_display(char **tab, quest_t quest, int dialogue,
    main_town_t *town);
void png_quest(quest_t quest, char **tab, main_town_t *town);
void display_rect_dialogue(main_town_t *town);
int display_dialogue(quest_t quest, int dialogue, main_town_t *town,
    char **tab);
int display_dialogue2(quest_t quest, int dialogue, main_town_t *town,
    char **tab);
void display_rect_response(main_town_t *town);
int did_png_is_in_range_for_quest(main_town_t *town, quest_t quest);
int dialogue_begin(int i, int dialogue);
void block_the_player(int lock);

//save
void save_interface(main_town_t *town, sfEvent *event);
void display_menu_save(main_town_t *town);
void choose_slot_save_down(sfEvent *event);
void choose_slot_save_up(sfEvent *event);
void choose_slot_load_down(sfEvent *event);
void choose_slot_load_up(sfEvent *event);
void choose_panel_one_down(sfEvent *event, int panel);
void choose_panel_one_up(sfEvent *event, int panel);
int if_pause_pressed_do_this(sfEvent *event, int panel);
int move_back(void);
int main_menu_test(char **env, sfRenderWindow *window, allsnd_t *music);
void draw_menu_all(main_town_t *town, enum save_txt TEST);
void all_parser_to_tab(main_town_t *town, char *path);
char *load_game_from_start_screen(main_town_t *town, sfEvent *event);
void draw_menu_bg(main_town_t *town, enum save_txt TEST);
void draw_sprites(main_town_t *town);
void down_chose(sfEvent *event);
void up_chose(sfEvent *event);
void draw_menu_text(main_town_t *town, char *str, sfVector2f p, int size);
int display_menu_save_slot3(main_town_t *town);

//stats
void diplay_stats(main_town_t *town);
void set_stats(void);
void draw_stats(main_town_t *town, enum save_txt TEST);
int life_display(int life_chose_sprite, main_town_t *town);
int xp_diplayed(int xp_chose_sprite, main_town_t *town);
int calcul_life(void);
int calcul_xp(void);
void draw_zone_text(main_town_t *town, enum stat_txt TEST);
void increase_capacities(void);

//set
void set_the_window(main_town_t *town);
void set_the_parser(main_town_t *town);
void set_view(main_town_t *town);
void set_the_enums(void);
void set_all(main_town_t *town, char **av, int ac);
void set_the_png(png_t *png);

//game over
void draw_all_game_over(main_town_t *town);
void game_over_event(main_town_t *town, sfEvent *event);
void draw_game_over(main_town_t *town, enum game_over TEST);
void display_game_over_panel2(main_town_t *town);
void display_game_over_panel1(main_town_t *town);
void load_game_over(main_town_t *town, sfEvent *event);
void load_game_over_continue(main_town_t *town, sfEvent *event);

//hero mvmt
void move_hero(png_t *png, sfEvent *event);
void stop_hero(png_t *png, sfEvent *event);
void change_dir_hero(png_t *png);
void clock_hero(png_t *png, allsnd_t *music);
void run_action_hero(png_t *png, sfIntRect *rect);
void attack_action_hero(png_t *png, sfIntRect *rect);

//music
void set_the_music(allsnd_t *music);
void change_volume_zik(allsnd_t *music);
void free_sound(allsnd_t *music);

#endif
