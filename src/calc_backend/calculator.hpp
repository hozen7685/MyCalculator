/******************************************************************************
 *  Copyright 2024
 *
 *  @file    calculator.hpp
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
#ifndef __CALCULATOR_HPP__
#define __CALCULATOR_HPP__
#include "calc_state.hpp"
using namespace std;

class calculator_c
{
private:
    calc_state_c *calc_state_;
public:
    calculator_c(calc_state_c *state) : calc_state_(nullptr) {
        this->trans_to(state);
    }

    ~calculator_c() {
        delete calc_state_;
    }

    void trans_to(calc_state_c *state);

    void calc_request(char value);
};

#endif /* __CALCULATOR_HPP__ */
