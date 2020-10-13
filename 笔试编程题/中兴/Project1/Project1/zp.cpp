/*
ά�˶಩ʿ������һ���ѱ䷴Ӧ�ѣ���ȡ�ô���Һ��״̬�ķ��������ʡ�
��Ӧ�ѵ�������V���ء�����Nƿ�ķ�����Һ�壬ÿ������һ����������
һ�����������Һ�嵹�뷴Ӧ��ʱ��Ҳ����һЩ��λ�����������ڣ�ά
�˶���Ҫ�����������󻯡����ǣ���һ���������������о���ԭ��Ԫ
�ص�����֪ʶ����ʷ����ʶ����Ӧ���ڷ�����Һ����������ܳ����ض�
���ٽ�����M������Ӧ�ͻ�ʧ�أ����������ҵı�ը��

дһ���㷨���������ӷ�Ӧ�ѻ��������������������������������

���룺

�ú��� / ���������������������------

reactorCap��һ����������ʾ��Ӧ�ѵ�����(V);
numberOfRadLiquid, һ����������ʾ����Сƿ������(N);
criticalMass��һ����������ʾ��Ӧ�ѵ�����ٽ�����(M);
volumes��һ�������б���˳���ʾN�ݷ�����Һ������;
masses��һ�������б���˳���ʾN�ݷ�����Һ�������;
energies, һ�������б���˳���ʾN�ݷ�����Һ�������������

�����
����һ����������ʾ�ɸ�����Լ�������´ӷ�Ӧ���в��������������

ʾ����
���룺
reactorCap = 100
numberOfRadLiquid = 5
criticalMass = 15
volumes = [50, 40, 30, 20, 10]
masses = [1, 2, 3, 9, 5]
energies = [300, 480, 270, 200, 180]

�����960
*/
#include<stdio.h>
void combination(int* input, int inputLen, int m, int* out, int outLen, int* volume, int reactorCap, 
	int* masses, int criticalMass, int numberOfRadLiquid, int* energies, int* energiesMax)
{
	//�����ĺ����ǣ���ȡ����inputǰinputLen���ֵĳ���Ϊm������������洢��out������
	//@input �������ϵ����ݣ�������{0,1,2,3,4}�����ִ��������λ��
	//@inputLen ��ȡinput��ǰinputLen���֣�����inputLen=3�����ȡinputΪ{0,1,2}
	//@m ��ȡ����Ϊm����ϣ�����m=2,inputLen=3������ܵ�����У�{0,1}{0,2}{1,2}
	//@out ��������ϵĽ���������ʼ���룬m=3����out����Ϊ{1,2,3}{1,2,4}��
	//@outLen out�ĳ���
	//���������Ϊ��Ŀ����
	int j;
	if (m == 0) // �˳��ݹ飬��ȡ��һ�����
	{
		//�жϸ�������µ��������Ƿ����ͬʱ������Լ������
		int volumeSum = 0, massesSum = 0, energiesSum = 0;
		for (j = 0; j<outLen; j++)
		{
			volumeSum += volume[out[j]];
			massesSum += masses[out[j]];
			energiesSum += energies[out[j]];
		}
		if (volumeSum <= reactorCap&&massesSum <= criticalMass)// �Ƿ�����Լ������
		{
			if (energiesSum>energiesMax[0]) // �ж��Ƿ����һ���洢��ֵ��
			{
				energiesMax[0] = energiesSum;
				for (int j = 0; j<outLen; j++) //
				{
					printf("%d", out[j]);//����������ʱ�����
					printf(" ");
				}
				printf("%d", energiesMax[0]); //����������
				printf("\n");
			}
		}
		return;
	}

	for (int i = inputLen; i >= m; i--) //ѭ���ݹ��ȡ�����
	{
		out[m - 1] = input[i - 1];
		combination(input, i - 1, m - 1, out, outLen, volume, reactorCap, 
			masses, criticalMass, numberOfRadLiquid, energies, energiesMax);
	}
}

int getMaxEnergies(int* volume, int reactorCap, int* masses, int criticalMass, int numberOfRadLiquid, int* energies)
{
	int i;
	int energiesMax[1] = { 0 }; //����������
	int *input = new int[numberOfRadLiquid]; //�������ϵ�����
	/*int input[numberOfRadLiquid]; */
	for (i = 0; i<numberOfRadLiquid; i++)   //��Ӧ�������ݣ�input={0,1,2,3,4}
	{
		input[i] = i;
	}

	for (i = 1; i <= numberOfRadLiquid; i++) //���������������1��2��3��4��5������֮��
	{
		int *out = new int[i];
		combination(input, numberOfRadLiquid, i, out, i, volume, reactorCap, 
			masses, criticalMass, numberOfRadLiquid, energies, energiesMax);
	}
	return energiesMax[0];
}

int main()
{
	int reactorCap = 100; //��Ӧ�ѵ�������V��
	int numberOfRadLiquid = 5;  //����Сƿ������N��
	int criticalMass = 15;  //��Ӧ�ѵ�����ٽ�������M��
	int volume[5] = { 50, 40, 30, 20, 10 };//���
	int masses[5] = { 1, 2, 3, 9, 5 };//����
	int energies[5] = { 300, 480, 270, 200, 180 }; //����
	int energiesMax[1] = { 0 }; //����������

	energiesMax[0]=getMaxEnergies(volume, reactorCap, masses, criticalMass, numberOfRadLiquid, energies);
	printf("�������Ϊ");
	printf("%d", energiesMax[0]);
}