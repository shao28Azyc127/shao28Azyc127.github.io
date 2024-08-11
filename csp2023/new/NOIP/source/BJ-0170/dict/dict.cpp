#include <bits/stdc++.h>

using namespace std;

string str[3030];
struct node{
    string s;
    int pos;
}Min[3030], Max[3030];
int n, m, t[30];
bool ans[3030];
bool cmp(node x, node y){
    return x.s < y.s;
}

int main (){
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> str[i];
        str[i] = " " + str[i];
    }
    if(n == 1) return cout << 1, 0;
    for(int i = 1; i <= n; i++){
        memset(t, 0, sizeof(t));
        for(int j = 1; j <= m; j++) t[str[i][j] - 'a']++;
        for(int j = 0; j < 26; j++)
            if(t[j])
                for(int k = 1; k <= t[j]; k++)
                    Min[i].s += (char)(j + 'a');
        for(int j = 25; j >= 0; j--)
            if(t[j])
                for(int k = 1; k <= t[j]; k++)
                    Max[i].s += (char)(j + 'a');
        Min[i].pos = Max[i].pos = i;
    }
    sort(Min + 1, Min + 1 + n, cmp);
    sort(Max + 1, Max + 1 + n, cmp);
    for(int i = 1; i <= n; i++){
        if(Min[i].pos == Max[1].pos){
            if(Min[i].s < Max[2].s) ans[Min[i].pos] = 1;
            else ans[Min[i].pos] = 0;
        }
        else{
            if(Min[i].s < Max[1].s) ans[Min[i].pos] = 1;
            else ans[Min[i].pos] = 0;
        }
    }
    for(int i = 1; i <= n; i++) cout << (int)ans[i];
    return 0;   
}