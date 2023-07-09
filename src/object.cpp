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