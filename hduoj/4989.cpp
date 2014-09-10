#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
using namespace std;
set<long long> s;
int a[105];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            s.insert(a[i]+a[j]);
        }
        long long sum=0;
        set<long long>::iterator it;
        for(it=s.begin();it!=s.end();it++)
        {
            sum+=*it;
        }
        cout<<sum<<endl;
        s.clear();
    }
}
