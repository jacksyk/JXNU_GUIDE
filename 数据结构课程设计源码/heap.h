#pragma once

#include "first.h"

// 小根堆的实现

int vis[MaxVerNum];
int dis[MaxVerNum];
int len = 0;
int pre[MaxVerNum];

typedef struct {
	int num;
	int val;
}dot;
dot heap[MaxVerNum];

//交换操作
void swap(dot* a, dot* b) {
	dot t;
	t = *a;
	*a = *b;
	*b = t;
}

//手写堆的push操作
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

//手写堆的pop操作
dot pop() {
	dot top = heap[1];
	swap(&heap[1], &heap[len--]);

	int pa = 1, son = 2;
	while (son <= len) {
		if (heap[son].val > heap[son + 1].val && son < len) {	//别忘了判断son + 1是否超过len
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
