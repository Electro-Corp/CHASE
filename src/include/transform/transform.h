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

typedef std::tuple<float, float, float> vector3;

namespace Transform {
    class Point {
    private:
    public:
        int x, y, z;
        Point(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {	};
    };

    // Returns true the passed two vectors of points are overlapping in any 
    bool checkOverlap(const std::vector<Transform::Point>& shape1, const std::vector<Transform::Point>& shape2) {
        // Check if any of the edges of shape1 intersect with any of the faces of shape2
        for (size_t i = 0; i < shape1.size(); ++i) {
            const Transform::Point& p1 = shape1[i];
            const Transform::Point& p2 = shape1[(i + 1) % shape1.size()];

            for (size_t j = 0; j < shape2.size(); ++j) {
                const Transform::Point& q1 = shape2[j];
                const Transform::Point& q2 = shape2[(j + 1) % shape2.size()];

                if (checkLineSegmentIntersection(p1, p2, q1, q2)) {
                    return true; // Shapes overlap
                }
            }
        }

        return Transform::checkInside(shape1, shape2) || Transform::checkInside(shape2, shape1); // No overlap found
    }

    bool checkInside(const std::vector<Transform::Point>& shape1, const std::vector<Transform::Point>& shape2) {
        // Check if all points of shape1 are inside shape2
        for (const Transform::Point& p : shape1) {
            if (!checkPointInside(p, shape2)) {
                return false; // Not all points are inside
            }
        }

        return true; // All points are inside
    }

    static bool checkPointInside(const Transform::Point& point, const std::vector<Transform::Point>& shape) {
        // Check if a point is inside a polygon (assuming it is a simple polygon without self-intersections)
        // You can implement a point-in-polygon test here based on your requirements

        // For simplicity, let's assume the shape is a triangle and use barycentric coordinates

        const Transform::Point& p0 = shape[0];
        const Transform::Point& p1 = shape[1];
        const Transform::Point& p2 = shape[2];

        double areaABC = Transform::calculateTriangleArea(p0, p1, p2);
        double areaPBC = Transform::calculateTriangleArea(point, p1, p2);
        double areaPCA = Transform::calculateTriangleArea(p0, point, p2);
        double areaPAB = Transform::calculateTriangleArea(p0, p1, point);

        return (areaPBC + areaPCA + areaPAB) <= areaABC;
    }

    bool checkLineSegmentIntersection(const Transform::Point& p1, const Transform::Point& p2,
        const Transform::Point& q1, const Transform::Point& q2) {
        // Check if the line segments intersect using a simple 2D algorithm
        // You can extend this to 3D if necessary

        // Calculate the 2D projections of the line segments onto the XY plane
        double p1x = p1.x;
        double p1y = p1.y;
        double p2x = p2.x;
        double p2y = p2.y;

        double q1x = q1.x;
        double q1y = q1.y;
        double q2x = q2.x;
        double q2y = q2.y;

        double d1 = (q2x - q1x) * (p1y - q1y) - (q2y - q1y) * (p1x - q1x);
        double d2 = (q2x - q1x) * (p2y - q1y) - (q2y - q1y) * (p2x - q1x);
        double d3 = (p2x - p1x) * (q1y - p1y) - (p2y - p1y) * (q1x - p1x);
        double d4 = (p2x - p1x) * (q2y - p1y) - (p2y - p1y) * (q2x - p1x);

        return (d1 * d2 < 0 && d3 * d4 < 0);
    }

    double calculateTriangleArea(const Transform::Point& p0, const Transform::Point& p1, const Transform::Point& p2) {
        // Calculate the area of a triangle in 3D space
        double crossProductLength = std::sqrt(
            std::pow((p1.y - p0.y) * (p2.z - p0.z) - (p1.z - p0.z) * (p2.y - p0.y), 2) +
            std::pow((p1.z - p0.z) * (p2.x - p0.x) - (p1.x - p0.x) * (p2.z - p0.z), 2) +
            std::pow((p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x), 2)
        );

        return 0.5 * crossProductLength;
    }
}

#endif