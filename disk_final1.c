#include<stdio.h>
int main()
{
	printf("\n------------------LOOK DISK SCHEDULING ALGORITHM--------------------\n");
	
	int previous_request=0,current_request=0,total_distance=0,no_cylinder=0;
	int no_request=0,no_lower=0,no_upper=0,temp;
	int i,j,flag;
	
	printf("\nEnter no. of cylinder : ");
	scanf("%d",&no_cylinder);
	printf("Enter previous request cylinder : ");
	scanf("%d",&previous_request);
	printf("Enter current request cylinder : ");
	scanf("%d",&current_request);
	printf("Enter the no. of request : ");
	scanf("%d",&no_request);
	
	int request_data[no_request],array_lower[no_request],array_upper[no_request],t=0;
	
	//taking input request
	printf("\nEnter the request cylinder within 0 and bound %d\n",no_cylinder);
	for(i=0;i<no_request;i++)
	{
		printf("Request %d : ",(i+1));
		scanf("%d",&t);
		if((t<0) || (t>=no_cylinder))
		i--;
		else
		request_data[i]=t;
	}
	
	//dividing request array into two halves according to current request
	for(i=0;i<no_request;i++)
	{
		if(request_data[i]>=current_request)
		{
			array_upper[no_upper]=request_data[i];
			no_upper++;
		}
		else
		{
			array_lower[no_lower]=request_data[i];
			no_lower++;
		}
	}
	
	//sorting high array in ascending order
	for(i=0;i<no_upper-1;i++)
	{
		for(j=0;j<no_upper-i-1;j++)
		{
			if(array_upper[j] > array_upper[j+1])
			{
				temp=array_upper[j];
				array_upper[j] = array_upper[j+1];
				array_upper[j+1] = temp;
			}
		}
	}
	
	//sorting low array in descending order
	for(i=0;i<no_lower-1;i++)
	{
		for(j=0;j<no_lower-i-1;j++)
		{
			if(array_lower[j] < array_lower[j+1])
			{
				temp=array_lower[j];
				array_lower[j] = array_lower[j+1];
				array_lower[j+1] = temp;
			}
		}
	}
	
	//for finding the direction in which disk arm will move
	if(previous_request<current_request)  
	flag=0;   //moves in upward direction : high array will be executed first
	else
	flag=1;   //moves in downward direction : low array will be executed first
	
	printf("\n\t    Current(From)     Next(To)   Distance covered");
	if(flag==0)
	{
		for(i=0;i<no_upper;i++)
		{
			total_distance=total_distance+(array_upper[i]-current_request);
			printf("\n\t\t%d\t\t%d\t\t%d",current_request,array_upper[i],array_upper[i]-current_request);
			if(i==no_upper)
			continue;
			else
			current_request=array_upper[i];
		}
		for(i=0;i<no_lower;i++)
		{
			total_distance=total_distance+(current_request-array_lower[i]);
			printf("\n\t\t%d\t\t%d\t\t%d",current_request,array_lower[i],current_request-array_lower[i]);
			current_request=array_lower[i];
		}
		printf("\n Total seek distance : %d",total_distance);
	
	}
	if(flag==1)
	{
		for(i=0;i<no_lower;i++)
		{
			total_distance+=(current_request-array_lower[i]);
			printf("\n\t\t%d\t\t%d\t\t%d",current_request,array_lower[i],current_request-array_lower[i]);
			if(i==no_lower)
			continue;
			else
			current_request=array_lower[i];
		}
		for(i=0;i<no_upper;i++)
		{
			total_distance+=(array_upper[i]-current_request);
			printf("\n\t\t%d\t\t%d\t\t%d",current_request,array_upper[i],array_upper[i]-current_request);
			current_request=array_upper[i];
		}
		printf("\n Total seek distance : %d",total_distance);
	}
}
