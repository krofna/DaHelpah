/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details. */

#include <cassert>

#include "Application.hpp"
#include "ConditionsEnum.hpp"

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
            ConditionValue1Label.set_text("Spell ID");
            ConditionValue2Label.set_text("Effect index (0-2)");
            ConditionValue3Label.set_text("Always 0!!");
            // ConditionValue3Entry TODO : set 0
            break;
        case 2:
            ConditionValue1Label.set_text("Item entry");
            ConditionValue2Label.set_text("Item count");
            ConditionValue3Label.set_text("In bank (0/1)");
            break;
        case 3:
            ConditionValue1Label.set_text("Item entry");
            ConditionValue2Label.set_text("Always 0!!");
            ConditionValue3Label.set_text("Always 0!!");
            // TODO: Set 2/3 to 0!
            break;
        case 4:
            ConditionValue1Label.set_text("Zone ID");
            ConditionValue2Label.set_text("Always 0!!");
            ConditionValue3Label.set_text("Always 0!!");
            // TODO: Set 2/3 to 0!
            break;
        case 5:
            ConditionValue1Label.set_text("Faction template ID");
            ConditionValue2Label.set_text("Rank");
            ConditionValue3Label.set_text("Always 0!!");
            // TODO: Set 3 to 0!
            break;
        case 6:
            ConditionValue1Label.set_text("Team ID (A: 469/ H:67)");
            ConditionValue2Label.set_text("Always 0!!");
            ConditionValue3Label.set_text("Always 0!!");
            // TODO: Set 2/3 to 0!
            break;
        case 7:
            ConditionValue1Label.set_text("Skill required");
            ConditionValue2Label.set_text("Skill value");
            ConditionValue3Label.set_text("Always 0!!");
            // TODO: Set 3 to 0!
            break;
        case 8:
            ConditionValue1Label.set_text("Quest ID");
            ConditionValue2Label.set_text("Always 0!!");
            ConditionValue3Label.set_text("Always 0!!");
            // TODO: Set 2/3 to 0!
            break;
        case 9:
            ConditionValue1Label.set_text("Quest ID");
            ConditionValue2Label.set_text("Always 0!!");
            ConditionValue3Label.set_text("Always 0!!");
            // TODO: Set 2/3 to 0!
            break;
        case 10:
            ConditionValue1Label.set_text("Drunken state (0-3)");
            ConditionValue2Label.set_text("Always 0!!");
            ConditionValue3Label.set_text("Always 0!!");
            // TODO: Set 2/3 to 0!
            break;
        case 11:
            ConditionValue1Label.set_text("World state index");
            ConditionValue2Label.set_text("World state value");
            ConditionValue3Label.set_text("Always 0!!");
            // TODO: Set 3 to 0!
            break;
        case 12:
            ConditionValue1Label.set_text("Event entry");
            ConditionValue2Label.set_text("Always 0!!");
            ConditionValue3Label.set_text("Always 0!!");
            // TODO: Set 2/3 to 0!
            break;
        case 13:            
            ConditionValue1Label.set_text("Entry");
            ConditionValue2Label.set_text("Data");
            ConditionValue3Label.set_text("Always 0!!");
            // TODO: Set 3 to 0!
            break;
        case 14:
            ConditionValue1Label.set_text("Quest ID");
            ConditionValue2Label.set_text("Always 0!!");
            ConditionValue3Label.set_text("Always 0!!");
            // TODO: Set 2/3 to 0!
            break;
        case 15:
            ConditionValue1Label.set_text("Class ID");
            ConditionValue2Label.set_text("Always 0!!");
            ConditionValue3Label.set_text("Always 0!!");
            // TODO: Set 2/3 to 0!
            break;
        case 16:
            ConditionValue1Label.set_text("Race");
            ConditionValue2Label.set_text("Always 0!!");
            ConditionValue3Label.set_text("Always 0!!");
            // TODO: Set 2/3 to 0!
            break;
        case 17:
            ConditionValue1Label.set_text("Achievement ID");
            ConditionValue2Label.set_text("Always 0!!");
            ConditionValue3Label.set_text("Always 0!!");
            // TODO: Set 2/3 to 0!
            break;
        case 18:
            ConditionValue1Label.set_text("Title ID");
            ConditionValue2Label.set_text("Always 0!!");
            ConditionValue3Label.set_text("Always 0!!");
            // TODO: Set 2/3 to 0!
            break;
        case 19:
            ConditionValue1Label.set_text("Spawn Mask");
            ConditionValue2Label.set_text("Always 0!!");
            ConditionValue3Label.set_text("Always 0!!");
            // TODO: Set 2/3 to 0!
            break;
        case 20:
        case 21:
            // TODO: goto case 0
            break;
        case 22:
            ConditionValue1Label.set_text("Map entry");
            ConditionValue2Label.set_text("Always 0!!");
            ConditionValue3Label.set_text("Always 0!!");
            // TODO: Set 2/3 to 0!
            break;
        case 23:
            ConditionValue1Label.set_text("Area ID");
            ConditionValue2Label.set_text("Always 0!!");
            ConditionValue3Label.set_text("Always 0!!");
            // TODO: Set 2/3 to 0!
            break;
        default:
            assert(false && "How the hell did you do this? Contact Krofna ASAP!");
            break;
    }
}
