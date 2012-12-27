/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details. */

#ifndef CONDITIONS_ENUM_HPP
#define CONDITIONS_ENUM_HPP

enum SourceTypeOrReferenceId
{
    CONDITION_SOURCE_TYPE_NONE                           = 0,
    CONDITION_SOURCE_TYPE_CREATURE_LOOT_TEMPLATE         = 1,
    CONDITION_SOURCE_TYPE_DISENCHANT_LOOT_TEMPLATE       = 2,
    CONDITION_SOURCE_TYPE_FISHING_LOOT_TEMPLATE          = 3,
    CONDITION_SOURCE_TYPE_GAMEOBJECT_LOOT_TEMPLATE       = 4,
    CONDITION_SOURCE_TYPE_ITEM_LOOT_TEMPLATE             = 5,
    CONDITION_SOURCE_TYPE_MAIL_LOOT_TEMPLATE             = 6,
    CONDITION_SOURCE_TYPE_MILLING_LOOT_TEMPLATE          = 7,
    CONDITION_SOURCE_TYPE_PICKPOCKETING_LOOT_TEMPLATE    = 8,
    CONDITION_SOURCE_TYPE_PROSPECTING_LOOT_TEMPLATE      = 9,
    CONDITION_SOURCE_TYPE_REFERENCE_LOOT_TEMPLATE        = 10,
    CONDITION_SOURCE_TYPE_SKINNING_LOOT_TEMPLATE         = 11,
    CONDITION_SOURCE_TYPE_SPELL_LOOT_TEMPLATE            = 12,
    CONDITION_SOURCE_TYPE_SPELL_IMPLICIT_TARGET          = 13,
    CONDITION_SOURCE_TYPE_GOSSIP_MENU                    = 14,
    CONDITION_SOURCE_TYPE_GOSSIP_MENU_OPTION             = 15,
    CONDITION_SOURCE_TYPE_CREATURE_TEMPLATE_VEHICLE      = 16,
    CONDITION_SOURCE_TYPE_SPELL                          = 17,
    CONDITION_SOURCE_TYPE_SPELL_CLICK_EVENT              = 18,
    CONDITION_SOURCE_TYPE_QUEST_ACCEPT                   = 19,
    CONDITION_SOURCE_TYPE_QUEST_SHOW_MARK                = 20,
    CONDITION_SOURCE_TYPE_VEHICLE_SPELL                  = 21,
    CONDITION_SOURCE_TYPE_SMART_EVENT                    = 22,
    CONDITION_SOURCE_TYPE_MAX                            = 23
};

enum ConditionTypeOrReference
{
    CONDITION_NONE                    = 0,
    CONDITION_AURA                    = 1,
    CONDITION_ITEM                    = 2,
    CONDITION_ITEM_EQUIPPED           = 3,
    CONDITION_ZONEID                  = 4,
    CONDITION_REPUTATION_RANK         = 5,
    CONDITION_TEAM                    = 6,
    CONDITION_SKILL                   = 7,
    CONDITION_QUESTREWARDED           = 8,
    CONDITION_QUESTTAKEN              = 9,
    CONDITION_DRUNKENSTATE            = 10,
    CONDITION_WORLD_STATE             = 11,
    CONDITION_ACTIVE_EVENT            = 12,
    CONDITION_INSTANCE_DATA           = 13,
    CONDITION_QUEST_NONE              = 14,
    CONDITION_CLASS                   = 15,
    CONDITION_RACE                    = 16,
    CONDITION_ACHIEVEMENT             = 17,
    CONDITION_TITLE                   = 18,
    CONDITION_SPAWNMASK               = 19,
    CONDITION_GENDER                  = 20,
    CONDITION_UNUSED_21               = 21,
    CONDITION_MAPID                   = 22,
    CONDITION_AREAID                  = 23,
    CONDITION_UNUSED_24               = 24,
    CONDITION_SPELL                   = 25,
    CONDITION_PHASEMASK               = 26,
    CONDITION_LEVEL                   = 27,
    CONDITION_QUEST_COMPLETE          = 28,
    CONDITION_NEAR_CREATURE           = 29,
    CONDITION_NEAR_GAMEOBJECT         = 30,
    CONDITION_OBJECT_ENTRY            = 31,
    CONDITION_TYPE_MASK               = 32,
    CONDITION_RELATION_TO             = 33,
    CONDITION_REACTION_TO             = 34,
    CONDITION_DISTANCE_TO             = 35,
    CONDITION_ALIVE                   = 36,
    CONDITION_HP_VAL                  = 37,
    CONDITION_HP_PCT                  = 38,
    CONDITION_MAX                     = 39
};

#endif
