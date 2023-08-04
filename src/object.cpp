/*
 * Copyright 2023 Electro Corparation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <pch.h>
#include <object.hpp>

Object::Object(vector3 _position, vector3 _size) : position(_position), size(_size) {

}

Object::Object() : position(0, 0, 0), size(0, 0, 0) {

}

void Object::set_pos(vector3 _pos) {
    this->position = _pos;
}

void Object::set_size(vector3 _size) {
    this->size = _size;
}