#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,tail=0;

struct Node {
    int l,r;
    string name;
};

vector<Node> G;

signed main() {
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    while(n--) {
        int op,x;
        string a,b;
        scanf("%lld",&op);
        if(op==2) {
            cin>>a>>b;
            if(a=="long") {
                G.push_back({(tail+7)/8*8,(tail+7)/8*8+7,b});
                tail=(tail+7)/8*8+7;
            }
            if(a=="int") {
                G.push_back({(tail+3)/4*4,(tail+3)/4*4+3,b});
                tail=(tail+3)/4*4+3;
            }
            if(a=="short") {
                G.push_back({(tail+1)/2*2,(tail+1)/2*2+1,b});
                tail=(tail+1)/2*2+1;
            }
            if(a=="byte") {
                G.push_back({tail+1,tail+1,b});
                tail++;
            }
        }
        if(op==3) {
            cin>>a;
            for(int i=0;i<G.size();i++) {
                if(G[i].name==a) {
                    cout<<G[i].l<<endl;
                    break;
                }
            }
        }
        if(op==4) {
            cin>>x;
            if(x>tail) {
                cout<<"ERR"<<endl;
                continue;
            }
            for(int i=0;i<G.size();i++) {
                if(G[i].l<=x && G[i].r>=x) {
                    cout<<G[i].name<<endl;
                    break;
                }
                if(G[i].r<x && G[i+1].l>x) {
                    cout<<"ERR"<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}
//meow