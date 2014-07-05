#include<stdio.h>
main()
{
    char c;
    int n,i,j,sum=0;
    while(scanf("%c",&c)&&c!='@')
    {
        if(sum++)
        printf("\n");
        scanf("%d",&n);
        getchar();
        for(i=1;i<=n;i++)
        {
            for(j=n-i;j>0;j--)
                printf(" ");
            if(i!=n)
            {
                printf("%c",c);
                for(j=2*i-3;j>0;j--)
                    printf(" ");
                if(i!=1)
                   printf("%c\n",c); 
                else
                   printf("\n"); 
            }
            else
            for(j=1;j<=2*n-1;j++)
                printf("%c",c);
        }
        printf("\n");
    }
}
