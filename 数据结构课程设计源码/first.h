#define _CRT_SECURE_NO_WARNINGS 1	//��ֹscanf����
#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>

#define MaxVerNum 100				//���ڵ���
#define	MaxNameLength 100			//�ڵ�������󳤶�
#define MaxDescribeLength 1000		//�ڵ���������󳤶�
#define PASSWORD "root"				//����Ա����
#define PASSWORDLENGTH 20			//���볤��
#define INFINITY 100000
#define DELAY 982337369 
#define CONFIRMATION "QUEREN"
#define True 1						//��������
#define False 0

//����洢���ݽṹ��
typedef struct {
	int num;
	char name[MaxNameLength];
	char features[MaxDescribeLength];	//�ڵ�����
}VertexType;	//�ڵ�����

typedef int EdgeType; //������

typedef struct {
	VertexType vers[MaxVerNum];
	EdgeType edges[MaxVerNum][MaxVerNum];
	int n;
	int e;
}MGraph;	//ͼ����

//ȫ�ֱ���
MGraph  JXNUmap;			//����У԰����ͼ
static int flag = 1;	//�ڱ������������ж��û�Ȩ��