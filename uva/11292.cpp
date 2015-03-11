#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
const int SIZE = 20005;
int dro[SIZE];
int nig[SIZE];
using namespace std;
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        if(!n&&!n)
        break;
        for(int i=1;i<=n;i++)
        cin>>dro[i];
        for(int i=1;i<=m;i++)
        cin>>nig[i];
        sort(dro+1,dro+n+1);
        sort(nig+1,nig+m+1);
        int sum=0,j=1;
        for(int i=1;i<=m;i++)
        {
            if(nig[i]>=dro[j])
            {
                sum+=nig[i];
                j++;
            }
            if(j>n)
            break;
        }
        if(j<=n)
        cout<<"Loowater is doomed!\n";
        else
        cout<<sum<<endl;
    }
}
