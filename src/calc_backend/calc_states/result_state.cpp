#include "result_state.hpp"
#include "left_state.hpp"
#include "oper_state.hpp"
#include "error_state.hpp"
#include "clear_state.hpp"
#include "../calc_data.hpp"
#include <stdio.h>

void result_state_c::input_state_proc(char value)
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
        cache_l = 0;
        update_left(value);
        snprintf(g_current_buffer, (WORDS_MAX - 1), "%d", cache_l);
        this->calculator_->trans_to(new left_state_c());
        break;
    case PLUS:
    case MINUS:
    case MULTIPLY:
    case DIVIDE:
        cache_l = result;
        operation = value;
        cache_r = 0;
        snprintf(g_history_buffer, (WORDS_MAX - 1), "%d %c\n", cache_l, operation);
        snprintf(g_current_buffer, (WORDS_MAX - 1), "%d", result);
        this->calculator_->trans_to(new oper_state_c());
        break;
    case RESULT:
        cache_l = result;
        if (0 == calc_left_and_right()) {
            snprintf(g_history_buffer, (WORDS_MAX - 1), "%d %c %d %c\n",
                cache_l, operation, cache_r, value);
            snprintf(g_current_buffer, (WORDS_MAX - 1), "%d", result);
        } else {
            snprintf(g_current_buffer, (WORDS_MAX - 1), "error overflow");
            this->calculator_->trans_to(new error_state_c());
        }
        break;
    case CLEAR:
        cache_l = 0;
        cache_r = 0;
        result = 0;
        snprintf(g_history_buffer, (WORDS_MAX - 1), "\n");
        snprintf(g_current_buffer, (WORDS_MAX - 1), "%d", result);
        this->calculator_->trans_to(new clear_state_c());
        break;
    default:
        break;
    }
}