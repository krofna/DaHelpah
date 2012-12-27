/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details. */

#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <sstream>

#include "BasicTypes.hpp"

template <class T> T ToInt(const std::string& What)
{
    std::stringstream Stream;
    T Result;
    Stream << What;
    Stream >> Result;
    return Result;
}

#endif
