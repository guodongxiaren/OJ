#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAX=1004;
int a[MAX][MAX];
int dp[MAX];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int m,n,x,y;
        memset(a,0,sizeof a);
        scanf("%d%d%d%d",&m,&n,&x,&y);
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                scanf("%d",&a[i][j]);
                a[i][j]+=a[i-1][j];
            }
        }
        int max_sum=0;
        for(int i=x; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                dp[j]=a[i][j]-a[i-x][j];
                dp[j]+=dp[j-1];
                if(j>=y)
                {
                    max_sum=max(max_sum,dp[j]-dp[j-y]);
                }
            }
        }
        printf("%d\n",max_sum);

    }
}
