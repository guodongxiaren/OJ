#include <stdio.h>
int c,big,little,L,i,j,k,n;
int main()
{
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d%d",&L,&n);
        big=little=0;
        for(i=0; i<n; i++)
        {
            scanf("%d",&k);
            if(k>big)
                big = k;
            if(L-k>big)
                big=L-k;
            if(k>L-k)
            k=L-k;
            if(k>little)
            little=k;
        }
        printf("%d %d\n",little,big);
    }
    if(c!=-1)
        printf("missing input\n");
}
