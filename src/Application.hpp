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
        Gtk::ComboBoxText ConditionTypeOrReferenceCombo;

        Gtk::Frame SourceFrame;
        Gtk::Frame ConditionFrame;

        Gtk::Label SourceGroupLabel;
        Gtk::Label SourceEntryLabel;
        Gtk::Label ConditionTargetLabel;
        Gtk::Label ConditionValue1Label;
        Gtk::Label ConditionValue2Label;
        Gtk::Label ConditionValue3Label;

        Gtk::Entry SourceGroupEntry;
        Gtk::Entry SourceEntryEntry; // Lol'd
        Gtk::Entry ConditionValue1Entry;
        Gtk::Entry ConditionValue2Entry;
        Gtk::Entry ConditionValue3Entry;

        Gtk::RadioButton ConditionTargetButton1;
        Gtk::RadioButton ConditionTargetButton2;

        Gtk::CheckButton NegativeConditionButton;
        
        // Signal stuff
        void SourceTypeOrReferenceIdComboChanged();
        void ConditionTypeOrReferenceComboChanged();
};

#endif
