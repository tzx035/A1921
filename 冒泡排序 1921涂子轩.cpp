#include<stdio.h>

void sort(int *a,int len)

{int i=0;

int j;

int t;

for(i=0;i<len-1;i++)

{

for(j=0;j<len-i-1;j++)

{

if(a[j]>a[j+1])

{

t=a[j];

a[j]=a[j+1];

a[j+1]=t;

}

}

}

}

int main(int argc, char *argv[])

{

int a[10]={
90,98,60,98,96,83,66,73,44,74
};

int i=0;

sort(a,10);

for(i=0;i<10;i++)

{

printf("%d",a[i]);

}

return 0;

}
