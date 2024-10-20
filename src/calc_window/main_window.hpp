/******************************************************************************
 *  Copyright 2024
 *
 *  @file    main_window.hpp
 *
 *  @brief   
 *
 *=============================================================================
 *  Revision History
 *  Version     Date        Author      Content
 *  -------     ----------  ---------   ---------------------------------------
 *  V1.00       2024/10/18  caohozen      Create.
 *
 *****************************************************************************/
#ifndef __MAIN_WINDOW_HPP__
#define __MAIN_WINDOW_HPP__

#include <cstdint>
#include <string>
#include "lv_conf.h"
#include "lvgl.h"
#include "lv_version.h"
using namespace std;

#define BTN_NUM 16

typedef enum {
    B_7,    B_8,   B_9,   B_DVI,
    B_4,    B_5,   B_6,   B_MP,
    B_1,    B_2,   B_3,   B_MI,
    B_C,    B_0,   B_RS,  B_PL
} btn_id_t;

class main_window_c
{
// Member functions
public:
    main_window_c();
    ~main_window_c();
    static void create_calc_window(void);
protected:
    
private:

// Member Variables
public:

protected:
    
private:
};

#endif /* __MAIN_WINDOW_HPP__ */
