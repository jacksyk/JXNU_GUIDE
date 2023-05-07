#define _CRT_SECURE_NO_WARNINGS 1	//防止scanf报错
#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>

#define MaxVerNum 100				//最大节点数
#define	MaxNameLength 100			//节点名的最大长度
#define MaxDescribeLength 1000		//节点描述的最大长度
#define PASSWORD "root"				//管理员密码
#define PASSWORDLENGTH 20			//密码长度
#define INFINITY 100000
#define DELAY 982337369 
#define CONFIRMATION "QUEREN"
#define True 1						//布尔常量
#define False 0

//构造存储数据结构体
typedef struct {
	int num;
	char name[MaxNameLength];
	char features[MaxDescribeLength];	//节点描述
}VertexType;	//节点类型

typedef int EdgeType; //边类型

typedef struct {
	VertexType vers[MaxVerNum];
	EdgeType edges[MaxVerNum][MaxVerNum];
	int n;
	int e;
}MGraph;	//图类型

//全局变量
MGraph  JXNUmap;			//生成校园导航图
static int flag = 1;	//哨兵变量，用于判断用户权限