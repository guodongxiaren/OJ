#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,a;
    vector<int> v;    
    cin>>n;
    v.reserve(n);
    while (n--) {
        cin>>a;
        v.push_back(a);
    }
    cin>>n;
    while (n--) {
        cin>>a;
        auto it = lower_bound(v.begin(), v.end(), a);
        cout<<(*it==a?"Yes ":"No ");
        cout<<distance(v.begin(), it)+1<<endl;
    }
    return 0;
}
