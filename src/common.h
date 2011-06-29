/*
    Copyright 2011 Paweł Czaplejewicz

    This file is part of Jazda.

    Jazda is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Jazda is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Jazda.  If not, see <http://www.gnu.org/licenses/>.
*/

#define true 1
#define false 0
#define STRVALUE(arg) #arg
#define NUMSTR(num) STRVALUE(num)
#define HIGH(PORT, PIN) PORT |= _BV(PIN)
#define LOW(PORT, PIN) PORT &= ~_BV(PIN)
#define MODULE_SIGNATURE_SIZE 8

typedef struct unsigned_point {
    uint8_t x;
    uint8_t y;
} upoint_t;

typedef struct signed_point {
    int8_t x;
    int8_t y;
} point_t;

typedef struct module_record {
    void (*redraw)(uint8_t force);
    struct module_actions * (*select_button)(uint8_t state);
    char signature[MODULE_SIGNATURE_SIZE]; // module logo for display
} module_record_t;

typedef struct module_actions {
    void (*button_left)(uint8_t state);
    void (*button_right)(uint8_t state);
} module_actions_t;

typedef struct time_storage {
    uint8_t seconds;
    uint8_t minutes;
    uint8_t hours;
} time_storage_t;

#define nibblepair_t uint8_t
#define NIBBLEPAIR(num1, num2) (nibblepair_t)((num1 << 4) | (num2 & 0x0F))

volatile uint16_t debug_variable;
