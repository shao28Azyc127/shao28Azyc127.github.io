#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#define ll long long
#define pii pair<string, ll>
using namespace std;
ll addr, si, k, op, n, cnt, ad;
string s, t, nn;
pii nam[10005];

int siz(string t){
    if(t=="long") return 8;
    if(t=="byte") return 1;
    if(t=="short") return 2;
    if(t=="int") return 4;
    return 8;
}

int main(){
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> op;
        if(op==2){
            cin >> t >> nn;
            si = siz(t);
            if(addr%si==0){
                addr = si*(addr/si) + si;
            } else{
                addr = si*(addr/si) + si+ si;
            }
            nam[cnt].first = nn;
            nam[cnt++].second = addr - si;
            // cout << nam[cnt-1].first << ' ' << nam[cnt-1].second << endl; 
        } else if(op==3){
            cin >> t;
            for(int j=0;j<cnt;j++){
                // cout << j << " j\n";
                if(nam[j].first==t){
                    cout << nam[j].second << endl;
                    break;
                }
            }
        } else if(op==4){
            cin >> ad;
            bool flag=0;
            for(int j=0;j<cnt;j++){
                if(nam[j].second==ad){
                    flag=1;
                    cout << nam[j].first << endl;
                    break;
                }
            }
            if(!flag) cout << "ERR\n";
        } else if(op==1){
            cin >> s >> k;
            for(int j=0;j<k;j++){
                cin >> t >> nn;
                si = siz(t);
                if(addr%si==0){
                    addr = si*(addr/si) + si;
                } else{
                    addr = si*(addr/si) + si+ si;
                }
                nam[cnt].first = s+nn;
                nam[cnt++].second = addr - si;
            }
        }

    }
    return 0;
}