#include "main.h"



int main()
{
	while(1)
	{
		
		int input;
		int login_ret;

		printf("                       解忧杂货店\n");
		printf("=================================================================\n");
		printf("1:注册                                    2：登陆\n");
		printf("=================================================================\n");

		scanf("%d",&input);

		if ( input == 1 ) 
		{
			Add();
		}
		if ( input == 2 )
		{
			if((login_ret = login_sys()) != 0)
				continue;
			Menu();
			break;
		}

	}
	
	return 0;
}




