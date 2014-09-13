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
int main()
{
    ll n,m,a,b;
    while(cin>>n>>m>>a>>b)
    {
        if(b<a*m)
        {
            ll sum=0;
            while(n>=m)
            {
                n-=m;
                sum+=b;
            }
            if(n*a>b)
            sum+=b;
            else
            sum+=n*a;
            cout<<sum<<endl;
        }
        else 
            cout<<n*a<<endl;
    }
}
