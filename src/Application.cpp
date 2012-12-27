/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details. */

#include <iostream>

#include "Application.hpp"
#include "ConditionsString.hpp"

Application::Application() :
SavedToDB               (false),
MainBox                 (Gtk::ORIENTATION_VERTICAL),
Box                     (Gtk::ORIENTATION_HORIZONTAL),
SourceBox               (Gtk::ORIENTATION_VERTICAL),
ConditionBox            (Gtk::ORIENTATION_VERTICAL),
MiscBox                 (Gtk::ORIENTATION_VERTICAL),
SourceGroupLabel        ("Source Group"),
SourceEntryLabel        ("Source Entry"),
SourceIdLabel           ("Source ID"),
ElseGroupLabel          ("Else Group"),
ConditionTargetLabel    ("Condition Target"),
ConditionValue1Label    ("Condition Value 1"),
ConditionValue2Label    ("Condition Value 2"),
ConditionValue3Label    ("Condition Value 3"),
ErrorTextIdLabel        ("Error Text ID"),
ScriptNameLabel         ("ScriptName"),
CommentLabel            ("Comment"),
ConditionTargetButton1  ("0:"),
ConditionTargetButton2  ("1:"),
SourceFrame             ("Source"),
ConditionFrame          ("Conditions"),
MiscFrame               ("Misc"),
NegativeConditionButton ("Invert condition?"),
NewConditionButton      ("New Condition"),
SourceTypeOrReferenceIdLabel("Source Type or Reference ID"),
SourceTypeOrReferenceIdCombo(true),
ConditionTypeOrReferenceCombo(true)
{
    WorldDatabase.Connect();
    ResetConditionData();
    
    // Frames
    SourceFrame.set_border_width(5);
    ConditionFrame.set_border_width(5);
    MiscFrame.set_border_width(5);
    Box.pack_start(SourceFrame);
    Box.pack_start(ConditionFrame);
    Box.pack_start(MiscFrame);
    SourceFrame.add(SourceBox);
    ConditionFrame.add(ConditionBox);
    MiscFrame.add(MiscBox);

    // SourceTypeOrReferenceId
    for (uint8 i = 0; SourceTypeOrReferenceIdString[i]; ++i)
        SourceTypeOrReferenceIdCombo.append(SourceTypeOrReferenceIdString[i]);

    SourceTypeOrReferenceIdCombo.set_active(0);
    SourceTypeOrReferenceIdCombo.signal_changed().connect(sigc::mem_fun(*this, &Application::SourceTypeOrReferenceIdComboChanged));
    SourceBox.pack_start(SourceTypeOrReferenceIdLabel);
    SourceBox.pack_start(SourceTypeOrReferenceIdCombo);

    // ConditionTypeOrReference
    for (uint8 i = 0; ConditionTypeOrReferenceString[i]; ++i)
        ConditionTypeOrReferenceCombo.append(ConditionTypeOrReferenceString[i]);

    ConditionTypeOrReferenceCombo.set_active(0);
    ConditionTypeOrReferenceCombo.signal_changed().connect(sigc::mem_fun(*this, &Application::ConditionTypeOrReferenceComboChanged));
    ConditionBox.pack_start(ConditionTypeOrReferenceCombo);

    // Source Group
    SourceGroupEntry.signal_changed().connect(sigc::mem_fun(*this, &Application::SourceGroupChanged));

    SourceBox.pack_start(SourceGroupLabel);
    SourceBox.pack_start(SourceGroupEntry);

    // Condition Target
    ConditionTargetButton1.signal_clicked().connect(sigc::mem_fun(*this, &Application::ConditionTargetButton1Changed));
    ConditionTargetButton2.signal_clicked().connect(sigc::mem_fun(*this, &Application::ConditionTargetButton2Changed));
    
    Gtk::RadioButton::Group Group = ConditionTargetButton1.get_group();
    ConditionTargetButton2.set_group(Group);

    ConditionBox.pack_start(ConditionTargetLabel);
    ConditionBox.pack_start(ConditionTargetButton1);
    ConditionBox.pack_start(ConditionTargetButton2);

    // Condition Value
    ConditionValue1Entry.signal_changed().connect(sigc::mem_fun(*this, &Application::ConditionValue1Changed));
    ConditionValue2Entry.signal_changed().connect(sigc::mem_fun(*this, &Application::ConditionValue2Changed));
    ConditionValue3Entry.signal_changed().connect(sigc::mem_fun(*this, &Application::ConditionValue3Changed));

    ConditionBox.pack_start(ConditionValue1Label);
    ConditionBox.pack_start(ConditionValue1Entry);
    ConditionBox.pack_start(ConditionValue2Label);
    ConditionBox.pack_start(ConditionValue2Entry);
    ConditionBox.pack_start(ConditionValue3Label);
    ConditionBox.pack_start(ConditionValue3Entry);
    
    // Negative condition
    NegativeConditionButton.signal_clicked().connect(sigc::mem_fun(*this, &Application::NegativeConditionChanged));
    ConditionBox.pack_start(NegativeConditionButton);
    
    // Source Id
    SourceIdEntry.signal_changed().connect(sigc::mem_fun(*this, &Application::SourceIdChanged));

    SourceBox.pack_start(SourceIdLabel);
    SourceBox.pack_start(SourceIdEntry);
    
    // Else Group
    ElseGroupEntry.signal_changed().connect(sigc::mem_fun(*this, &Application::ElseGroupChanged));
    
    SourceBox.pack_start(ElseGroupLabel);
    SourceBox.pack_start(ElseGroupEntry);
    
    // Error Text Id
    ErrorTextIdEntry.signal_changed().connect(sigc::mem_fun(*this, &Application::ErrorTextIdChanged));
    
    MiscBox.pack_start(ErrorTextIdLabel);
    MiscBox.pack_start(ErrorTextIdEntry);
    
    // Script Name
    ScriptNameEntry.signal_changed().connect(sigc::mem_fun(*this, &Application::ScriptNameChanged));
    
    MiscBox.pack_start(ScriptNameLabel);
    MiscBox.pack_start(ScriptNameEntry);
    
    // Comment
    CommentEntry.signal_changed().connect(sigc::mem_fun(*this, &Application::CommentChanged));
    
    MiscBox.pack_start(CommentLabel);
    MiscBox.pack_start(CommentEntry);

    // Window
    MainBox.pack_start(Box);
    add(MainBox);
    set_border_width(5);
    set_title("DaHelpah");
    RefActionGroup = Gtk::ActionGroup::create();
    
    // New Condition
    MainBox.pack_start(NewConditionButton);

    // File
    RefActionGroup->add(Gtk::Action::create("FileMenu", "File"));

    // File->
    RefActionGroup->add(Gtk::Action::create("FileNew", Gtk::Stock::NEW),
          sigc::mem_fun(*this, &Application::ResetConditionData));
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
        Box.pack_start(*pMenubar, Gtk::PACK_SHRINK);

    show_all_children();
}

Application::~Application()
{
}
