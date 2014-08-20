/*hdu oj的gcc/g++64位整型是不能用longlong的。只能__int64,%I64d*/
#include<stdio.h>
__int64 fibo[51];
void init()
{
    int i;
    fibo[0]=0;
    fibo[1]=1;
    fibo[2]=2;
    for(i=3; i<=50; i++)
    {
        fibo[i]=fibo[i-1]+fibo[i-2];
    }
}
int main()
{
    int n;
    init();
    scanf("%d",&n);
    while(n--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        b-=a;
        printf("%I64d\n",fibo[b]);
    }
}
