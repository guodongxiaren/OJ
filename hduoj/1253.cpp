//开始没有用做标记的方法BFS。导致MLE。只多几十k
//讨论区有个什么短码王的逗比，该题排名第一。
//提出剪枝方案a+b+c-3>ti,实际没有优化多少。
//还有人说0 0 0位置若是1则直接输出-1.我加上这个判定也WA了
//发现了编译器的规律。C++不易超时，但更容易超内存G++正好相反，果然是时间空间不可兼得。
#include<iostream>
#include<queue>
using namespace std;
#include<cstdio>
#include<cstring>
#define INF 0x3f3f3f3f
struct node
{
    int x,y,z;
    int level;
    node(int i,int j,int k,int l):x(i),y(j),z(k),level(l){};
    void set(int i,int j,int k,int l)
    {
        x=i;
        y=j;
        z=k;
        level=l;
    }
};
int d[6][3]={0,1,0,0,-1,0,1,0,0,-1,0,0,0,0,1,0,0,-1};
int used[50][50][50];
int a,b,c,ti,step;
queue<node> q;
void bfs(int x,int y,int z)
{
    int i,j,k,l;
    node pos(x,y,z,0);
    q.push(pos);
    used[x][y][z]=1;
    while(!q.empty())
    {
        pos = q.front();
        i = pos.x;
        j = pos.y;
        k = pos.z;
        l = pos.level;
        q.pop();
        if(i==a-1&&j==b-1&&k==c-1)
        {
            if(l<step)
                step=l;
            continue;
        }
        for(int t=0;t<6;t++)
        {
            x=i+d[t][0];
            y=j+d[t][1];
            z=k+d[t][2];
            if(x<0||x>=a||y<0||y>=b||z<0||z>=c||used[x][y][z]||l+1>ti)
                continue;
            pos.set(x,y,z,l+1);
            used[x][y][z]=1;
            q.push(pos);
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(used,0,sizeof used);
        step = INF;
        scanf("%d%d%d%d",&a,&b,&c,&ti);
        for(int i=0;i<a;i++)
        for(int j=0;j<b;j++)
        for(int k=0;k<c;k++)
            scanf("%d",&used[i][j][k]);
        bfs(0,0,0);
        if(step!=INF)
            printf("%d\n",step);
        else
            printf("-1\n");
    }
}
