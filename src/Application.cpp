/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details. */

#include <iostream>

#include "Application.hpp"

Application::Application() :
MainBox                 (Gtk::ORIENTATION_VERTICAL),
ButtonBox               (Gtk::ORIENTATION_HORIZONTAL),
NewConditionButton      ("New Condition"),
DeleteConditionButton   ("Delete Condition")
{    
    // Notebook
    NotebookPage* pNotebook = Gtk::manage(new NotebookPage(0, -1));
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
    RefActionGroup->add(Gtk::Action::create("FileNew", "_Reset", "Reset all conditions"),
          sigc::mem_fun(*this, &Application::Reset));
    RefActionGroup->add(Gtk::Action::create("FileSave", "_Save", "Save all conditions"),
          sigc::mem_fun(*this, &Application::Save));
    RefActionGroup->add(Gtk::Action::create("FileQuit", Gtk::Stock::QUIT),
            sigc::mem_fun(*this, &Application::Quit));

    RefUIManager = Gtk::UIManager::create();
    RefUIManager->insert_action_group(RefActionGroup);
    add_accel_group(RefUIManager->get_accel_group());

    // Layout menubar
    Glib::ustring ui_info =
    "<ui>"
    "  <menubar name='MenuBar'>"
    "    <menu action='FileMenu'>"
    "      <menuitem action='FileNew'/>"
    "      <menuitem action='FileSave'/>"
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
    Gtk::MessageDialog Dialog(*this, "Logical condition", false, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_NONE);
    Dialog.set_secondary_text("Pick one, mothafucka");
    Dialog.add_button("AND", 0);
    Dialog.add_button("OR", 1);

    int Result = Dialog.run();
    
    if (Result < 0 || Result > 1)
        return;

    NotebookPage* pCurrent = (NotebookPage*)Notebook.get_nth_page(Notebook.get_current_page());
    NotebookPage* pNotebook = Gtk::manage(new NotebookPage(pCurrent, Result));
    Notebook.append_page(*pNotebook);
    Notebook.show_all_children();
}

void Application::OnDeleteConditionButtonClicked()
{
    if (Notebook.get_n_pages() > 1)
        Notebook.remove_page(Notebook.get_current_page());
}
