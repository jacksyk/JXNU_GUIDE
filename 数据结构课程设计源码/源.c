#include"first.h"
#include"func.h"
//test
//�޸�һ��
int main(void) {
	system("color f0");
	//system("mode con cols=80 lines=70");

	create();
	printf("Weclome to the JXNU\n");

	while (True) {
		printf("��ӭʹ��JXNUGuide\n");
		printf("��ѡ����ʹ�õĽ�ɫ\n");
		printf("�ο��밴1\n");
		printf("����Ա�밴2\n");
		printf("����ѡ���˳�ϵͳ\n");

		int choose;
		scanf_s("%d", &choose);

		switch (choose) {
		case 1:
			Visiter();	//ת���οͽ���
			break;
		case 2:
			printf("���������Ա���룺");
			char password[PASSWORDLENGTH] = { 0 };	//�洢����
			int i = 0;								//��¼���볤��
			char c;									//����ʵ��������ʽ����

			while (True) {
				c = _getch();						//�� _getch() �������룬�ַ�������ʾ����Ļ��
				if (c == '\r') {					//�����س������������������
					break;							//while ѭ���ĳ���
				}
				else if (c == '\b') {				//�����˸���Ҫɾ��ǰһ���Ǻ�
					printf("\b \b");				//�˸񣬴�һ���ո����˸�ʵ�������ÿո񸲸ǵ��Ǻ�
					--i;
				}
				else {
					password[i++] = c;				//���ַ���������
					printf("*");
				}
			}
			password[i++] = '\0';					//����ַ����������
			printf("\n");

			if (strcmp(password, PASSWORD) == False) {
				printf("������ȷ����������ϵͳ\n");
				Administrator();	//ת�����Ա����
			}
			else {
				system("cls");
				printf("----------�������---------\n");
				printf("ϵͳ����1S�󷵻���ҳ��");
				Sleep(1000);
				system("cls");
			}
			break;
		default:
			printf("������1s���˳�ϵͳ����л����ʹ�á�");
			Sleep(1000);
			return 0;
		}
	}


	return 0;
}