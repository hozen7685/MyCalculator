/******************************************************************************
 *  Copyright 2024
 *
 *  @file    clear_state.cpp
 *
 *  @brief
 *
 *=============================================================================
 *  Revision History
 *  Version     Date        Author      Content
 *  -------     ----------  ---------   ---------------------------------------
 *  V1.00       2024/10/23  caohz       Create.
 *
 *****************************************************************************/

/******************************************************************************
 *
 * INCLUDES
 *
 *****************************************************************************/
#include "clear_state.hpp"
#include "left_state.hpp"
#include "oper_state.hpp"
#include "../calc_data.hpp"
#include <stdio.h>
/******************************************************************************
 *
 * FUNCTIONS
 *
 *****************************************************************************/
void clear_state_c::input_state_proc(char value)
{
    switch (value)
    {
    case NUM_0:
    case NUM_1:
    case NUM_2:
    case NUM_3:
    case NUM_4:
    case NUM_5:
    case NUM_6:
    case NUM_7:
    case NUM_8:
    case NUM_9:
        update_left(value);
        snprintf(g_current_buffer, (WORDS_MAX - 1), "%d", cache_l);
        this->calculator_->trans_to(new left_state_c());
        break;
    case PLUS:
    case MINUS:
    case MULTIPLY:
    case DIVIDE:
        operation = value;
        this->calculator_->trans_to(new oper_state_c());
        break;
    case RESULT:
        break;
    case CLEAR:
        break;
    default:
        break;
    }
}
/* - End Of File - */
