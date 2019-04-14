#include<stdio.h>
int main()
{
	printf("\n------------------LOOK DISK SCHEDULING ALGORITHM--------------------\n");
	int previous=125,current=143,distance=0;
	int request[] = {86, 1470, 913, 1774, 948, 1509, 1022, 1750, 130},low[50],high[50];
	int length_request=sizeof(request)/sizeof(int),length_low=0,length_high=0,temp;
	int i,j,flag;
	
	//dividing request array into two halves according to current request
	for(i=0;i<length_request;i++)
	{
		if(request[i]>=current)
		{
			high[length_high]=request[i];
			length_high++;
		}
		else
		{
			low[length_low]=request[i];
			length_low++;
		}
	}
	
	printf("\nHigh array content : ");
	for(i=0;i<length_high;i++)
	printf(" %d",high[i]);
	
	printf("\nLow array content : ");
	for(i=0;i<length_low;i++)
	printf(" %d",low[i]);
	
	//sorting high array in ascending order
	for(i=0;i<length_high-1;i++)
	{
		for(j=0;j<length_high-i-1;j++)
		{
			if(high[j] > high[j+1])
			{
				temp=high[j];
				high[j] = high[j+1];
				high[j+1] = temp;
			}
		}
	}
	
	//sorting low array in descending order
	for(i=0;i<length_low-1;i++)
	{
		for(j=0;j<length_low-i-1;j++)
		{
			if(low[j] < low[j+1])
			{
				temp=low[j];
				low[j] = low[j+1];
				low[j+1] = temp;
			}
		}
	}
	
	printf("\nHigh array content after sorting(ascending) : ");
	for(i=0;i<length_high;i++)
	printf(" %d",high[i]);
	
	printf("\nLow array content after sorting(descending) : ");
	for(i=0;i<length_low;i++)
	printf(" %d",low[i]);
	
	//for finding the direction in which disk arm will move
	if(previous<current)
	flag=0;
	else
	flag=1;
}
