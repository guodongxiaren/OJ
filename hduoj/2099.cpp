#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b))
    {
        if(!a&&!b)
            break;
        a*=100;
        int sum=0,i;
        for(i=0; i<100; i++)
        {
            int c=a+i;
            if(c%b==0)
                break;
        }
        while(i<100)
        {
            if(sum++)
                printf(" ");
            if(i<10)
                printf("0%d",i);
            else
                printf("%d",i);
            i+=b;
        }
        printf("\n");
    }
}
