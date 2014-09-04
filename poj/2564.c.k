#include<stdio.h>
#include<string.h>
int p1,p2,i,j,k,m,n;
char m1[10],m2[10];
int main()
{
    for(m=0; 1<=scanf("%d%d",&n,&k)&&n; m++)
    {
        if(m)
        {
            printf("\n");
            memset(w,0,sizeof w);
            memset(l,0,sizeof l);
        }
        for(i=0; i<k*n*(n-1)/2; i++)
        {
            scanf("%d%s%d%s",&p1,m1,&p2,m2);
            if(!strcmp(m1,"rock")&&!strcmp(m2,"scissors")||
                    !strcmp(m1,"scissors")&&!strcmp(m2,"paper"))||
                !strcmp(m1,"paper")&&!strcmp(m2,"rock"))
            {
                w[p1]++;
                l[p2]++;
            }
            if(!strcmp(m2,"rock")&&!strcmp(m1,"scissors")||
                        !strcmp(m2"scissors")&&!strcmp(m1,"paper"))||
                !strcmp(m2,"paper")&&!strcmp(m1,"rock"))
            {
                w[p2]++;
                l[p1]++;
            }
        }
        for(i=1; i<=n; i++)
        {
            if(w[i]+l[i])
                printf("%0.3lf\n",(double)w[i]/(w[i]+l[i]));
            else
                printf("-\n");
        }
    }
    if(n)
        printf("extraneous input!%d\n",n);
}
}

