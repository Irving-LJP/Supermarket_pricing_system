#include "double_list.h"



//1,创建链表
D_Node *Create_List()
{
	//1,申请堆内存
	D_Node *head =(D_Node *) malloc(sizeof(D_Node));
	if(head == NULL)
	{
		perror("malloc failed");
		return NULL;
	}
	
	//2,初始化头结点
	head->next = NULL;
	head->prev = NULL;
	return head;
}

//2,创建链表节点
D_Node *Create_Node(Goods_Info goods, int num)
{
	//1)申请堆空间
	D_Node *p =(D_Node *) malloc(sizeof(D_Node));
	if(p == NULL)
	{
		perror("malloc failed");
		return NULL;
	}
	//2)对节点内容进行赋值
	p->goods =  goods;
	p->num = num;
	p->All_price = num * goods.price;
	p->prev = NULL;
	p->next = NULL;
	//3)返回节点指针
	return p;
}

//3,节点加入链表
bool Insert_Node(D_Node * list, D_Node * newnode)
{
	//头插法
	/*
	newnode->next = list->next;
	list->next = newnode;
	newnode->next->prev = newnode;
	newnode->prev = list;*/

	//尾插法
	D_Node *p = list;
	//把节点添加到链表中
	while(p->next != NULL)
	{
		//往后遍历
		p = p->next;
	}
	p->next = newnode;
	newnode->prev = p;
	return true;
	
}

//4,删除特征链表节点
bool Remove_Node(D_Node * list, char code[])
{
	if (list->next == NULL)
	{
		return false;
	}

	D_Node *p = list->next;

	while(p != NULL)
	{
		if (strcmp(p->goods.code, code) == 0)
		{
			if (p->next == NULL)
			{
				p->prev->next = NULL;
				free(p);
			}
			else
			{
				p->prev->next = p->next;
				p->next->prev = p->prev;
				free(p);
			}

		}

		p = p->next;
	}
}

//5,遍历显示链表
void Show_List(D_Node * list)
{
	
	if (list == NULL)
	{
		printf("empty\n");
		return;
	}

	D_Node *p = list->next;
	while(p != NULL)
	{
		//输出p指针指向空间的数据
		printf("%s %s %d %f \n", p->goods.name,p->goods.code,p->num,p->All_price);
		//往后遍历
		p = p->next;
	}
	printf("\n");
}

//6,查找节点
/*bool Serach_Node(D_Node * list, int data)
{
	if (list->next == NULL)
	{
		return false;
	}

	D_Node *p = list->next;

	while(p != NULL)
	{
		if (p->data == data)
		{
			printf("%d\n", p->data);
		}
	}
}*/


//7,删除链表
void Delete_List(D_Node * list)
{
	if (list->next == list)
	{
		free(list);
		return;
	}

	D_Node *p = list;
	D_Node *q = p;
	while(p != NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
	free(list);
}

/*int main(int argc, char *argv[])
{
	int i, data;
	//创建双向链表
	D_Node *d_list = Create_List();
	D_Node *newnode = NULL;
	//添加5个节点
	for (i = 0; i < 5; ++i)
	{
		newnode = Create_Node(i);
		Insert_Node(d_list,newnode);
	}
	Show_List(d_list);
	//删除节点
	scanf("%d",&data);
	Remove_Node(d_list,data);
	Show_List(d_list);
	
	//删除链表
	Delete_List(d_list);
	return 0;
}*/