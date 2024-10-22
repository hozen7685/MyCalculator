/******************************************************************************
 *  Copyright 2024
 *
 *  @file    error_state.hpp
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
#ifndef __ERROR_STATE_HPP__
#define __ERROR_STATE_HPP__

#include "../calc_state.hpp"

class error_state_c : public calc_state_c
{
// Member Variables
public:
    
protected:
    
private:
    
// Member Functions
public:
    void input_state_proc(char value, input_type_t type) override;
protected:
    
private:
    
};

#endif /* __ERROR_STATE_HPP__ */
