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
        // TODO: Reset
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
            case CONDITION_SOURCE_TYPE_SPELL_IMPLICIT_TARGET:
                SourceGroupLabel.set_text("Effect mask");
                SourceEntryLabel.set_text("Spell ID");
                ConditionTargetButton1.set_label("0: Spell Target");
                ConditionTargetButton2.set_label("1: Spell Caster");
                break;
            case CONDITION_SOURCE_TYPE_GOSSIP_MENU:
                SourceGroupLabel.set_text("Gossip menu entry");
                SourceEntryLabel.set_text("Gossip menu text ID");
                ConditionTargetButton1.set_label("0: Player");
                ConditionTargetButton2.set_label("1: WorldObject");
                break;
            case CONDITION_SOURCE_TYPE_GOSSIP_MENU_OPTION:
                SourceGroupLabel.set_text("Gossip menu entry");
                SourceEntryLabel.set_text("Gossip menu option ID");
                ConditionTargetButton1.set_label("0: Player");
                ConditionTargetButton2.set_label("1: WorldObject");
                break;
            case CONDITION_SOURCE_TYPE_CREATURE_TEMPLATE_VEHICLE:
                SourceGroupLabel.set_text("Always 0!");
                SourceGroupEntry.set_text("0"); // TODO: Always 0
                SourceEntryLabel.set_text("Creature entry");
                ConditionTargetButton1.set_label("0: Player");
                ConditionTargetButton2.set_label("1: Vehicle Creature");
                break;
            case CONDITION_SOURCE_TYPE_SPELL:
                SourceGroupLabel.set_text("Always 0!");
                SourceGroupEntry.set_text("0"); // TODO: Always 0
                SourceEntryLabel.set_text("Spell ID");
                ConditionTargetButton1.set_label("0: Spell Caster");
                ConditionTargetButton2.set_label("1: Explicit Target");
                break;
            case CONDITION_SOURCE_TYPE_SPELL_CLICK_EVENT:
                SourceGroupLabel.set_text("Creature entry");
                SourceEntryLabel.set_text("Spell ID");
                ConditionTargetButton1.set_label("0: Clicker");
                ConditionTargetButton2.set_label("1: Clickee");
                break;
            case CONDITION_SOURCE_TYPE_QUEST_ACCEPT:
                SourceEntryLabel.set_text("Quest ID");
                ConditionTargetButton1.set_active(); // TODO: Condition._ConditionTarget = 0;
                ConditionTargetButton1.set_label("0:");
                ConditionTargetButton2.set_label("1:");
                // SourceGroup: ? <--- 0?
                break;
            case CONDITION_SOURCE_TYPE_QUEST_SHOW_MARK:
                SourceEntryLabel.set_text("Quest ID");
                ConditionTargetButton1.set_active(); // TODO: Condition._ConditionTarget = 0;
                ConditionTargetButton1.set_label("0:");
                ConditionTargetButton2.set_label("1:");
                // SourceGroup: ? <--- 0?
                break;
            case CONDITION_SOURCE_TYPE_VEHICLE_SPELL:
                SourceGroupLabel.set_text("Creature entry");
                SourceEntryLabel.set_text("Spell ID");
                ConditionTargetButton1.set_label("0: Player");
                ConditionTargetButton2.set_label("1: Vehicle Creature");
                break;
            case CONDITION_SOURCE_TYPE_SMART_EVENT:
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
}

void Application::SetConditionTypeNull(uint8 Count)
{
    if (Count)
    {
        ConditionValue3Label.set_text("Always 0!");
        ConditionValue3Entry.set_text("0");
        ConditionValue3Entry.set_editable(false);
        --Count;
    }
    else
        ConditionValue3Entry.set_editable(true);
    
    if (Count)
    {
        ConditionValue2Label.set_text("Always 0!");
        ConditionValue2Entry.set_text("0");
        ConditionValue2Entry.set_editable(false);
        --Count;
    }
    else
        ConditionValue2Entry.set_editable(true);

    if (Count)
    {
        ConditionValue1Label.set_text("Always 0!");
        ConditionValue1Entry.set_text("0");
        ConditionValue1Entry.set_editable(false);
    }
    else
        ConditionValue1Entry.set_editable(true);
}

void Application::ConditionTypeOrReferenceComboChanged()
{
    Condition._ConditionTypeOrReference = ConditionTypeOrReferenceCombo.get_active_row_number();
    
    switch (Condition._ConditionTypeOrReference)
    {
        case 0:
            SetConditionTypeNull(3);
            break;
        case CONDITION_AURA:
            ConditionValue1Label.set_text("Spell ID");
            ConditionValue2Label.set_text("Effect index (0-2)");
            SetConditionTypeNull(1);
            break;
        case CONDITION_ITEM:
            ConditionValue1Label.set_text("Item entry");
            ConditionValue2Label.set_text("Item count");
            ConditionValue3Label.set_text("In bank (0/1)");
            break;
        case CONDITION_ITEM_EQUIPPED:
            ConditionValue1Label.set_text("Item entry");
            SetConditionTypeNull(2);
            break;
        case CONDITION_ZONEID:
            ConditionValue1Label.set_text("Zone ID");
            SetConditionTypeNull(2);
            break;
        case CONDITION_REPUTATION_RANK:
            ConditionValue1Label.set_text("Faction template ID");
            ConditionValue2Label.set_text("Rank");
            SetConditionTypeNull(1);
            break;
        case CONDITION_TEAM:
            ConditionValue1Label.set_text("Team ID (A: 469/ H:67)");
            SetConditionTypeNull(2);
            break;
        case CONDITION_SKILL:
            ConditionValue1Label.set_text("Skill required");
            ConditionValue2Label.set_text("Skill value");
            SetConditionTypeNull(1);
            break;
        case CONDITION_QUESTREWARDED:
            ConditionValue1Label.set_text("Quest ID");
            SetConditionTypeNull(2);
            break;
        case CONDITION_QUESTTAKEN:
            ConditionValue1Label.set_text("Quest ID");
            SetConditionTypeNull(2);
            break;
        case CONDITION_DRUNKENSTATE:
            ConditionValue1Label.set_text("Drunken state (0-3)");
            SetConditionTypeNull(2);
            break;
        case CONDITION_WORLD_STATE:
            ConditionValue1Label.set_text("World state index");
            ConditionValue2Label.set_text("World state value");
            SetConditionTypeNull(1);
            break;
        case CONDITION_ACTIVE_EVENT:
            ConditionValue1Label.set_text("Event entry");
            SetConditionTypeNull(2);
            break;
        case CONDITION_INSTANCE_DATA:            
            ConditionValue1Label.set_text("Entry");
            ConditionValue2Label.set_text("Data");
            SetConditionTypeNull(1);
            break;
        case CONDITION_QUEST_NONE:
            ConditionValue1Label.set_text("Quest ID");
            SetConditionTypeNull(2);
            break;
        case CONDITION_CLASS:
            ConditionValue1Label.set_text("Class ID");
            SetConditionTypeNull(2);
            break;
        case CONDITION_RACE:
            ConditionValue1Label.set_text("Race");
            SetConditionTypeNull(2);
            break;
        case CONDITION_ACHIEVEMENT:
            ConditionValue1Label.set_text("Achievement ID");
            SetConditionTypeNull(2);
            break;
        case CONDITION_TITLE:
            ConditionValue1Label.set_text("Title ID");
            SetConditionTypeNull(2);
            break;
        case CONDITION_SPAWNMASK:
            ConditionValue1Label.set_text("SpawnMask");
            SetConditionTypeNull(2);
            break;
        case CONDITION_GENDER:
            SetConditionTypeNull(3);
            break;
        case CONDITION_UNUSED_21:
            // TODO
            break;
        case CONDITION_MAPID:
            ConditionValue1Label.set_text("Map entry");
            SetConditionTypeNull(2);
            break;
        case CONDITION_AREAID:
            ConditionValue1Label.set_text("Area ID");
            SetConditionTypeNull(2);
            break;
        case CONDITION_UNUSED_24:
            // TODO
            break;
        case CONDITION_SPELL:
            ConditionValue1Label.set_text("Spell ID");
            SetConditionTypeNull(2);
            break;
        case CONDITION_PHASEMASK:
            ConditionValue1Label.set_text("PhaseMask value");
            SetConditionTypeNull(2);
            break;
        case CONDITION_LEVEL:
            ConditionValue1Label.set_text("Player level");
            ConditionValue2Label.set_text("==,>,<,>=,<= (0-4)");
            SetConditionTypeNull(1);
            break;
        case CONDITION_QUEST_COMPLETE:
            ConditionValue1Label.set_text("Quest ID");
            SetConditionTypeNull(2);
            break;
        case CONDITION_NEAR_CREATURE:
            ConditionValue1Label.set_text("Creature entry");
            ConditionValue2Label.set_text("Distance in yards");
            SetConditionTypeNull(1);
            break;
        case CONDITION_NEAR_GAMEOBJECT:
            ConditionValue1Label.set_text("Gameobject entry");
            ConditionValue2Label.set_text("Distance in yards");
            SetConditionTypeNull(1);
            break;
        case CONDITION_OBJECT_ENTRY:
            ConditionValue1Label.set_text("Type ID (U:3 P:4 GO:5 CORPSE:7");
            ConditionValue2Label.set_text("Creature/GO Entry (0: Any)");
            SetConditionTypeNull(1);
            break;
        case CONDITION_TYPE_MASK:
            ConditionValue1Label.set_text("TypeMask (TODO: tooltip)");
            SetConditionTypeNull(2);
            break;
        case CONDITION_RELATION_TO:
            ConditionValue1Label.set_text("?? TODO: Krofna doesn't get this one");
            ConditionValue2Label.set_text("Relation type TOOLTIP PLZ");
            SetConditionTypeNull(1);
        
            ConditionValue1: target to which relation is checked - one of ConditionTargets available in current SourceType.
    ConditionValue2: RelationType - defines relation of current ConditionTarget to target specified in ConditionValue1.
        0 - RELATION_SELF
        1 - RELATION_IN_PARTY
        2 - RELATION_IN_RAID_OR_PARTY
        3 - RELATION_OWNED_BY (ConditionTarget is owned by ConditionValue1)
        4 - RELATION_PASSENGER_OF (ConditionTarget is passenger of ConditionValue1)
        5 - RELATION_CREATED_BY (ConditionTarget is summoned by ConditionValue1) 
    ConditionValue3: always 0 
            break;
        case CONDITION_REACTION_TO:
        case CONDITION_DISTANCE_TO:
        case CONDITION_ALIVE:
        case CONDITION_HP_VAL:
        case CONDITION_HP_PCT:
            break;
        default:
            assert(false && "How the hell did you do this? Contact Krofna ASAP!");
            break;
    }
}
