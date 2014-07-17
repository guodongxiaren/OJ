//判断有环和判断是否有三元环是一个意思
//因为有环，就必存在三元环
//若无环，出度一定为n-1,n-2,n-3...
//若有环，则出度在上面的基础上一定会出现一增，一减。所以一定会出现两对重复的出度
//实际只需判断有一对出度相等就可以了。
#include<stdio.h>
#include<string.h>
int outdegree[2005];
int flag;
int hash[2005];
int main()
{
    int t,n,cas,i,j;
    char a[2005];
    scanf("%d",&t);
    for(cas=1;cas<=t;cas++)
    {
        memset(hash,0,sizeof hash);
        scanf("%d",&n);
        flag=0;
        for(i=0;i<n;i++)
        {
            scanf("%s",a);
            outdegree[i]=0;
            for(j=0;j<n;j++)
            {
                if(a[j]=='1')
                    outdegree[i]++;
            }
            getchar();
            if(hash[outdegree[i]])
                flag=1;
            else
                hash[outdegree[i]]=1;
        }
        if(!flag)
            printf("Case #%d: No\n",cas);
        else
            printf("Case #%d: Yes\n",cas);
    }
}
