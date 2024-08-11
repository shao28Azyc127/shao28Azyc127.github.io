#include <bits/stdc++.h>
using namespace std;
int main(void){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,a1,a2,c=0,c2=1;
    bool o=false;
    cin >> n;
    vector<bool> has(n,true);
    while(1){
        for(int i=0;i<has.size();i++){
            c %= 3;
            bool t=has.at(i);
            if(!t) continue;
            if(!c) has.at(i) = false;
            c++;
        }
        if(has.at(n-1) == false) a2=c2;
        for(int i=0;i<has.size();i++){
            o = (o || has.at(i));
        }
        if(!o) {
            a1=c2;
            break;
        }
        o=false;
        c=0;
        c2++;
    }
    cout << a1 << ' ' << a2;
    return 0;
}
