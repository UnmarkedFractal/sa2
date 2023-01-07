.include "constants/constants.inc"

.syntax unified
.text
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	movs r0, #5
	str r0, [sp, #0x28]
	ldr r0, _08003A04 @ =REG_DISPSTAT
	ldrh r1, [r0]
	movs r0, #1       @ DISPSTAT_VBLANK
	ands r0, r1
	cmp r0, #0
	bne _08003A08
	movs r0, #0
	b sub_80039E4_return
	.align 2, 0
_08003A04: .4byte REG_DISPSTAT
_08003A08:
	ldr r0, _08003BA4 @ =gUnknown_03005390
	ldrb r1, [r0]
	cmp r1, #0
	bne _08003A12
	b sub_80039E4_return_1
_08003A12:
	movs r5, #0
	cmp r5, r1
	blo _08003A1A
	b _08003EC2
_08003A1A:
	lsls r0, r5, #2
	ldr r1, _08003BA8 @ =gUnknown_03004D10
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [sp, #0xc]
	ldr r1, [r0, #0xc]
	movs r0, #1
	rsbs r0, r0, #0
	adds r2, r5, #1
	str r2, [sp, #0x3c]
	cmp r1, r0
	bne _08003A34
	b _08003EB2
_08003A34:
	mov sl, r1
	ldr r3, [sp, #0xc]
	ldr r0, [r3, #0x10]
	movs r1, #0xc0
	lsls r1, r1, #9
	ands r0, r1
	lsrs r3, r0, #0xf
	lsls r0, r3, #1
	ldr r4, _08003BAC @ =gBgCntRegs
	adds r0, r0, r4
	ldrh r2, [r0]
	movs r0, #0xc
	ands r0, r2
	lsls r0, r0, #0xc
	movs r1, #0xc0
	lsls r1, r1, #0x13
	adds r0, r0, r1
	str r0, [sp, #0x14]
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r0, r2
	lsls r0, r0, #3
	adds r0, r0, r1
	str r0, [sp, #0x18]
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _08003A70
	movs r6, #6
	str r6, [sp, #0x28]
_08003A70:
	cmp r3, #1
	bhi _08003A76
	b _08003C2C
_08003A76:
	ldr r7, _08003BB0 @ =gDispCnt
	ldrh r1, [r7]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _08003A84
	b _08003C2C
_08003A84:
	lsrs r1, r2, #0xe
	movs r0, #0x80
	lsls r0, r0, #0xd
	lsls r0, r1
	lsrs r0, r0, #0x10
	str r0, [sp, #0x10]
	ldr r0, _08003BB4 @ =gUnknown_03002794
	ldr r1, [r0]
	ldr r2, [sp, #0xc]
	ldrh r0, [r2, #0xa]
	ldr r1, [r1, #8]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [sp, #0x1c]
	mov r3, sl
	ldrb r1, [r3, #1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r4, [sp, #0x1c]
	adds r4, r4, r0
	str r4, [sp, #0x1c]
	movs r5, #0
	str r5, [sp, #8]
	ldrh r6, [r3, #2]
	cmp r5, r6
	blo _08003ABE
	b _08003EB2
_08003ABE:
	mov sb, sp
	ldr r7, [sp, #0x10]
	lsls r0, r7, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x30]
_08003AC8:
	ldr r0, [sp, #0x1c]
	ldr r1, _08003BB8 @ =0x040000D4
	str r0, [r1]
	mov r2, sp
	str r2, [r1, #4]
	ldr r0, _08003BBC @ =0x80000003
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r3, [sp, #0x1c]
	adds r3, #6
	str r3, [sp, #0x1c]
	mov r4, sb
	ldrh r3, [r4]
	movs r1, #0xc0
	lsls r1, r1, #8
	ands r1, r3
	lsrs r1, r1, #0xc
	ldrh r2, [r4, #2]
	movs r0, #0xc0
	lsls r0, r0, #8
	ands r0, r2
	lsrs r0, r0, #0xe
	orrs r1, r0
	lsls r1, r1, #1
	ldr r5, _08003BC0 @ =gUnknown_080984DC
	adds r0, r1, r5
	ldrb r0, [r0]
	lsrs r0, r0, #3
	str r0, [sp, #0x20]
	ldr r6, _08003BC4 @ =gUnknown_080984DD
	adds r1, r1, r6
	ldrb r0, [r1]
	lsrs r0, r0, #3
	mov ip, r0
	mov r4, ip
	ldr r7, [sp, #0xc]
	movs r0, #0x18
	ldrsh r1, [r7, r0]
	mov r2, sl
	movs r5, #0xa
	ldrsh r0, [r2, r5]
	subs r5, r1, r0
	movs r6, #0x16
	ldrsh r1, [r7, r6]
	movs r7, #8
	ldrsh r0, [r2, r7]
	subs r1, r1, r0
	mov r8, r1
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r1, r0
	mov r8, r1
	movs r0, #0xff
	ands r0, r3
	adds r0, r5, r0
	asrs r0, r0, #3
	ldr r2, [sp, #0x10]
	muls r0, r2, r0
	ldr r3, [sp, #0x18]
	adds r7, r3, r0
	ldr r5, [sp, #0xc]
	ldr r1, [r5, #4]
	ldr r6, [sp, #0x14]
	subs r1, r1, r6
	ldr r0, [sp, #0x28]
	lsrs r1, r0
	mov r3, sb
	ldrh r2, [r3, #4]
	ldr r0, _08003BC8 @ =0x000003FF
	ands r0, r2
	adds r5, r1, r0
	movs r6, #0xff
	ands r5, r6
	subs r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov ip, r0
	ldr r0, [sp, #8]
	adds r0, #1
	str r0, [sp, #0x40]
	cmp r4, #0
	beq _08003C18
	ldr r1, [sp, #0x30]
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	str r0, [sp, #0x34]
_08003B74:
	mov r2, sb
	ldrh r0, [r2, #2]
	ldr r1, _08003BCC @ =0x000001FF
	ands r1, r0
	add r1, r8
	asrs r1, r1, #3
	adds r2, r7, r1
	ldr r0, [sp, #0x20]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	mov r6, ip
	subs r6, #1
	ldr r4, [sp, #0x20]
	cmp r4, #0
	beq _08003BF2
	movs r4, #1
_08003B96:
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	bne _08003BD0
	str r5, [sp, #0x24]
	b _08003BDE
	.align 2, 0
_08003BA4: .4byte gUnknown_03005390
_08003BA8: .4byte gUnknown_03004D10
_08003BAC: .4byte gBgCntRegs
_08003BB0: .4byte gDispCnt
_08003BB4: .4byte gUnknown_03002794
_08003BB8: .4byte 0x040000D4
_08003BBC: .4byte 0x80000003
_08003BC0: .4byte gUnknown_080984DC
_08003BC4: .4byte gUnknown_080984DD
_08003BC8: .4byte 0x000003FF
_08003BCC: .4byte 0x000001FF
_08003BD0:
	lsls r0, r5, #8
	ldr r1, [sp, #0x24]
	orrs r1, r0
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x24]
	strh r0, [r2]
_08003BDE:
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r2, #1
	adds r1, r3, #0
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r1, #0
	bne _08003B96
_08003BF2:
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08003C08
	ldrh r1, [r2]
	movs r0, #0xff
	lsls r0, r0, #8
	ands r0, r1
	ldr r1, [sp, #0x24]
	orrs r0, r1
	strh r0, [r2]
_08003C08:
	ldr r2, [sp, #0x34]
	adds r7, r7, r2
	mov r1, ip
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	mov ip, r0
	cmp r1, #0
	bne _08003B74
_08003C18:
	ldr r3, [sp, #0x40]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #8]
	mov r4, sl
	ldrh r4, [r4, #2]
	cmp r0, r4
	bhs _08003C2A
	b _08003AC8
_08003C2A:
	b _08003EB2
_08003C2C:
	movs r6, #0x20
	str r6, [sp, #0x10]
	lsls r0, r3, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	lsrs r1, r0, #0xe
	subs r0, r1, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08003C46
	movs r7, #0x40
	str r7, [sp, #0x10]
_08003C46:
	ldr r0, _08003D14 @ =gUnknown_03002794
	ldr r1, [r0]
	ldr r2, [sp, #0xc]
	ldrh r0, [r2, #0xa]
	ldr r1, [r1, #8]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [sp, #0x1c]
	mov r3, sl
	ldrb r1, [r3, #1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r4, [sp, #0x1c]
	adds r4, r4, r0
	str r4, [sp, #0x1c]
	movs r6, #0
	str r6, [sp, #8]
	adds r5, #1
	str r5, [sp, #0x3c]
	ldrh r7, [r3, #2]
	cmp r6, r7
	blo _08003C78
	b _08003EB2
_08003C78:
	mov sb, sp
_08003C7A:
	ldr r0, [sp, #0x1c]
	ldr r1, _08003D18 @ =0x040000D4
	str r0, [r1]
	mov r2, sp
	str r2, [r1, #4]
	ldr r0, _08003D1C @ =0x80000003
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r3, [sp, #0x1c]
	adds r3, #6
	str r3, [sp, #0x1c]
	mov r4, sb
	ldrh r2, [r4]
	movs r1, #0xc0
	lsls r1, r1, #8
	ands r1, r2
	lsrs r1, r1, #0xc
	ldrh r3, [r4, #2]
	movs r0, #0xc0
	lsls r0, r0, #8
	ands r0, r3
	lsrs r0, r0, #0xe
	orrs r1, r0
	lsls r1, r1, #1
	ldr r5, _08003D20 @ =gUnknown_080984DC
	adds r0, r1, r5
	ldrb r0, [r0]
	lsrs r0, r0, #3
	str r0, [sp, #0x20]
	ldr r6, _08003D24 @ =gUnknown_080984DD
	adds r1, r1, r6
	ldrb r0, [r1]
	lsrs r0, r0, #3
	mov ip, r0
	ldr r4, _08003D28 @ =0x000001FF
	ands r4, r3
	movs r6, #0xff
	ands r6, r2
	ldr r0, [sp, #0xc]
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0xc
	mov r7, sb
	ldrh r7, [r7, #4]
	adds r0, r0, r7
	mov r1, sb
	strh r0, [r1, #4]
	ldr r2, [sp, #0xc]
	ldr r1, [r2, #0x10]
	lsrs r1, r1, #0xb
	mov r5, sl
	ldrb r0, [r5]
	lsrs r0, r0, #1
	eors r0, r1
	movs r7, #1
	ands r0, r7
	cmp r0, #0
	beq _08003D4A
	movs r1, #0x80
	lsls r1, r1, #6
	adds r0, r1, #0
	eors r0, r3
	mov r2, sb
	strh r0, [r2, #2]
	ldrb r1, [r5]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08003D2C
	ldr r3, [sp, #0xc]
	movs r5, #0x18
	ldrsh r0, [r3, r5]
	mov r7, sl
	movs r2, #0xa
	ldrsh r1, [r7, r2]
	b _08003D3C
	.align 2, 0
_08003D14: .4byte gUnknown_03002794
_08003D18: .4byte 0x040000D4
_08003D1C: .4byte 0x80000003
_08003D20: .4byte gUnknown_080984DC
_08003D24: .4byte gUnknown_080984DD
_08003D28: .4byte 0x000001FF
_08003D2C:
	ldr r3, [sp, #0xc]
	movs r5, #0x18
	ldrsh r0, [r3, r5]
	mov r7, sl
	ldrh r1, [r7, #6]
	movs r3, #0xa
	ldrsh r2, [r7, r3]
	subs r1, r1, r2
_08003D3C:
	adds r0, r0, r1
	adds r5, r0, #0
	subs r5, #8
	lsls r0, r6, #0x10
	rsbs r0, r0, #0
	lsrs r6, r0, #0x10
	b _08003D58
_08003D4A:
	ldr r5, [sp, #0xc]
	movs r7, #0x18
	ldrsh r1, [r5, r7]
	mov r2, sl
	movs r3, #0xa
	ldrsh r0, [r2, r3]
	subs r5, r1, r0
_08003D58:
	ldr r7, [sp, #0xc]
	ldr r0, [r7, #0x10]
	lsrs r0, r0, #0xa
	movs r3, #1
	ands r0, r3
	mov r1, sl
	ldrb r2, [r1]
	adds r1, r3, #0
	ands r1, r2
	cmp r0, r1
	beq _08003DB4
	mov r2, sb
	ldrh r0, [r2, #2]
	movs r7, #0x80
	lsls r7, r7, #5
	adds r1, r7, #0
	eors r0, r1
	strh r0, [r2, #2]
	mov r0, sl
	ldrb r1, [r0]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08003D96
	ldr r1, [sp, #0xc]
	movs r2, #0x16
	ldrsh r0, [r1, r2]
	mov r3, sl
	movs r7, #8
	ldrsh r1, [r3, r7]
	b _08003DA6
_08003D96:
	ldr r1, [sp, #0xc]
	movs r2, #0x16
	ldrsh r0, [r1, r2]
	mov r3, sl
	ldrh r1, [r3, #4]
	movs r7, #8
	ldrsh r2, [r3, r7]
	subs r1, r1, r2
_08003DA6:
	adds r0, r0, r1
	subs r0, #8
	mov r8, r0
	lsls r0, r4, #0x10
	rsbs r0, r0, #0
	lsrs r4, r0, #0x10
	b _08003DC4
_08003DB4:
	ldr r0, [sp, #0xc]
	movs r2, #0x16
	ldrsh r1, [r0, r2]
	mov r3, sl
	movs r7, #8
	ldrsh r0, [r3, r7]
	subs r1, r1, r0
	mov r8, r1
_08003DC4:
	movs r0, #0x10
	rsbs r0, r0, #0
	mov r1, r8
	ands r1, r0
	mov r8, r1
	adds r0, #8
	ands r5, r0
	mov r2, sb
	ldrh r1, [r2, #2]
	movs r0, #0x80
	lsls r0, r0, #5
	ands r0, r1
	movs r3, #2
	str r3, [sp, #0x2c]
	cmp r0, #0
	beq _08003DE8
	movs r7, #0xfe
	str r7, [sp, #0x2c]
_08003DE8:
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	beq _08003DFA
	ldr r1, [sp, #0x10]
	lsls r0, r1, #0x19
	rsbs r0, r0, #0
	b _08003DFE
_08003DFA:
	ldr r2, [sp, #0x10]
	lsls r0, r2, #0x19
_08003DFE:
	lsrs r0, r0, #0x18
	str r0, [sp, #0x30]
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	adds r0, r5, r0
	asrs r0, r0, #2
	ldr r3, [sp, #0x10]
	muls r0, r3, r0
	ldr r5, [sp, #0x18]
	adds r7, r5, r0
	ldr r6, [sp, #0xc]
	ldr r1, [r6, #4]
	ldr r0, [sp, #0x14]
	subs r1, r1, r0
	ldr r2, [sp, #0x28]
	lsrs r1, r2
	mov r3, sb
	ldrh r2, [r3, #4]
	ldr r0, _08003EDC @ =0x0000F3FF
	ands r0, r2
	adds r1, r1, r0
	ldrh r2, [r3, #2]
	movs r0, #0xc0
	lsls r0, r0, #6
	ands r0, r2
	lsrs r0, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	mov r1, ip
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov ip, r0
	ldr r6, [sp, #8]
	adds r6, #1
	str r6, [sp, #0x40]
	cmp r1, #0
	beq _08003EA0
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	add r0, r8
	asrs r0, r0, #2
	str r0, [sp, #0x38]
	ldr r1, [sp, #0x30]
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	mov r8, r0
_08003E5E:
	ldr r3, [sp, #0x38]
	adds r2, r7, r3
	ldr r0, [sp, #0x20]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	mov r6, ip
	subs r6, #1
	ldr r4, [sp, #0x20]
	cmp r4, #0
	beq _08003E92
	ldr r1, [sp, #0x2c]
	lsls r0, r1, #0x18
	asrs r4, r0, #0x18
_08003E7A:
	adds r1, r5, #0
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	strh r1, [r2]
	adds r2, r2, r4
	adds r1, r3, #0
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r1, #0
	bne _08003E7A
_08003E92:
	add r7, r8
	mov r1, ip
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	mov ip, r0
	cmp r1, #0
	bne _08003E5E
_08003EA0:
	ldr r2, [sp, #0x40]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #8]
	mov r3, sl
	ldrh r3, [r3, #2]
	cmp r0, r3
	bhs _08003EB2
	b _08003C7A
_08003EB2:
	ldr r4, [sp, #0x3c]
	lsls r0, r4, #0x18
	lsrs r5, r0, #0x18
	ldr r6, _08003EE0 @ =gUnknown_03005390
	ldrb r6, [r6]
	cmp r5, r6
	bhs _08003EC2
	b _08003A1A
_08003EC2:
	movs r0, #0
	ldr r7, _08003EE0 @ =gUnknown_03005390
	strb r0, [r7]
sub_80039E4_return_1:
	movs r0, #1
sub_80039E4_return:
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08003EDC: .4byte 0x0000F3FF
_08003EE0: .4byte gUnknown_03005390

.syntax divided