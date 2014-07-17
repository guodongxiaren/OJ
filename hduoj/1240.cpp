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
char m[10][10][10];
bool used[10][10][10];
int s[3],e[3];
int n,step;
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
        if(i==e[2]&&j==e[1]&&k==e[0])
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
            if(x<0||x>=n||y<0||y>=n||z<0||z>=n||m[x][y][z]!='O'||used[x][y][z])
                continue;
            pos.set(x,y,z,l+1);
            used[x][y][z]=1;
            q.push(pos);
        }
    }
}
int main()
{
    char str[6];
    while(cin>>str>>n)
    {
        memset(used,0,sizeof used);
        step = INF;
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        for(int k=0;k<n;k++)
            cin>>m[i][j][k];
        cin>>s[0]>>s[1]>>s[2]>>e[0]>>e[1]>>e[2];
        cin>>str;
        bfs(s[2],s[1],s[0]);
        if(step!=INF)
            cout<<n<<" "<<step<<endl;
        else
            cout<<"NO ROUTE"<<endl;
    }
}
