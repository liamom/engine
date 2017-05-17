#pragma once

#include "exception.h"
#include "renderer.h"
#include "surface.h"
#include "texture.h"
#include "window.h"


class SDLInit {
public:
  explicit SDLInit(Uint32 flags) {
    if (SDL_Init(flags) != 0) {
      throw SDLException("SDL_Init failed");
    }
  }

  ~SDLInit() {
    SDL_Quit();
  }
};

class IMGinit {
public:
  explicit IMGinit(int flags) {
    if (IMG_Init(flags) == 0) {
      throw SDLException("IMG_Init");
    }
  }

  ~IMGinit() {
    IMG_Quit();
  }
};



