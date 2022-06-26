/*
 *Copyright (c) 2022 All rights reserved
 *@description: realeazation for screen function
 *@author: Zhixing Lu
 *@date: 2022-06-26
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

#include "screen.hpp"
#include <iostream>

Screen::Screen()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer);
    SDL_RenderSetScale(renderer, 2, 2);
}

void Screen::pixel(float x, float y)
{
    points.push_back({x, y});
}

void Screen::show()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (auto &point : points)
    {
        SDL_RenderDrawPointF(renderer, point.x, point.y);
    }
    SDL_RenderPresent(renderer);
}

Mouse Screen::input()
{    
    Mouse mouse;
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT) {
            SDL_Quit();
            exit(0);
        }

        Uint32 buttons;

        SDL_PumpEvents();  // make sure we have the latest mouse state.

        buttons = SDL_GetMouseState(&mouse.x, &mouse.y);

        if ((buttons & SDL_BUTTON_LMASK) != 0) {
            // std::cout << mouse.x << " " << mouse.y << std::endl;
            return mouse;
        }
    }
    mouse.x = -1;
    mouse.y = -1;
    return mouse;
}

void Screen::clear() {
    points.clear();
}
