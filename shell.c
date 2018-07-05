#include <stdio.h>
void ShellSort(int* pData,int Count)
{
	int i, j, step;

	for (step = Count / 2; step > 0; step /= 2) //步长
	{
		for (i = 0; i < step; i++)        //直接插入排序
		{
			for (j = i + step; j < Count; j += step)
				if (pData[j] < pData[j - step])
				{
					int temp = pData[j];
					int k = j - step;
					while (k >= 0 && pData[k] > temp)
					{
						pData[k + step] = pData[k];
						k -= step;
					}
					pData[k + step] = temp;
				}
		}
	}
}

void main()
{
	int data[] = {10,9,8,7,6,5,4,3,2,1,-10,-1};
	ShellSort(data,12);
	for (int i=0;i<12;i++)
		fprintf (stdout, "%d ", data[i]);
	putchar ('\n');
}
