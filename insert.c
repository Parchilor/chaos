#include <stdio.h>
void SelectSort(int* pData,int Count)
{
	int iTemp;
	int iPos;
	int i, j;
	for(i=0; i<Count-1; i++)	{
		iTemp = pData[i];
		iPos = i;
		for(j=i+1; j < Count; j++)	{
			if(pData[j] < iTemp)	{
				iTemp = pData[j];
				iPos = j;
			}
		}
		pData[iPos] = pData[i];
		pData[i] = iTemp;
	}
}
int
main(int argc, char *argv[])
{
	int data[] = {10,9,8,7,6,5,4}, i;
	SelectSort(data,7);
	for (i=0;i<7;i++)
		fprintf (stdout, "%d ", data[i]);
	putchar ('\n');
}
