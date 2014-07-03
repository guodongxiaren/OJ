#include<stdio.h>
int a[10];
int fac(int n)
{
    int x=1,i;
    for(i=n;i>1;i--)
        x*=i;
    return x;
}
main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        int i,sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        int x=1;
        for(i=sum;i>sum-m;i--)
            x*=i;
        for(i=0;i<=m;i++)

    }
}
