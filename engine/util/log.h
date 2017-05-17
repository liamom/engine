#pragma once

#include <iostream>
#include <iomanip>

struct _logger
{
  std::ostream &stream_;

  _logger(std::ostream &stream, const char *file_name, int line_number) : stream_(stream) 
  {
    stream << std::setw(30) << file_name << " " << std::setw(5) << " " << line_number << " ";
  }

  ~_logger() {
    stream_ << "\n";
  }
};

#define dbg _logger(std::cout, __file_name__, __line_number__).stream_