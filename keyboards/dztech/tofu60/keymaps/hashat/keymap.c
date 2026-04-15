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
#include "sendstring_swedish.h"

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
	_SC,	//for use with KTA scanning software
	_FH,	//function layer with homerow mods
	_FL,	//function layer without hrm
};

// custom keycodes for use with KTA
enum custom_keycodes {
	KTA_CTN = SAFE_RANGE,	//complete and take next activity
	KTA_DTY,				//go to document typede
	KTA_FLD,				//go to fields
	KTA_NP,					//next page
	KTA_PP,					//previous page 	
};

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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case KTA_CTN:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LCTL) SS_DELAY(50) "y");
        } else {
        }
        break;
    case KTA_DTY:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LCTL) SS_DELAY(50) "7");
        } else {
			layer_clear();
		}
        break;
    case KTA_FLD:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LCTL) SS_DELAY(50) "6");
        } else {
        }
        break;
    case KTA_NP:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LCTL) SS_DELAY(50) "b");
        } else {
        }
        break;
    case KTA_PP:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LCTL) SS_DELAY(50) SS_LSFT("b"));
        } else {
        }
        break;
    }
    return true;
};

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
		case SE_ARNG:
		case SE_ADIA:
		case SE_ODIA:
        case SE_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

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
    //base with homerow mods
	[_BH] = LAYOUT_60_iso_split_bs_rshift(
        KC_ESC,  SE_1,    SE_2,    SE_3,    SE_4,    SE_5,    SE_MINS, SE_RBRC, SE_EQL,  SE_6,    SE_7,    SE_8,    SE_9, KC_DEL, SE_0,
        KC_TAB,  SE_Q,    SE_W,    SE_F,    SE_P,    SE_G,    SE_LBRC, SE_SLSH, SE_J,    SE_L,    SE_U,    SE_Y,    SE_ARNG,  
        KC_BSPC, HOME_A,  HOME_R,  HOME_S,  HOME_T,  SE_ODIA, SE_SCLN, SE_QUOT, SE_ADIA, HOME_N,  HOME_E,  HOME_I,  HOME_O,  KC_ENT,
        KC_LSFT, SE_Z,    SE_X,    SE_C,    SE_D,    SE_V,    SE_COMM, SE_DOT,  SE_B,    SE_H,    SE_M,    SE_K,    KC_RSFT, MO(_FH),
        KC_LGUI, KC_LALT,    KC_LCTL,                            KC_SPC,                          KC_RALT, TG(_SC), KC_RGUI, KC_RCTL
    ), 
	//base without homerow mods
    [_BL] = LAYOUT_60_iso_split_bs_rshift(
        KC_ESC,  SE_1,    SE_2,    SE_3,    SE_4,    SE_5,    SE_MINS, SE_RBRC, SE_EQL,  SE_6,    SE_7,    SE_8,    SE_9, KC_DEL, SE_0,
        KC_TAB,  SE_Q,    SE_W,    SE_F,    SE_P,    SE_G,    SE_LBRC, SE_SLSH, SE_J,    SE_L,    SE_U,    SE_Y,    SE_ARNG,  
        KC_BSPC, SE_A,    SE_R,    SE_S,    SE_T,    SE_ODIA, SE_SCLN, SE_QUOT, SE_ADIA, SE_N,    SE_E,    SE_I,    SE_O,  KC_ENT,
        KC_LSFT, SE_Z,    SE_X,    SE_C,    SE_D,    SE_V,    SE_COMM, SE_DOT,  SE_B,    SE_H,    SE_M,    SE_K,    KC_RSFT, MO(_FH),
        KC_LGUI, KC_LALT,    KC_LCTL,                            KC_SPC,                          KC_RALT, TG(_SC), KC_RGUI, KC_RCTL
    ),
	//numpad and navigation with HRM
	[_FH] = LAYOUT_60_iso_split_bs_rshift(
        KC_NUM , KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   ALT_F4,  KC_F11,  QK_BOOT, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F12,  KC_F10,
		_______, KC_PPLS, KC_P7,   KC_P8,   KC_P9,   KC_PAST, _______, _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______,
        _______, TO(_SC), HOME_P4, HOME_P5, HOME_P6, KC_PDOT, KC_MPRV, KC_MNXT, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_ENT,
        _______, KC_PMNS, KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PSLS, KC_MPLY, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, QK_LLCK,
        _______, _______, _______,                              KC_PENT,                         _______,  QK_LLCK, TG(_SC), _______
    ),
	//numpad and navigation no HRM
	[_FL] = LAYOUT_60_iso_split_bs_rshift(
        KC_NUM , KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   ALT_F4,  KC_F11,  QK_BOOT, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F12,  KC_F10,
		_______, KC_PPLS, KC_P7,   KC_P8,   KC_P9,   KC_PAST, _______, _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______,
        _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PDOT, KC_MPRV, KC_MNXT, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_ENT,
        _______, KC_PMNS, KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PSLS, KC_MPLY, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, QK_LLCK,
        _______, _______, _______,                              KC_PENT,                         _______,  QK_LLCK, TG(_SC), _______
    ),
	//for use with KTA
	[_SC] = LAYOUT_60_iso_split_bs_rshift(
        KC_ESC , KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   ALT_F4,  KC_F11,  _______, KTA_FLD, KTA_DTY, KC_F8,   KC_F9,   KC_F12,  KC_F10,
		_______, KC_PPLS, KC_P7,   KC_P8,   KC_P9,   KC_PAST, _______, _______, KC_PGUP, KC_HOME, KC_UP,   KTA_CTN, _______,
        _______, _______, HOME_P4, HOME_P5, HOME_P6, KC_PDOT, _______, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, TG(_SC), KC_ENT,
        _______, KC_PMNS, KC_P0,   KC_P1,   KC_P2,   KC_P3,   KTA_PP,  KTA_NP,  _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                              KC_PENT,                         _______,  TG(_SC), TG(_SC), _______
    )

};
