#include<stdio.h>
#include<math.h>
main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        if(!a&&!b)
            break;
        int flag=0;
        for(int i=-10000;i<=10000;i++)
        {
            if((a-i)*i==b)
            {
                flag=1;
                break;
            }
        }
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
}
