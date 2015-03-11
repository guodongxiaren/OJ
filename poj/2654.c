#include<stdio.h>
#include<string.h>
int w[200],l[200];
int p1,p2,i,j,k,m,n;
char m1[10],m2[10];
int main()
{
    int flag=0;
    while(1)
    {
        scanf("%d",&n);
        if(!n)
            break;
        scanf("%d",&k);
        if(flag)
            printf("\n");
        else
            flag=1;
        memset(w,0,sizeof w);
        memset(l,0,sizeof l);
        for(i=0; i<k*n*(n-1)/2; i++)
        {
            scanf("%d%s%d%s",&p1,m1,&p2,m2);
            if((m1[0]=='r'&&m2[0]=='s')||(m1[0]=='s'&&m2[0]=='p')||
                    (m1[0]=='p'&&m2[0]=='r'))
            {
                w[p1]++;
                l[p2]++;
            }
            if((m2[0]=='r'&&m1[0]=='s')||(m2[0]=='s'&&m1[0]=='p')||
                    (m2[0]=='p'&&m1[0]=='r'))
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
