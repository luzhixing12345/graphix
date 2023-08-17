/*
 *Copyright (c) 2022 All rights reserved
 *@description: head file for transform event
 *@author: Zhixing Lu
 *@date: 2022-06-26
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
 */

#ifndef TRANSFORM_HPP_
#define TRANSFORM_HPP_

#include <cmath>

#include "screen.hpp"

struct vec3 {
    float x;
    float y;
    float z;
};

struct connection {
    int start;
    int end;
};

class Polyhedron {
   public:
    std::vector<vec3> vertexs;
    std::vector<connection> edges;

    explicit Polyhedron(Screen &screen) : screen(screen){};
    void rotate();
    void calculateCentroid();
    void _rotate(vec3 &point, float x_axis, float y_axis, float z_axis);
    void drawEdges();
    void line(float x1, float y1, float x2, float y2);
    // void restoreInitialState();
    void calculateNewRotateSpeed();
    void resetMouse();

   private:
    Screen screen;
    KeyBoard key;
    vec3 centriod = {0, 0, 0};

    // float constant_x_axis = 0.002;
    // float constant_y_axis = 0.001;

    float x_axis = 0.01;
    float y_axis = 0.02;
    float z_axis = 0.02;

    // float restore_var = 0.00001;
    float change_var = 0.0002;

    bool mouse_clicked = false;
    KeyBoard last;
    KeyBoard second;
};

#endif
