#include "result_state.hpp"
#include "left_state.hpp"

void result_state_c::input_state_proc(char value)
{
    switch (value)
    {
    case NUMBER:
        cache_l = 0;
        cache_r = 0;
        update_left(value);
        state = LEFT_S;
        this->calculator_->trans_to(new left_state_c());
        break;
    case OPERATOR:
        res_oper_proc(value);
        break;
    default:
        break;
    }
}