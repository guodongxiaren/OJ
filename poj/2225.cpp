#include<iostream>
#include<queue>
using namespace std;
#include<cstdio>
#include<cstring>
#define INF 0x3f3f3f3f
#define M 1000
struct node
{
    int x,y,z,level;
};
int d[6][3]={0,1,0,0,-1,0,1,0,0,-1,0,0,0,0,1,0,0,-1};
char m[10][10][10];
int used[10][10][10];
int s[3],e[3];
int n,step;
node q[M];
void bfs(int x,int y,int z)
{
    int i,j,k,l;
    int front=0,rear=0;
    node pos;
    pos.x=x;
    pos.y=y;
    pos.z=z;
    pos.level=0;
    q[front]=pos;
    front=(front+1)%M;
    while(rear!=front)
    {
        pos = q[rear];
        i = pos.x;
        j = pos.y;
        k = pos.z;
        l = pos.level;
        rear=(rear+1)%M;
        if(l<used[i][j][k])
            used[i][j][k]=l;
        if(i==e[2]&&j==e[1]&&k==e[0])
        {
            if(used[i][j][k]<step)
                step=used[i][j][k];
            continue;
        }
        for(int t=0;t<6;t++)
        {
            x=i+d[t][0];
            y=j+d[t][1];
            z=k+d[t][2];
            if(x<0||x>=n||y<0||y>=n||z<0||z>=n||m[x][y][z]!='O'||l+1>=used[x][y][z])
                continue;
            pos.x=x;
            pos.y=y;
            pos.z=z;
            pos.level=l+1;
            q[front]=pos;
            front=(front+1)%M;
        }
    }
}
int main()
{
    char str[6];
    while(cin>>str>>n)
    {
        memset(used,0x3f,sizeof used);
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
