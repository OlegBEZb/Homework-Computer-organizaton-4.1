#include "CMSIS/stm32f10x.h"
#include "stdlib.h"

// здесь 0 <= j < size - номер нужной позиции, начиная с нуля
int32_t getOrderStatistic(int32_t * buf, uint32_t size, uint32_t j);

void sort(int32_t * buf, uint32_t size);

int main(void)
{
	int32_t const N=20;//задаём размер массива
	int32_t buf[N];
	for(int i=0; i<N; i++) 
	{
		buf[i] = rand()%1000-500;
	}//массив инициализируется случайными числами от -500 до 499 
	
	int32_t j=5;//жипорядковая статистика
	
	volatile int32_t answer=getOrderStatistic(buf,N,j);//что даёт честно украденый алгоритм
	
	sort(buf,N);
	volatile int32_t check=buf[j];
	volatile int correct=(answer==check);//проверяем
	
	while(1);
	return 0;
}

int32_t getOrderStatistic(int32_t * buf, uint32_t size, uint32_t j)
{
	int32_t L=0, R=size-1, temp, l, r;
	
	while(L<R)
	{
		l=L;
		r=R;
		while(buf[l]<buf[j]) l++;
		while(buf[r]>buf[j]) r--;
		if(l<=r)
		{
			temp=buf[l];
			buf[l]=buf[r];
			buf[r]=temp;
			l++;
			r--;
		}
		if(r<j) L=l;
		if(j<l) R=r;
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
