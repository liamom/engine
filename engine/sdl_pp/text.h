#pragma once

#include <SDL_ttf.h>
#include <string>

#include "sdl_pp.h"

class SDLTextInit {
public:
  explicit SDLTextInit() {
    if (TTF_Init() != 0) {
      throw SDLException("TTF_Init");
    }
  }

  ~SDLTextInit() {
    TTF_Quit();
  }
};

class SDLText : RaiiBase<TTF_Font> {
public:
  SDLText(const std::string &font_file, int font_size) {
    native_ptr_ = TTF_OpenFont(font_file.c_str(), font_size);
    if (native_ptr_ == nullptr) {
      throw SDLException("TTF_OpenFont");
    }
  }

  Texture CreateText(Renderer &renderer,SDL_Color color, const std::string &text) {
    //We need to first render to a surface as that's what TTF_RenderText
    //returns, then load that surface into a texture
    Surface surf(TTF_RenderText_Blended(native_ptr_, text.c_str(), color));
    Texture texture(SDL_CreateTextureFromSurface(renderer, surf));
    return texture;
  }

  ~SDLText() {
    TTF_CloseFont(native_ptr_);
  }
};