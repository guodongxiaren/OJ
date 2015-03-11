#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MY_MIN 99999999
#define MY_MAX -99999999
struct CNode
{
    int L,R;
    int nMin,nMax;
    CNode *pLeft,*pRight;
};
int nMax,nMin;
CNode Tree[1000000];
int nCount = 0;
void buildTree(CNode *pRoot,int L,int R)
{
    pRoot->L=L;
    pRoot->R=R;

    pRoot->nMin = MY_MIN;
    pRoot->nMax = MY_MAX;

    if(L!=R)
    {
        nCount++;
        pRoot->pLeft = Tree + nCount;
        nCount++;
        pRoot->pRight = Tree + nCount;
        buildTree(pRoot->pLeft,L,(L+R)/2);
        buildTree(pRoot->pRight,(L+R)/2+1,R);
    }
}
void insert(CNode *pRoot,int i,int v)
{
    if(pRoot->L==i&&pRoot->R==i)
    {
        pRoot->nMin=pRoot->nMax=v;
        return;
    }
    pRoot->nMin=min(pRoot->nMin,v);
    pRoot->nMax=max(pRoot->nMax,v);
    if(i<=(pRoot->L+pRoot->R)/2)
        insert(pRoot->pLeft,i,v);
    else
        insert(pRoot->pRight,i,v);
}
void query(CNode *pRoot,int s,int e)
{
    if(pRoot->nMin>=nMin&&pRoot->nMax<=nMax)
        return;
    if(s==pRoot->L&&e==pRoot->R)
    {
        nMin=min(pRoot->nMin,nMin);
        nMax=max(pRoot->nMax,nMax);
        return;
    }
    if(e<=(pRoot->L+pRoot->R)/2)
        query(pRoot->pLeft,s,e);
    else if(s>=(pRoot->L+pRoot->R)/2+1)
        query(pRoot->pRight,s,e);
    else
    {
        query(pRoot->pLeft,s,(pRoot->L+pRoot->R)/2);
        query(pRoot->pRight,(pRoot->L+pRoot->R)/2+1,e);
    }
}
int main()
{
    int n,q,h;
    int i,j,k;
    scanf("%d%d",&n,&q);
    nCount=0;
    buildTree(Tree,1,n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&h);
        insert(Tree,i,h);
    }
    for(i=0;i<q;i++)
    {
        int s,e;
        scanf("%d%d",&s,&e);
        nMax=MY_MAX;
        nMin=MY_MIN;
        query(Tree,s,e);
        printf("%d\n",nMax-nMin);
    }
    return 0;
}

