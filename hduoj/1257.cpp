//本题采用了人人为我的dp思路
//但是我并不理解，这道题为什么看作LIS就能AC
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int a[40000],w[40000];
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            w[i]=1;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(a[i]>=a[j])
                    w[i]=max(w[i],w[j]+1);
            }
        }
        cout<<*max_element(w,w+n)<<endl;
    }
}
