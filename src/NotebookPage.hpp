/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details. */

#ifndef NOTEBOOK_PAGE_HPP
#define NOTEBOOK_PAGE_HPP

#include <gtkmm.h>

#include "ConditionsData.hpp"

class NotebookPage : public Gtk::HBox
{
    public:
        NotebookPage(NotebookPage* pPrev, int Result);

        void GetConditionData(char* Buffer, bool Flag);
        void ResetConditionData();

    private:
        ConditionsData Condition;
    
        // GUI Stuff
        Gtk::ComboBoxText SourceTypeOrReferenceIdCombo;
        Gtk::ComboBoxText ConditionTypeOrReferenceCombo;

        Gtk::Frame SourceFrame;
        Gtk::Frame ConditionFrame;
        Gtk::Frame MiscFrame;

        Gtk::Label SourceTypeOrReferenceIdLabel;
        Gtk::Label SourceGroupLabel;
        Gtk::Label SourceEntryLabel;
        Gtk::Label SourceIdLabel;
        Gtk::Label ElseGroupLabel;
        Gtk::Label ConditionTargetLabel;
        Gtk::Label ConditionValue1Label;
        Gtk::Label ConditionValue2Label;
        Gtk::Label ConditionValue3Label;
        Gtk::Label ErrorTextIdLabel;
        Gtk::Label ScriptNameLabel;
        Gtk::Label CommentLabel;

        Gtk::Entry SourceGroupEntry;
        Gtk::Entry SourceEntryEntry; // Lol'd
        Gtk::Entry SourceIdEntry;
        Gtk::Entry ElseGroupEntry;
        Gtk::Entry ConditionValue1Entry;
        Gtk::Entry ConditionValue2Entry;
        Gtk::Entry ConditionValue3Entry;
        Gtk::Entry ErrorTextIdEntry;
        Gtk::Entry ScriptNameEntry;
        Gtk::Entry CommentEntry;

        Gtk::RadioButton ConditionTargetButton1;
        Gtk::RadioButton ConditionTargetButton2;

        Gtk::CheckButton NegativeConditionButton;
        
        Gtk::Box SourceBox;
        Gtk::Box ConditionBox;
        Gtk::Box MiscBox;
        
        // Signal stuff
        void SourceTypeOrReferenceIdComboChanged();
        void ConditionTypeOrReferenceComboChanged();
        void ConditionValue1Changed();
        void ConditionValue2Changed();
        void ConditionValue3Changed();
        void NegativeConditionChanged();
        void ConditionTargetButton1Changed();
        void ConditionTargetButton2Changed();
        void SourceIdChanged();
        void SourceGroupChanged();
        void ElseGroupChanged();
        void ErrorTextIdChanged();
        void ScriptNameChanged();
        void CommentChanged();

        // Helper
        void SetConditionValueNull(uint8 Count);
};

#endif
