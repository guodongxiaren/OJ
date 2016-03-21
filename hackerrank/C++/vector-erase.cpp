#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,a,b;
    vector<int> v;
    v.reserve(n);
    cin>>n;
    while(n--) {
        cin>>a;
        v.push_back(a);
    }
    cin>>a;
    v.erase(v.begin()+a-1);
    cin>>a>>b;
    v.erase(v.begin()+a-1, v.begin()+b-1);
    cout<<v.size()<<endl;
    for_each(v.begin(), v.end(), [](int  &x){cout<<x<<" ";});
    return 0;
}
