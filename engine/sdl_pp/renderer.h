#pragma once

#include <SDL.h>
#include "exception.h"
#include "raii_base.h"
#include "texture.h"

class Renderer : public RaiiBase<SDL_Renderer> {
public:
  Renderer(SDL_Window *win, int index, Uint32 flags) {
    native_ptr_ = SDL_CreateRenderer(win, index, flags);
    if (native_ptr_ == nullptr) {
      throw SDLException("SDL_CreateRenderer failed");
    }
  }

  void Clear() {
    SDL_RenderClear(native_ptr_);
  }

  void RenderPresent() {
    SDL_RenderPresent(native_ptr_);
  }

  void DrawRect(SDL_Rect *rect) {
    if (SDL_RenderDrawRect(native_ptr_, rect) != 0) {
      throw SDLException("SDL_RenderDrawRect");
    }
  }
  void DrawRects(SDL_Rect *rect, int n) {
    if (SDL_RenderDrawRects(native_ptr_, rect, n) != 0) {
      throw SDLException("SDL_RenderDrawRects");
    }
  }

  void FillRect(SDL_Rect *rect) {
    if (SDL_RenderFillRect(native_ptr_, rect) != 0) {
      throw SDLException("SDL_RenderFillRect");
    }
  }

  void FillRects(SDL_Rect *rect, int n) {
    if (SDL_RenderFillRects(native_ptr_, rect, n) != 0) {
      throw SDLException("SDL_RenderFillRect");
    }
  }

  void Render(SDL_Texture *tex) {
    SDL_RenderCopy(native_ptr_, tex, NULL, NULL);
  }

  void Render(Texture &tex, int x, int y) {
    //Query the texture to get its width and height to use
    SDLSize size = tex.QueryTexture();
    Render(tex, SDL_Rect{ x, y, size.width, size.height });
  }

  void Render(SDL_Texture *tex, SDL_Rect& dst) {
    SDL_RenderCopy(native_ptr_, tex, NULL, &dst);
  }

  void Render(SDL_Texture *tex, SDL_Rect& dst, SDL_Rect &clip) {
    SDL_RenderCopy(native_ptr_, tex, &clip, &dst);
  }

  ~Renderer() {
    SDL_DestroyRenderer(native_ptr_);
  }
};
