#include"first.h"
#include"func.h"
//test
//修改一下
int main(void) {
	system("color f0");
	//system("mode con cols=80 lines=70");

	create();
	printf("Weclome to the JXNU\n");

	while (True) {
		printf("欢迎使用JXNUGuide\n");
		printf("请选择您使用的角色\n");
		printf("游客请按1\n");
		printf("管理员请按2\n");
		printf("其他选择将退出系统\n");

		int choose;
		scanf_s("%d", &choose);

		switch (choose) {
		case 1:
			Visiter();	//转到游客界面
			break;
		case 2:
			printf("请输入管理员密码：");
			char password[PASSWORDLENGTH] = { 0 };	//存储密码
			int i = 0;								//记录密码长度
			char c;									//用于实现密码隐式输入

			while (True) {
				c = _getch();						//用 _getch() 函数输入，字符不会显示在屏幕上
				if (c == '\r') {					//遇到回车，表明密码输入结束
					break;							//while 循环的出口
				}
				else if (c == '\b') {				//遇到退格，需要删除前一个星号
					printf("\b \b");				//退格，打一个空格，再退格，实质上是用空格覆盖掉星号
					--i;
				}
				else {
					password[i++] = c;				//将字符放入数组
					printf("*");
				}
			}
			password[i++] = '\0';					//添加字符串结束标记
			printf("\n");

			if (strcmp(password, PASSWORD) == False) {
				printf("密码正确，即将进入系统\n");
				Administrator();	//转入管理员界面
			}
			else {
				system("cls");
				printf("----------密码错误---------\n");
				printf("系统将在1S后返回主页面");
				Sleep(1000);
				system("cls");
			}
			break;
		default:
			printf("即将在1s后退出系统，感谢您的使用。");
			Sleep(1000);
			return 0;
		}
	}


	return 0;
}