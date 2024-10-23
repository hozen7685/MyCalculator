/******************************************************************************
 *  Copyright 2024
 *
 *  @file    clear_state.hpp
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
#ifndef __CLEAR_STATE_HPP__
#define __CLEAR_STATE_HPP__

#include "../calc_state.hpp"

class clear_state_c : public calc_state_c
{
// Member functions
public:

protected:

private:

// Member Variables
public:
    void input_state_proc(char value) override;
protected:

private:

};

#endif /* __CLEAR_STATE_HPP__ */
