/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details. */

#include "Application.hpp"
#include "Utility.hpp"

void Application::ConditionValue1Changed()
{
    Condition._ConditionValue1 = ToInt<uint32>(ConditionValue1Entry.get_text().raw());
}

void Application::ConditionValue2Changed()
{
    Condition._ConditionValue2 = ToInt<uint32>(ConditionValue2Entry.get_text().raw());
}

void Application::ConditionValue3Changed()
{
    Condition._ConditionValue3 = ToInt<uint32>(ConditionValue3Entry.get_text());
}

void Application::NegativeConditionChanged()
{
    Condition._NegativeCondition = NegativeConditionButton.get_active();
}

void Application::ConditionTargetButton1Changed()
{
    Condition._ConditionTarget = 0;
}

void Application::ConditionTargetButton2Changed()
{
    Condition._ConditionTarget = 1;
}

void Application::SourceIdChanged()
{
    Condition._SourceId = ToInt<uint32>(SourceIdEntry.get_text());
}

void Application::ErrorTextIdChanged()
{
    Condition._ErrorTextId = ToInt<uint32>(ErrorTextIdEntry.get_text());
}

void Application::ScriptNameChanged()
{
    Condition._ScriptName = ScriptNameEntry.get_text();
}

void Application::CommentChanged()
{
    Condition._Comment = CommentEntry.get_text();
}

void Application::SourceGroupChanged()
{
    Condition._SourceGroup = ToInt<uint32>(SourceGroupEntry.get_text());
}

void Application::ElseGroupChanged()
{
    Condition._ElseGroup = ToInt<uint32>(ElseGroupEntry.get_text());
}
