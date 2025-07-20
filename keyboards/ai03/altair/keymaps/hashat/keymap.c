/* Copyright 2024 ai03 Design Studio */
/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

#define HOME_A LT(_FH, SE_A)
#define HOME_R LALT_T(SE_R)
#define HOME_S LCTL_T(SE_S)
#define HOME_T LSFT_T(SE_T)
#define HOME_P4 LALT_T(KC_P4)
#define HOME_P5 LCTL_T(KC_P5)
#define HOME_P6 LSFT_T(KC_P6)

#define HOME_N RSFT_T(SE_N)
#define HOME_E RCTL_T(SE_E)
#define HOME_I LALT_T(SE_I)
#define HOME_O LT(_FH, SE_O)
#define ALT_F4 LALT(KC_F4)

enum layer_names {
	_BH,	//modded colemak base with homerow mods
	_BL,	//modded colemak base without hrm
	_QW,	//qwerty (swedish?)
	_FH,	//function layer with homerow mods
	_FL,	//function layer without hrm
	_GL,	//gaming layer
	_GF,	//gaming sublayer
};


// turning swedish symbols to ANSI-versions
const key_override_t shift_2_override = ko_make_basic(MOD_MASK_SHIFT, SE_2, SE_AT);				//shift+2 > @
const key_override_t shift_4_override = ko_make_basic(MOD_MASK_SHIFT, SE_4, SE_DLR);			//shift+4 > $
const key_override_t shift_6_override = ko_make_basic(MOD_MASK_SHIFT, SE_6, SE_CIRC);			//shift+6 > ^ (dead)
const key_override_t altgr_6_override = ko_make_basic(MOD_BIT(KC_ALGR), SE_6, SE_CIRC);			//ralt+6 > ^ (dead)
const key_override_t shift_7_override = ko_make_basic(MOD_MASK_SHIFT, SE_7, SE_AMPR);			//shift+7 > &
const key_override_t shift_8_override = ko_make_basic(MOD_MASK_SHIFT, SE_8, SE_ASTR);			//shift+8 > *
const key_override_t shift_9_override = ko_make_basic(MOD_MASK_SHIFT, SE_9, SE_PIPE);			//shift+9 > |
const key_override_t shift_0_override = ko_make_basic(MOD_MASK_SHIFT, SE_0, SE_BSLS);			//shift+0 > (backslash
const key_override_t shift_quot_override = ko_make_basic(MOD_MASK_SHIFT, SE_QUOT, SE_DQUO);		//shift+' > "
const key_override_t shift_eql_override = ko_make_basic(MOD_MASK_SHIFT, SE_EQL, SE_PLUS);		//shift+= > +
const key_override_t shift_lbrc_override = ko_make_basic(MOD_MASK_SHIFT, SE_LBRC, SE_LCBR);		//shift+[ > {
const key_override_t shift_rbrc_override = ko_make_basic(MOD_MASK_SHIFT, SE_RBRC, SE_RCBR);		//shift+] > }
const key_override_t shift_slsh_override = ko_make_basic(MOD_MASK_SHIFT, SE_SLSH, SE_QUES);		//shift+/ > ?
const key_override_t shift_scln_override = ko_make_basic(MOD_MASK_SHIFT, SE_SCLN, SE_COLN);		//shift+; > :
const key_override_t shift_comm_override = ko_make_basic(MOD_MASK_SHIFT, SE_COMM, SE_LABK);		//shift+, > <
const key_override_t shift_dot_override = ko_make_basic(MOD_MASK_SHIFT, SE_DOT, SE_RABK);		//shift+. > >
// shift+backspace to delete and shift+delete to backspace
const key_override_t shift_bspc_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);		//shift+backspace > DEL
const key_override_t shift_del_override = ko_make_basic(MOD_MASK_SHIFT, KC_DEL, KC_BSPC);		//shift+del > BSPC
// adding missing symbols
const key_override_t altgr_slsh_override = ko_make_basic(MOD_BIT(KC_ALGR), SE_SLSH, SE_BSLS);	//ralt+/ > (backslash)
const key_override_t altgr_z_override = ko_make_basic(MOD_BIT(KC_ALGR), SE_Z, SE_PIPE);			//ralt+z > |
const key_override_t altgr_eql_override = ko_make_basic(MOD_BIT(KC_ALGR), SE_EQL, SE_ACUT);		//ralt+= > ´ (dead)
const key_override_t altgr_quot_override = ko_make_basic(MOD_BIT(KC_ALGR), SE_QUOT, SE_GRV);	//ralt+' > ` (dead)
const key_override_t altgr_scln_override = ko_make_basic(MOD_BIT(KC_ALGR), SE_SCLN, SE_DIAE);	//ralt+; > ¨ (dead)
const key_override_t altgr_mins_override = ko_make_basic(MOD_BIT(KC_ALGR), SE_MINS, SE_TILD);	//ralt+- > ~ (dead)
const key_override_t altgr_1_override = ko_make_basic(MOD_BIT(KC_ALGR), SE_1, SE_HALF);			//ralt+1 > ½
const key_override_t altgr_7_override = ko_make_basic(MOD_BIT(KC_ALGR), SE_7, SE_SECT);			//ralt+7 > §
const key_override_t altgr_8_override = ko_make_basic(MOD_BIT(KC_ALGR), SE_8, SE_CURR);			//ralt+8 > ¤


// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&shift_2_override,
	&shift_4_override,
	&shift_6_override,
	&altgr_6_override,
	&shift_7_override,
	&shift_8_override,
	&shift_9_override,
	&shift_0_override,
	&shift_quot_override,
	&shift_eql_override,
	&shift_lbrc_override,
	&shift_rbrc_override,
	&shift_slsh_override,
	&shift_scln_override,
	&shift_comm_override,
	&shift_dot_override,
	&shift_bspc_override,
	&shift_del_override,
	&altgr_slsh_override,
	&altgr_z_override,
	&altgr_eql_override,
	&altgr_quot_override, 
	&altgr_scln_override, 
	&altgr_mins_override, 
	&altgr_1_override, 
	&altgr_7_override, 
	&altgr_8_override
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	//base with homerow mods
    [_BH] = LAYOUT(
        KC_ESC,  SE_1,    SE_2,    SE_3,    SE_4,    SE_5,    SE_MINS, SE_EQL,  SE_6,    SE_7,    SE_8,    SE_9,    SE_0,    KC_DEL,
        KC_TAB,  SE_Q,    SE_W,    SE_F,    SE_P,    SE_G,    SE_LBRC, SE_RBRC, SE_J,    SE_L,    SE_U,    SE_Y,    SE_ARNG, SE_SCLN,
        KC_BSPC, HOME_A,  HOME_R,  HOME_S,  HOME_T,  SE_ODIA, SE_LPRN, SE_RPRN, SE_ADIA, HOME_N,  HOME_E,  HOME_I,  HOME_O,  SE_QUOT,
        KC_LSFT, SE_Z,    SE_X,    SE_C,    SE_D,    SE_V,    SE_COMM, SE_DOT,  SE_B,    SE_H,    SE_M,    SE_K,    SE_SLSH, KC_ENT,
                                   KC_LALT, KC_LCTL, KC_SPC,  MO(_FH), MO(_FH), KC_SPC,  KC_RGUI, KC_RALT
    ),
	//base without homerow mods
    [_BL] = LAYOUT(
        KC_ESC,  SE_1,    SE_2,    SE_3,    SE_4,    SE_5,    SE_MINS, SE_EQL,  SE_6,    SE_7,    SE_8,    SE_9,    SE_0,    KC_DEL,
        KC_TAB,  SE_Q,    SE_W,    SE_F,    SE_P,    SE_G,    SE_LBRC, SE_RBRC, SE_J,    SE_L,    SE_U,    SE_Y,    SE_ARNG, SE_SCLN,
        KC_BSPC, SE_A,    SE_R,    SE_S,    SE_T,    SE_ODIA, SE_LPRN, SE_RPRN, SE_ADIA, SE_N,    SE_E,    SE_I,    SE_O,    SE_QUOT,
        KC_LSFT, SE_Z,    SE_X,    SE_C,    SE_D,    SE_V,    SE_COMM, SE_DOT,  SE_B,    SE_H,    SE_M,    SE_K,    SE_SLSH, KC_ENT,
                                   KC_LALT, KC_LCTL, KC_SPC,  MO(_FH), MO(_FH), KC_SPC,  KC_RGUI, KC_RALT
    ),
	//normal qwerty - needs fixing for SE maybe?
	[_QW] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NUHS,
        KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LPRN, KC_RPRN, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_GRV,  KC_NUBS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                                   KC_LALT, KC_LCTL, KC_SPC,  MO(_FH), MO(_FH), KC_SPC,  KC_RGUI, KC_RALT
    ),
	//numpad+nav+media+f-row with HRM
    [_FH] = LAYOUT(
        KC_NUM,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   ALT_F4,  QK_BOOT, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, KC_PPLS, KC_P7,   KC_P8,   KC_P9,   KC_PAST, KC_VOLU, KC_MPRV, KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, KC_F12,
        _______, _______, HOME_P4, HOME_P5, HOME_P6, KC_PDOT, KC_VOLD, KC_MNXT, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
        _______, KC_PMNS, KC_P1,   KC_P2,   KC_P3,   KC_PSLS, KC_MUTE, KC_MPLY, _______, _______, _______, _______, _______, _______,
                                   TG(_FL), KC_P0,   KC_PENT, TG(_GL), _______, KC_TAB,  TG(_BL), TG(_FL)
    ), 	
	//numpad+nav+media+f-row no HRM
    [_FL] = LAYOUT(
        KC_NUM,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   ALT_F4,  QK_BOOT, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, KC_PPLS, KC_P7,   KC_P8,   KC_P9,   KC_PAST, KC_VOLU, KC_MPRV, KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, KC_F12,
        _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PDOT, KC_VOLD, KC_MNXT, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
        _______, KC_PMNS, KC_P1,   KC_P2,   KC_P3,   KC_PSLS, KC_MUTE, KC_MPLY, _______, _______, _______, _______, _______, _______,
                                   TG(_FL), KC_P0,   KC_PENT, _______, _______, KC_TAB,  _______, TG(_FL)
    ),	
	//gaming
    [_GL] = LAYOUT(
        KC_ESC,  SE_5,    SE_4,    SE_3,    SE_2,    SE_1,    _______, _______, SE_1,    SE_2,    SE_3,    SE_4,    SE_5,    KC_ESC, 
        KC_TAB,  SE_T,    SE_Q,    SE_W,    SE_E,    SE_R,    _______, _______, SE_R,    SE_Q,    SE_W,    SE_E,    SE_T,    KC_TAB, 
        KC_LSFT, SE_G,    SE_A,    SE_S,    SE_D,    SE_F,	  _______, _______, SE_F,    SE_A,    SE_S,    SE_D,    SE_G,    KC_LSFT, 
        KC_LALT, SE_Z,    SE_X,    SE_C,    SE_V,    SE_B,    _______, _______, SE_B,    SE_V,    SE_C,    SE_X,    SE_Z,    KC_LALT, 
                                   TG(_GL), KC_LCTL, KC_SPC,  MO(_GF), MO(_GF), KC_SPC, KC_LCTL, TG(_GL) 
    ),
	//gaming sublayer
    [_GF] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, _______, 
        _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, 
        KC_ENT,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_ENT, 
                                   _______, _______, _______, _______, _______, _______, _______, _______ 
    ),
};
