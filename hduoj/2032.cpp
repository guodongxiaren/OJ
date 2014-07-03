#include<iostream>
using namespace std;
int a[32][32];
void makea()
{
    a[0][0]=1;
    for(int i=1;i<30;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0)
                a[i][j]=1;
            else
                a[i][j]=a[i-1][j]+a[i-1][j-1];
        }
    }
}
int main()
{
    int n;
    makea();
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(i!=j)
                    cout<<a[i][j]<<" ";
                else
                    cout<<a[i][j]<<endl;
            }
        }
        cout<<endl;
    }
}
