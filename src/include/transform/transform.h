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
#pragma once

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <tuple>
#include <valarray>
#include <vector>

typedef std::tuple<float, float, float> vector3;

namespace Transform {
    class Point {
    private:
    public:
        int x, y, z;
        Point(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {	};
    };

   
    double calculateTriangleArea(Transform::Point p0, Transform::Point p1, Transform::Point p2);

    static bool checkPointInside(Transform::Point point, std::vector<Transform::Point> shape);

    bool checkInside(std::vector<Transform::Point> shape1, std::vector<Transform::Point> shape2);

    bool checkLineSegmentIntersection(Transform::Point p1, Transform::Point p2,
        Transform::Point& q1, Transform::Point& q2);

    // Returns true the passed two vectors of points are overlapping in any 
    bool checkOverlap(std::vector<Transform::Point> shape1, std::vector<Transform::Point> shape2);
}

#endif