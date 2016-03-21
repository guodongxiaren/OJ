#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    vector<int> v;
    while(n--) {
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), [](int  &x){cout<<x<<" ";});
    cout<<endl;
    return 0;
}
