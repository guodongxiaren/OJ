#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int num;
int w,h;
bool g[20][20];
void dfs(int i,int j)
{
    if(i-1>=0&&g[i-1][j])
    {
        num++;
        g[i-1][j]=false;
        dfs(i-1,j);
    }
    if(j-1>=0&&g[i][j-1])
    {
        num++;
        g[i][j-1]=false;
        dfs(i,j-1);
    }
    if(i+1<h&&g[i+1][j])
    {
        num++;
        g[i+1][j]=false;
        dfs(i+1,j);
    }
    if(j+1<w&&g[i][j+1])
    {
        num++;
        g[i][j+1]=false;
        dfs(i,j+1);
    }
}
int main()
{
    char c;
    int si,sj;
    while(cin>>w>>h)
    {
        if(!w&&!h)
            break;
        num=1;
        for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
        {
            cin>>c;
            if(c=='.')
                g[i][j]=true;
            else if(c=='@')
            {
                si=i;
                sj=j;
            }
        }
        dfs(si,sj);
        cout<<num<<endl;
        memset(g,false,sizeof(g));
    }
}
