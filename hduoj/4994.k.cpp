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
    int t;
    cin>>t;
    while(t--)
    {
        int n,tem;
        bool flag=false;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>tem;
            if(tem!=1)
            {
                if(i&1)
                {
                    cout<<"Yes"<<endl;
                    flag=true;
                    break;
                }
                else
                {
                    cout<<"No"<<endl;
                    flag=true;
                    break;
                }
            }
        }
        if(!flag)
        {
            if(n&1)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
}
