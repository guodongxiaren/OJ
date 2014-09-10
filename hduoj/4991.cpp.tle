#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int s[10005];
int dp[10005][105];
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        memset(s,0,sizeof(s));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&s[i]);
            dp[i][1]=1;
        }
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=2;j<=m;j++)
            {
                sum=0;
                for(int k=1;k<i;k++)
                {
                    if(s[k]<s[i])
                    {
                        sum+=(dp[k][j-1])%123456789;
                    }
                }
                dp[i][j]=sum;
            }
        }
        sum=0;
        for(int i=1;i<=n;i++)
        {
            sum+=dp[i][m];
        }
        printf("%d\n",sum);
    }
}

