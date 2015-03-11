#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char cell[105];
int c[105];
int main()
{
    int n;
    while(cin>>n)
    {
        cin>>cell;
        int tem=1;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            int x=cell[i]-'0';
            tem+=x;
            int y=tem%2;
            if(y!=x)
            sum++;
            tem/=2;
        }
        cout<<sum<<endl;
    }
}

