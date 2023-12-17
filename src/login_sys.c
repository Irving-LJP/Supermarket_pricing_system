#include "login_sys.h"
#include "main.h"

/*
 *功   能：登陆函数
 *参   数：无
 *返回值：0为成功，-1为不成功
 */
int login_sys()
{
   char u_name[12];
   char u_passwd[12];
   int i;

   int fd;
   int ret;

   /*打开记录用户的文件*/
   if ((fd = open("user_info.txt", O_RDONLY)) == -1)
   {
       perror("no suc file");
       return -1;
   }


   bzero(&u_info, sizeof(u_info));

   

    while(getchar() != '\n');

    printf("\n       请输入您的用户名:");
    fgets(u_name,5,stdin);
    
    printf("\n       请输入您的密码:");
    fgets(u_passwd,5,stdin);

    while(1)
   {

        ret = read(fd, &u_info,sizeof(u_info));
        if (0 == ret)
        {
            break;
        }

        //printf("u_info.userName = %s\n",u_info.userName);
        //printf("u_info.userPWD = %s\n",u_info.userPWD);

        if ((strcmp(u_info.userName,u_name)==0) && (strcmp(u_info.userPWD,u_passwd)==0))/*验证用户名和密码*/
        {
            printf("\n                      *用户名和密码正确，显示主菜单*");
            return 0;
        }    
           
        if ((strcmp(u_info.userName,u_name)==0) && (strcmp(u_info.userPWD,u_passwd)!=0))
        {
            printf("passwd error");
            printf("请重新输入:\n");
            while(1)
            {
                fgets(u_passwd,5,stdin);
                if (strcmp(u_info.userPWD,u_passwd) == 0)
                {
                    printf("\n                      *用户名和密码正确，显示主菜单*\n");
                    return 0;
                }
            }
        }
        

        if (strcmp(u_info.userName,u_name)!=0)
        {
            bzero(&u_info, sizeof(u_info));
            continue;
        }

    }
    perror("没有该用户！");
    return -1;
} 

  
