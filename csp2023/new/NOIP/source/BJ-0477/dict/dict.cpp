#include <bits/stdc++.h>
using namespace std;

int const N = 3010;

int n, l;
char s[N][N], t1[N][N], t2[N][N];

bool cmp2(char a, char b){
    return a > b;
}

bool cmp1(char a, char b){
    return a <b;
}

bool check(char a[], char b[]){
    for (int i = 0;i < n;++i){
        if (a[i] != b[i])
            return a[i] > b[i];
    }
}

int main(){
    freopen("dict.in", "r", stdin);
    freopen("dict.out","w", stdout);
    cin >> n >> l;
    for (int i = 1;i <= n;++i){
        scanf("%s", s[i]);
        for (int j = 0;j < l;++j) t1[i][j] = t2[i][j] = s[i][j];
    }
    for (int i = 1;i <= n;++i){
        sort(t1[i], t1[i] + l, cmp1);
        sort(t2[i], t2[i] + l, cmp2);
    }
    // for (int i = 1;i <= n;++i) cout << t1[i] << t2[i] << endl;
    for (int i = 1;i <= n;++i){
        bool flag = 1;
        for (int j = 1;j <= n;++j){
            if (i != j){
                if (check(t1[i], t2[j])){
                    flag = 0;
                    break;
                }
            }
        }
        cout << flag;
    }
    return 0;
}
