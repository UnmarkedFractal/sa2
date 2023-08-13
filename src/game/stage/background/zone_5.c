#include "global.h"
#include "core.h"
#include "flags.h"
#include "game/game.h"

#include "constants/tilemaps.h"

extern const Background gUnknown_080D5864[4];

void StageInit_Zone5(void)
{
    Background *background = &gUnknown_03005850.unk0;
    if (IS_SINGLE_PLAYER) {
        gDispCnt |= 0x100;
        gBgCntRegs[0] = 0x1b0c;
        *background = gUnknown_080D5864[3];
        background->tilemapId = TM_SKY_CANYON_CLOUDS_FOREGROUND;
        background->graphics.dest = (void *)BG_SCREEN_ADDR(24);
        background->tilesVram = (void *)BG_SCREEN_ADDR(27);
        background->unk26 = 0x20;
        background->unk28 = 0x20;
        sub_8002A3C(background);
    }
    gBgScrollRegs[0][0] = 0;
    gBgScrollRegs[0][1] = 0;
    gBgScrollRegs[3][0] = 0;
    gBgScrollRegs[3][1] = 0;
}

#define BG_CLOUD_START_Y 96

void StageBgUpdateZone5Acts12(s32 UNUSED a, s32 UNUSED b)
{
    s32 num;
    u16 *cursor, i, val;
    gBgScrollRegs[0][0]++;
    gBgScrollRegs[3][0] = 0;
    num = gUnknown_03005590 * 2;
    if (IS_SINGLE_PLAYER) {
        gFlags = gFlags | 4;
        gUnknown_03002878 = (void *)REG_ADDR_BG3HOFS;
        gUnknown_03002A80 = 2;
        cursor = gUnknown_03001884;
        if (gCurrentLevel != 18) {
            gDispCnt |= 0x100;
            gDispCnt |= 0x2000;
            gWinRegs[5] = 0x3f;
            gWinRegs[4] = 0x3f3f;
            gWinRegs[0] = 0xf0;
            gWinRegs[2] = 0xa0;
            gWinRegs[1] = 0xf0;
            gWinRegs[3] = 0xa0;
            gBldRegs.bldY = 7;
            gBldRegs.bldCnt = 0x3f41;
            gBldRegs.bldAlpha = 0x1010;
        }

        // Move the parallax clouds

        for (i = 0; i < BG_CLOUD_START_Y; i++) {
            *cursor++ = 0;
        }

        val = Div(num, 8);
        for (; i < BG_CLOUD_START_Y + 4; i++) {
            *cursor++ = val;
        }

        val = Div(num, 7);
        for (; i < BG_CLOUD_START_Y + 8; i++) {
            *cursor++ = val;
        }

        val = Div(num, 6);
        for (; i < BG_CLOUD_START_Y + 16; i++) {
            *cursor++ = val;
        }

        val = Div(num, 5);
        for (; i < BG_CLOUD_START_Y + 24; i++) {
            *cursor++ = val;
        }

        val = Div(num, 4);
        for (; i < BG_CLOUD_START_Y + 32; i++) {
            *cursor++ = val;
        }

        val = Div(num, 3);
        for (; i < BG_CLOUD_START_Y + 48; i++) {
            *cursor++ = val;
        }

        val = Div(num, 2);
        for (; i < BG_CLOUD_START_Y + 63; i++) {
            *cursor++ = val;
        }
    }
}