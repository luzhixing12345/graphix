/*
 *Copyright (c) 2022 All rights reserved
 *@description: main function for 
 *@author: Zhixing Lu
 *@date: 2022-06-25
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

#include <iostream>
#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
    SDL_Window* window = 0;
    SDL_Renderer* render = 0;
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("hello" , SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    render = SDL_CreateRenderer(window,-1,0);
    SDL_SetRenderDrawColor(render,0,255,0,255);
    SDL_RenderClear(render);
    SDL_RenderPresent(render);
    SDL_Delay(5000);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(render);
    SDL_Quit();

    return 0;
}
