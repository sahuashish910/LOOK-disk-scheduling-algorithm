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
	
	//for finding the direction in which disk arm will move
	if(previous<current)  
	flag=0;   //moves in upward direction : high array will be executed first
	else
	flag=1;   //moves in downward direction : low array will be executed first
	
	printf("\n\t    Current(From)     Next(To)   Distance covered");
	switch(flag)
	{
		case 0:
			for(i=0;i<length_high;i++)
			{
				distance=distance+(high[i]-current);
				printf("\n\t\t%d\t\t%d\t\t%d",current,high[i],high[i]-current);
				if(i==length_high)
				continue;
				else
				current=high[i];
			}
			for(i=0;i<length_low;i++)
			{
				distance=distance+(current-low[i]);
				printf("\n\t\t%d\t\t%d\t\t%d",current,low[i],current-low[i]);
				current=low[i];
			}
			printf("\n Total seek distance : %d",distance);
			break;
			
		case 1:
			for(i=0;i<length_low;i++)
			{
				distance+=(current-low[i]);
				printf("\n\t\t%d\t\t%d\t\t%d",current,low[i],current-low[i]);
				if(i==length_low)
				continue;
				else
				current=low[i];
			}
			for(i=0;i<length_high;i++)
			{
				distance+=(high[i]-current);
				printf("\n\t\t%d\t\t%d\t\t%d",current,high[i],high[i]-current);
				current=low[i];
			}
			printf(" %d",distance);
			break;
	}
}

