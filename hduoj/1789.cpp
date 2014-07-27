#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAX=1005;
bool used[MAX];
struct sub{
    int d,s;
}item[MAX];
bool operator <(const sub& a,const sub& b)
{
    return a.s>b.s;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(used,0,sizeof used);
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
           scanf("%d",&item[i].d);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&item[i].s);
        }
        sort(item,item+n);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            int p;
            for(p=item[i].d;p>0;p--)
            {
                if(!used[p])
                {
                    used[p]=1;
                    break;
                }
            }
            if(p<=0)
                sum+=item[i].s;
        }
        printf("%d\n",sum);
    }
}
