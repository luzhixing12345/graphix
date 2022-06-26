/*
 *Copyright (c) 2022 All rights reserved
 *@description: basic transformation action
 *@author: Zhixing Lu
 *@date: 2022-06-26
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

#include "transform.hpp"

void line(Screen &screen, float x1, float y1, float x2, float y2) {
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