/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details. */

#include <cassert>

#include "Application.hpp"

void Application::SourceTypeOrReferenceIdComboChanged()
{
    Condition._SourceTypeOrReferenceId = SourceTypeOrReferenceIdCombo.get_active_row_number();

    if (Condition._SourceTypeOrReferenceId == CONDITION_SOURCE_TYPE_NONE ||
        Condition._SourceTypeOrReferenceId == CONDITION_SOURCE_TYPE_MAX)
    {
        // Reset
    }
    else if (Condition._SourceTypeOrReferenceId < 13)
    {
        SourceGroupLabel.set_text("Loot entry");
        SourceEntryLabel.set_text("Item ID");
        ConditionTargetButton1.set_active(); // TODO: Condition._ConditionTarget = 0;
        ConditionTargetButton1.set_label("0:");
        ConditionTargetButton2.set_label("1:");
    }
    else
    {
        switch (Condition._SourceTypeOrReferenceId)
        {
            case 13:
                SourceGroupLabel.set_text("Effect mask");
                SourceEntryLabel.set_text("Spell ID");
                ConditionTargetButton1.set_label("0: Spell Target");
                ConditionTargetButton2.set_label("1: Spell Caster");
                break;
            case 14:
                SourceGroupLabel.set_text("Gossip menu entry");
                SourceEntryLabel.set_text("Gossip menu text ID");
                ConditionTargetButton1.set_label("0: Player");
                ConditionTargetButton2.set_label("1: WorldObject");
                break;
            case 15:
                SourceGroupLabel.set_text("Gossip menu entry");
                SourceEntryLabel.set_text("Gossip menu option ID");
                ConditionTargetButton1.set_label("0: Player");
                ConditionTargetButton2.set_label("1: WorldObject");
                break;
            case 16:
                SourceGroupLabel.set_text("Always 0!");
                //SourceGroupEntry TODO: set to 0
                SourceEntryLabel.set_text("Creature entry");
                ConditionTargetButton1.set_label("0: Player");
                ConditionTargetButton2.set_label("1: Vehicle Creature");
                break;
            case 17:
                SourceGroupLabel.set_text("Always 0!");
                //SourceGroupEntry TODO: set to 0
                SourceEntryLabel.set_text("Spell ID");
                ConditionTargetButton1.set_label("0: Spell Caster");
                ConditionTargetButton2.set_label("1: Explicit Target");
                break;
            case 18:
                SourceGroupLabel.set_text("Creature entry");
                SourceEntryLabel.set_text("Spell ID");
                ConditionTargetButton1.set_label("0: Clicker");
                ConditionTargetButton2.set_label("1: Clickee");
                break;
            case 19:
                SourceEntryLabel.set_text("Quest ID");
                ConditionTargetButton1.set_active(); // TODO: Condition._ConditionTarget = 0;
                ConditionTargetButton1.set_label("0:");
                ConditionTargetButton2.set_label("1:");
                // SourceGroup: ? <--- 0?
                break;
            case 20:
                SourceEntryLabel.set_text("Quest ID");
                ConditionTargetButton1.set_active(); // TODO: Condition._ConditionTarget = 0;
                ConditionTargetButton1.set_label("0:");
                ConditionTargetButton2.set_label("1:");
                // SourceGroup: ? <--- 0?
                break;
            case 21:
                SourceGroupLabel.set_text("Creature entry");
                SourceEntryLabel.set_text("Spell ID");
                ConditionTargetButton1.set_label("0: Player");
                ConditionTargetButton2.set_label("1: Vehicle Creature");
                break;
            case 22:
                SourceGroupLabel.set_text("SmartScript ID");
                SourceEntryLabel.set_text("SmartScript EntryOrGuid");
                // TODO: SourceId: SourceType (smart_scripts.source_type)
                ConditionTargetButton1.set_label("0: Invoker");
                ConditionTargetButton2.set_label("1: Object");
                break;
            default:
                assert(false && "How the hell did you do this? Contact Krofna ASAP!");
                break;
        }
    }
};

void Application::ConditionTypeOrReferenceComboChanged()
{
    Condition._ConditionTypeOrReference = ConditionTypeOrReferenceCombo.get_active_row_number();
    
    switch (Condition._ConditionTypeOrReference)
    {
        case 0:
            // Reset
            break;
        case 1:
            break;
        default:
            assert(false && "How the hell did you do this? Contact Krofna ASAP!");
            break;
    }
}
