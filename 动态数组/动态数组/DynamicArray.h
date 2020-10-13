#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//��̬�����ڴ棬���� ��������ݵ��ڴ�ŵ�����
//��̬���� ���5��Ԫ�� �����ڴ� ����Ԫ�� �ͷ��ڴ�     6������   7������
//capacity ��ʾ����ڴ�ռ�һ�����Դ�Ŷ���Ԫ��
//size ��¼��ǰ�����о����Ԫ�ظ���

typedef struct DYNAMICARRAY
{
	int* pAddr;//������ݵĵ�ַ
	int size;//��ǰ�ж���Ԫ��
	int capacity;//��ǰ����������
}Dynamic_Array;

//дһϵ�е���ضԽṹ������ĺ���
//��ʼ��
Dynamic_Array* Init_Array();
//����
void PushBack_Array(Dynamic_Array* arr, int value);
//����λ��ɾ��
void RemoveByPos_Array(Dynamic_Array* arr, int Pos);
//����ֵɾ��
void RemoveByValue_Array(Dynamic_Array* arr, int value);
//����
int Find_Array(Dynamic_Array* arr, int value);
//��ӡ
void Print_Array(Dynamic_Array* arr);
//�ͷŶ�̬������ڴ�
void FreeSpace_Array(Dynamic_Array* arr);
//�������
void Clear_Array(Dynamic_Array* arr);
//��ö�̬��������
int Capacity_Array(Dynamic_Array* arr);
//��ö�̬���鵱ǰԪ�ظ���
int Size_Array(Dynamic_Array* arr);
//����λ�û��ĳ��λ��Ԫ��
int At_Array(Dynamic_Array* arr, int Pos);