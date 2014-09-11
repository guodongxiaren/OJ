#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
struct CNode
{
    int L,R;
    CNode *pLeft,*pRight;
    long long nSum;
    long long Inc;
};
CNode Tree[1000000];
int nCount = 0;
int mid(CNode *pRoot)
{
    return (pRoot->L+pRoot->R)/2;
}
void buildTree(CNode *pRoot,int L,int R)
{
    pRoot->L=L;
    pRoot->R=R;
    pRoot->nSum=0;
    pRoot->Inc=0;
    if(L==R)
    {
        return;
    }
    nCount++;
    pRoot->pLeft=Tree+nCount;
    nCount++;
    pRoot->pRight=Tree+nCount;
    buildTree(pRoot->pLeft,L,(L+R)/2);
    buildTree(pRoot->pRight,(L+R)/2+1,R);
}
void insert(CNode *pRoot,int i,int v)
{
    if(pRoot->L==i&&pRoot->R==i)
    {
        pRoot->nSum=v;
        return;
    }
    pRoot->nSum+=v;
    if(i<=mid(pRoot))
        insert(pRoot->pLeft,i,v);
    else
        insert(pRoot->pRight,i,v);
}
void add(CNode *pRoot,int a,int b,long long c)
{
    if(pRoot->L==a&&pRoot->R==b)
    {
        pRoot->Inc+=c;
        return;
    }
    pRoot->nSum+=c*(b-a+1);
    if(b<=(pRoot->L+pRoot->R)/2)
        add(pRoot->pLeft,a,b,c);
    else if(a>=(pRoot->L+pRoot->R)/2+1)
        add(pRoot->pRight,a,b,c);
    else
    {
        add(pRoot->pLeft,a,(pRoot->L+pRoot->R)/2,c);
        add(pRoot->pRight,(pRoot->L+pRoot->R)/2+1,b,c);
    }
}
long long query(CNode *pRoot,int a,int b)
{
    if(pRoot->L==a&&pRoot->R==b)
        return pRoot->nSum+(pRoot->R-pRoot->L+1)*pRoot->Inc;
    pRoot->nSum+=(pRoot->R-pRoot->L+1)*pRoot->Inc;
    add(pRoot->pLeft,pRoot->L,mid(pRoot),pRoot->Inc);
    add(pRoot->pRight,mid(pRoot)+1,pRoot->R,pRoot->Inc);
    pRoot->Inc=0;

    if(b<=mid(pRoot))
        return query(pRoot->pLeft,a,b);
    else if(a>=mid(pRoot)+1)
        return query(pRoot->pRight,a,b);
    else
    {
        return query(pRoot->pLeft,a,mid(pRoot))+
            query(pRoot->pRight,mid(pRoot)+1,b);
    }
}
int main()
{
    int n,q,a,b,c;
    char cmd[10];
    scanf("%d%d",&n,&q);
    int i,j,k;
    nCount=0;
    buildTree(Tree,1,n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        insert(Tree,i,a);
    }
    for(i=0;i<q;i++)
    {
        scanf("%s",cmd);
        if(cmd[0]=='C')
        {
            scanf("%d%d%d",&a,&b,&c);
            add(Tree,a,b,c);
        }
        else
        {
            scanf("%d%d",&a,&b);
            printf("%lld\n",query(Tree,a,b));
        }
    }
}
