/*已知A1=(A0+A2)/2 - C1, A2=(A1+A3)/2 - C2 , ...

=>A1+A2 = (A0+A2+A1+A3)/2 - (C1+C2)

=>A1+A2 = A0+A3 - 2(C1+C2) 

类似的有：

A1+A2 = A0+A3 - 2(C1+C2)

A1+A3 = A0+A4 - 2(C1+C2+C3)

A1+A4 = A0+A5 - 2(C1+C2+C3+C4)

...

A1+An = A0+An+1 - 2(C1+C2+...+Cn)

A1+A1 = A0+A2 - 2(C1) (本来就是)

----------------------------------------------------- 左右求和

(n+1)A1+(A2+A3+...+An) = nA0 +(A2+A3+...+An) + An+1 - 2(nC1+(n-1)C2+...+2Cn-1+Cn)

=> (n+1)A1=nA0 + An+1 - 2(nC1+(n-1)C2+...+2Cn-1+Cn)

=> A1 = [nA0 + An+1 - 2(nC1+(n-1)C2+...+2Cn-1+Cn)]/(n+1)
 */
#include<stdio.h>
#define MAX 3005
double c[MAX];
int main()
{
    int n;
    double a,b;
    while(~scanf("%d",&n))
    {
        scanf("%lf%lf",&a,&b);
        int i;
        for(i=0; i<n; i++)
        {
            scanf("%lf",&c[i]);
        }
        double sum=0;
        for(i=0; i<n; i++)
        {
            sum+=c[i]*(n-i);
        }
        double a1=(n*a+b-2*sum)/(n+1);
        printf("%.2f\n",a1);
    }
}
//后记：gcc默认使用的是gnu89的标准。变量声明不需要总放在开头。但不能放进for括号里。
//对于浮点型的输入lf和f是有差别的。而对于输出都使用f就可以。
