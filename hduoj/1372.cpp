#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int d[8][2]={-1,-2,1,-2,-1,2,1,2,-2,1,-2,-1,2,1,2,-1};
int map[8][8];
int bi,bj;
void dfs(int i,int j,int step)
{
    map[i][j]=step;
    if(bi==i&&bj==j)
        return;
    for(int ii=0;ii<8;ii++)
    {
        int x=i+d[ii][0];
        int y=j+d[ii][1];
        if(x<0||x>=8||y<0||y>=8||map[x][y]<=step+1)
            continue;
        dfs(x,y,step+1);
    }
}
int main()
{
    char a,b;
    int ai,aj;
    while(cin>>a>>aj>>b>>bj)
    {
        memset(map,0x3f,sizeof map);
        ai=a-'a';
        bi=b-'a';
        aj--;
        bj--;
        dfs(ai,aj,0);
        printf("To get from %c%d to %c%d takes %d knight moves.\n",a,aj+1,b,bj+1,map[bi][bj]);
    }
}
