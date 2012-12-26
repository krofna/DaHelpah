/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details. */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>

#include "Application.hpp"
#include "Database.hpp"

Application::Application() :
SavedToDB               (false),
Box                     (Gtk::ORIENTATION_VERTICAL)
{
    WorldDatabase.Connect();
    Reset();

    add(Box);
    set_border_width(10);
    set_title("DaHelpah");
    set_default_size(500, 500);

    RefActionGroup = Gtk::ActionGroup::create();
    
    // File
    RefActionGroup->add(Gtk::Action::create("FileMenu", "File"));

    // File->
    RefActionGroup->add(Gtk::Action::create("FileNew", Gtk::Stock::NEW),
            sigc::mem_fun(*this, &Application::Reset));
    RefActionGroup->add(Gtk::Action::create("FileSave", "_Save", "Save Condition"));
    RefActionGroup->add(Gtk::Action::create("FileQuit", Gtk::Stock::QUIT),
            sigc::mem_fun(*this, &Application::Quit));
    
    // File->Save->
    RefActionGroup->add(Gtk::Action::create("FileSaveDB", "To _DB", "Save to Database"),
          sigc::mem_fun(*this, &Application::SaveToDB));
    RefActionGroup->add(Gtk::Action::create("FileSaveFile", "To _File", "Save to File"),
          sigc::mem_fun(*this, &Application::SaveToFile));
    
    RefUIManager = Gtk::UIManager::create();
    RefUIManager->insert_action_group(RefActionGroup);
    add_accel_group(RefUIManager->get_accel_group());
    
    // Layout menubar
    Glib::ustring ui_info = 
        "<ui>"
        "  <menubar name='MenuBar'>"
        "    <menu action='FileMenu'>"
        "      <menuitem action='FileNew'/>"
        "      <menu action='FileSave'>"
        "          <menuitem action='FileSaveDB'/>"
        "          <menuitem action='FileSaveFile'/>"
        "      </menu>"
        "      <separator/>"
        "      <menuitem action='FileQuit'/>"
        "    </menu>"
        "  </menubar>"
        "</ui>";

    try
    {
        RefUIManager->add_ui_from_string(ui_info);
    }
    catch(const Glib::Error& ex)
    {
        std::cerr << "building menus failed: " <<  ex.what();
    }

    // Get the menubar widget, and add it to container
    Gtk::Widget* pMenubar = RefUIManager->get_widget("/MenuBar");
    if(pMenubar)
        Box.pack_start(*pMenubar, Gtk::PACK_SHRINK);

    show_all_children();
}

Application::~Application()
{
}

void Application::SaveToDB()
{
    _Save(false);
}

void Application::SaveToFile()
{
    _Save(true);
}

void Application::_Save(bool ToFile)
{
    char Buffer[MAX_QUERY_LEN];

    if (ToFile || !SavedToDB)
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
    
    if (ToFile)
    {
        std::ofstream SqlDump("ConditionsData.sql");
        SqlDump << Buffer;
    }
    else
    {
        WorldDatabase.Execute(&Buffer[0]);
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
