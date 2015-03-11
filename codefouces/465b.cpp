#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int a[1005];
int b[1005];
int main()
{
    int n;
    while(cin>>n)
    {
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        int s=0;
        int j=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i])
            b[j++]=i;
        }
        if(b[0]==0)
        {
            cout<<0<<endl;
            break;
        }
        int sum=1;
        for(int i=1;i<j;i++)
        {
            if(b[i]-b[i-1]==1) 
            sum++;
            else
            sum+=2;
        }
        cout<<sum<<endl;
    }
}
