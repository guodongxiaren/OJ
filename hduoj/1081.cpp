#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAX=104;
int a[MAX][MAX];
int dp[MAX];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(a,0,sizeof a);
        memset(dp,0,sizeof dp);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                scanf("%d",&a[i][j]);
                a[i][j]+=a[i-1][j];
            }
        }
        int max_sum=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<i; j++)
            {
                for(int k=1; k<=n; k++)
                {
                    dp[k]=a[i][k]-a[j][k];
                    dp[k]+=dp[k-1];
                    if(dp[k]<0)
                        dp[k]=0;
                    if(dp[k]>max_sum)
                        max_sum=dp[k];
                }
            }
        }
        printf("%d\n",max_sum);
    }
}
