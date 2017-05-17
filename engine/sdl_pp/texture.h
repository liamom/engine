#pragma once


#include <SDL_image.h>
#include "exception.h"
#include "raii_base.h"
#include "../util/util.h"


class Texture : public RaiiBase<SDL_Texture> {
public:
  Texture(const Texture&) = delete;
  Texture(Texture && obj) = default;
  explicit Texture(SDL_Texture* texture) :RaiiBase(texture) { }

  Texture(SDL_Renderer *ren, const std::string &file) {
    if (get_file_extension(file) == ".bmp") {
      loadBMP(ren, file.c_str());
    }
    else {
      native_ptr_ = IMG_LoadTexture(ren, file.c_str());
      if (native_ptr_ == nullptr) {
        throw SDLException("LoadTexture");
      }
    }
  }

  SDLSize QueryTexture() {
    SDLSize size;
    if (SDL_QueryTexture(native_ptr_, NULL, NULL, &size.width, &size.height) == -1) {
      throw SDLException("SDL_QueryTexture");
    }
    return size;
  }

  ~Texture() {
    SDL_DestroyTexture(native_ptr_);
  }

private:
  void loadBMP(SDL_Renderer *ren, const char *file) {
    //Load the image
    SDL_Surface *loadedImage = SDL_LoadBMP(file);
    //If the loading went ok, convert to texture and return the texture
    if (loadedImage != nullptr) {
      native_ptr_ = SDL_CreateTextureFromSurface(ren, loadedImage);
      SDL_FreeSurface(loadedImage);
      //Make sure converting went ok too
      if (native_ptr_ == nullptr) {
        throw SDLException("CreateTextureFromSurface");
      }
    }
    else {
      throw SDLException("LoadBMP");
    }
  }
};
