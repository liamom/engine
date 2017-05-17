#pragma once

#include <SDL.h>

template<class NATIVE_TYPE>
class RaiiBase {
public:
  RaiiBase() = default;
  RaiiBase(RaiiBase&& obj) {
    native_ptr_ = obj.native_ptr_;
    obj.native_ptr_ = nullptr;
  }
  RaiiBase(RaiiBase&) = delete;
  RaiiBase(NATIVE_TYPE *ptr) : native_ptr_(ptr) {
    if (ptr == nullptr) {
      throw SDLException(typeid(NATIVE_TYPE).name());
    }
  }

  bool isValid() const {
    return native_ptr_ != nullptr;
  }

  operator bool() const {
    return isValid();
  }

  NATIVE_TYPE* get() const {
    return native_ptr_;
  }

  operator NATIVE_TYPE*() const {
    return native_ptr_;
  }

protected:
  NATIVE_TYPE *native_ptr_ = nullptr;
};