#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,q,y;
    string x;
    map<string, int> m;
    cin>>n;
    while (n--) {
        cin>>q>>x;
        map<string, int>::iterator it;
        switch (q) {
            case 1: cin>>y; it = m.find(x); 
                if (it == m.end() ) {
                    m.insert(make_pair(x,y));
                }else {
                    it->second+=y;
                } break;
            case 2: m.erase(x); break;
            case 3:{ auto it = m.find(x); cout<<(it != m.end()?it->second:0)<<endl;}
        }
    }
    return 0;
}
