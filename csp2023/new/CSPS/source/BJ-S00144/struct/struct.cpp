#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

long long n,op,now;

struct st{
    string s,name;
    long long spcl,spcr,spc;
};

int main() {
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> op;
        if(op==2) {
            string t,n;
            cin >> t >> n;
        }
    }
}
