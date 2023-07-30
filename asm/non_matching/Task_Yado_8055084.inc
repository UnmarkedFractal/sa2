.include "constants/constants.inc"

.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	ldr r0, _080550F0 @ =gCurTask
	mov sl, r0
	ldr r0, [r0]
	ldrh r0, [r0, #6]
	mov r8, r0      @ r8 = gCurTask->data
	movs r1, #0xc0
	lsls r1, r1, #0x12
	add r1, r8
	mov sb, r1      @ sb = yado
	ldr r5, _080550F4 @ =IWRAM_START + 0xC
	add r5, r8      @ r5 = s
	ldr r2, [r1]
	str r2, [sp, #0x1c] @ sp1C = me
	ldr r0, [r1, #0x44]
	asrs r7, r0, #8     @ r7 = yado->spawnX
	str r7, [sp, #0x20] @ sp20 = yado->spawnX
	ldr r0, [r1, #0x48]
	asrs r6, r0, #8     @ r6 = yado->spawnY
	str r6, [sp, #0x24] @ sp20 = yado->spawnY
	ldr r1, _080550F8 @ =gCamera
	ldr r0, [r1]
	adds r2, r7, #0
	subs r0, r2, r0
	strh r0, [r5, #0x16]
	ldr r0, [r1, #4]
	ldr r1, [sp, #0x24]
	subs r0, r1, r0
	strh r0, [r5, #0x18]
	ldr r4, _080550FC @ =gPlayer
	ldr r0, [r4, #0x20]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0805511C
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r6, #0
	movs r3, #1
	bl sub_800C4FC
	cmp r0, #1
	bne _08055100
	mov r2, sl
	ldr r0, [r2]
	bl TaskDestroy
	b Task_8055084_Return
	.align 2, 0
_080550F0: .4byte gCurTask
_080550F4: .4byte IWRAM_START + 0xC
_080550F8: .4byte gCamera
_080550FC: .4byte gPlayer
_08055100:
	str r4, [sp]
	movs r0, #0
	str r0, [sp, #4]
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r6, #0
	movs r3, #0
	bl sub_800C204
	adds r2, r0, #0
	cmp r2, #1
	beq _0805511A
	b _0805525C
_0805511A:
	b _08055134
_0805511C:
	str r4, [sp]
	movs r1, #0
	str r1, [sp, #4]
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r6, #0
	movs r3, #0
	bl sub_800C204
	adds r2, r0, #0
	cmp r2, #1
	bne _08055156
_08055134:
	movs r0, #0xf7
	lsls r0, r0, #8
	strh r0, [r4, #0x12]
	adds r1, r4, #0
	adds r1, #0x64
	movs r0, #0x32
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x6c
	strb r2, [r0]
	adds r1, #9
	movs r0, #5
	strb r0, [r1]
	movs r0, #0x99
	bl m4aSongNumStart
	b _0805525C
_08055156:
	adds r4, r7, #0
	str r6, [sp, #0x28] @ sp28 = yado->spawnY
	ldr r0, _0805524C @ =gUnknown_030056A4
	ldr r0, [r0]
	cmp r0, #0
	bne _08055164
	b _0805525C
_08055164:
	mov ip, r0          @ ip = gUnknown_030056A4
	mov r2, sl
	ldr r0, [r2]        @ r0 = gCurTask
	ldrh r0, [r0, #6]
	movs r1, #0xc0
	lsls r1, r1, #0x12
	adds r7, r0, r1     @ r7 = yado2
	mov r2, ip
	ldr r1, [r2, #0x4c]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0805525C
	ldr r0, _08055250 @ =IWRAM_START + 0x38
	add r0, r8
	movs r3, #0
	ldrsb r3, [r0, r3]
	adds r2, r4, r3
	mov r1, ip
	ldr r0, [r1]
	asrs r0, r0, #8
	adds r1, #0x50
	movs r6, #0
	ldrsb r6, [r1, r6]  @ r6 = gUnknown_030056A4->unk50
	adds r1, r0, r6
	cmp r2, r1
	bgt _080551B0
	ldr r0, _08055254 @ =IWRAM_START + 0x3A
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, r0, r3
	adds r0, r2, r0     @ r0 = w
	cmp r0, r1
	bge _080551C2
	cmp r2, r1
	blt _0805525C
_080551B0:
	mov r0, ip      @ r0 = ip = gUnknown_030056A4
	adds r0, #0x52
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, r0, r6
	adds r0, r1, r0
	cmp r0, r2
	blt _0805525C
_080551C2:
	adds r0, r5, #0
	adds r0, #0x2d
	movs r6, #0
	ldrsb r6, [r0, r6]
	ldr r2, [sp, #0x28] @r2 = yado->spawnY
	adds r3, r2, r6
	mov r1, ip      @ r1 = ip = gUnknown_030056A4
	ldr r0, [r1, #4]
	asrs r0, r0, #8
	adds r1, #0x51
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r2, r0, r1
	cmp r3, r2
	bgt _080551F8
	adds r0, r5, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, r0, r6
	adds r0, r3, r0
	cmp r0, r2
	bge _0805520A
	cmp r3, r2
	blt _0805525C
_080551F8:
	mov r0, ip      @ r0 = ip = gUnknown_030056A4
	adds r0, #0x53
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, r0, r1
	adds r0, r2, r0
	cmp r0, r3
	blt _0805525C
_0805520A:
	ldr r0, _08055258 @ =gGameMode
	ldrb r0, [r0]
	cmp r0, #2
	bls _08055226
	bl sub_8019224
	movs r1, #3
	strb r1, [r0]
	ldrh r1, [r7, #4]
	strb r1, [r0, #1]
	ldrh r1, [r7, #6]
	strb r1, [r0, #2]
	ldrb r1, [r7, #9]
	strb r1, [r0, #3]
_08055226:
	lsls r5, r4, #0x10
	asrs r5, r5, #0x10
	ldr r2, [sp, #0x28]
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	adds r0, r5, #0
	adds r1, r4, #0
	bl CreateDustCloud
	adds r0, r5, #0
	adds r1, r4, #0
	bl CreateTrappedAnimal
	adds r0, r5, #0
	adds r1, r4, #0
	bl CreateEnemyDefeatScoreAndManageLives
	b _08055288
	.align 2, 0
_0805524C: .4byte gUnknown_030056A4
_08055250: .4byte IWRAM_START + 0x38
_08055254: .4byte IWRAM_START + 0x3A
_08055258: .4byte gGameMode
_0805525C:
	ldrh r0, [r5, #0x16]
	adds r0, #0x80
	lsls r0, r0, #0x10
	movs r1, #0xf8
	lsls r1, r1, #0x11
	cmp r0, r1
	bhi _08055280
	movs r1, #0x18
	ldrsh r0, [r5, r1]
	adds r0, #0x80
	cmp r0, #0
	blt _08055280
	movs r2, #0x18
	ldrsh r1, [r5, r2]
	movs r0, #0x90
	lsls r0, r0, #1
	cmp r1, r0
	ble _08055298
_08055280:
	mov r1, sb
	ldrb r0, [r1, #8]
	ldr r2, [sp, #0x1c]
	strb r0, [r2]
_08055288:
	ldr r0, _08055294 @ =gCurTask
	ldr r0, [r0]
	bl TaskDestroy
	b Task_8055084_Return
	.align 2, 0
_08055294: .4byte gCurTask
_08055298:
	mov r1, sb
	ldr r0, [r1, #0x44]
	ldr r1, [r1, #0x48]
	bl sub_80122DC
	mov r2, sb
	adds r2, #0x4c
	ldrb r0, [r2]
	subs r1, r0, #1
	strb r1, [r2]
	movs r3, #0xff
	lsls r0, r1, #0x18
	cmp r0, #0
	bne _080552E4
	movs r0, #0x78
	strb r0, [r2]
	movs r1, #0
	ldr r0, _080552D8 @ =0x000001F1
	strh r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x20
	strb r1, [r0]
	adds r1, r5, #0
	adds r1, #0x21
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	ldr r0, _080552DC @ =gCurTask
	ldr r1, [r0]
	ldr r0, _080552E0 @ =Task_YadoMain
	str r0, [r1, #8]
	b _08055358
	.align 2, 0
_080552D8: .4byte 0x000001F1
_080552DC: .4byte gCurTask
_080552E0: .4byte Task_YadoMain
_080552E4:
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3c
	bne _08055340
	add r1, sp, #8
	movs r2, #0
	movs r0, #4
	strh r0, [r1]
	movs r0, #0xf9
	lsls r0, r0, #1
	strh r0, [r1, #2]
	adds r0, r1, #0
	strb r2, [r0, #4]
	ldr r0, [r5, #0x10]
	movs r1, #0x80
	lsls r1, r1, #3
	ands r0, r1
	cmp r0, #0
	beq _08055318   @ (s->unk10 & SPRITE_FLAG_MASK_X_FLIP)
	ldr r0, [sp, #0x20]
	adds r0, #6
	lsls r0, r0, #8
	str r0, [sp, #0x14]
	add r1, sp, #8
	movs r0, #0
	b _08055326
_08055318:
	ldr r0, [sp, #0x20]
	subs r0, #5
	lsls r0, r0, #8
	str r0, [sp, #0x14]
	add r1, sp, #8
	movs r0, #0x80
	lsls r0, r0, #2
_08055326:
	strh r0, [r1, #6]
	ldr r0, [sp, #0x24]
	subs r0, #6
	lsls r0, r0, #8
	str r0, [sp, #0x18]
	add r1, sp, #8
	movs r0, #0xc0
	lsls r0, r0, #1
	strh r0, [r1, #8]
	adds r0, r1, #0
	bl CreateProjectile
	b _08055358
_08055340:
	cmp r0, #6
	bne _08055358
	ldr r0, _08055374 @ =0x000001F1
	strh r0, [r5, #0xa]
	adds r1, r5, #0
	adds r1, #0x20
	movs r0, #2
	strb r0, [r1]
	adds r1, #1
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
_08055358:
	adds r0, r5, #0
	bl sub_8004558
	adds r0, r5, #0
	bl sub_80051E8
Task_8055084_Return:
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08055374: .4byte 0x000001F1
.syntax divided