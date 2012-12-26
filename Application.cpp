/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details. */

#include <cstdio>

#include "Application.hpp"
#include "Database.hpp"

Application::Application(),
Saved                   (false)
{
    WorldDatabase.Connect();

    std::memset(&Condition, 0, sizeof(ConditionsData) - 2 * sizeof(std::string));

    set_border_width(10);
}

Application::~Application()
{
}

void Save(bool ToFile)
{
    char Buffer[MAX_QUERY_LEN];

    if (ToFile || Saved)
    {
        snprintf(Buffer, "INSERT INTO conditions VALUES (%i, %u, %i, %u, %u, %i, %u, %u, %u, %u, %u, %u, '%s', '%s')",
                 Condition._SourceTypeOrReferenceId, Condition._SourceGroup,
                 Condition._SourceEntry, Condition._SourceId, Condition._ElseGroup, Condition._ConditionTypeOrReference,
                 Condition._ConditionTarget, Condition._ConditionValue1, Condition._ConditionValue2, Condition._ConditionValue3,
                 Condition._NegativeCondition, Condition._ErrorTextId, Condition._ScriptName.c_str(), Condition._Comment.c_str());
    }
    else
    {
        snprintf(Buffer, "UPDATE conditions SET SourceTypeOrReferenceId=%i, SourceGroup=%u, "
                         "SourceEntry=%i, SourceId=%u, ElseGroup=%u, ConditionTypeOrReference=%i, "
                         "ConditionTarget=%u, ConditionValue1=%u, ConditionValue2=%u, ConditionValue3=%u, "
                         "NegativeCondition=%u, ErrorTextId=%u, ScriptName='%s', Comment='%s'",
                         Condition._SourceTypeOrReferenceId, Condition._SourceGroup,
                         Condition._SourceEntry, Condition._SourceId, Condition._ElseGroup, Condition._ConditionTypeOrReference,
                         Condition._ConditionTarget, Condition._ConditionValue1, Condition._ConditionValue2, Condition._ConditionValue3,
                         Condition._NegativeCondition, Condition._ErrorTextId, Condition._ScriptName.c_str(), Condition._Comment.c_str());
    }
    
    if (ToFile)
    {
        std::ofstream SqlDump("ConditionsData.sql");
        SqlDump << Buffer;
    }
    else
    {
        WorldDatabase.Execute(&Buffer);
    }
}
