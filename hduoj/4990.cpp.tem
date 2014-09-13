#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include<iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include<vector>

const int MAX=100000*2;
const int INF=1e9;

int main()
{
    int n,m,ans,i;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        ans=0;
        if(n&1)
        {
            n--;
            if(!n)
            ans=0;
            else
            ans=2*pow(4,n/2-1)+2*pow(4,n/2-2)+2;
            ans=ans*2+1;
        }
        else
        {
            if(n==2)
            ans=2;
            else
            ans=2*pow(4,n/2-1)+2*pow(4,n/2-2)+2;
        }
        printf("%d\n",ans);
    }
    return 0;
}
