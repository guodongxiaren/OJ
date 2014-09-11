#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int b[105][105]; 
int even(int i,int j)
{
//    return b[i][j-1]|b[i][j+1]|b[i-1][j]|b[i+1][j];
    int sum = b[i][j-1]+b[i][j+1]+b[i-1][j]+b[i+1][j];
    return sum&1;
} 
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(b,0,sizeof b);
        char t;
        for(int i=1;i<=n;i++)
        {
            getchar(); 
            for(int j=1;j<=n;j++)
            {
                scanf("%c",&t);
                if(t=='o')
                    b[i][j]=1;
            }
        }
        bool flag=true;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(even(i,j))
                    flag=false;
            }
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
