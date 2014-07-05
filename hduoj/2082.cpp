#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int w[27];
int sum;
void dfs(int i,int num)
{
    if(num>50)
        return;
    else if(i)
        sum++;
    for(int j=i;j<=26;j++)
    {
        if(w[j]&&j+num<=50)
        {
            w[j]--;
            dfs(j,num+j);
            w[j]++;
        }
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    cin>>n;
    while(n--)
    {
        bool flag=true;
        sum=0;
        for(int i=1;i<=26;i++)
        {
            cin>>w[i];
        }
        dfs(0,0);
        cout<<sum<<endl;    
        memset(w,0,sizeof w);
    }
}
