#include "Add.h"
#include "main.h"


/*
 *功   能：注册函数
 *参   数：无
 *返回值：无
 */
void Add()
{
	int fd;
	struct user_info
	{
		char name[12];		//用户名
		char passwd[12];	//第一次输入密码
		char pass_wd[12];	//确认密码
	}info;

	/*先打开文件*/
	fd = open("./user_info.txt", O_RDWR | O_CREAT, 0777);
	if (-1 == fd)
	{
		perror("error");
	}

	while(1)
	{
		while(getchar() != '\n');

		printf("输入用户名\n");
		fgets(info.name,5,stdin);
		printf("输入密码\n");
		fgets(info.passwd,5,stdin);
		printf("确认密码\n");
		fgets(info.pass_wd,5,stdin);

		if ((strcmp(info.passwd,info.pass_wd) == 0))
		{
			strcpy(u_info.userName,info.name);
			strcpy(u_info.userPWD,info.passwd);
			printf("==========================注册成功========================\n");
			printf("\n\n\n");
		}
		else{
			continue;
		}

		lseek(fd,0,SEEK_END);
		write(fd, &u_info, sizeof(u_info));

		break;
	}
	
} 

