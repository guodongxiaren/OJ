#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int d[4][2]={-1,0,0,-1,1,0,0,1};
int w,h,step,num;
char g[205][205];
bool used[205][205];
bool flag;
void dfs(int i,int j,int num)
{
    int x,y,inr=1;
    if(g[i][j]=='x')
        inr=2;
    else if(g[i][j]=='r')
    {
        if(num<step)
            step=num;
        flag = true;
        return;
    }
    for(int ii=0;ii<4;ii++)
    {
        x=i+d[ii][0];
        y=j+d[ii][1];
        if(x<0||x>=h||y<0||y>=w)
            continue;
        if(used[x][y])
        {
            used[x][y]=false;
            dfs(x,y,num+inr);
            used[x][y]=true;
        }
    }
}
int main()
{
    int si,sj;
    while(cin>>h>>w)
    {
        num=0;
        step=w*h;
        flag=false;
        for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
        {
            cin>>g[i][j];
            if(g[i][j]=='a')
            {
                si=i;
                sj=j;
            }
            else if(g[i][j]=='r'||g[i][j]=='x'||g[i][j]=='.')
                used[i][j]=true;
        }
        dfs(si,sj,0);
        if(flag)
            cout<<step<<endl;
        else
            cout<<"Poor ANGEL has to stay in the prison all his life."<<endl;
        memset(used,false,sizeof(used));
    }
}
