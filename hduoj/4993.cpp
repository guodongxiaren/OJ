#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
using namespace std;
typedef long long ll;
int sum;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        sum=0;
        for(int i=1;;i++)
        {
            if(c-a*i<=0)
                break;
            if((c-a*i)%b==0)
                sum++;
        }
        cout<<sum<<endl;
    }
}
