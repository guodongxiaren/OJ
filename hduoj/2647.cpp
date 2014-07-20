#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
const int max_size=10001;
int n,m;
int head[max_size];
int in[max_size];
int reward[max_size];
queue<int> q;
struct Edge
{
    int to;
    int next;
    Edge(){};
    Edge(int i,int j):to(i),next(j){};
};
Edge edges[max_size*2];
void add(int i,int j)
{
    static int k=0;
    edges[k].to=j;
    edges[k].next=head[i];
    head[i]=k++;
    if(k==m)
        k=0;
}
void topo()
{
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0)
        {
            reward[i]=0;
            q.push(i);
        }
    }
    int top;
    int to;
    while(!q.empty())
    {
        top=q.front();
        q.pop();
        for(int k=head[top];k!=-1;k=edges[k].next)
        {
            to = edges[k].to;
            in[to]--;
            if(in[to]==0)
                q.push(to);
            reward[to]=reward[top]+1;
        }
    }
    int sum=n*888;
    for(int i=1;i<=n;i++)
    {
        if(reward[i]<0)
        {
            cout<<-1<<endl;
            return;
        }
        sum+=reward[i];
    }
    cout<<sum<<endl;
}
int main()
{
    int i,j;
    while(cin>>n>>m)
    {
        memset(in,0,sizeof in);
        memset(head,-1,sizeof head);
        memset(reward,-1,sizeof reward);
        for(int t=0;t<m;t++)
        {
            cin>>i>>j;
            add(j,i);
            in[i]++;
        }
        topo();
    }
}
