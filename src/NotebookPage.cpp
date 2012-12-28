/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details. */

#include <cstdio>
#include <cstring>

#include "NotebookPage.hpp"
#include "ConditionsString.hpp"

NotebookPage::NotebookPage() :
SourceBox                 (Gtk::ORIENTATION_VERTICAL),
ConditionBox              (Gtk::ORIENTATION_VERTICAL),
MiscBox                   (Gtk::ORIENTATION_VERTICAL),
SourceGroupLabel          ("Source Group"),
SourceEntryLabel          ("Source Entry"),
SourceIdLabel             ("Source ID"),
ElseGroupLabel            ("Else Group"),
ConditionTargetLabel      ("Condition Target"),
ConditionValue1Label      ("Condition Value 1"),
ConditionValue2Label      ("Condition Value 2"),
ConditionValue3Label      ("Condition Value 3"),
ErrorTextIdLabel          ("Error Text ID"),
ScriptNameLabel           ("ScriptName"),
CommentLabel              ("Comment"),
ConditionTargetButton1    ("0:"),
ConditionTargetButton2    ("1:"),
SourceFrame               ("Source"),
ConditionFrame            ("Conditions"),
MiscFrame                 ("Misc"),
NegativeConditionButton   ("Invert condition?"),
SourceTypeOrReferenceIdLabel("Source Type or Reference ID"),
SourceTypeOrReferenceIdCombo(true),
ConditionTypeOrReferenceCombo(true)
{
    // Zero out data
    ResetConditionData();

    // Frames
    SourceFrame.set_border_width(5);
    ConditionFrame.set_border_width(5);
    MiscFrame.set_border_width(5);
    pack_start(SourceFrame);
    pack_start(ConditionFrame);
    pack_start(MiscFrame);
    SourceFrame.add(SourceBox);
    ConditionFrame.add(ConditionBox);
    MiscFrame.add(MiscBox);

    // SourceTypeOrReferenceId
    for (uint8 i = 0; SourceTypeOrReferenceIdString[i]; ++i)
        SourceTypeOrReferenceIdCombo.append(SourceTypeOrReferenceIdString[i]);

    SourceTypeOrReferenceIdCombo.set_active(0);
    SourceTypeOrReferenceIdCombo.signal_changed().connect(sigc::mem_fun(*this, &NotebookPage::SourceTypeOrReferenceIdComboChanged));
    SourceBox.pack_start(SourceTypeOrReferenceIdLabel);
    SourceBox.pack_start(SourceTypeOrReferenceIdCombo);

    // ConditionTypeOrReference
    for (uint8 i = 0; ConditionTypeOrReferenceString[i]; ++i)
        ConditionTypeOrReferenceCombo.append(ConditionTypeOrReferenceString[i]);

    ConditionTypeOrReferenceCombo.set_active(0);
    ConditionTypeOrReferenceCombo.signal_changed().connect(sigc::mem_fun(*this, &NotebookPage::ConditionTypeOrReferenceComboChanged));
    ConditionBox.pack_start(ConditionTypeOrReferenceCombo);

    // Source Group
    SourceGroupEntry.signal_changed().connect(sigc::mem_fun(*this, &NotebookPage::SourceGroupChanged));

    SourceBox.pack_start(SourceGroupLabel);
    SourceBox.pack_start(SourceGroupEntry);

    // Condition Target
    ConditionTargetButton1.signal_clicked().connect(sigc::mem_fun(*this, &NotebookPage::ConditionTargetButton1Changed));
    ConditionTargetButton2.signal_clicked().connect(sigc::mem_fun(*this, &NotebookPage::ConditionTargetButton2Changed));
    
    Gtk::RadioButton::Group Group = ConditionTargetButton1.get_group();
    ConditionTargetButton2.set_group(Group);

    ConditionBox.pack_start(ConditionTargetLabel);
    ConditionBox.pack_start(ConditionTargetButton1);
    ConditionBox.pack_start(ConditionTargetButton2);

    // Condition Value
    ConditionValue1Entry.signal_changed().connect(sigc::mem_fun(*this, &NotebookPage::ConditionValue1Changed));
    ConditionValue2Entry.signal_changed().connect(sigc::mem_fun(*this, &NotebookPage::ConditionValue2Changed));
    ConditionValue3Entry.signal_changed().connect(sigc::mem_fun(*this, &NotebookPage::ConditionValue3Changed));

    ConditionBox.pack_start(ConditionValue1Label);
    ConditionBox.pack_start(ConditionValue1Entry);
    ConditionBox.pack_start(ConditionValue2Label);
    ConditionBox.pack_start(ConditionValue2Entry);
    ConditionBox.pack_start(ConditionValue3Label);
    ConditionBox.pack_start(ConditionValue3Entry);
    
    // Negative condition
    NegativeConditionButton.signal_clicked().connect(sigc::mem_fun(*this, &NotebookPage::NegativeConditionChanged));
    ConditionBox.pack_start(NegativeConditionButton);
    
    // Source Id
    SourceIdEntry.signal_changed().connect(sigc::mem_fun(*this, &NotebookPage::SourceIdChanged));

    SourceBox.pack_start(SourceIdLabel);
    SourceBox.pack_start(SourceIdEntry);
    
    // Else Group
    ElseGroupEntry.signal_changed().connect(sigc::mem_fun(*this, &NotebookPage::ElseGroupChanged));
    
    SourceBox.pack_start(ElseGroupLabel);
    SourceBox.pack_start(ElseGroupEntry);
    
    // Error Text Id
    ErrorTextIdEntry.signal_changed().connect(sigc::mem_fun(*this, &NotebookPage::ErrorTextIdChanged));
    
    MiscBox.pack_start(ErrorTextIdLabel);
    MiscBox.pack_start(ErrorTextIdEntry);
    
    // Script Name
    ScriptNameEntry.signal_changed().connect(sigc::mem_fun(*this, &NotebookPage::ScriptNameChanged));
    
    MiscBox.pack_start(ScriptNameLabel);
    MiscBox.pack_start(ScriptNameEntry);
    
    // Comment
    CommentEntry.signal_changed().connect(sigc::mem_fun(*this, &NotebookPage::CommentChanged));
    
    MiscBox.pack_start(CommentLabel);
    MiscBox.pack_start(CommentEntry);
}

void NotebookPage::GetConditionData(char* Buffer, bool Flag)
{
    if (Flag)
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
}

void NotebookPage::ResetConditionData()
{
    std::memset(&Condition, 0, sizeof(ConditionsData) - 2 * sizeof(std::string));
}
