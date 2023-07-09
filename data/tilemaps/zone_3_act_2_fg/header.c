#include "global.h"
#include "core.h"

const u16 Palette_zone_3_act_2_fg[]
    = INCBIN_U16("data/tilemaps/zone_3_act_2_fg/palette.gbapal");
const u8 Tileset_zone_3_act_2_fg[]
    = INCBIN_U8("data/tilemaps/zone_3_act_2_fg/tileset.4bpp");
const u8 Tileset_AnimTiles_zone_3_act_2_fg[]
    = INCBIN_U8("data/tilemaps/zone_3_act_2_fg/tileset_anim.4bpp");
const u8 CollHeightMap_zone_3_act_2_fg[]
    = INCBIN_U8("data/tilemaps/zone_3_act_2_fg/height_map.coll");
const u8 CollTileRot_zone_3_act_2_fg[]
    = INCBIN_U8("data/tilemaps/zone_3_act_2_fg/tile_rot.coll");
const u8 CollFlags_zone_3_act_2_fg[]
    = INCBIN_U8("data/tilemaps/zone_3_act_2_fg/flags.coll");
const u16 Metatiles_zone_3_act_2_fg[]
    = INCBIN_U16("data/tilemaps/zone_3_act_2_fg/metatiles.tilemap2");

const u16 Map_zone_3_act_2_fg0[]
    = INCBIN_U16("data/tilemaps/zone_3_act_2_fg/map_front.bin");

const u16 Map_zone_3_act_2_fg1[]
    = INCBIN_U16("data/tilemaps/zone_3_act_2_fg/map_back.bin");

ALIGNED(4) const struct MapHeader MapHeader_zone_3_act_2_fg0 = 
{
    .h = {
        .xTiles = 12,
        .yTiles = 12,
        .animTileSize = 256,
        .animFrameCount = 8,
        .animDelay = 5,
        .tiles = Tileset_zone_3_act_2_fg,
        .tilesSize = sizeof(Tileset_zone_3_act_2_fg),
        .palette = Palette_zone_3_act_2_fg,
        .palOffset = 0,
        .palLength = sizeof(Palette_zone_3_act_2_fg) / sizeof(u16),
        .map = Metatiles_zone_3_act_2_fg,
    },
    .metatileMap = Map_zone_3_act_2_fg0,
    .mapWidth = 278,
    .mapHeight = 42,
};

ALIGNED(4) const struct MapHeader MapHeader_zone_3_act_2_fg1 = 
{
    .h = {
        .xTiles = 12,
        .yTiles = 12,
        .animTileSize = 256,
        .animFrameCount = 8,
        .animDelay = 5,
        .tiles = Tileset_zone_3_act_2_fg,
        .tilesSize = sizeof(Tileset_zone_3_act_2_fg),
        .palette = Palette_zone_3_act_2_fg,
        .palOffset = 0,
        .palLength = sizeof(Palette_zone_3_act_2_fg) / sizeof(u16),
        .map = Metatiles_zone_3_act_2_fg,
    },
    .metatileMap = Map_zone_3_act_2_fg1,
    .mapWidth = 278,
    .mapHeight = 42,
};

const Collision CollHeader_zone_3_act_2_fg = { CollHeightMap_zone_3_act_2_fg,
                                               CollTileRot_zone_3_act_2_fg,
                                               Metatiles_zone_3_act_2_fg,
                                               Map_zone_3_act_2_fg0,
                                               Map_zone_3_act_2_fg1,
                                               CollFlags_zone_3_act_2_fg,
                                               278,
                                               42,
                                               0x40,
                                               0x68,
                                               0x00,
                                               0x00,
                                               0x0FC0,
                                               0x0000 };