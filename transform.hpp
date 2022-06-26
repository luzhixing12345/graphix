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
    void rotate(float x_axis, float y_axis, float z_axis);
    void calculateCentroid();
    void _rotate(vec3 &point, float x_axis, float y_axis, float z_axis);
    void drawEdges();
    void line(float x1, float y1, float x2, float y2);

private:
    Screen screen;
    vec3 centriod = {0,0,0};
};

#endif
