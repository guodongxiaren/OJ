#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[2005][2005];
char s[30],m[2005],k[2005];
int b[30];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        scanf("%s",s);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&b[s[i]-'a']);
        }
        scanf("%s%s",m,k);
        int n1=strlen(m);
        int n2=strlen(k);
        memset(dp,0,sizeof(int)*(n1+1));
        for(int i=0;i<=n2;i++)
            dp[0][i]=0;
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(m[i-1]==k[j-1])
                    dp[i][j]=dp[i-1][j-1]+b[m[i-1]-'a'];
                else 
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        printf("%d\n",dp[n1][n2]);
    }
}
