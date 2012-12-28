/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details. */

#include <iostream>

#include "Application.hpp"

Application::Application() :
SavedToDB               (false),
MainBox                 (Gtk::ORIENTATION_VERTICAL),
ButtonBox               (Gtk::ORIENTATION_HORIZONTAL),
NewConditionButton      ("New Condition"),
DeleteConditionButton   ("Delete Condition")
{
    WorldDatabase.Connect();
    
    // Notebook
    NotebookPage* pNotebook = Gtk::manage(new NotebookPage);
    Notebook.append_page(*pNotebook);

    // Window
    MainBox.pack_start(Notebook);
    MainBox.pack_start(ButtonBox);
    add(MainBox);
    set_border_width(5);
    set_title("DaHelpah");
    RefActionGroup = Gtk::ActionGroup::create();
    
    // New/Delete Condition
    NewConditionButton.signal_clicked().connect(sigc::mem_fun(*this, &Application::OnNewConditionButtonClicked));
    DeleteConditionButton.signal_clicked().connect(sigc::mem_fun(*this, &Application::OnDeleteConditionButtonClicked));
    ButtonBox.pack_start(NewConditionButton);
    ButtonBox.pack_start(DeleteConditionButton);

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
        std::cerr << "Building menus failed: " <<  ex.what();
    }

    // Get the menubar widget, and add it to container
    Gtk::Widget* pMenubar = RefUIManager->get_widget("/MenuBar");
    if(pMenubar)
        MainBox.pack_start(*pMenubar, Gtk::PACK_SHRINK);

    show_all_children();
}

Application::~Application()
{
}

void Application::Reset()
{
    // TODO: nisi spremio??
    // Reset sve
}

void Application::OnNewConditionButtonClicked()
{
    NotebookPage* pNotebook = Gtk::manage(new NotebookPage);
    Notebook.append_page(*pNotebook);
    Notebook.show_all_children();
}

void Application::OnDeleteConditionButtonClicked()
{
    Notebook.remove_page(Notebook.get_current_page());
}
