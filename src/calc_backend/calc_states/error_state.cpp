/******************************************************************************
 *  Copyright 2024
 *
 *  @file    error_state.cpp
 *
 *  @brief   
 *
 *=============================================================================
 *  Revision History
 *  Version     Date        Author      Content
 *  -------     ----------  ---------   ---------------------------------------
 *  V1.00       2024/10/22  caohz      Create.
 *
 *****************************************************************************/

/******************************************************************************
 *
 * INCLUDES
 *
 *****************************************************************************/
#include "error_state.hpp"
#include "calc_data.hpp"

/******************************************************************************
 *
 * FUNCTIONS
 *
 *****************************************************************************/
void error_state_c::input_state_proc(char value, input_type_t type)
{
    switch (type)
    {
    case NUMBER:
        cache_l = 0;
        cache_r = 0;
        update_left(value);
        snprintf(g_history_buffer, (WORDS_MAX - 1), "\n");
        state = LEFT_S;
        break;
    case OPERATOR:
        cache_l = 0;
        cache_r = 0;
        result = 0;
        snprintf(g_history_buffer, (WORDS_MAX - 1), "\n");
        snprintf(g_current_buffer, (WORDS_MAX - 1), "%d", result);
        state = RESULT_S;
        break;
    default:
        break;
    }
}
/* - End Of File - */
