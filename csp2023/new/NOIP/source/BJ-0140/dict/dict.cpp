#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
int n, m, buk[30];
string s[N], s2[N];


int main(){
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> s[i];
    if (n == 1){
        printf("1");
        return 0;
    }
    for (int i=1; i<=n; i++) s2[i] = s[i];
    int cnt;
    string tmp;
    for (int i=1; i<=n; i++){
        for (int j=0; j<26; j++) buk[j] = 0;
        for (int j=0; j<m; j++) buk[s[i][j] - 'a']++;
        tmp = "";
        for (int j=0; j<26; j++){
            while (buk[j]--) tmp += j + 'a';
        }
        s[i] = tmp;
    }//sort in increasing order
    for (int i=1; i<=n; i++){
        for (int j=0; j<26; j++) buk[j] = 0;
        for (int j=0; j<m; j++) buk[s2[i][j] - 'a']++;
        tmp = "";
        for (int j=25; j>=0; j--){
            while (buk[j]--) tmp += j + 'a';
        }
        s2[i] = tmp;
    }//sort in decreasing order
    int mn = -1, mn2 = -1;
    string mns = "", mns2 = "";
    for (int i=1; i<=m; i++) mns += 'z', mns2 += 'z';
    for (int i=1; i<=n; i++){
        if (s2[i] < mns || s2[i] == mns){
            mns2 = mns;
            mns = s2[i];
        }
        else if (s2[i] < mns2){
            mns2 = s2[i];
        }
    }
    for (int i=1; i<=n; i++){
        if (s2[i] != mns){
            if (s[i] < mns) printf("1");
            else printf("0");
        }
        else{
            if (s[i] < mns2) printf("1");
            else printf("0");
        }
    }
    printf("\n");
    return 0;
}
