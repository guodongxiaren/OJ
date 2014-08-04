//经典题目，A了一天。DP+二分
//普通的LIS的O(N^2)算法，会超时
//用二分进行搜索就降到了O(NlgN)
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int max_size=500005;
int r[max_size];
int dp[max_size];
int len;
void update(int n,int x)
{
    int low=1,high=n,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(dp[mid]<x)
            low=mid+1;
        else
            high=mid-1;
    }
    dp[low]=x;
    if(low>n)
        len++;
}
int main()
{
    int n;
    int cas=1;
    while(~scanf("%d",&n))
    {
        int x,y;
        len=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&x,&y);
            r[x]=y;
        }
        for(int i=1;i<=n;i++)
        {
            update(len,r[i]);
        }
        printf("Case %d:\nMy king, at most %d %s can be built.\n\n",cas++,len,
               len==1?"road":"roads");
    }
}
