#include<stdio.h>
int fibo(int);
int main()
{
    int a,b;
    printf("enter the limit %d",a);
    scanf("%d",&a);
    b=fibo(a);
    printf("%d",&b);
}
int fibo(int p)
{
    int f,i;
    f=0;
    for(i=1;i<p;i++)
    {
        printf("%d",i);
    }
        f=f+i;


}




