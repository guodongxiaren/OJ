/*
 * 输入的时候要保留下来数据。为了更好地用并查集处理
*并查集的使用，使得逻辑上相同rating的点只有一个被保留，其余皆剔除图外。
*然后相当于用的都是不重复rating的点来构建图
*邻接矩阵存储会MLE
*每次都只能有一个入度为0的点，即每次将入度为0点出队后，减掉相连点的入度，
*接着只能得到一个入度为0的新点
*然后按照普通拓扑排序处理
*如果有环而冲突
*如果某一时刻有多个度为0的点，即有多个子图，故不确定
*既有冲突，又有不确定，输出冲突
*其余情况为OK
* */
#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAX=10005;
int k;
int root[MAX];
int in[MAX];
int head[MAX];
int le[MAX*2];
int ri[MAX*2];
char op[MAX*2];
struct Edge
{
    int to,next;
}edges[MAX*2];
void init(int n)
{
    k=0;
    memset(in,0,sizeof in);
    memset(head,-1,sizeof head);
    for(int i=0; i<n; i++)
        root[i]=i;
}
void add(int i,int j)
{
    in[j]++;
    edges[k].to=j;
    edges[k].next=head[i];
    head[i]=k++;
}
int get_root(int a)
{
    while(root[a]!=a)
        a=root[a];
    return a;
}
queue<int> q;
void topo(int n,int c)
{
    bool flag=false;
    for(int i=0; i<n; i++)
    {
        if(root[i]==i&&!in[i])
            q.push(i);
    }
    while(!q.empty())
    {
        if(q.size()>1)
            flag=true;
        int v=q.front();
        c--;
        q.pop();
        for(int k=head[v];k!=-1;k=edges[k].next)
        {
            int to=edges[k].to;
            in[to]--;
            if(!in[to])
                q.push(to);
        }
    }
    if(c>0)
        cout<<"CONFLICT"<<endl;
    else if(flag)
        cout<<"UNCERTAIN"<<endl;
    else
        cout<<"OK"<<endl;
}
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        if(!m)
        {
            cout<<"UNCERTAIN"<<endl;
            continue;
        }
        init(n);
        int l,r,c=n;
        bool flag=false;
        for(int i=0; i<m; i++)
        {
            cin>>le[i]>>op[i]>>ri[i];
            if(op[i]=='=')
            {
                r=get_root(ri[i]);
                l=get_root(le[i]);
                if(r!=l)
                root[l]=r;
            }
        }
        for(int i=0; i<m; i++)
        {
            l=get_root(le[i]);
            r=get_root(ri[i]);
            if(op[i]=='=')
            {
                c--;
                continue;
            }
            if(l==r)
            {
                flag=true;
                break;
            }
            if(op[i]=='>')
                add(l,r);
            else if(op[i]='<')
                add(r,l);
        }
        if(flag)
            cout<<"CONFLICT"<<endl;
        else
            topo(n,c);
    }
}
