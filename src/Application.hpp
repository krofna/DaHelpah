/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details. */

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "NotebookPage.hpp"

class Application : public Gtk::Window
{
    public:
        Application();
        virtual ~Application();

    private:
        // DaHelpah stuff
        void Save();
        void _Save(const char* FileName);
        void Quit();
        void Reset();

        // GUI stuff
        Glib::RefPtr<Gtk::ActionGroup> RefActionGroup;
        Glib::RefPtr<Gtk::UIManager> RefUIManager;

        Gtk::Box MainBox;
        Gtk::Box ButtonBox;
        Gtk::Button NewConditionButton;
        Gtk::Button DeleteConditionButton;
        Gtk::Notebook Notebook;
        
        // Signal stuff
        void OnNewConditionButtonClicked();
        void OnDeleteConditionButtonClicked();
};

#endif
