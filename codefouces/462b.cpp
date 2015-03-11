#include <iostream>
#include <cstring>
#include <functional>
#include <algorithm>
#include <cstdio>
using namespace std;
long long card[30];
int main()
{
    long long n,k;
    while(cin>>n>>k)
    {
        memset(card,0,sizeof card);
        char t;
        for(long long i=0;i<n;i++)
        {
            cin>>t;
            card[t-'A']++;
        }
        sort(card,card+30,greater<long long>());
        long long sum=0;
        int i=0;
        while(k>0)
        {
            if(card[i]<k)
            {
                sum+=card[i]*card[i];
            }
            else
            {
                sum+=k*k;
            }
                k-=card[i];
            i++;
        }
        cout<<sum<<endl;
    }
}
