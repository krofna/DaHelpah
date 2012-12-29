/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details. */

#include <fstream>

#include "Application.hpp"

void Application::Save()
{
    Gtk::FileChooserDialog Dialog("Dump da sql, mon.", Gtk::FILE_CHOOSER_ACTION_SAVE);
    Dialog.set_transient_for(*this);
    Dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
    Dialog.add_button("Save", Gtk::RESPONSE_OK);

    if (Dialog.run() == Gtk::RESPONSE_OK)
        _Save(Dialog.get_filename().c_str());
}

void Application::_Save(const char* FileName)
{
    char Buffer[2048];
    std::ofstream SqlDump(FileName);
    
    SqlDump << "INSERT INTO `conditions` VALUES\n";

    for (int i = 0; i != Notebook.get_n_pages(); ++i)
    {
        ((NotebookPage*)Notebook.get_nth_page(i))->GetConditionData(Buffer, true);
        SqlDump << Buffer << (i == (Notebook.get_n_pages() - 1) ? ';' : ',') << '\n';
    }
}

void Application::Quit()
{
    hide();
}
