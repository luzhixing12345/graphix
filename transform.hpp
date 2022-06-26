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

struct Polyhedron {
    std::vector<vec3> vertexs;
    std::vector<connection> edges;
};

void line(Screen &screen, float x1, float y1, float x2, float y2);

#endif
