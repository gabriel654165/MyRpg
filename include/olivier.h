/*
** EPITECH PROJECT, 2020
** olivier_h
** File description:
** olivier_h
*/

#ifndef OLIVIER_H
#define OLIVIER_H
#include "graphic.h"
#include "town.h"

enum text_chest {
    TONNEAU,
    TONNEAU2,
    TONNEAU3,
    CHEST
};

static const texture_t TEXTURE_CHEST[CHEST] = {
    {TONNEAU, "texture_pack/medium_obj/barrel1-0.png"},
    {TONNEAU2, "texture_pack/medium_obj/barrel1-0.png"},
    {TONNEAU3, "texture_pack/medium_obj/barrel1-0.png"}
};

sfTexture *tab_chest[CHEST];

enum texture_wooden {
    WOODEN_BANC_COTE,
    WOODEN_BANC_FACE,
    WOODEN_BANC_OBLIQUE,
    WOODEN_BANC_COTE_DESTROYED,
    WOODEN_BANC_FACE_DESTROYED,
    WOODEN_BANC_OBLIQUE_DESTROYED,
    WOODEN_WALL_COTE_LEFT,
    WOODEN_WALL_FACE,
    WOODEN_WALL_COTE_RIGHT,
    WOODEN_WALL_FACE_DAMAGED,
    WOODEN_WALL_COTE_RIGHT_DAMAGED,
    WOODEN_WALL_COTE_LEFT_DAMAGED,
    WOODEN
};

static const texture_t TEXTURE_WOODEN[WOODEN] = {
    {WOODEN_BANC_COTE, "texture_pack/medium_obj/none.png"},
    {WOODEN_BANC_FACE, "texture_pack/medium_obj/none.png"},
    {WOODEN_BANC_OBLIQUE, "texture_pack/medium_obj/none.png"},
    {WOODEN_BANC_COTE_DESTROYED, "texture_pack/medium_obj/none.png"},
    {WOODEN_BANC_FACE_DESTROYED, "texture_pack/medium_obj/none.png"},
    {WOODEN_BANC_OBLIQUE_DESTROYED, "texture_pack/medium_obj/none.png"},
    {WOODEN_WALL_COTE_LEFT, "texture_pack/medium_obj/WoodenWall4-2.png"},
    {WOODEN_WALL_FACE, "texture_pack/medium_obj/WoodenWall4-1.png"},
    {WOODEN_WALL_COTE_RIGHT, "texture_pack/medium_obj/WoodenWall4-2.png"},
    {WOODEN_WALL_FACE_DAMAGED, "texture_pack/medium_obj/WoodenWall4-1.png"},
    {WOODEN_WALL_COTE_RIGHT_DAMAGED,
    "texture_pack/medium_obj/WoodenWall4-2.png"},
    {WOODEN_WALL_COTE_LEFT_DAMAGED, "texture_pack/medium_obj/WoodenWall4-2.png"}
};

sfTexture *tab_text_wooden[WOODEN];

enum texture_city {
    FOUNTAIN,
    MOTTE,
    BARREL,
    BUCKET_WATER,
    WOODEN_BOX,
    FENCE1,
    FENCE2,
    ECHELLE_SIDE,
    ECHELLE_FACE,
    LANTERN_RIGHT,
    LANTERN_LEFT,
    LANTERN_FACE,
    HACHE,
    OVEN,
    GUILLOTINE,
    SIGN,
    SIGN2,
    TOUR,
    TOUR2,
    TOUR3,
    SWORD_DEBOUT,
    SWORD_COUCHEE,
    TENTE_FACE,
    TENTE_DOS,
    TENTE_SIDE,
    TENTE_INCLINE,
    TORCHE_RIGHT,
    TORCHE_LEFT,
    WATER_HORSE_FACE,
    WATER_HORSE_COTE,
    WATER_HORSE_OBLIQUE,
    WELL_HOUSE_FACE,
    WELL_HOUSE_DROITE,
    WELL_HOUSE_GAUCHE,
    OVEN_2,
    OVEN_3,
    FIRE,
    STUFF
};

static const texture_t TEXTURE_STUFF[STUFF] = {
    {FOUNTAIN, "texture_pack/medium_obj/fountain2-0.png"},
    {MOTTE, "texture_pack/medium_obj/none.png"},
    {BARREL, "texture_pack/medium_obj/barrel1-0.png"},
    {BUCKET_WATER, "texture_pack/medium_obj/none.png"},
    {WOODEN_BOX, "texture_pack/medium_obj/crate3-3.png"},
    {FENCE2, "texture_pack/medium_obj/none.png"},
    {FENCE1, "texture_pack/medium_obj/none.png"},
    {ECHELLE_SIDE, "texture_pack/medium_obj/none.png"},
    {ECHELLE_FACE, "texture_pack/medium_obj/none.png"},
    {LANTERN_RIGHT, "texture_pack/medium_obj/none.png"},
    {LANTERN_LEFT, "texture_pack/medium_obj/none.png"},
    {LANTERN_FACE, "texture_pack/medium_obj/none.png"},
    {HACHE, "texture_pack/medium_obj/none.png"},
    {OVEN, "texture_pack/medium_obj/oven2-0.png"},
    {GUILLOTINE, "texture_pack/medium_obj/none.png"},
    {SIGN, "texture_pack/medium_obj/none.png"},
    {SIGN2, "texture_pack/medium_obj/none.png"},
    {TOUR, "texture_pack/medium_obj/stage1-0.png"},
    {TOUR2, "texture_pack/medium_obj/stage1-4.png"},
    {TOUR3, "texture_pack/medium_obj/stage1-4.png"},
    {SWORD_DEBOUT, "texture_pack/medium_obj/none.png"},
    {SWORD_COUCHEE, "texture_pack/medium_obj/sword-3.png"},
    {TENTE_FACE, "texture_pack/medium_obj/tent-0.png"},
    {TENTE_DOS, "texture_pack/medium_obj/tent-0.png"},
    {TENTE_SIDE, "texture_pack/medium_obj/tent-1.png"},
    {TENTE_INCLINE, "texture_pack/medium_obj/tent-1.png"},
    {TORCHE_RIGHT, "texture_pack/medium_obj/torch1-0.png"},
    {TORCHE_LEFT, "texture_pack/medium_obj/torch1-1.png"},
    {WATER_HORSE_FACE, "texture_pack/medium_obj/none.png"},
    {WATER_HORSE_COTE, "texture_pack/medium_obj/none.png"},
    {WATER_HORSE_OBLIQUE, "texture_pack/medium_obj/none.png"},
    {WELL_HOUSE_FACE, "texture_pack/medium_obj/wellHouse-0.png"},
    {WELL_HOUSE_DROITE, "texture_pack/medium_obj/none.png"},
    {WELL_HOUSE_GAUCHE, "texture_pack/medium_obj/none.png"},
    {OVEN_2, "texture_pack/medium_obj/none.png"},
    {OVEN_3, "texture_pack/medium_obj/none.png"},
    {FIRE, "texture_pack/medium_obj/campfire1-0.png"}
};

sfTexture *tab_txt_stuff[STUFF];

enum texture_rock {
    ROCK_LONG,
    ROCK_TRIANGLE_DROITE,
    ROCK_HAUT,
    ROCK_TRIANGLE_GAUCHE,
    ROCK_TRIANGLE,
    ROCK_TRIANGLE2,
    ROCK_BOULE,
    ROCK_PLAT,
    WALL_ROCK_COTE,
    WALL_ROCK_COTE2,
    WALL_ROCK_COTE3,
    WALL_ROCK_COTE4,
    WALL_ROCK_COTE5,
    WALL_ROCK_FACE,
    WALL_ROCK_FACE2,
    WALL_ROCK_FACE_DESTROYED,
    WALL_GALETS_COTE,
    WALL_GALETS_COTE2,
    WALL_GALETS_COTE3,
    WALL_GALETS_FACE,
    WALL_GALETS_FACE2,
    WALL_GALETS_FACE3,
    WALL_GALETS_FACE_DESTROYED,
    ROCKS
};

static const texture_t TEXTURE_ROCKS[ROCKS] = {
    {ROCK_LONG, "texture_pack/medium_obj/rock1-2.png"},
    {ROCK_TRIANGLE_DROITE, "texture_pack/medium_obj/rock1-2.png"},
    {ROCK_TRIANGLE_GAUCHE, "texture_pack/medium_obj/rock1-2.png"},
    {ROCK_HAUT, "texture_pack/medium_obj/rock1-2.png"},
    {ROCK_TRIANGLE, "texture_pack/medium_obj/rock3-1.png"},
    {ROCK_TRIANGLE2, "texture_pack/medium_obj/rock3-1.png"},
    {ROCK_BOULE, "texture_pack/medium_obj/rock3-1.png"},
    {ROCK_PLAT, "texture_pack/medium_obj/rock3-1.png"},
    {WALL_ROCK_COTE, "texture_pack/medium_obj/WallRock1-0.png"},
    {WALL_ROCK_COTE2, "texture_pack/medium_obj/WallRock1-0.png"},
    {WALL_ROCK_COTE3, "texture_pack/medium_obj/WallRock1-0.png"},
    {WALL_ROCK_COTE4, "texture_pack/medium_obj/WallRock1-0.png"},
    {WALL_ROCK_COTE5, "texture_pack/medium_obj/WallRock1-0.png"},
    {WALL_ROCK_FACE, "texture_pack/medium_obj/WallRock1-1.png"},
    {WALL_ROCK_FACE2, "texture_pack/medium_obj/WallRock1-1.png"},
    {WALL_ROCK_FACE_DESTROYED, "texture_pack/medium_obj/WallRock1-1.png"},
    {WALL_GALETS_COTE, "texture_pack/medium_obj/WallRock1-0.png"},
    {WALL_GALETS_COTE2, "texture_pack/medium_obj/WallRock1-0.png"},
    {WALL_GALETS_COTE3, "texture_pack/medium_obj/WallRock1-0.png"},
    {WALL_GALETS_FACE, "texture_pack/medium_obj/WallRock1-1.png"},
    {WALL_GALETS_FACE2, "texture_pack/medium_obj/WallRock1-1.png"},
    {WALL_GALETS_FACE3, "texture_pack/medium_obj/WallRock1-1.png"},
    {WALL_GALETS_FACE_DESTROYED, "texture_pack/medium_obj/WallRock1-1.png"}
};

sfTexture *tab_txt_rocks[ROCKS];

enum texture_nature {
    RED_FLOWER,
    WHITE_FLOWER,
    HERBE1,
    HERBE2,
    HERBE3,
    BOUQUET_BLANC,
    BOUQUET_ROUGE,
    POUSSE_ARBRE,
    TREES_FACE,
    TREES_DIAGO,
    TREES_SORTED,
    SAPIN,
    SAPIN_DROITE,
    SAPIN_GAUCHE,
    SAPIN_DEFOURNI,
    SAPIN_DEFOURNI2,
    SAPIN_DEFOURNI3,
    ARBRE_MORT,
    ARBRE_MORT2,
    ARBRE_MORT3,
    ARBRE_MORT4,
    ARBRE_MORT5,
    ARBRE_MORT6,
    BANAL_TREE,
    BANAL_TREE_RIGHT,
    BANAL_TREE_LEFT,
    BIG_TREE,
    BIG_TREE2,
    BIG_TREE3,
    MOCHE_TREE,
    MOCHE_TREE2,
    MOCHE_TREE3,
    TRONC_COTE,
    TRONC_FACE,
    TRONC_OBLIQUE,
    TRONC_PETIT_COTE,
    TRONC_PETIT_FACE,
    TRONC_PETIT_OBLIQUE,
    TRONC,
    TRONC_RACINES,
    NATURE
};

static const texture_t TEXTURE_NATURE[NATURE] = {
    {RED_FLOWER, "texture_pack/medium_obj/none.png"},
    {WHITE_FLOWER, "texture_pack/medium_obj/none.png"},
    {HERBE1, "texture_pack/medium_obj/plant1-0.png"},
    {HERBE2, "texture_pack/medium_obj/plant1-0.png"},
    {HERBE3, "texture_pack/medium_obj/plant1-0.png"},
    {BOUQUET_BLANC, "texture_pack/medium_obj/plant1-0.png"},
    {BOUQUET_ROUGE, "texture_pack/medium_obj/plant1-0.png"},
    {POUSSE_ARBRE, "texture_pack/medium_obj/plant1-0.png"},
    {TREES_FACE, "texture_pack/medium_obj/none.png"},
    {TREES_DIAGO, "texture_pack/medium_obj/none.png"},
    {TREES_SORTED, "texture_pack/medium_obj/lumberjackTrees3-2.png"},
    {SAPIN, "texture_pack/medium_obj/spruce1-1.png"},
    {SAPIN_DROITE, "texture_pack/medium_obj/spruce1-1.png"},
    {SAPIN_GAUCHE, "texture_pack/medium_obj/spruce1-1.png"},
    {SAPIN_DEFOURNI, "texture_pack/medium_obj/spruce1-1.png"},
    {SAPIN_DEFOURNI2, "texture_pack/medium_obj/spruce1-1.png"},
    {SAPIN_DEFOURNI3, "texture_pack/medium_obj/spruce1-1.png"},
    {ARBRE_MORT, "texture_pack/medium_obj/spruce4-0.png"},
    {ARBRE_MORT2, "texture_pack/medium_obj/spruce4-0.png"},
    {ARBRE_MORT3, "texture_pack/medium_obj/spruce4-0.png"},
    {ARBRE_MORT4, "texture_pack/medium_obj/spruce4-0.png"},
    {ARBRE_MORT5, "texture_pack/medium_obj/spruce4-0.png"},
    {ARBRE_MORT6, "texture_pack/medium_obj/spruce4-0.png"},
    {BANAL_TREE, "texture_pack/medium_obj/tree3-0.png"},
    {BANAL_TREE_RIGHT, "texture_pack/medium_obj/tree3-0.png"},
    {BANAL_TREE_LEFT, "texture_pack/medium_obj/tree3-0.png"},
    {BIG_TREE, "texture_pack/medium_obj/tree3-0.png"},
    {BIG_TREE2, "texture_pack/medium_obj/tree3-0.png"},
    {BIG_TREE3, "texture_pack/medium_obj/tree3-0.png"},
    {MOCHE_TREE, "texture_pack/medium_obj/tree3-0.png"},
    {MOCHE_TREE2, "texture_pack/medium_obj/tree3-0.png"},
    {MOCHE_TREE3, "texture_pack/medium_obj/tree3-0.png"},
    {TRONC_COTE, "texture_pack/medium_obj/none.png"},
    {TRONC_FACE, "texture_pack/medium_obj/none.png"},
    {TRONC_OBLIQUE, "texture_pack/medium_obj/none.png"},
    {TRONC_PETIT_COTE, "texture_pack/medium_obj/none.png"},
    {TRONC_PETIT_FACE, "texture_pack/medium_obj/none.png"},
    {TRONC_PETIT_OBLIQUE, "texture_pack/medium_obj/none.png"},
    {TRONC, "texture_pack/medium_obj/none.png"},
    {TRONC_RACINES, "texture_pack/medium_obj/none.png"}
};

sfTexture *tab_txt_nature[NATURE];

#endif
