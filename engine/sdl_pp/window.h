#pragma once

#include "exception.h"
#include "raii_base.h"

class Window : public RaiiBase<SDL_Window> {
public:
  Window(const char *title, int x, int y, int w, int h, Uint32 flags) {
    title_ = title;
    x_ = x;
    y_ = y;
    w_ = w;
    h_ = h;
    flags_ = flags;

    native_ptr_ = SDL_CreateWindow(title_, x_, y_, w_, h_, flags_);
    if (native_ptr_ == nullptr) {
      throw SDLException("SDL_CreateWindow failed");
    }
  }

  ~Window() {
    SDL_DestroyWindow(native_ptr_);
  }

  SDLSize getSize() {
    return SDLSize{ w_, h_ };
  }

  int screen_width() {
    return w_;
  }

  int screen_height() {
    return h_;
  }

private:
  const char *title_;
  int         x_;
  int         y_;
  int         w_;
  int         h_;
  Uint32      flags_;
};
