#include<stdio.h>
#include<stdlib.h>
int *queue,*arr,frame_size,size,fault_count=0;
void display(int);
int main()
{
	printf("Enter the size of the reference String: ");
	scanf("%d",&size);
	printf("\n Enter the frame size:  ");
	scanf("%d",&frame_size);
	queue=(int*)calloc(frame_size,sizeof(int));
	arr=(int *)calloc(size,sizeof(int));
	for(int i=0;i<size;i++)
	arr[i]=rand()%10;
	printf("REFERENCE STRING:\n");
	for(int i=0;i<size;i++)
	printf("%d\t",arr[i]);
	for(int i=0;i<frame_size;i++)
	queue[i]=1000;
	printf("\n\n");
	int j=0;
	for(int i=0;i<size;i++)
	{	
	  	int avail=0;
    	for(int k=0;k<frame_size;k++)
		{
			if(queue[k]==arr[i])
        	{
			avail=1;
			break;
			}
    	}
		if(i<frame_size && avail==0)
		{
			queue[j]=arr[i];
			fault_count++;
			display(j);
			j=(j+1)%frame_size;
			continue;
		}
		if(avail==0)
		{
			queue[j]=arr[i];
            j=(j+1)%frame_size;
			fault_count++;
			display(frame_size-1);
		}
	}
	printf("\nPAGE FAULT: %d",fault_count);
}
void display(int border)
{	printf("\n");	
	for(int i=0;i<=border;i++)
		printf("|%d|",queue[i]);
	printf("\n");
}
