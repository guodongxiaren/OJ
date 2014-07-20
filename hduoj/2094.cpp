#include<iostream>
#include<queue>
#include<string>
#include<map>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAX 10000
map<string,int> man;
int n;
int in[MAX];
void topo()
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(!in[i])
        {
            count++;
        }
    }
    if(count==1)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
int main()
{
    string a,b;
    int i,j,m;
    while(cin>>m)
    {
        if(!m)
            break;
        int k=0;
        memset(in,0,sizeof in);
        while(m--)
        {
            cin>>a>>b;
            if(!man.count(a))
            { 
                man[a]=k;
                i=k++;
            }
            else
                i=man[a];
            if(!man.count(b))
            { 
                man[b]=k;
                j=k++;
            }
            else
                j=man[b];
            in[j]++;
        } 
        n=k;
        topo();
        man.clear();
    }
}
