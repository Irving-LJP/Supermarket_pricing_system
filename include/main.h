#ifndef _MAIN_H
#define _MAIN_H


struct user
{
	char userName[12];/*用户名*/
	char userPWD[12];/*密码*/
}u_info;

int Num;//记录购买了的种类

//#define MAX 20 /*最多给你20本书，多了不写*/

#include "login_sys.h"
#include "Add.h"
#include "Menu.h"
#include "Output.h"
#include "double_list.h"



#endif