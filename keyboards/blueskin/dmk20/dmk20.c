/* Copyright 2019 Blueskin Design
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
#include "dmk20.h"


void matrix_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts up
	setPinOutput(GREEN_LED);
	setPinOutput(YELLOW_LED);
	setPinOutput(RED_LED);
	matrix_init_user();
}

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if(res) {
        writePin(GREEN_LED, !led_state.num_lock);
        writePin(YELLOW_LED, !led_state.caps_lock);
        writePin(RED_LED, !led_state.scroll_lock);
    }
    return res;
}
