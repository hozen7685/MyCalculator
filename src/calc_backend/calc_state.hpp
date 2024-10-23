/******************************************************************************
 *  Copyright 2024
 *
 *  @file    calc_state.hpp
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
#ifndef __CALC_STATE_HPP__
#define __CALC_STATE_HPP__
#include "calculator.hpp"

class calc_state_c
{
// Member functions
public:
    
protected:
    calculator_c *calculator_;
private:
    
// Member Variables
public:
    virtual ~calc_state_c() {
    }

    void set_calculator(calculator_c *calculator);
    virtual void input_state_proc(char value) = 0;
protected:
    
private:
    
};

#endif /* __CALC_STATE_HPP__ */
