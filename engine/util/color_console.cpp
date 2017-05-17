#include "stdafx.h"
#include "color_console.h"
#include <Windows.h>

ForeGroundColor ForeGroundColor::Red        {1,0,0,1};
ForeGroundColor ForeGroundColor::Blue       {0,0,1,1};
ForeGroundColor ForeGroundColor::Green      {0,1,0,1};
ForeGroundColor ForeGroundColor::LightRed   {1,0,0,0};
ForeGroundColor ForeGroundColor::LightBlue  {0,0,1,0};
ForeGroundColor ForeGroundColor::LightGreen {0,1,0,0}; 
ForeGroundColor ForeGroundColor::Yellow     {1,1,0,1};
ForeGroundColor ForeGroundColor::Purple     {1,0,1,1};
ForeGroundColor ForeGroundColor::Cyan       {0,1,1,1};
ForeGroundColor ForeGroundColor::LightYellow{1,1,0,0};  
ForeGroundColor ForeGroundColor::LightPurple{1,0,1,0};  
ForeGroundColor ForeGroundColor::LightCyan  {0,1,1,0};

BackGroundColor BackGroundColor::Red{ 1,0,0,1 };
BackGroundColor BackGroundColor::Blue{ 0,0,1,1 };
BackGroundColor BackGroundColor::Green{ 0,1,0,1 };
BackGroundColor BackGroundColor::LightRed{ 1,0,0,0 };
BackGroundColor BackGroundColor::LightBlue{ 0,0,1,0 };
BackGroundColor BackGroundColor::LightGreen{ 0,1,0,0 };
BackGroundColor BackGroundColor::Yellow{ 1,1,0,1 };
BackGroundColor BackGroundColor::Purple{ 1,0,1,1 };
BackGroundColor BackGroundColor::Cyan{ 0,1,1,1 };
BackGroundColor BackGroundColor::LightYellow{ 1,1,0,0 };
BackGroundColor BackGroundColor::LightPurple{ 1,0,1,0 };
BackGroundColor BackGroundColor::LightCyan{ 0,1,1,0 };

namespace {
  HANDLE gHandle_;
  WORD   gSettings_;
}

std::ostream& operator<<(std::ostream& stream, ForeGroundColor& c) {
  bool bblue = c.blue != 0;
  bool bgreen = c.green != 0;
  bool bred = c.red != 0;
  bool bintensety = c.intensety != 0;

  gSettings_ &= 0xFFFFFFF0;

  gSettings_ |= bblue;
  gSettings_ |= bgreen << 1;
  gSettings_ |= bred << 2;
  gSettings_ |= bintensety << 3;

  SetConsoleTextAttribute(gHandle_, gSettings_);

  return stream;
}

std::ostream& operator<<(std::ostream& stream, BackGroundColor& c) {
  bool bblue = c.blue != 0;
  bool bgreen = c.green != 0;
  bool bred = c.red != 0;
  bool bintensety = c.intensety != 0;

  gSettings_ &= 0xFFFFFF0F;

  gSettings_ |= bblue << 4;
  gSettings_ |= bgreen << 5;
  gSettings_ |= bred << 6;
  gSettings_ |= bintensety << 7;

  SetConsoleTextAttribute(gHandle_, gSettings_);

  return stream;
}

std::ostream& operator<<(std::ostream& stream, _DefaultColor& c) {
  gSettings_ = 0;
  SetConsoleTextAttribute(gHandle_, gSettings_);
  return stream;
}