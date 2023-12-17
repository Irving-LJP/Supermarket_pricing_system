#ifndef _DOUBLE_LIST_H_
#define _DOUBLE_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct goods_info
{
	float price;	//单价
	char name[16];	//商品名
	char code[16];	//条形码（12位）
}Goods_Info;

typedef	struct list_node{
	int num;		//商品数量
	float All_price;//所有商品价格
	Goods_Info goods;//商品信息结构体
	
	struct list_node *prev;
	struct list_node *next;
}D_Node; 
	


D_Node *d_list;//记录已购商品
D_Node *p;		//记录选购的信息
D_Node *B_list;//记录库存商品

//1,创建链表
D_Node *Create_List();
//2,创建链表节点
D_Node *Create_Node(Goods_Info goods, int num);
//3,节点加入链表
bool Insert_Node(D_Node * list, D_Node * newnode);
//4,删除特征链表节点
bool Remove_Node(D_Node * list, char code[]);
//5,遍历显示链表
void Show_List(D_Node * list);
//6,查找节点
//bool Serach_Node(D_Node * list, int data);
//7,删除链表
void Delete_List(D_Node * list);

#endif