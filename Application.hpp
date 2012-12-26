/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details. */
 
#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <gtkmm.h>

#include "ConditionsData.hpp"

class Application : public Gtk::Window
{
    public:
        Application();
        virtual ~Application();
    
    protected:
    
    private:
        // DaHelpah stuff
        void SaveToDB();
        void SaveToFile();
        void _Save(const char* FileName);
        void Reset();
        void Quit();

        bool SavedToDB;
        ConditionsData Condition;
        
        // GUI stuff
        Gtk::Box Box;
        Glib::RefPtr<Gtk::ActionGroup> RefActionGroup;
        Glib::RefPtr<Gtk::UIManager> RefUIManager;
        
        Gtk::ComboBoxText SourceTypeOrReferenceIdCombo;
        
        // Signal stuff
        void SourceTypeOrReferenceIdComboChanged();
};

#endif
