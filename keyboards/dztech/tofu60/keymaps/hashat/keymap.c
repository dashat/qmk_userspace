/* Copyright 2022 DZTECH <moyi4681@Live.cn>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

#define HOME_A LGUI_T(SE_A)
#define HOME_R LALT_T(SE_R)
#define HOME_S LCTL_T(SE_S)
#define HOME_T LSFT_T(SE_T)
#define HOME_N RSFT_T(SE_N)
#define HOME_E RCTL_T(SE_E)
#define HOME_I LALT_T(SE_I)
#define HOME_O RGUI_T(SE_O)


// turning swedish symbols to ANSI-versions
const key_override_t shift_2_override = ko_make_basic(MOD_MASK_SHIFT, SE_2, SE_AT);				//shift+2 > @
const key_override_t shift_4_override = ko_make_basic(MOD_MASK_SHIFT, SE_4, SE_DLR);			//shift+4 > $
const key_override_t shift_6_override = ko_make_basic(MOD_MASK_SHIFT, SE_6, SE_CIRC);			//shift+6 > ^ (dead)
const key_override_t altgr_6_override = ko_make_basic(MOD_BIT(KC_ALGR), SE_6, SE_CIRC);			//ralt+6 > ^ (dead)
const key_override_t shift_7_override = ko_make_basic(MOD_MASK_SHIFT, SE_7, SE_AMPR);			//shift+7 > &
const key_override_t shift_8_override = ko_make_basic(MOD_MASK_SHIFT, SE_8, SE_ASTR);			//shift+8 > *
const key_override_t shift_9_override = ko_make_basic(MOD_MASK_SHIFT, SE_9, SE_LPRN);			//shift+9 > (
const key_override_t shift_0_override = ko_make_basic(MOD_MASK_SHIFT, SE_0, SE_RPRN);			//shift+0 > )
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
const key_override_t altgr_i_override = ko_make_basic(MOD_BIT(KC_ALGR), SE_I, SE_PIPE);			//ralt+i > |
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
	&altgr_i_override,
	&altgr_eql_override,
	&altgr_quot_override, 
	&altgr_scln_override, 
	&altgr_mins_override, 
	&altgr_1_override, 
	&altgr_7_override, 
	&altgr_8_override
};

    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ 0 │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 10│ 11│ 12│ 14│ 13│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
     * │ 15  │ 16│ 17│ 18│ 19│ 20│ 21│ 22│ 23│ 24│ 25│ 26│ 27│     │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐ 41 │
     * │   28 │ 29│ 30│ 31│ 32│ 33│ 34│ 35│ 36│ 37│ 38│ 39│ 40│    │
     * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┤
     * │ 42 │ 43│ 44│ 45│ 46│ 47│ 48│ 49│ 50│ 51│ 52│ 53│  54  │ 55│
     * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬┴───┤
     * │ 56 │ 57 │ 58 │            59          │ 60 │ 61 │ 62 │ 63 │
     * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
     */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_60_iso_split_bs_rshift(
        KC_ESC,  SE_1,    SE_2,    SE_3,    SE_4,    SE_5,    SE_6,    SE_EQL,  SE_7,    SE_8,    SE_9,    SE_0,    SE_LBRC, KC_DEL, SE_RBRC, 
        KC_TAB,  SE_Q,    SE_W,    SE_F,    SE_P,    SE_B,    SE_QUOT, SE_J,    SE_L,    SE_U,    SE_Y,    SE_K,    SE_ARNG, 
        KC_BSPC, HOME_A,  HOME_R,  HOME_S,  HOME_T,  SE_G,    SE_SCLN, SE_ODIA, HOME_N,  HOME_E,  HOME_I,  HOME_O,  SE_ADIA, KC_ENT,
        KC_LSFT, SE_Z,    SE_X,    SE_C,    SE_D,    SE_V,    SE_MINS, SE_SLSH, SE_H,    SE_M,    SE_COMM, SE_DOT,  KC_RSFT, MO(2),
        KC_LGUI, KC_LALT,    KC_LCTL,                            KC_SPC,                          KC_RALT,  MO(3),    MO(1), KC_RCTL
    ),    
	[1] = LAYOUT_60_iso_split_bs_rshift(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_GRV, 
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(2),
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(3),  _______, KC_RCTL
    ),
	[2] = LAYOUT_60_iso_split_bs_rshift(
        KC_NUM , KC_PPLS, KC_PMNS, KC_PAST, KC_PSLS, _______, _______, QK_BOOT,   _______, _______, _______, _______, _______, _______, _______, 
		_______, KC_P7,   KC_P8,   KC_P9,   _______, _______, _______, _______, _______, KC_PGUP, KC_HOME, KC_UP,   KC_END, 
        _______,  KC_P4,   KC_P5,   KC_P6,   KC_PDOT, _______, _______, _______, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT,
        _______, KC_P0,   KC_P1,   KC_P2,   KC_P3,   _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                              KC_PENT,                         _______,  _______, TG(1), _______
    ),
    [3] = LAYOUT_60_iso_split_bs_rshift(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_PSCR, KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_BSPC, KC_F12,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        KC_CAPS, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_MPLY, KC_MPRV, KC_MNXT, _______, _______, _______, _______, _______, _______, _______, _______, _______, TG(2),
        _______, _______, _______,                             _______,                         _______,  _______,  TG(1), _______
    )

};
