
#include<iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int n, m;
string s[3010];
struct node{
    string up, down;
    int id;
}a[3010];
int cnt[3010][3010];


int main(){
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> n >> m;

    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++){
            char cmp;
            cin >> cmp;
            int ccccc = (int)cmp;
            cnt[i][ccccc]++;
        }

        for(int j = (int)'a'; j <= (int)'z'; j++){
            for(int k = 1; k <= cnt[i][j]; k++){
                a[i].up += char(j);
            }
        }

         for(int j = (int)'z'; j >= (int)'a'; j--){
            for(int k = 1; k <= cnt[i][j]; k++){
                a[i].down += char(j);
            }
        }
    }

    if(n == 1){
        cout << 1 <<endl;
        return 0;
    }else{

        for(int i = 1; i  <= n; i++){

            bool flag = false;
            for(int j = 1; j <= n; j++){
                if(j != i){
                    if(a[j].down <= a[i].up){
                        flag = true;
                        break;
                    }
                }
            }

            if(flag){
                cout << 0;
                continue;
            }
            cout<<1;
        }
        return 0;
    }
    return 0;
}
//sto dzd orz
//sto kksc03 orz
//sto chen_zhe orz
//sto lxl orz
//sto Shan_creeper orz
//let me pass it
