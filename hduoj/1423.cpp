//LCIS,最长公共递增子序列。使用了滚动数组。降低内存。
//dp[i]保存以b[i]结尾的最大LCIS。
//最终结果不是在dp[len2]中，因为不一定是以b[len2]结尾的。
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[505],b[505];
int dp[505];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int len1,len2;
        scanf("%d",&len1);
        for(int i=0;i<len1;i++)
            scanf("%d",&a[i]);
        scanf("%d",&len2);
        for(int i=0;i<len2;i++)
            scanf("%d",&b[i]);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=len1;i++)
        {
            int MAX=0;
            for(int j=1;j<=len2;j++)
            {
                if(a[i-1]==b[j-1])
                    dp[j]=MAX+1;
                else if(a[i-1]>b[j-1])
                    MAX=max(MAX,dp[j]);
            }
        }
        printf("%d\n",*max_element(dp+1,dp+len2+1));
        if(t) puts("");
    }
}
