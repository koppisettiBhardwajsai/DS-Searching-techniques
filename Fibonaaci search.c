#include<stdio.h>
#define min(a,b) a < b ? a : b //macro
//int min(int a,int b)    
//{
//  return a < b ? a : b;
//}
//int min(int a,int b)
//{
//	if(a<b) return a;
//	else return b;
//}
int fibonaaci(int *d,int n,int se)
{
	int a,b,i; 
	a=0;
	b=1;
	int c=a+b;
	int offset;
	while(c<n)
	{
		a=b;
		b=c;
		c=a+b;
	}
	offset=-1;
	while(c>1)
	{
	 i=min(offset+a,n-1);
	 if(se==d[i]) return i;//elemen found
     else if(se>d[i])
	{
		//bring all 3 fib numbers 1 fib dowm
		c=b;
		b=a;
		a=c-b;
		//set offset to index
		offset=i;
	}
	else if(se<d[i])
	{
		//bring all 3 fib numbers 2 fib down
		c=a;
		b=b-a;
		a=c-b;
	}
	}
	if(b && d[offset+1]==se){
		return offset + 1;
	}
	return -1;
}
int main()
{
	int n,j,i;
	scanf("%d",&n);
	int d[n];
	for(j=0;j<n;j++)
	{
		scanf("%d",&d[j]);
	}
	int se;
	scanf("%d",&se);
	 i=fibonaaci(d,n,se);
	if(i==-1)
	{
		printf("Element is not present");
	}
	else
	{
		printf("Element is found at %d index",i);
	}
}
