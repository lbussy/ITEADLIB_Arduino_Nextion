/**
 * @file NexPicture.cpp
 *
 * The implementation of class NexPicture. 
 *
 * @author  Wu Pengfei (email:<pengfei.wu@itead.cc>)
 * @date    2015/8/13
 * @copyright 
 * Copyright (C) 2014-2015 ITEAD Intelligent Systems Co., Ltd. \n
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 */

#include "NexPicture.h"

/**
 * Constructor,inherited NexTouch's constructor function.
 *
 */
NexPicture::NexPicture(uint8_t pid, uint8_t cid, const char *name)
    :NexTouch(pid, cid, name)
{
}

/**
 * Get picture's number.
 * 
 * @param number - an output parameter to save picture number.  
 * 
 * @retval true - success. 
 * @retval false - failed. 
 */
bool NexPicture::getPic(uint32_t *number)
{
    String cmd = String("get ");
    cmd += getObjName();
    cmd += ".pic";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

/**
 * Set picture's number.
 * 
 * @param number -the picture number.
 *
 * @retval true - success.
 * @retval false - failed. 
 */
bool NexPicture::setPic(uint32_t number)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd += getObjName();
    cmd += ".pic=";
    cmd += buf;

    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}
 
