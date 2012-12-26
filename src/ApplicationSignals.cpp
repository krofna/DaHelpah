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

    if (Condition._SourceTypeOrReferenceId == 0)
    {
        // Reset
    }

    if (Condition._SourceTypeOrReferenceId < 13)
    {
        Condition._ConditionTarget = 0;
        SourceGroupLabel.set_text("Loot entry");
        SourceEntryLabel.set_text("Item ID");
    }
    else
    {
        switch (Condition._SourceTypeOrReferenceId)
        {
            case 13:
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
