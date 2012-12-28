/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details. */

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
    NotebookPage* pPage = (NotebookPage*)Notebook.get_nth_page(Notebook.get_current_page());

    if (FileName || !SavedToDB)
        pPage->GetConditionData(Buffer, true);
    else
        pPage->GetConditionData(Buffer, false);

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

void Application::Quit()
{
    hide();
}
