#include "global.h"
#include "core.h"

const u16 Palette_zone_1_act_2_bg[]
    = INCBIN_U16("data/tilemaps/zone_1_act_2_bg/palette.gbapal");
const u8 Tiles_zone_1_act_2_bg[] = INCBIN_U8("data/tilemaps/zone_1_act_2_bg/tiles.4bpp");
const u16 Tilemap_zone_1_act_2_bg[]
    = INCBIN_U16("data/tilemaps/zone_1_act_2_bg/tilemap.tilemap2");

const Tilemap zone_1_act_2_bg = {
    .xTiles = 32,
    .yTiles = 30,
    .animTileSize = 0,
    .animFrameCount = 0,
    .animDelay = 0,
    .tiles = Tiles_zone_1_act_2_bg,
    .tilesSize = sizeof(Tiles_zone_1_act_2_bg),
    .palette = Palette_zone_1_act_2_bg,
    .palOffset = 0,
    .palLength = sizeof(Palette_zone_1_act_2_bg) / sizeof(u16),
    .map = Tilemap_zone_1_act_2_bg,
};