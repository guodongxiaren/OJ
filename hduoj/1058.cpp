/*要用C++提交，G++会编译错误*/
/*惭愧，代码参考了网友的*/
/*我自己一开始没在for括号里判断pow<=...
 * 但是在循环内有判断大小，最后数组保存的结果应该也是对的
 * 但是我自己测试着对，提交就WA。。
 * 难道是中间环节因为计算出的数太大，导致了问题了么。
 * 编译器版本不一致还真是不方便*/
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXVAL=2000000000;
const int MAXSIZE=5900;
int humble[MAXSIZE];
int p=0;
void init()
{
    for(int i=0;i<=30&&pow(2,i)<=MAXVAL;i++)
    for(int j=0;j<=19&&pow(2,i)*pow(3,j)<=MAXVAL;j++)
    for(int k=0;k<=13&&pow(2,i)*pow(3,j)*pow(5,k)<=MAXVAL;k++)
    for(int s=0;s<=11&&pow(2,i)*pow(3,j)*pow(5,k)*pow(7,s)<=MAXVAL;s++)
    {
        humble[p++]=pow(2,i)*pow(3,j)*pow(5,k)*pow(7,s);

    }
    sort(humble,humble+p);

}
int main()
{
    init();
    int t;
    while(scanf("%d",&t),t)
    {
        printf("The %d",t);
        if(t%10==1&&t%100!=11)
        printf("st ");
        else if(t%10==2&&t%100!=12)
        printf("nd ");
        else if(t%10==3&&t%100!=13)
        printf("rd ");
        else
        printf("th ");
        printf("humble number is %d.\n",humble[t-1]);

    }
    return 0;

}
