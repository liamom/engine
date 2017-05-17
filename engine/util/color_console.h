#pragma once

#include <ostream>

namespace {
  class _DefaultColor {};

struct Color {
  Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t intensety) : red(red), green(green), blue(blue), intensety(intensety) {}
protected:
  uint8_t red;
  uint8_t green;
  uint8_t blue;
  uint8_t intensety;
};


}

struct ForeGroundColor : public Color {
  ForeGroundColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t intensety) : Color(red, green, blue, intensety) {}
  friend std::ostream& operator<<(std::ostream&, ForeGroundColor& c);

  static ForeGroundColor Red;
  static ForeGroundColor Blue;
  static ForeGroundColor Green;
  static ForeGroundColor LightRed;
  static ForeGroundColor LightBlue;
  static ForeGroundColor LightGreen;
  static ForeGroundColor Yellow;
  static ForeGroundColor Purple;
  static ForeGroundColor Cyan;
  static ForeGroundColor LightYellow;
  static ForeGroundColor LightPurple;
  static ForeGroundColor LightCyan;
};

struct BackGroundColor : public Color {
  BackGroundColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t intensety) : Color(red, green, blue, intensety) {}
  friend std::ostream& operator<<(std::ostream&, BackGroundColor& c);

  static BackGroundColor Red;
  static BackGroundColor Blue;
  static BackGroundColor Green;
  static BackGroundColor LightRed;
  static BackGroundColor LightBlue;
  static BackGroundColor LightGreen;
  static BackGroundColor Yellow;
  static BackGroundColor Purple;
  static BackGroundColor Cyan;
  static BackGroundColor LightYellow;
  static BackGroundColor LightPurple;
  static BackGroundColor LightCyan;
};

std::ostream& operator<<(std::ostream&, ForeGroundColor& c);
std::ostream& operator<<(std::ostream&, BackGroundColor& c);
std::ostream& operator<<(std::ostream&, _DefaultColor& c);