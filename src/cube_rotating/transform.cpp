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
    float dy = y2 - y1;
    float dx = x2 - x1;
    float length = std::sqrt(dx * dx + dy * dy);
    float angle = std::atan2(dy, dx);

    for (int i = 0; i < length; i++) {
        screen.pixel(x1 + std::cos(angle) * i, y1 + std::sin(angle) * i);
    }
}

void Polyhedron::_rotate(vec3 &point, float x_axis = 1, float y_axis = 1, float z_axis = 1) {
    point.x -= centriod.x;
    point.y -= centriod.y;
    point.z -= centriod.z;

    float rad = 0;

    // rotate about X axis
    rad = x_axis;
    point.y = std::cos(rad) * point.y - std::sin(rad) * point.z;
    point.z = std::sin(rad) * point.y + std::cos(rad) * point.z;

    // rotate about Y axis
    rad = y_axis;
    point.x = std::cos(rad) * point.x + std::sin(rad) * point.z;
    point.z = -std::sin(rad) * point.x + std::cos(rad) * point.z;

    // rotate about Z axis
    rad = z_axis;
    point.x = std::cos(rad) * point.x - std::sin(rad) * point.y;
    point.y = std::sin(rad) * point.x + std::cos(rad) * point.y;

    point.x += centriod.x;
    point.y += centriod.y;
    point.z += centriod.z;
}

/**
 * @brief 计算多面体的旋转中心点坐标, 假定分布均匀, 取几何中心
 *
 */
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
        line(vertexs[edge.start].x, vertexs[edge.start].y, vertexs[edge.end].x, vertexs[edge.end].y);
    }
}

// void Polyhedron::restoreInitialState() {
//     if (x_axis != constant_x_axis) {
//         x_axis = x_axis < constant_x_axis ? x_axis + restore_var : x_axis - restore_var;
//     }
//     if (y_axis != constant_y_axis) {
//         y_axis = y_axis < constant_y_axis ? y_axis + restore_var : y_axis - restore_var;
//     }
//     // z_axis speed no change
// }

// void Polyhedron::resetMouse() {
//     last = {.x = -1, .y = -1};
//     second = {.x = -1, .y = -1};
//     mouse_clicked = false;
// }

// void Polyhedron::calculateNewRotateSpeed() {
//     if (last.x > second.x && last.y > second.y) {
//         // right + down
//         x_axis = (last.x - second.x) * change_var;
//         y_axis = -(last.y - second.y) * change_var;
//     } else if (last.x > second.x && last.y < second.y) {
//         // right + up
//         x_axis = -(last.x - second.x) * change_var;
//         y_axis = (last.y - second.y) * change_var;
//     } else if (last.x < second.x && last.y > second.y) {
//         // left + down
//         x_axis = -(last.x - second.x) * change_var;
//         y_axis = (last.y - second.y) * change_var;
//     } else {
//         // left + up
//         x_axis = (last.x - second.x) * change_var;
//         y_axis = -(last.y - second.y) * change_var;
//     }
// }

void Polyhedron::rotate() {
    for (vec3 &point : vertexs) {
        _rotate(point, x_axis, y_axis, z_axis);
        screen.pixel(point.x, point.y);
    }

    drawEdges();

    screen.show();
    screen.clear();
    key = screen.input();
    if (key != 0) {
        switch (key) {
            case SDLK_UP:
                x_axis -= 0.01;
                break;
            case SDLK_DOWN:
                x_axis += 0.01;
                break;
            case SDLK_LEFT:
                y_axis += 0.01;
                break;
            case SDLK_RIGHT:
                y_axis -= 0.01;
                break;
        }
    }
    SDL_Delay(30);
}
