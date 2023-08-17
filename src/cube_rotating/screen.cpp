/*
 *Copyright (c) 2022 All rights reserved
 *@description: realeazation for screen function
 *@author: Zhixing Lu
 *@date: 2022-06-26
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
 */

#include "screen.hpp"

#include <SDL2/SDL_events.h>

#include <cstdio>
#include <iostream>

Screen::Screen() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        // 处理初始化错误
        SDL_Log("无法初始化SDL: %s", SDL_GetError());
        // 可以抛出异常或者采取其他处理措施
    }

    window = SDL_CreateWindow(
        "窗口标题", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        // 处理窗口创建错误
        SDL_Log("无法创建窗口: %s", SDL_GetError());
        // 可以抛出异常或者采取其他处理措施
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        // 处理渲染器创建错误
        SDL_Log("无法创建渲染器: %s", SDL_GetError());
        // 可以抛出异常或者采取其他处理措施
    }

    SDL_RenderSetScale(renderer, 2, 2);
}

void Screen::pixel(float x, float y) {
    points.push_back({(float)x, (float)y});
}

void Screen::show() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (auto &point : points) {
        SDL_RenderDrawPointF(renderer, point.x, point.y);
    }
    SDL_RenderPresent(renderer);
}

KeyBoard Screen::input() {
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            SDL_Quit();
            exit(0);
        } else if (e.type == SDL_KEYDOWN) {
            return e.key.keysym.sym;
        }
    }
    return 0;
}

void Screen::clear() {
    points.clear();
}
