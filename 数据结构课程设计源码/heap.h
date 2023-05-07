#pragma once

#include "first.h"

// С���ѵ�ʵ��

int vis[MaxVerNum];
int dis[MaxVerNum];
int len = 0;
int pre[MaxVerNum];

typedef struct {
	int num;
	int val;
}dot;
dot heap[MaxVerNum];

//��������
void swap(dot* a, dot* b) {
	dot t;
	t = *a;
	*a = *b;
	*b = t;
}

//��д�ѵ�push����
void push(dot n) {
	heap[++len] = n;

	int son = len;
	while (son / 2) {
		if (heap[son / 2].val > heap[son].val) {
			swap(&heap[son / 2], &heap[son]);
			son /= 2;
		}
		else
			break;
	}
}

//��д�ѵ�pop����
dot pop() {
	dot top = heap[1];
	swap(&heap[1], &heap[len--]);

	int pa = 1, son = 2;
	while (son <= len) {
		if (heap[son].val > heap[son + 1].val && son < len) {	//�������ж�son + 1�Ƿ񳬹�len
			son++;
		}

		if (heap[son].val > heap[pa].val)
			break;
		swap(&heap[son], &heap[pa]);
		pa = son;
		son = pa * 2;
	}

	return top;
}
