/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details. */

#include <cstring>
#include <cstdio>
#include <fstream>

#include "Application.hpp"

void Application::SaveToDB()
{
    Save(0);
}

void Application::SaveToFile()
{
    Gtk::FileChooserDialog Dialog("Dump da sql, mon.", Gtk::FILE_CHOOSER_ACTION_SAVE);
    Dialog.set_transient_for(*this);

    Dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
    Dialog.add_button("Save", Gtk::RESPONSE_OK);

    if (Dialog.run() == Gtk::RESPONSE_OK)
        Save(Dialog.get_filename().c_str());
}

void Application::Save(const char* FileName)
{
    char Buffer[MAX_QUERY_LEN];

    if (FileName || !SavedToDB)
    {
        snprintf(Buffer, MAX_QUERY_LEN, "INSERT INTO conditions VALUES (%i, %u, %i, %u, %u, %i, %u, %u, %u, %u, %u, %u, '%s', '%s')",
                 Condition._SourceTypeOrReferenceId, Condition._SourceGroup,
                 Condition._SourceEntry, Condition._SourceId, Condition._ElseGroup, Condition._ConditionTypeOrReference,
                 Condition._ConditionTarget, Condition._ConditionValue1, Condition._ConditionValue2, Condition._ConditionValue3,
                 Condition._NegativeCondition, Condition._ErrorTextId, Condition._ScriptName.c_str(), Condition._Comment.c_str());
    }
    else
    {
        snprintf(Buffer, MAX_QUERY_LEN, "UPDATE conditions SET SourceTypeOrReferenceId=%i, SourceGroup=%u, "
                 "SourceEntry=%i, SourceId=%u, ElseGroup=%u, ConditionTypeOrReference=%i, "
                 "ConditionTarget=%u, ConditionValue1=%u, ConditionValue2=%u, ConditionValue3=%u, "
                 "NegativeCondition=%u, ErrorTextId=%u, ScriptName='%s', Comment='%s'",
                 Condition._SourceTypeOrReferenceId, Condition._SourceGroup,
                 Condition._SourceEntry, Condition._SourceId, Condition._ElseGroup, Condition._ConditionTypeOrReference,
                 Condition._ConditionTarget, Condition._ConditionValue1, Condition._ConditionValue2, Condition._ConditionValue3,
                 Condition._NegativeCondition, Condition._ErrorTextId, Condition._ScriptName.c_str(), Condition._Comment.c_str());
    }

    if (FileName)
    {
        std::ofstream SqlDump(FileName);
        SqlDump << Buffer << ';';
    }
    else
    {
        WorldDatabase.Execute(Buffer);
        SavedToDB = true;
    }
}

void Application::Reset()
{
    std::memset(&Condition, 0, sizeof(ConditionsData) - 2 * sizeof(std::string));
}

void Application::Quit()
{
    hide();
}
