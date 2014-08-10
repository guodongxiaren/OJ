//虽然经过了w排序，但是在下面比较的时候，还是要比较w
//因为如果不再比较一次，则会出现w相同的情况
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAX=1005;
struct mouse
{
    int i,w,s;
};
mouse mice[MAX];
int dp[MAX];
int pre[MAX];
int seq[MAX];
bool operator<(const mouse&a,const mouse&b)
{
    return a.w<b.w;
}
int main()
{
    int n=0;
    while(cin>>mice[n].w>>mice[n].s)
    {
        mice[n].i=n+1;
        pre[n]=-1;
        dp[n]=1;
        n++;
    }
    sort(mice,mice+n);
    int len = 0,p = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(mice[j].w>mice[i].w&&mice[j].s<mice[i].s&&dp[j]<dp[i]+1)
            {
                dp[j]=dp[i]+1;
                pre[j]=i;
            }
            if(len<dp[j])
            {
                len=dp[j];
                p=j;
            }
        }
    }
    cout<<len<<endl;
    int i=p;
    int j=0;
    while(i!=-1)
    {
        seq[j++]=mice[i].i;
        i=pre[i];
    }
    for(i=len-1; i>=0; i--)
        cout<<seq[i]<<endl;
}
