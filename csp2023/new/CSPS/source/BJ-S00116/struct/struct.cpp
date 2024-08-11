#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int n,yi,now_dd;
struct Node{
    int l,r;
};
map<string,Node> mp;
int main(void) {
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (;n--;) {
        int opt;
        cin >> opt;
        if (opt==2) {
            string tp,nme;
            cin >> tp >> nme;
            int g;
            if (tp=="byte") g=1;
            if (tp=="short") g=2;
            if (tp=="int") g=4;
            if (tp=="long") g=8;
            yi=max(yi,g);
            int ll=((now_dd/yi)+((now_dd%yi)>0))*yi;
            int rr=ll+g-1;
            now_dd=rr+1;
            mp[nme].l=ll;
            mp[nme].r=rr;
            cout << ll << endl;
        } else if (opt==3) {
            string s;
            cin >> s;
            int ll=mp[s].l,rr=mp[s].r;
            cout << ll << endl;
        } else if (opt==4) {
            int addl;
            bool is=0;
            cin >> addl;
            for (auto it:mp) {
                if (it.second.l<=addl&&it.second.r>=addl) {
                    cout << it.first << endl;
                    is=1;
                    break;
                }
            }
            if (!is)
            cout << "ERR\n";
        }
    }
    return 0;
}