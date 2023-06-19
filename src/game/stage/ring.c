#include "global.h"
#include "sprite.h"
#include "task.h"
#include "trig.h"
#include "game/game.h"
#include "game/stage/collect_ring_effect.h"
#include "game/stage/rings_manager.h"

#include "constants/animations.h"
#include "constants/zones.h"

typedef struct {
    Sprite s;
    s16 unk30;
} StageRing;

void Task_StageRing(void);

void sub_800BAAC(s16 x, s16 y)
{
    struct Task *t = TaskCreate(Task_StageRing, sizeof(StageRing), 0x2000, 0, NULL);
    StageRing *ring = TaskGetStructPtr(t);
    Sprite *s;

    ring->unk30 = 0;

    s = &ring->s;
    s->x = x;
    s->y = y;

    s->graphics.dest = RESERVED_RING_TILES_VRAM;
    s->unk1A = 0x3C0;
    s->graphics.size = 0;
    s->graphics.anim = SA2_ANIM_RING_STATIC;
    s->variant = 0;
    s->unk14 = 0;
    s->unk1C = 0;
    s->unk21 = 0xFF;
    s->unk22 = 0x10;
    s->palId = 0;
    s->unk10 = (SPRITE_FLAG_MASK_19 | SPRITE_FLAG_MASK_18 | SPRITE_FLAG(PRIORITY, 2));
}

// https://decomp.me/scratch/EmhmV
NONMATCH("asm/non_matching/Task_StageRing.inc", void Task_StageRing(void))
{
    StageRing *ring = TaskGetStructPtr(gCurTask);
    Player *p = &gPlayer;
    s32 ringToPlayerX = Q_24_8_TO_INT(p->x) - (u16)ring->s.x;
    s32 ringToPlayerY = Q_24_8_TO_INT(p->y) - (u16)ring->s.y;

    s16 sinVal = sub_8004418(ringToPlayerY, ringToPlayerX);
    s16 ringX;
    s16 ringY;

    s32 lvalue, rvalue;

    ring->unk30 += 0x40;

    ring->s.x += (ring->unk30 * COS(sinVal)) >> 22;
    ring->s.y += (ring->unk30 * SIN(sinVal)) >> 22;

    ringY = ring->s.y;
    ringX = ring->s.x;

    lvalue = ring->s.x - 8;
    rvalue = Q_24_8_TO_INT(p->x) + gUnknown_03005AF0.unk38;

    if (((lvalue <= rvalue) && (ring->s.x + 8 < rvalue))
        || ((ringY - 16 > Q_24_8_TO_INT(gPlayer.y) + gUnknown_03005AF0.unk39))
        || ((Q_24_8_TO_INT(p->y) >= gUnknown_03005AF0.unk39)
            || ringY - 16 < gUnknown_03005AF0.unk39)) {

    }

    else if (gUnknown_03005AF0.unk3B - gUnknown_03005AF0.unk39
             >= Q_24_8_TO_INT(gPlayer.y) + ringY) {
        // _0800BC36
        if (PLAYER_IS_ALIVE) {
            u16 oldRings = gRingCount;
            gRingCount++;

            if ((gCurrentLevel != COURSE_INDEX(ZONE_FINAL, ACT_TRUE_AREA_53))
                && (Div(gRingCount, 100) != Div(oldRings, 100))
                && (gGameMode == GAME_MODE_SINGLE_PLAYER)) {
                u32 lives = gNumLives;
                if (lives + 1 > 255)
                    gNumLives = 255;
                else
                    gNumLives = lives + 1;

                gUnknown_030054A8.unk3 = 0x10;
            }

            if (gGameMode == GAME_MODE_MULTI_PLAYER_COLLECT_RINGS) {
                if (gRingCount > 255)
                    gRingCount = 255;
            }

            CreateCollectRingEffect(ringX, ringY);
        }
        TaskDestroy(gCurTask);
        return;
    }

    {
        ring->s.x -= gCamera.x;
        ring->s.y -= gCamera.y;
        sub_8004558(&ring->s);
        sub_80051E8(&ring->s);
        ring->s.x = ringX;
        ring->s.y = ringY;
    }
}
END_NONMATCH