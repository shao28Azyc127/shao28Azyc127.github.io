#include <bits/stdc++.h>
using namespace std;

string a[3333], x;
int n, m, mi = 1;

bool cmp(char a, char b){
    return a > b;
}

int main(){
//    freopen("a.in", "r", stdin);
//    freopen("a.out", "w", stdout);
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sort(a[i].begin(), a[i].end(), cmp);
        if(a[i] < a[mi]) mi = i;
    }
    for(int i = 1; i <= n; i++){
        x = a[i];
        sort(x.begin(), x.end());
//        cout << a[i] << ' ' << x << endl;
        int ans = 1;
        if(i == mi){
            for(int j = 1; j <= n; j++){
                if(j != i && a[j] <= x){
    //                cout << i << ':' << j << ' ' << x << ' ' << a[i] << endl;
                    ans = 0;
                    break;
                }
            }
        }else{
            ans = x < a[mi];
        }
        cout << ans;
    }
    return 0;
}
