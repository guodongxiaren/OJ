#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,j,k,a[111111];
int ans = 0;
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",a+i);
    if(n==1)
    {        
        printf("%d\n%d\n",a[1],a[1]);
        return 0;
    }
    int nn = n;
    sort(a+1,a+n+1);
    while(n>3)
    {
        if(a[1]+a[n-1]<2*a[2])
            ans += a[n]+a[1]*2+a[n-1];
        else
            ans += a[2]*2+a[1]+a[n];
        n -=2;
    }
    if(n==2)
    ans += a[2];
    else
    ans +=a[1]+a[2]+a[3];
    printf("%d\n",ans);
    n = nn;
    while(n>3)
    {
        if(a[1]+a[n-1]<2*a[2])
            printf("%d %d\n%d\n%d %d\n%d\n",a[1],a[n],a[1],a[1],a[n-1],a[1]);
        else
            printf("%d %d\n%d\n%d %d\n%d\n",a[1],a[2],a[1],a[n-1],a[n],a[2]);
        n -=2;
    }
    if(n==2)
    printf("%d %d\n",a[1],a[2]);
    else
    printf("%d %d\n%d\n%d %d\n",a[1],a[3],a[1],a[1],a[2]);

}

