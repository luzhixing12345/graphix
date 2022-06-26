/*
 *Copyright (c) 2022 All rights reserved
 *@description: basic transformation action
 *@author: Zhixing Lu
 *@date: 2022-06-26
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

#include "transform.hpp"
#include <iostream>

void Polyhedron::line(float x1, float y1, float x2, float y2) {
    float dy = y2-y1;
    float dx = x2-x1;
    float length = std::sqrt(dx*dx + dy*dy);
    float angle = std::atan2(dy,dx);

    for (int i=0 ;i<length ;i++) {
        screen.pixel(
            x1 + std::cos(angle) *i,
            y1 + std::sin(angle) *i
        );
    }
}



void Polyhedron::_rotate(vec3 &point, float x_axis = 1, float y_axis = 1, float z_axis = 1) {

    point.x -= centriod.x;
    point.y -= centriod.y;
    point.z -= centriod.z;

    float rad = 0;

    rad = x_axis;
    point.y = std::cos(rad) * point.y - std::sin(rad) * point.z;
    point.z = std::sin(rad) * point.y + std::cos(rad) * point.z;

    rad = y_axis;
    point.x = std::cos(rad) * point.x + std::sin(rad) * point.z;
    point.z = -std::sin(rad) * point.x + std::cos(rad) * point.z;

    rad = z_axis;
    point.x = std::cos(rad) * point.x - std::sin(rad) * point.y;
    point.y = std::sin(rad) * point.x + std::cos(rad) * point.y;

    
    point.x += centriod.x;
    point.y += centriod.y;
    point.z += centriod.z;

}

void Polyhedron::calculateCentroid() {
    for (vec3 &point : vertexs) {
        centriod.x += point.x;
        centriod.y += point.y;
        centriod.z += point.z;
    }
    centriod.x /= vertexs.size();
    centriod.y /= vertexs.size();
    centriod.z /= vertexs.size();

    // std::cout << centriod.x << centriod.y << centriod.z;
}

void Polyhedron::drawEdges() {
    
    for (connection &edge : edges) {
        line(vertexs[edge.start].x,
             vertexs[edge.start].y,
             vertexs[edge.end].x,
             vertexs[edge.end].y);
    }
}

void Polyhedron::rotate(float x_axis, float y_axis, float z_axis) {
    
    for (vec3 &point : vertexs) {
        _rotate(point, x_axis, y_axis, z_axis);
        screen.pixel(point.x, point.y);
    }

    drawEdges();

    screen.show();
    screen.clear();
    screen.input();
    SDL_Delay(30);
}