#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

//˳����нṹ��
typedef struct SEQQUEUE
{
	void* data[MAX_SIZE];
	int size;
}SeqQueue;

//��ʼ��
SeqQueue* Init_SeqQueue();
//���
void Push_SeqQueue(SeqQueue* queue, void* data);
//���ض�ͷԪ��
void* Front_SeqQueue(SeqQueue* queue);
//����
void Pop_SeqQueue(SeqQueue* queue);
//���ض�βԪ��
void* Back_SeqQueue(SeqQueue* queue);
//���ش�С
int Size_SeqQueue(SeqQueue* queue);
//��ն���
void Clear_SeqQueue(SeqQueue* queue);
//����
void FreeSpace_SeqQueue(SeqQueue* queue);