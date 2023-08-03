/**
 * 信号测试程序
*/

#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"math.h"
#include"base_typedef.h"

#include"signal.h"



void sianal_test(void)
{


    signal(SIGINT,SIG_IGN);
    for(u8 i = 0; i < 10; i++)
    {
        write(1,"*", 1);
        sleep(1);
    }
    exit(0);
}