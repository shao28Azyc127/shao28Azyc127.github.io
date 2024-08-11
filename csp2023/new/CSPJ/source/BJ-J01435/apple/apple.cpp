#include<iostream>
#include<sys/stat.h>
#include<bits/stdc++.h>
using namespace std;

struct a{
    int p;
    int n;
};

a apples[1000000000];


int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out",  "w", stdout);
    int n, cnt, ans1 = 0, ans2 = 519438, cont;
    bool flag = true;
    cin >> n;
    cnt = n;
    for(int i = 0; i < n; i++){
        apples[i].n = i + 1;
        apples[i].p = i - 1;
    }
    while(cnt > 0){
        cont = 0;
        for(int i = ans1; ; i++){
            if(cont == 2){
                if(apples[i].n >= n){
                    ans2 = ans1;
                    apples[apples[i].p].n = apples[i].n;
                    break;
                }
                apples[apples[i].p].n = apples[i].n;
                apples[apples[i].n].p = apples[i].p;
                cont = 0;
                cnt--;
            }
            else{
                cont++;
            }
            if(apples[i].n >= n){
                break;
            }
            i = apples[i].n;
        }
        ans1++;
        cnt--;
    }
    if(ans2 == 519438){
        ans2 = ans1 - 1;
    }
    cout << ans1 << ' ' << ans2 + 1;
    return 0;
}
