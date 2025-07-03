/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2021 Elliot Powell @e11i0t23
Copyright 2025 Andrei Vasile @andyterrify

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "qp.h"
#include "qp_comms.h"
#include "qp_st77xx_opcodes.h"
// #include "gfx/mb.qgf.h"
#include "qp_lvgl.h"
#include "printf.h"
// #include "display/display.h"
#include "display/testing.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Init board:
// - Draw logo

// https://docs.qmk.fm/custom_quantum_functions#keyboard-pre-initialization-code
// native fn, used to init keyboard
void keyboard_post_init_kb(void) {
    display_init();
}

// native fn, used to mainain keyboard
// void housekeeping_task_kb(void) {
//     display_housekeeping_task();
// }
