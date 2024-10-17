#include <SDL2/SDL.h>
#include <stdio.h>

#include "err_macro.h"

int main() {
  if (SDL_Init(SDL_INIT_VIDEO)) {
    ERR(SDL_Init, CRITICAL_ERROR);
  }
  atexit(SDL_Quit);

  SDL_Window* w = SDL_CreateWindow("Key and Mouse control", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500, 800,
                                   SDL_WINDOW_SHOWN);
  SDL_Renderer* r = SDL_CreateRenderer(w, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  int x0, y0, x1, y1;
  x0 = y0 = x1 = y1 = -1;
  for (;;) {
    SDL_Event event;
    // Uint32 start, elapsed, estimated = 1000 / 20;  // estimated 50 fps
    // start = SDL_GetTicks();

    SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
    SDL_RenderClear(r);

    while (SDL_PollEvent(&event) != 0) {
      switch (event.type) {
        case SDL_QUIT:
          goto end;
          break;
        case SDL_KEYDOWN:
          printf("%s\n", SDL_GetKeyName(event.key.keysym.sym));
          break;
        case SDL_MOUSEBUTTONDOWN:
          x0 = event.button.x;
          y0 = event.button.y;
          break;
        case SDL_MOUSEMOTION:
          x1 = event.button.x;
          y1 = event.button.y;
          break;
        case SDL_MOUSEBUTTONUP:
          x0 = y0 = x1 = y1 = -1;
          break;
      }
    }

    if (x0 != -1 && x1 != -1) {
      // Set drawing color to black
      SDL_SetRenderDrawColor(r, 0, 0, 0, 255);
      SDL_Rect rect;
      rect.x = x0;
      rect.y = y0;
      rect.w = x1 - x0;
      rect.h = y1 - y0;
      SDL_RenderFillRect(r, &rect);
    }

    SDL_RenderPresent(r);

    // elapsed = SDL_GetTicks() - start;
    // if (elapsed < estimated) {
    //   SDL_Delay(estimated - elapsed);
    // }

    SDL_Delay(10);
  }

end:
  SDL_DestroyRenderer(r);
  SDL_DestroyWindow(w);

  return 0;
}