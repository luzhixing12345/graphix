/*
 *Copyright (c) 2022 All rights reserved
 *@description: use SDL to create a window and show on the screen
 *@author: Zhixing Lu
 *@date: 2022-06-26
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
 */

#pragma once
#ifndef SCREEN_HPP_
#define SCREEN_HPP_ 

#include <SDL2/SDL.h>
#include <vector>

class Screen
{
public:
    SDL_Event e;
    SDL_Window *window;
    SDL_Renderer *renderer;
    std::vector<SDL_FPoint> points;

    Screen();
    void pixel(float x, float y);
    void show();
    void input();
    void clear();

private:
    const int WINDOW_WIDTH = 1280;
    const int WINDOW_HEIGHT = 960;
};


#endif
