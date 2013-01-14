/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details. */

#include <cassert>

#include "NotebookPage.hpp"
#include "ConditionsEnum.hpp"

void NotebookPage::SourceTypeOrReferenceIdComboChanged()
{
    Condition._SourceTypeOrReferenceId = SourceTypeOrReferenceIdCombo.get_active_row_number();
    
    SourceGroupEntry.set_editable(true);
    SourceIdEntry.set_editable(false);

    if (Condition._SourceTypeOrReferenceId == CONDITION_SOURCE_TYPE_NONE ||
        Condition._SourceTypeOrReferenceId == CONDITION_SOURCE_TYPE_MAX)
    {
        SetConditionValueNull(3);
    }
    else if (Condition._SourceTypeOrReferenceId < 13)
    {
        SourceGroupLabel.set_text("Loot entry");
        SourceEntryLabel.set_text("Item ID");
        ConditionTargetButton1.set_active();
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
                SetSourceGroupNull();
                SourceEntryLabel.set_text("Creature entry");
                ConditionTargetButton1.set_label("0: Player");
                ConditionTargetButton2.set_label("1: Vehicle Creature");
                break;
            case CONDITION_SOURCE_TYPE_SPELL:
                SetSourceGroupNull();
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
                ConditionTargetButton1.set_active();
                ConditionTargetButton1.set_label("0:");
                ConditionTargetButton2.set_label("1:");
                SetSourceGroupNull();
                break;
            case CONDITION_SOURCE_TYPE_QUEST_SHOW_MARK:
                SourceEntryLabel.set_text("Quest ID");
                ConditionTargetButton1.set_active();
                ConditionTargetButton1.set_label("0:");
                ConditionTargetButton2.set_label("1:");
                SetSourceGroupNull();
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
                SourceIdEntry.set_editable(true);
                SourceIdLabel.set_text("Source ID");
                SourceIdEntry.set_tooltip_text("SAI Source Type:\n"
                                               "0: Creature\n"
                                               "1: Gameobject\n"
                                               "2: Areatrigger\n"
                                               "9: Timed Actionlist");
                ConditionTargetButton1.set_label("0: Invoker");
                ConditionTargetButton2.set_label("1: Object");
                break;
            case CONDITION_SOURCE_TYPE_NPC_VENDOR:
                SourceGroupLabel.set_text("Creature entry");
                SourceGroupEntry.set_tooltip_text("Vendor entry");
                SourceEntryLabel.set_text("Item ID");
                ConditionTargetButton1.set_label("0:");
                ConditionTargetButton2.set_label("1:");
                break;
            default:
                assert(false && "How the hell did you do this? Contact Krofna ASAP!");
                break;
        }
    }
}

void NotebookPage::SetSourceGroupNull()
{
    SourceGroupLabel.set_text("Source Group");
    SourceGroupEntry.set_text("0");
    SourceGroupEntry.set_editable(false);
}

void NotebookPage::SetConditionValueNull(uint8 Count)
{
    if (Count)
    {
        ConditionValue3Label.set_text("Condition Value 3");
        ConditionValue3Entry.set_text("0");
        ConditionValue3Entry.set_editable(false);
        --Count;
    }
    else
        ConditionValue3Entry.set_editable(true);

    if (Count)
    {
        ConditionValue2Label.set_text("Condition Value 2");
        ConditionValue2Entry.set_text("0");
        ConditionValue2Entry.set_editable(false);
        --Count;
    }
    else
        ConditionValue2Entry.set_editable(true);

    if (Count)
    {
        ConditionValue1Label.set_text("Condition Value 1");
        ConditionValue1Entry.set_text("0");
        ConditionValue1Entry.set_editable(false);
    }
    else
        ConditionValue1Entry.set_editable(true);
}

void NotebookPage::ConditionTypeOrReferenceComboChanged()
{
    Condition._ConditionTypeOrReference = ConditionTypeOrReferenceCombo.get_active_row_number();

    switch (Condition._ConditionTypeOrReference)
    {
        case 0:
            SetConditionValueNull(3);
            break;
        case CONDITION_AURA:
            ConditionValue1Label.set_text("Spell ID");
            ConditionValue2Label.set_text("Effect index");
            ConditionValue2Entry.set_tooltip_text("0-2, don't use wowhead");
            SetConditionValueNull(1);
            break;
        case CONDITION_ITEM:
            ConditionValue1Label.set_text("Item entry");
            ConditionValue2Label.set_text("Item count");
            ConditionValue3Label.set_text("In bank");
            ConditionValue3Entry.set_tooltip_text("0: False\n"
                                                  "1: True");
            break;
        case CONDITION_ITEM_EQUIPPED:
            ConditionValue1Label.set_text("Item entry");
            SetConditionValueNull(2);
            break;
        case CONDITION_ZONEID:
            ConditionValue1Label.set_text("Zone ID");
            SetConditionValueNull(2);
            break;
        case CONDITION_REPUTATION_RANK:
            ConditionValue1Label.set_text("Faction template ID");
            ConditionValue2Label.set_text("Rank");
            SetConditionValueNull(1);
            break;
        case CONDITION_TEAM:
            ConditionValue1Label.set_text("Team ID");
            ConditionValue1Entry.set_tooltip_text("469: Alliance\n"
                                                  "67: Horde");
            SetConditionValueNull(2);
            break;
        case CONDITION_SKILL:
            ConditionValue1Label.set_text("Skill required");
            ConditionValue2Label.set_text("Skill value");
            SetConditionValueNull(1);
            break;
        case CONDITION_QUESTREWARDED:
            ConditionValue1Label.set_text("Quest ID");
            SetConditionValueNull(2);
            break;
        case CONDITION_QUESTTAKEN:
            ConditionValue1Label.set_text("Quest ID");
            SetConditionValueNull(2);
            break;
        case CONDITION_DRUNKENSTATE:
            ConditionValue1Label.set_text("Drunken state");
            ConditionValue1Entry.set_tooltip_text("0: Sober\n"
                                                  "1: Tipsy\n"
                                                  "2: Drunk\n"
                                                  "3: Smashes");
            SetConditionValueNull(2);
            break;
        case CONDITION_WORLD_STATE:
            ConditionValue1Label.set_text("World state index");
            ConditionValue2Label.set_text("World state value");
            SetConditionValueNull(1);
            break;
        case CONDITION_ACTIVE_EVENT:
            ConditionValue1Label.set_text("Event entry");
            SetConditionValueNull(2);
            break;
        case CONDITION_INSTANCE_INFO:
            ConditionValue1Label.set_text("Entry");
            ConditionValue2Label.set_text("Data");
            ConditionValue3Label.set_text("Instance Info");
            ConditionValue3Entry.set_tooltip_text("0: Data\n"
                                                  "1: Data64\n"
                                                  "2: Boss State");
            break;
        case CONDITION_QUEST_NONE:
            ConditionValue1Label.set_text("Quest ID");
            SetConditionValueNull(2);
            break;
        case CONDITION_CLASS:
            ConditionValue1Label.set_text("Class ID");
            SetConditionValueNull(2);
            break;
        case CONDITION_RACE:
            ConditionValue1Label.set_text("Race");
            SetConditionValueNull(2);
            break;
        case CONDITION_ACHIEVEMENT:
            ConditionValue1Label.set_text("Achievement ID");
            SetConditionValueNull(2);
            break;
        case CONDITION_TITLE:
            ConditionValue1Label.set_text("Title ID");
            SetConditionValueNull(2);
            break;
        case CONDITION_SPAWNMASK:
            ConditionValue1Label.set_text("SpawnMask");
            SetConditionValueNull(2);
            break;
        case CONDITION_GENDER:
            ConditionValue1Label.set_text("Gender");
            ConditionValue1Entry.set_tooltip_text("0: Male\n"
                                                  "1: Female\n"
                                                  "2: None");
            SetConditionValueNull(2);
            break;
        case CONDITION_UNIT_STATE:
            ConditionValue1Label.set_text("Unit State");
            SetConditionValueNull(2);
            break;
        case CONDITION_MAPID:
            ConditionValue1Label.set_text("Map entry");
            SetConditionValueNull(2);
            break;
        case CONDITION_AREAID:
            ConditionValue1Label.set_text("Area ID");
            SetConditionValueNull(2);
            break;
        case CONDITION_UNUSED_24:
            SetConditionValueNull(3);
            break;
        case CONDITION_SPELL:
            ConditionValue1Label.set_text("Spell ID");
            SetConditionValueNull(2);
            break;
        case CONDITION_PHASEMASK:
            ConditionValue1Label.set_text("PhaseMask value");
            SetConditionValueNull(2);
            break;
        case CONDITION_LEVEL:
            ConditionValue1Label.set_text("Player level");
            ConditionValue2Label.set_text("Condition");
            ConditionValue2Entry.set_tooltip_text("0: ==\n"
                                                  "1: >\n"
                                                  "2: <\n"
                                                  "3: >=\n"
                                                  "4: <=");
            SetConditionValueNull(1);
            break;
        case CONDITION_QUEST_COMPLETE:
            ConditionValue1Label.set_text("Quest ID");
            SetConditionValueNull(2);
            break;
        case CONDITION_NEAR_CREATURE:
            ConditionValue1Label.set_text("Creature entry");
            ConditionValue2Label.set_text("Distance");
            ConditionValue2Entry.set_tooltip_text("In yards");
            SetConditionValueNull(1);
            break;
        case CONDITION_NEAR_GAMEOBJECT:
            ConditionValue1Label.set_text("Gameobject entry");
            ConditionValue2Label.set_text("Distance");
            ConditionValue2Entry.set_tooltip_text("In yards");
            SetConditionValueNull(1);
            break;
        case CONDITION_OBJECT_ENTRY:
            ConditionValue1Label.set_text("Type ID");
            ConditionValue1Entry.set_tooltip_text("3: Unit\n"
                                                  "4: Player\n"
                                                  "5: Gameobject\n"
                                                  "7: Corpse\n");
            ConditionValue2Label.set_text("Entry");
            ConditionValue2Entry.set_tooltip_text("TypeID Unit: Creature entry\n"
                                                  "TypeID GO: Gameobject entry\n"
                                                  "0: Any object of given type\n");
            SetConditionValueNull(1);
            break;
        case CONDITION_TYPE_MASK:
            ConditionValue1Label.set_text("TypeMask");
            ConditionValue1Entry.set_tooltip_text("8: TYPEMASK_UNIT\n"
                                                  "16: TYPEMASK_PLAYER\n"
                                                  "32: TYPEMASK_GAMEOBJECT\n"
                                                  "128: TYPEMASK_CORPSE");
            SetConditionValueNull(2);
            break;
        case CONDITION_RELATION_TO:
            ConditionValue1Label.set_text("Target");
            ConditionValue1Entry.set_tooltip_text("One of Condition Targets (0-1)");
            ConditionValue2Label.set_text("Relation Type");
            ConditionValue2Entry.set_tooltip_text("0: RELATION_SELF\n"
                                                  "1: RELATION_IN_PARTY\n"
                                                  "2: RELATION_IN_RAID_OR_PARTY\n"
                                                  "3: RELATION_OWNED_BY (ConditionTarget is owned by ConditionValue1)\n"
                                                  "4: RELATION_PASSENGER_OF (ConditionTarget is passenger of ConditionValue1)\n"
                                                  "5: RELATION_CREATED_BY (ConditionTarget is summoned by ConditionValue1)");
            SetConditionValueNull(1);
            break;
        case CONDITION_REACTION_TO:
            ConditionValue1Label.set_text("Target");
            ConditionValue1Entry.set_tooltip_text("One of Condition Targets (0-1)");
            ConditionValue2Label.set_text("RankMask");
            ConditionValue2Entry.set_tooltip_text("1: Hated\n"
                                                  "2: Hostile\n"
                                                  "4: Unfriendly\n"
                                                  "8: Neutral\n"
                                                  "16: Friendly\n"
                                                  "32: Honored\n"
                                                  "64: Revered\n"
                                                  "28: Exalted");
            SetConditionValueNull(1);
            break;
        case CONDITION_DISTANCE_TO:
            ConditionValue1Label.set_text("Target");
            ConditionValue1Entry.set_tooltip_text("One of Condition Targets (0-1)");
            ConditionValue2Label.set_text("Distance");
            ConditionValue2Entry.set_tooltip_text("Distance Between ConditionTarget and Target");
            ConditionValue3Label.set_text("Condition");
            ConditionValue3Entry.set_tooltip_text("0: ==\n"
                                                  "1: >\n"
                                                  "2: <\n"
                                                  "3: >=\n"
                                                  "4: <=");
            break;
        case CONDITION_ALIVE:
            SetConditionValueNull(3);
            NegativeConditionButton.set_label("Dead?");
            break;
        case CONDITION_HP_VAL:
            ConditionValue1Label.set_text("Health");
            ConditionValue2Label.set_text("Condition");
            ConditionValue2Entry.set_tooltip_text("0: ==\n"
                                                  "1: >\n"
                                                  "2: <\n"
                                                  "3: >=\n"
                                                  "4: <=");
            SetConditionValueNull(1);
            break;
        case CONDITION_HP_PCT:
            ConditionValue1Label.set_text("Percent of max HP");
            ConditionValue2Label.set_text("Condition");
            ConditionValue2Entry.set_tooltip_text("0: ==\n"
                                                  "1: >\n"
                                                  "2: <\n"
                                                  "3: >=\n"
                                                  "4: <=");
            SetConditionValueNull(1);
            break;
        default:
            assert(false && "How the hell did you do this? Contact Krofna ASAP!");
            break;
    }
}
