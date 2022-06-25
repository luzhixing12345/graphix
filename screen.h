/*
 *Copyright (c) 2022 All rights reserved
 *@description: use SDL to create a window and show on the screen
 *@author: Zhixing Lu
 *@date: 2022-06-26
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
 */

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

void Screen::input()
{
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
        {
            SDL_Quit();
            exit(0);
        }
    }
}

void Screen::clear() {
    points.clear();
}