#include <string.h>
#include <iostream>
using namespace std;
const int MAX = 1024;
int rudu[MAX+10];
int parent[MAX+10];

void init() {
    memset(parent, -1, sizeof(parent));
    memset(rudu, -1, sizeof(rudu));
}

int find(int a) {
    if (parent[a] != a) {
        parent[a] = find(parent[a]);
    }
    return parent[a];
}

void merge(int a,int b) {
    int p1 = find(a);
    int p2 = find(b);
    if (p1 == p2)
        return;
    parent[p1] = p2;
}

int main() {
    int a,b,c=1;

    init();
    while (cin>>a>>b, a >= 0 && b >= 0) {
        if (rudu[a] == -1) {
            rudu[a] = 0;
            parent[a] = a;
        }
        if (rudu[b] == -1) {
            rudu[b] = 0;
            parent[b] = b;
        }
        if (!a && !b) {
            int root_num = 0;
            bool flag = true;
            for (int i = 1; i <= MAX; i++) {
                if(rudu[i] > 1) {
                    flag = false;
                    break;
                }
                if(parent[i] == i) {
                    if (++root_num > 1) {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag) {
                cout<<"Case "<<c++<<" is a tree."<<endl;
            } else {
                cout<<"Case "<<c++<<" is not a tree."<<endl;
            }
            init();
            continue;
        }
        if (find(a) != find(b)) {
            merge(a, b);
        }
        rudu[b]++;
    }
}
