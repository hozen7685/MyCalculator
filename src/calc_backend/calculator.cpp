/******************************************************************************
 *  Copyright 2024
 *
 *  @file    calculator.cpp
 *
 *  @brief   
 *
 *=============================================================================
 *  Revision History
 *  Version     Date        Author      Content
 *  -------     ----------  ---------   ---------------------------------------
 *  V1.00       2024/10/19  caohozen      Create.
 *
 *****************************************************************************/

/******************************************************************************
 *
 * INCLUDES
 *
 *****************************************************************************/
#include "calculator.hpp"
#include <typeinfo>
#include <iostream>
/******************************************************************************
 *
 * FUNCTIONS
 *
 *****************************************************************************/
void calculator_c::trans_to(calc_state_c *state)
{
    cout << "calculator: trans to " << typeid(*state).name() << ".\n";
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
