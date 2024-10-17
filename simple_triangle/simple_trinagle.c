#include <SDL2/SDL.h>

#include "err_macro.h"

int main() {
  if (SDL_Init(SDL_INIT_VIDEO)) {
    ERR(SDL_Init, CRITICAL_ERROR);
  }
  atexit(SDL_Quit);

  SDL_Window* w = SDL_CreateWindow("First SDL triangle", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 300, 400,
                                   SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
  SDL_Renderer* r = SDL_CreateRenderer(w, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  SDL_SetRenderDrawColor(r, 0xff, 0xff, 0xff, 0xff);
  for (;;) {
    int pending;
    SDL_Event event;
    pending = SDL_PollEvent(&event);
    if (pending && event.type == SDL_QUIT) {
      break;
    }

    int w, h;
    SDL_RenderClear(r);

    SDL_GetRendererOutputSize(r, &w, &h);
    SDL_Vertex vertex_1 = {{100, 100}, {0, 0, 0xff, 0xff}, {}};
    SDL_Vertex vertex_2 = {{w - 100, 100}, {0xff - 150, 0xff, 0xff, 0xff}, {}};
    SDL_Vertex vertex_3 = {{100, h - 100}, {0xff, 0, 0, 0xff}, {}};

    SDL_Vertex vertices[] = {vertex_1, vertex_2, vertex_3};

    SDL_RenderGeometry(r, NULL, vertices, 3, NULL, 0);

    SDL_RenderPresent(r);
  }
  SDL_DestroyRenderer(r);
  SDL_DestroyWindow(w);
  return 0;
}