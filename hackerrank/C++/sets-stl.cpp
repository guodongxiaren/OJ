#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    set<int>s;
    int n,x,y;
    cin>>n;
    while (n--) {
        cin>>y>>x;
        switch (y) {
            case 1: s.insert(x);break;
            case 2: s.erase(x);break;
            case 3: auto it = s.find(x);cout<<(it!=s.end()?"Yes":"No")<<endl;
        }
    }
    return 0;
}
