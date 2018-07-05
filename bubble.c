#include <stdio.h>
void BubbleSort(int* pData,int Count)
#if 0
{
	int iTemp;
	for(int i=1;i<Count;i++)	{
		for(int j=Count-1;j>=i;j--)	{
			if(pData[j]<pData[j-1])	{
				iTemp = pData[j-1];
				pData[j-1] = pData[j];
				pData[j] = iTemp;
			}
		}
	}
}
#else
{
	int iTemp;
	for(int i = 0; i<Count;i++)	{
		for(int j = 0; j < Count-1;j++)	{
			if (pData[j]>pData[j+1])	{
				iTemp = pData[j+1];
				pData[j+1] = pData[j];
				pData[j] = iTemp;
			}
		}
	}
}
#endif
void main()
{
	int data[] = {10,9,8,7,6,5,4}, i;
	BubbleSort(data,7);
	for (i=0;i<7;i++)
		fprintf(stdout, "%d ", data[i]);
	putchar('\n');
}
