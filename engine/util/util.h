#ifndef UTIL_H
#define UTIL_H

#include <string>

/// <summary>
/// 
/// </summary>
/// <param name="file"></param>
/// <returns>".png"</returns>
std::string get_file_extension(const std::string &file);

/*
* Get the resource path for resources located in res/subDir
* It's assumed the project directory is structured like:
* bin/
*  the executable
* res/
*  Lesson1/
*  Lesson2/
*
* Paths returned will be Lessons/res/subDir
*/
std::string getResourcePath(const std::string &subDir = "");
#endif // UTIL_H