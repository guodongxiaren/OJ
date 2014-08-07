#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[505],b[505];
int dp[505][505];
int main()
{
    while(~scanf("%s%s",a,b))
    {
        int len1=strlen(a);
        int len2=strlen(b);
        for(int i=0;i<len1;i++)
            dp[0][i]=0;
        for(int i=0;i<len2;i++)
            dp[i][0]=0;
        for(int i=1;i<=len1;i++)
        {
            for(int j=1;j<=len2;j++)
            {
                if(a[i-1]==b[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        printf("%d\n",dp[len1][len2]);

    }
}
