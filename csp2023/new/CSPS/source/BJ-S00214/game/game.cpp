#include <bits/stdc++.h>
using namespace std;
struct letter{
    char name;
    int counta = 0;
};
vector <string> test;
bool testabc(string b,int l,int r){
    int tag = 1;
    struct letter x[100000];
    for(int i = l;i <= r;i++){
        bool finda = false;
        for(int j = 1;j <= tag;j++){
            if(x[j].name == b[i]){
                x[j].counta += 1;
                finda = true;
                break;
            }
        }
        if(!finda){
            x[tag].name = b[i];
            tag += 1;
        }
    }
    for(int i = 1;i <= tag;i++){
        if(x[i].counta % 2 == 1){
            return false;
        }
    }
    return true;
}
bool foward(string b,int l,int r){
    int le = l;
    int re = r;
    while(le < re){
        if(b[le] != b[re]){
            return false;
        }
        le += 1;
        re -= 1;
    }
    return true;
}
bool testfind(string b,int l,int r){
    string z = "";
    for(int i = l;i <= r;i++){
        z += b[i];
    }
    int testsize = test.size();
    for(int a = 0;a < testsize;a++){
        for(int b = a + 1;b < testsize;b++){
            if(z == test[a] + test[b] || z == test[b] + test[a]){
                return true;
            }
        }
    }
    return false;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    int ans = 0;
    string b;
    cin >> n >> b;
    for(int i = 0;i < n;i++){
        for(int j = i + 1;j < n;j++){
            if((j - i) % 2 == 0){
                continue;
            }
            if(!testabc(b,i,j)){
                continue;
            }
            if(!foward(b,i,j)){
                continue;
            }
            string z = "";
            for(int k = i;k <= j;k++){
                z += b[k];
            }
            test.push_back(z);
            ans += 1;
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = i + 1;j < n;j++){
            if((j - i) % 2 == 0){
                continue;
            }
            if(!testabc(b,i,j)){
                continue;
            }
            if(testfind(b,i,j)){
                ans += 1;
            }
        }
    }
    cout << ans;
    return 0;
}
