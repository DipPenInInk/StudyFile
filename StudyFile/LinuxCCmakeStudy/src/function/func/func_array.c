#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"math.h"

#include"func_array.h"


/**
 * @brief 打印一维数组
 * 
 * @param p 
 * @param num 
 */
void print_arr(int *p,int num)
{ 
    printf("%s:%d\n", __FUNCTION__, sizeof(p));

    for(int i = 0; i < num; i++)
    {
        printf("%d ", *(p + i));
        printf("%d ", p[i]);
    }
    printf("\n");

}

/**
 * @brief 一维数组逆序
 * 
 * @param p 
 * @param num 
 */
void reverse_order_arr(int *p,int num)
{
    for(int i = 0, j = 0, tmp = 0; i <= ((num - 1) / 2); i++)
    {
        tmp = p[i];
        p[i] = p[num - 1 -i];
        p[num - 1 -i] = tmp;

    }
}


/**
 * @brief 函数与数组测试
 * 
 * @return int 
 */
int func_array_test(void)
{
  
  //一维数组测试
  int a1[] = {0, 1, 2, 3, 4};
  print_arr(a1, sizeof(a1) / sizeof(*a1));

}
