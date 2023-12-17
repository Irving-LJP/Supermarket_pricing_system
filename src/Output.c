#include "Output.h"
#include "main.h"


/*
*
*功能：显示所有商品信息
*返回值：无
*参数：无
* 
*/
void Output()
{  
   int i;

   Goods_Info G[10] = {
   {0.500000, "卫龙",      "164090000001"},
   {2.000000, "怡宝矿泉水","164090000002"},
   {1.500000, "喜之郎果冻","164090000003"},
   {3.500000, "乐事薯片",  "164090000004"},
   {7.000000, "百威啤酒",  "164090000005"},
   {1.000000, "旺仔小馒头","164090000006"},
   {5.000000, "八宝粥",    "164090000007"},
   {4.500000, "佳得乐",    "164090000008"},
   {11.000000,"无穷鸡翅",  "164090000009"},
   {2.500000, "百事可乐",  "164090000010"}
};

   if (B_list == NULL)//用于第一次调用函数时创建链表
   {
      B_list = Create_List();//建立链表头节点

      for (i = 0; i < 10; ++i)
      {
         p = Create_Node(G[i],100);
         Insert_Node(B_list,p);
      }
   }
   
   p = B_list->next;
   while(p != NULL)
   {
      //输出p指针指向空间的数据
      printf("商品名：%s\t  商品编号：%s\t 商品库存：%d\t 商品单价：%f\t \n", p->goods.name,p->goods.code,p->num,p->goods.price);
      //往后遍历
      p = p->next;
   }
   printf("\n");
}

/*
*
*功能：购买的商品
*返回值：无
*参数：无
*
 */
void buy()
{
   int num;
   int flag = 0;
   char buf[16];

   D_Node *sign;

   if (d_list == NULL)
   {
      d_list = Create_List();//建立链表头节点
   }
   
   Output();
   
   while(1)
   {
      bzero(buf,sizeof(buf));
      while(getchar() != '\n');
      printf("输入想要商品的编号：");
      fgets(buf,13,stdin);
      while(getchar() != '\n');
      printf("输入购买数量：");
      scanf("%d",&num);

      p = B_list->next;
      while(p != NULL)
      {  

         if (strncmp(buf,p->goods.code,12) == 0)
         {
            if (num > p->num)
            {
               printf("库存不足，只能给你100件\n");
               num = p->num;
            }

            sign = Create_Node(p->goods,num);
            Insert_Node(d_list,sign);
            Num++;

            p->num = p->num - num;   
         } 
         p = p->next;
      }

      printf("是否继续购物？1.是    2.否\n");
      scanf("%d",&flag);
      if (flag == 2)
      { 
         break;
      }
   }

}

/*
*
*功能：查看已购买的商品
*返回值：无
*参数：无
*
 */
void Check()
{
   if (Num == 0)
   {
      printf("购物车没东西！\n");
      return;
   }
   //p = d_list->next;
   Show_List(d_list);
}

/*
*
*功能：计算总价格
*返回值：float
*参数：D_Node *
*
 */
float Sum(D_Node * list)
{
   if (Num == 0)
   {
      printf("购物车没东西！\n");
      return 0.0;
   }

   float sum;
   D_Node *p = list->next;
   while(p != NULL)
   {
      sum += p->All_price;
      //往后遍历
      p = p->next;
   }
   return sum;
}


/*
*
*功能：取消购买商品
*返回值：空
*参数：D_Node *
*
 */
void Delete(D_Node * list)
{
   if (Num == 0)
   {
      printf("购物车没东西！\n");
      return;
   }

   char buf[16];
   while(getchar() != '\n');
   printf("输入删除的编号：");
   fgets(buf,13,stdin);
   Remove_Node(list, buf);
}


/*
*
*功能：添加商品种类
*返回值：空
*参数：无
*
 */
void add_goods()
{
   int i,num;
   float price;
   Goods_Info new;
   char buf_name[16];
   char buf_code[16];
   printf("==================当前设置仅可添加商品信息！\n");
   printf("===============是否进行？ 1：是       2：否\n");
   scanf("%d",&i);

   if (i == 2)
   {
      return;
   }

   while(getchar() != '\n');
   printf("输入商品名字：\n");
   fgets(buf_name,13,stdin);
   while(getchar() != '\n');
   printf("输入商品编号：\n");
   fgets(buf_code,13,stdin);
   while(getchar() != '\n');
   printf("输入商品库存：\n");
   scanf("%d",&num);
   printf("输入商品单价：\n");
   scanf("%f",&price);

   sprintf(new.name,"%s",buf_name);
   sprintf(new.code,"%s",buf_code);
   new.price = price;

   p = Create_Node(new,num);
   Insert_Node(B_list,p);
}



