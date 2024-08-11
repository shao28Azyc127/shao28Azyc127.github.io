#include <bits/stdc++.h>
using namespace std;

set <string> aa;

void add_all_valid(string a){
    set <string> bb;
    for (int i=0;i<5;i++){
        for (char j=0;j<10;j++){
            a[i] += 1;
            if (a[i] == 58){
                a[i] = 48;
            }
            if (j == 9){
                goto _1;
            }
            bb.insert(a);
        }
        _1:;
    }
    for (int i=0;i<4;i++){
        for (char j=0;j<10;j++){
            a[i] += 1;
            a[i+1] += 1;
            if (a[i] == 58){
                a[i] = 48;
            }
            if (a[i+1] == 58){
                a[i+1] = 48;
            }
            if (j == 9){
                goto _2;
            }
            bb.insert(a);
        }
        _2:;
    }
    if (aa.empty()){
        for (auto i:bb){
            aa.insert(i);
        }
    }
    else{
        vector <string> tmp_erase;
        for (auto i:aa){
            if (bb.find(i) == bb.end()){
                tmp_erase.push_back(i);
            }
        }
        for (auto i:tmp_erase){
            aa.erase(i);
        }
    }
}

int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n;
    scanf("%d",&n);
    while(n--){
        string a;
        for (int i=0;i<5;i++){
            int k;
            scanf("%d",&k);
            a += (char)(k+48);
        }
        add_all_valid(a);
    }
    cout << aa.size() << endl;
    return 0;
}