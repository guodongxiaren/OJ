#include<iostream>
#include<cstring>
#include<functional>
#include<algorithm>
using namespace std;
bool used[64];
int len[64],n,l,last;
bool dfs(int r,int m)
{
    if(r==0&&m==0)
        return true;
    if(m==0)
        m=l;
    int start=0;
    if(m!=l)
        start=last+1;
    for(int i=0;i<n;i++)
    {
        if(!used[i]&&len[i]<=m)
        {
            if(i>0)
            {
                if(used[i-1]==false&&len[i]==len[i-1])
                    continue;
            }
            used[i]=true;
            last=i;
            if(dfs(r-1,m-len[i]))
                return true;
            else
            {
                used[i]=false;
                if(len[i]==m||m==l)
                    return false;
            }
        }
    }
    return false;
}
int main()
{
    while(cin>>n)
    {
        if(!n)
        break;
        memset(used,false,sizeof(used));
        int total=0;
        for(int i=0;i<n;i++)
        {
            cin>>len[i];
            total+=len[i];
        }
        sort(len,len+n,greater<int>());
        for(l=len[0];l<=total/2;l++)
        {
            if(dfs(n,l))
            {
                cout<<l<<endl;
                break;
            }
        }
        if(l>total/2)
            cout<<total<<endl;
    }
    return 0;
}
