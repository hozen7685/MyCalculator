/******************************************************************************
 *  Copyright 2024
 *
 *  @file    calc_state.cpp
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
#include "calc_state.hpp"
#include <typeinfo>
#include <iostream>
/******************************************************************************
 *
 * FUNCTIONS
 *
 *****************************************************************************/
void calc_state_c::set_calculator(calculator_c *calculator)
{
    this->calculator_ = calculator;
}

void calculator_c::trans_to(calc_state_c *state)
{
    std::cout << "calculator: trans to " << typeid(*state).name() << ".\n";
    if (nullptr != this->calc_state_) {
        delete this->calc_state_;
    }
    this->calc_state_ = state;
    this->calc_state_->set_calculator(this);
}

void calculator_c::calc_request(char value)
{
    this->calc_state_->input_state_proc(value);
}

/* - End Of File - */
