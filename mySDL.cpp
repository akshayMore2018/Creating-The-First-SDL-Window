#include <SDL2/SDL.h>
#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) >= 0) {
        window = SDL_CreateWindow("Hello SDL",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            SCREEN_WIDTH, SCREEN_HEIGHT,
            SDL_WINDOW_OPENGL);

        if (window != 0) {
            renderer = SDL_CreateRenderer(window, -1, 0);
        }
    }
    else {
        std::cout << "Couldnt initialize SDL :" << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(5000);
    SDL_Quit();
    return 0;
}
