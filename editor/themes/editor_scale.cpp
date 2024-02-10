/**************************************************************************/
/*  editor_scale.cpp                                                      */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#include "editor_scale.h"

// Static member initialization
float EditorScale::_scale = 1.0f;
const float EditorScale::MIN_SCALE = 0.1f; // Minimum scale value
const float EditorScale::MAX_SCALE = 10.0f; // Maximum scale value

void EditorScale::set_scale(float p_scale) {
    // Clamp the value of p_scale to ensure it's within the min and max bounds
    if (p_scale < MIN_SCALE) {
        p_scale = MIN_SCALE;
    } else if (p_scale > MAX_SCALE) {
        p_scale = MAX_SCALE;
    }
    _scale = p_scale;
    // Optionally, trigger an event or callback here to notify about the scale change
}

float EditorScale::get_scale() {
    return _scale;
}

// Increment the scale by a fixed factor, ensuring it does not exceed MAX_SCALE
void EditorScale::increase_scale(float factor) {
    set_scale(_scale + factor);
}

// Decrement the scale by a fixed factor, ensuring it does not fall below MIN_SCALE
void EditorScale::decrease_scale(float factor) {
    set_scale(_scale - factor);
}

