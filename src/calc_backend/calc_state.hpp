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

class calculator_c;

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

#endif /* __CALC_STATE_HPP__ */
