#include "Menu.h"
#include "main.h"


/*
 *函数功能：界面主菜单
 *参数：无
 */
void Menu()
{
  int choice;
  float sum;

  Num = 0;
  do
  {    
     printf("\n\n\n               ********解忧杂货店********\n\n");
     printf("                      1. 购买登记\n\n");
     printf("                      2. 查看已购\n\n");
     printf("                      3. 取消购买\n\n");
     printf("                      4. 总计价格\n\n");
     printf("                      5. 系统设置\n\n");
     printf("                      6. 帮助\n\n");
     printf("                      7. 退出\n\n");
     printf("                       请选择（1-7）:");
     scanf("%d",&choice);
     printf("\n\n\n"); 
    switch(choice)
    {
      case 1: buy(); break;/*购买登记*/
      case 2: Check(); break;/*查看已购*/
      case 3: Delete(d_list); break;/*取消购买*/
      case 4: printf("sum = %f\n", sum = Sum(d_list));  break;/*总计价格*/
      case 5: add_goods(); break;/*系统设置*/
      case 6: printf("要买东西就按1\n"); break;/*帮助*/
      case 7: break;/*退出系统*/ 
    } 
  }while(choice != 7);
}

