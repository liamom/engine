#pragma once

#include <exception>
#include <SDL.h>

class SDLException : public std::exception {
public:
  SDLException(const char* what) : std::exception(what), sdl_error_(SDL_GetError()) {};
  const char* sdl_error() const {
    return sdl_error_;
  }

private:

  const char* sdl_error_;
};

struct SDLPosition {
  int x;
  int y;
};

struct SDLSize {
  int width;
  int height;
};
