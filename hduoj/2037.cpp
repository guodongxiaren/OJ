#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=105;
bool f[MAX];
struct jiemu
{
    int s;
    int e;
};
jiemu dis[MAX];
bool operator<(const jiemu &a,const jiemu &b)
{
    return a.e<b.e;
}
int main()
{
    int n;
    while(scanf("%d",&n))
    {
        if(!n)
        break;
        memset(f,0,sizeof f);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&dis[i].s,&dis[i].e);
        }
        sort(dis,dis+n);
        int sum=1;
        int p=0;
        for(int j=1;j<n;j++)
        {
            if(dis[j].s>=dis[p].e)
            {
                sum++;
                p=j;
            }
        }
        printf("%d\n",sum);
    }

}
