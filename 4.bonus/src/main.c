#include "CMSIS/stm32f10x.h"
#include "stdlib.h"

// здесь 0 <= j < size - номер нужной позиции, начиная с нуля
int32_t getOrderStatistic(int32_t * buf, uint32_t size, uint32_t j);

void sort(int32_t * buf, uint32_t size);


int main(void)
{
	int32_t const N=10;
	
	int32_t buf[N];
//	for(int i=0; i<N; i++) 
//	{
//		buf[i] = rand()%1000-500;
//	}
	
	int32_t j=8;
	
	volatile int32_t answer=getOrderStatistic(buf,N,j);
	
	sort(buf,N);
	volatile int32_t check=buf[j];
	
	volatile int correct=(answer==check);
	
	while(1);
	return 0;
}

int32_t getOrderStatistic(int32_t * buf, uint32_t size, uint32_t j)
{
	int32_t l=0, k=size-1, temp;
	while(l<k)
	{
		while(buf[l]<buf[j]) l++;
		while(buf[k]>buf[j]) k--;
		if(l<k)
		{	
			temp=buf[l];
			buf[l]=buf[k];
			buf[k]=temp;
			if((l==j)||(k==j))
			{
				l=0;
				k=size-1;
			}
			else
			{
				l++;
				k--;
			}
		}
	}
	return buf[j];
}


void sort(int32_t * buf, uint32_t size)
 {
	int i=0;
	int temp;
	while (i< size)
	{
		if((i==0)||(buf[i-1]<=buf[i])) i++;
		else
		{
			temp=buf[i];
			buf[i]=buf[i-1];
			buf[i-1]=temp;
			i--;
		}
	}
 }