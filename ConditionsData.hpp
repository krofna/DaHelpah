/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details. */

#ifndef CONDITIONS_DATA_HPP
#define CONDITIONS_DATA_HPP

#include <string>

#include "BasicTypes.hpp"

struct Conditions
{
    int32 _SourceTypeOrReferenceId;
    uint32 _SourceGroup;
    int32 _SourceEntry;
    uint32 _SourceId;
    uint32 _ElseGroup;
    int32 _ConditionTypeOrReference;
    uint8 _ConditionTarget;
    uint32 _ConditionValue1;
    uint32 _ConditionValue2;
    uint32 _ConditionValue3;
    uint8 _NegativeCondition;
    uint32 _ErrorTextId;
    std::string _ScriptName;
    std::string _Comment;
};

#endif
