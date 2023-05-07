#pragma once
#pragma warning(disable:4996)

#include"first.h"
#include"heap.h"

//1.���������б�
void showInfo(void);					//������о���
void Visiter(void);						//�ο�ϵͳ
void Administrator(void);				//����Աϵͳ
void introduct(void);					//�������
void DijkstraHeap(void);				//�����ο����ھ�������������ľ��루���Ż��ĵϽ�˹�����㷨��
void Floyd(void);						//�����ο�ָ�����������������·������
void modifyInfo(void);					//�޸ľ�����Ϣ
void addInfo(void);						//��Ӿ���
void delInfo(void);						//ɾ������ 
void addPath(void);						//��ӵ�·
void delPath(void);						//ɾ����·
void create(void);						//����ͼ
void printPath(int[], int, int);		//���·����Ϣ			


void showInfo(void) {
	system("cls");	//����
	printf("JXNU�����б�:\n");
	for (int i = 0; i < JXNUmap.n; i++) {
		printf("%d ��%s\n", i + 1, JXNUmap.vers[i].name);
	}

	return;
}

void Visiter(void) {
	system("cls");	//����
	int choose = 0;

	while (True) {
		printf("�����ϵܣ���ӭ��������ʦ����ѧJXNU\n");
		printf("���ܲ˵�\n");
		printf("1.��������\n");
		printf("2.��ѯ��ǰλ�õ�����λ�õ����·��\n");
		printf("3.��ѯ��������λ�õ����·��\n");
		printf("4.�뿪ϵͳ\n");
		scanf_s("%d", &choose);
		system("cls");

		switch (choose) {
		case 1:
			printf("��������:\n");
			introduct();
			break;
		case 2:
			printf("�Ͻ�˹�����㷨���������·��\n");
			DijkstraHeap();
			break;
		case 3:
			printf("�������°��㿴��������������·��\n");
			Floyd();
			break;
		case 4:
			printf("��� �ص��������ˣ��ϸ��ټ�~�\\n");
			return;
		default:
			printf("�ϸ�������˰ɣ��������ԣ�\n");
			break;
		}
	}

	return;
}

void introduct(void) {
	if (JXNUmap.n <= 0) {
		printf("���Ǹ���ѧУ��û���κξ���\n");
		return;
	}

	showInfo();
	printf("��Ҫ���Ǹ�����Ľ����أ���˵�ţ�");
	int num;
	scanf_s("%d", &num);
	system("cls");

	while (num < 1 || num > JXNUmap.n) {
		printf("�ⶼ�����1��%d֮�䣬�����䣡\n", JXNUmap.n);
		scanf_s("%d", &num);
	}

	printf("%s:%s\n", JXNUmap.vers[num - 1].name, JXNUmap.vers[num - 1].features);
	Sleep(1000);
	printf("����1S�󷵻�������\n");
	Sleep(1000);
	return;
}

void DijkstraHeap(void) {
	if (JXNUmap.n <= 0) {
		printf("��ͼ�����κξ��㣬������Ӿ��㣡\n");
		return;
	}

	showInfo();
	printf("�����������ڵľ�����:");
	int num;
	scanf_s("%d", &num);

	while (num < 1 || num > JXNUmap.n) {
		printf("����������󣬱��Ӧλ��1��%d֮�䣬�������룡\n", JXNUmap.n);
		scanf_s("%d", &num);
	}
	num--;

	//��ʼ��dis
	for (int i = 0; i < MaxVerNum; i++) {
		dis[i] = INFINITY;
	}

	dot t;
	t.num = num;
	t.val = 0;
	push(t);	//���

	dis[num] = 0;

	while (len) {
		dot top = pop();	//�����Ѷ�Ԫ�أ���Ϊ��С���ѣ��Ѷ�Ԫ��ֵ�϶�Ϊ��С�ģ�

		if (vis[top.num]) {	//����һ�������̾�����θı䣬
			continue;		//���Զ��п����ж���ظ�ϵ�G������ÿ��ȡ���Ķ�����С�ģ����Ա�ȡ��һ�κ�							
		}					//������ظ��ڵ㶼���Ժ���
		vis[top.num] = 1;

		for (int i = 0; i < JXNUmap.n; i++) {
			if (JXNUmap.edges[top.num][i] && !vis[i] && dis[i] > JXNUmap.edges[top.num][i] + top.val) {
				dot t;
				t.num = i;
				t.val = JXNUmap.edges[top.num][i] + top.val;
				push(t);

				//�޸ľ���
				dis[i] = JXNUmap.edges[top.num][i] + top.val;
				//��¼ǰһ���ڵ�
				pre[i] = top.num;
			}
		}
	}

	//���·�ߺ;���
	for (int i = 0; i < JXNUmap.n; i++) {
		if (i != num) {
			printf("��������%s����%s�ľ�����%dm\n", JXNUmap.vers[num].name, JXNUmap.vers[i].name, dis[i]);
			printf("·���ǣ�");
			printPath(pre, i, num);
			printf("\b\b     \n\n");
			Sleep(1000);
		}
	}

	//����vis��pre
	for (int i = 0; i < MaxVerNum; i++) {
		vis[i] = 0;
		pre[i] = 0;
	}

	system("pause");
	system("cls");

	return;
}

void printPath(int pre[], int i, int num) {
	//ʹ�õݹ�ķ������·�ߣ�
	if (i == num) {
		printf("%s->", JXNUmap.vers[num].name);
		return;
	}
	printPath(pre, pre[i], num);
	printf("%s->", JXNUmap.vers[i].name);

	return;
}

void Floyd(void) {
	if (JXNUmap.n <= 0) {
		printf("��ͼ�����κξ��㣬������Ӿ��㣡\n");
		return;
	}

	showInfo();
	int path[MaxVerNum][MaxVerNum];
	int dist[MaxVerNum][MaxVerNum];
	int i, j, k;
	int temp;

	for (i = 0; i < JXNUmap.n; i++)
		for (j = 0; j < JXNUmap.n; j++) {
			dist[i][j] = JXNUmap.edges[i][j];
			path[i][j] = j;
		}
	for (k = 0; k < JXNUmap.n; k++)
		for (i = 0; i < JXNUmap.n; i++)
			for (j = 0; j < JXNUmap.n; j++) {
				//temp = (dist[i][k] == INFINITY || dist[k][j] == INFINITY) ? INFINITY : (dist[i][k] + dist[k][j]);
				temp = dist[i][k] + dist[k][j];
				if (dist[i][j] > temp) {
					dist[i][j] = temp;
					path[i][j] = k;
				}
			}
	int a, b;
	printf("��������Ҫ��ѯ֮���������������ţ��м��ÿո������\n");
	scanf_s("%d %d", &b, &a);
	while (a < 1 || a > JXNUmap.n || b < 1 || b > JXNUmap.n || a == b) {
		if (a == b)
			printf("��������������ͬ��ţ��������룡\n");
		else
			printf("�����������������Ŷ�Ӧλ��1��%d֮�䣬�������룡\n", JXNUmap.n);
		scanf_s("%d %d", &b, &a);
	}
	if (dist[a - 1][b - 1] == INFINITY) {
		printf("%s��%s֮����·����\n", JXNUmap.vers[b - 1].name, JXNUmap.vers[a - 1].name);
		return;
	}
	else {
		printf("%s��%s�����·������Ϊ��%d��\n", JXNUmap.vers[b - 1].name, JXNUmap.vers[a - 1].name, dist[a - 1][b - 1]);
		printf("·��Ϊ��");
		int pre[MaxVerNum];
		for (int i = 0; i < JXNUmap.n; i++) {
			pre[i] = path[i][b - 1];
		}
		printPath(pre, a - 1, b - 1);
		printf("\b\b  \n");

		Sleep(1000);
	}
	system("pause");
	printf("ϵͳ����1S��ص������");
	Sleep(1000);
	system("cls");

	return;
}

void Administrator(void) {
	system("cls");
	while (True) {
		int choose;
		printf("ֻ�й���Ա���ܿ����Ĺ���ϵͳ\n");
		printf("1.�������\n");
		printf("2.���������ڵľ��㵽������������·��\n");
		printf("3.����������������֮������·��\n");
		printf("4.�޸ľ�����Ϣ\n");
		printf("5.���Ӿ�����Ϣ\n");
		printf("6.ɾ��������Ϣ\n");
		printf("7.���ӵ�·\n");
		printf("8.ɾ����·\n");
		printf("9.�˳�����ϵͳ\n");

		scanf_s("%d", &choose);
		switch (choose) {
		case 1:
			system("cls");
			printf("���Ҹ���������\n");
			introduct();
			break;
		case 2:
			system("cls");
			printf("�Ͻ�˹�����㷨\n");
			DijkstraHeap();
			break;
		case 3:
			system("cls");
			printf("���������㷨\n");
			Floyd();
			break;
		case 4:
			system("cls");
			printf("�Ĵ��ˣ�����ģ�\n");
			modifyInfo();
			break;
		case 5:
			system("cls");
			printf("�ٶ�д�������\n");
			addInfo();
			break;
		case 6:
			system("cls");
			printf("д���ˣ�ɾ�˰�\n");
			delInfo();
			break;
		case 7:
			system("cls");
			printf("ʦ������·��\n");
			addPath();
			break;
		case 8:
			system("cls");
			printf("����·�������ˣ�\n");
			delPath();
			break;
		case 9:
			system("cls");
			printf("�ټ�~~~\n");
			return;
		default:
			system("cls");
			printf("�ϸ�����ˣ�Ҫ���������ԣ�\n");
			break;
		}
	}

	return;
}

void create(void) {
	FILE* num, * edge, * vers;

	if (fopen_s(&num, "num.txt", "r") || fopen_s(&edge, "edge.txt", "r") || fopen_s(&vers, "vers.txt", "r") != 0) {
		printf("�ļ������ڣ�");
		return;
	}
	fscanf_s(num, "%d%d", &JXNUmap.n, &JXNUmap.e);

	//��ʼ��ÿ����������
	for (int i = 0; i < MaxVerNum; i++) {
		JXNUmap.vers[i].num = i + 1;
	}

	//��ÿ���߳�ʼ��
	for (int i = 0; i < MaxVerNum; i++) {
		for (int j = 0; j < MaxVerNum; j++) {
			if (i == j)
				JXNUmap.edges[i][j] = 0;
			else
				JXNUmap.edges[i][j] = INFINITY;
		}
	}

	//����ÿ���������Ϣ
	for (int i = 0; i < JXNUmap.n; i++) {
		int j;

		//��ȡ������Ϣ
		fscanf_s(vers, "%d", &j);
		fscanf_s(vers, "%s%s", JXNUmap.vers[j].name, MaxNameLength, JXNUmap.vers[j].features, MaxDescribeLength);
	}


	//���������еı�
	for (int i = 0; i < JXNUmap.e; i++) {
		int a, b, c;
		fscanf_s(edge, "%d%d%d", &a, &b, &c);
		JXNUmap.edges[a][b] = JXNUmap.edges[b][a] = c;
	}
	fclose(num);
	fclose(edge);
	fclose(vers);

	return;
}

void modifyInfo(void) {
	if (JXNUmap.n <= 0) {
		printf("����һ����ٵ�ѧУ����Ȼû���κξ���\n");
		return;
	}
	showInfo();
	int a;
	printf("��˵����Ҫ�ģ�˵��ţ�\n");
	scanf_s("%d", &a);
	while (a < 1 || a > JXNUmap.n) {
		printf("�������ˣ���1��ʼ��%d���������Ա��\n", JXNUmap.n);
		scanf_s("%d", &a);
	}
	char newName[MaxNameLength];
	char newFeatures[MaxNameLength];
	printf("����ԭ����%s,��Ҫ��������ɶ?:\n", JXNUmap.vers[a - 1].name);
	scanf_s("%s", newName, MaxNameLength);
	printf("���������:\n%s\n��˵�ĳ�ɶ?:\n", JXNUmap.vers[a - 1].features);
	scanf_s("%s", newFeatures, MaxNameLength);
	printf("�����޸�...\n");
	strcpy(JXNUmap.vers[a - 1].name, newName);
	strcpy(JXNUmap.vers[a - 1].features, newFeatures);
	printf("���˸ĺ���\n");
	printf("Ҫ���ľ�����1�����ľ��˳���\n");
	int flag;
	scanf_s("%d", &flag);
	if (flag == True) {
		modifyInfo();
	}

	return;
}

void addInfo(void) {
	if (JXNUmap.n >= MaxVerNum) {
		printf("ʦ���Ѿ����˲����ټ���\n");
		return;
	}
	showInfo();

	char newName[100];
	char newFeature[1000];
	printf("�¼ӵ���������ɶ?:\n");
	scanf_s("%s", newName, MaxNameLength);
	printf("���������ӵ����:\n");
	scanf_s("%s", newFeature, MaxNameLength);
	showInfo();

	int m;
	printf("���Ա��м�������:\n");
	scanf_s("%d", &m);
	int i, a, distance;
	for (i = 0; i < m; i++) {
		printf("��һ��%s�ĵ�%d�������ľ�����:\n", newName, i + 1);
		scanf_s("%d", &a);
		while (a< 1 || a>JXNUmap.n || JXNUmap.edges[a - 1][JXNUmap.n] != INFINITY) {
			if (a<1 || a>JXNUmap.n)
			{
				printf("����ˣ������1��%d֮�䣬�����䣡\n", JXNUmap.n);
				scanf_s("%d", &a);
			}
			if (JXNUmap.edges[a - 1][JXNUmap.n] != INFINITY)
			{
				printf("�ϸ磬����Ѿ����ˣ�������\n");
				scanf_s("%d", &a);
			}
		}

		printf("%s��%s֮��ľ����Ƕ��٣�:\n", newName, JXNUmap.vers[a - 1].name);
		scanf_s("%d", &distance);
		while (distance <= 0 || distance > INFINITY)
		{
			printf("��������Ƿ����������룡\n");
			scanf_s("%d", &distance);
		}
		JXNUmap.edges[a - 1][JXNUmap.n] = JXNUmap.edges[JXNUmap.n][a - 1] = distance;
	}
	printf("������Ӿ���...\n");
	strcpy(JXNUmap.vers[JXNUmap.n++].name, newName, MaxNameLength);
	strcpy(JXNUmap.vers[JXNUmap.n - 1].features, newFeature, MaxNameLength);
	JXNUmap.e += m;

	printf("���������ӳɹ��ˣ�\n");
	printf("��Ҫ�Ӿ�����1�����������ַ����˳�\n");
	int flag;
	scanf_s("%d", &flag);
	if (flag == 1)
		addInfo();
	return;
}


//ɾ��������Ϣ

//ɾ��������Ϣ����Ҫ�޸ıߵĳ��ȣ�������Ϣ����Ҫ��ɾ������ĺ������о������Ǩ�ƣ���Ӧ��·��ҲӦ��������Ӧ�ı任��
void delInfo(void) {
	if (JXNUmap.n <= 0) {
		printf("�Ѿ�ɾû�ˣ�������ɾ��!\n");
		return;
	}
	showInfo();
	printf("��������Ҫɾ������ı��:\n");
	int a;
	scanf_s("%d", &a);
	while (a < 1 || a > JXNUmap.n) {
		printf("������ˣ�����id��ΧΪ1-%d", JXNUmap.n);
		scanf_s("%d", &a);
	}
	printf("ɾ���ľ���Ϊ: %sȷ��ɾ�������1ȷ��ɾ��:\n", JXNUmap.vers[a - 1].name);
	int flag;
	scanf_s("%d", &flag);
	if (flag == 1) {
		printf("ɾ�������У����Ժ�.....\n");
		int i, j, count = 0;
		//count��¼����Ҫɾ����������ı��
		for (i = 0; i < JXNUmap.n; i++) {
			if (JXNUmap.edges[a - 1][i] != INFINITY) {
				count++;
			}
		}
		//��Ҫɾ���ľ���ĺ����ڵ�Ǩ��
		for (i = a - 1; i < JXNUmap.n; i++) {
			JXNUmap.vers[i] = JXNUmap.vers[i + 1];
		}
		for (i = 0; i < JXNUmap.n; i++) {
			for (j = a - 1; j < JXNUmap.n; j++) {
				JXNUmap.edges[i][j] = JXNUmap.edges[i][j + 1];
				JXNUmap.edges[j][i] = JXNUmap.edges[j + 1][i];
			}
		}
		JXNUmap.n--;
		JXNUmap.e -= count;
	}
	else {
		printf("�˳���\n");
		return;
	}
	printf("�Ѿ�ɾ���ˣ�����ɾ��֮��ľ���\n");
	showInfo();
	printf("����Ҫɾ���Ҫ�Ļ�����1:\n");
	scanf_s("%d", &flag);
	if (flag == 1) {
		delInfo();
	}
	Sleep(100);
	return;
}

void addPath(void) {
	if (JXNUmap.n <= 1) {
		printf("ʦ�󾰵��������� ��Ӳ���\n");
		return;
	}
	showInfo();
	printf("��������Ҫ������������֮���·����д���:\n");
	int a, b;
	scanf_s("%d %d", &a, &b);
	while (a < 1 || a > JXNUmap.n || b < 1 || b>JXNUmap.n || a == b) {
		if (a == b)
			printf("����˰ɣ�����զһ���أ���\n");
		else
			printf("�������������С��1�� �����%d��������\n", JXNUmap.n);
		scanf_s("%d %d", &a, &b);
	}


	if (JXNUmap.edges[a - 1][b - 1] != INFINITY) {
		printf("%s��%s֮������·�Ѿ����ˣ���Ҫ����ӣ�\n", JXNUmap.vers[a - 1].name, JXNUmap.vers[b - 1].name);
		return;
	}
	else
	{
		int distance;
		printf("������%s��%s֮���·�ĳ��ȣ�\n", JXNUmap.vers[a - 1].name, JXNUmap.vers[b - 1].name);
		scanf_s("%d", &distance);
		while (distance <= 0 || distance >= INFINITY)
		{
			printf("�������������,����������:\n");
			scanf_s("%d", &distance);
		}
		printf("������ӵ�·...\n");
		JXNUmap.edges[a - 1][b - 1] = JXNUmap.edges[b - 1][a - 1] = distance;
		JXNUmap.e++;

		printf("����·��ӳɹ��ˣ�\n");
		printf("%s��%s���ڵ�·Ϊ%dm\n", JXNUmap.vers[a - 1].name, JXNUmap.vers[b - 1].name, JXNUmap.edges[b - 1][a - 1]);
		printf("��Ҫ�Ӿ�����1�����������ַ����˳�\n");
		int flag;
		scanf_s("%d", &flag);
		if (flag == True) {
			addPath();
		}
		else {
			printf("1s���˳���������\n");
			Sleep(1000);
		}
	}
	return;
}

void delPath(void) {
	if (JXNUmap.n <= 1) {
		printf("ʦ�󾰵��������� ɾ���ˣ���ȥ��·��\n");
		return;
	}
	if (JXNUmap.e <= 0)
	{
		printf("��ͼ�����κε�·��������ӣ�\n");
		return;
	}
	showInfo();
	printf("��������Ҫɾ����������֮���·����д���:\n");
	int a, b;
	scanf_s("%d %d", &a, &b);
	while (a < 1 || a > JXNUmap.n || b < 1 || b>JXNUmap.n || a == b) {
		if (a == b)
			printf("����˰ɣ�����զһ���أ���\n");
		else
			printf("�������������С��1�� �����%d��������\n", JXNUmap.n);
		scanf_s("%d %d", &a, &b);
	}


	if (JXNUmap.edges[a - 1][b - 1] == INFINITY) {
		printf("%s��%s֮������·û�У���ɾ���·��\n", JXNUmap.vers[a - 1].name, JXNUmap.vers[b - 1].name);
		return;
	}
	else
	{
		printf("��Ҫɾ������%s��%s�ĵ�·,ȷ������1 \n", JXNUmap.vers[a - 1].name, JXNUmap.vers[b - 1].name);
		int flag;
		scanf_s("%d", &flag);
		if (flag == 1)
		{
			printf("����ɾ����·...\n");
			JXNUmap.edges[a - 1][b - 1] = JXNUmap.edges[b - 1][a - 1] = INFINITY;
			JXNUmap.e--;
			printf("ɾ���ɹ�\n");
			printf("��Ҫɾ��������1�����������ַ����˳�\n");
			scanf_s("%d", &flag);
			if (flag == True) {
				delPath();
			}
			else {
				printf("1s���˳���������\n");
				Sleep(1000);
			}
		}
		else {
			printf("1s��ص�������");
			Sleep(1000);
		}
	}

	return;
}
