//搞了一晚上，总是超时(1000ms)。换了printf，scanf就过了。400多ms。差距啊
//逆拓扑，然后用优先队列从大到小出队存储，输出时再次反向输出
//感觉题意歧义很大啊。。。
#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
const int max_size=30010;
int n,m;
int in[max_size];
priority_queue<int> q;
vector<int> map[max_size];
int s[max_size];
void topo()
{
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0)
        {
            q.push(i);
        }
    }
    int c=0;
    int top;
    while(!q.empty())
    {
        top=q.top();
        q.pop();
        s[c++]=top;
        for(int k=0;k<map[top].size();k++)
        {
            int to = map[top][k];
            in[to]--;
            if(in[to]==0)
                q.push(to);
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        printf("%d",s[i]);
        if(i!=0)
            printf(" ");
        else
            printf("\n");
    }
}
int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--)
    {   
        scanf("%d%d",&n,&m);
        memset(in,0,sizeof in);
        for(int i=1;i<=n;i++)
        {
            map[i].clear();
        }
        while(m--)
        {
            scanf("%d%d",&i,&j);
            map[j].push_back(i);
            in[i]++;
        }
        topo();
    }
    return 0;
}
