#include<stdio.h>
void printarr(int num,int *arr,int size)
{
    int i;
    printf("\n array %d is \n",num);
    for(i=0;i<size;i++)
        printf("%4d",arr[i]);
}
void mergearrays(int *a,int asize,int *b,int bsize,int *c)
{
    int ap=0,bp=0,cp=0;
    while(ap<asize && bp<bsize)
    {
        if(a[ap]<b[bp])
            c[cp++]=a[ap++];
        else
           c[cp++]=b[bp++];
    }
    while(ap<asize)
        c[cp++]=a[ap++];
    while(bp<bsize)
        c[cp++]=b[bp++];
}
void main()
{
    int a[10]={33,40,54,60,65,67,77,85,95,100};
    int b[5]={20,30,40,50,60},ap=0,bp=0,cp=0,c[15],i,j;
    printarr(1,a,10);
    printarr(2,b,5);
    mergearrays(a,10,b,5,c);
    printarr(3,c,15);
}
