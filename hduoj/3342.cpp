#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int n,m;
int map[105][105];
int in[105];
queue<int> q;
void topo()
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(!in[i])
        {
            q.push(i);
            count++;
        }
    }
    while(!q.empty())
    {
        int top=q.front();
        q.pop();
        for(int i=0;i<n;i++)
        {
            if(map[top][i])
            {
                in[i]--;
                if(!in[i])
                {
                    q.push(i);
                    count++;
                }
            }
        }
    }
    if(count==n)
        cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
}
int main()
{
    while(cin>>n>>m)
    {
        if(!n)
            break;
        memset(in,0,sizeof in);
        memset(map,0,sizeof map);
        int i,j;
        while(m--)
        {
            cin>>i>>j;
            if(map[i][j])
                continue;
            map[i][j]=1;
            in[j]++;
        }
        topo();
    }
}
