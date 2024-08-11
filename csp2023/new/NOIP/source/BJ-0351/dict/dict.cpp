#include <bits/stdc++.h>
using namespace std;
int n, m;
char S[15005][5005];
char smin[5005][5005];
char smax[5005][5005];
string ans= "";
bool cmp (char a, char b) {
    return (int)a > (int)b;
}
void Fm(char* ss, int c) {
    char s[5005], s1[5005], s2[5005];
    strcpy(s,ss);
    strcpy(s1,ss);
    strcpy(s2,ss);
    char minc, maxc;
    int minst=0, maxst=0;
    sort(s, s + m);
    for (int i = 0; i < m; i++) {
        if (s[i] != s1[i]) {
            minc = s[i];
            minst = i;
            break;
        }
    }
    sort(s, s + m, cmp);
    for (int i = 0; i < m; i++) {
        if (s[i] != s2[i]) {
            maxc = s[i];
            maxst = i;
            break;
        }
    }
    int maxIdx=maxst, minIdx=minst;
    int flag1 = 0, flag2 = 114514;
    for (int i = 0; i < m; i++) {
        if (i >= maxst && ss[i] == maxc) {
            maxIdx = i;
        }
        if (i >= minst && ss[i] == minc) {
            minIdx = i;
        }
    }
    swap(s1[maxst], s1[maxIdx]);
    swap(s2[minst], s2[minIdx]);
    strcpy(smax[c],s1);
    strcpy(smin[c],s2);

}
int lowD(char* s1, char* s2) {
    for (int i = 0; i < m; i++) {
        if (s1[i] < s2[i]) {
            return 1;
        }
    }
    return 0;
}
int judge(int idx) {
    for (int i = 0; i < n; i++) {
        if (i == idx)continue;
        if (!lowD(smin[idx], smax[i])){
             return 0;
        }
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(false);
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> S[i];
        Fm(S[i], i);
    }
    for (int i = 0; i < n; i++){
      ans += judge(i) + '0';
    }
    cout << ans;
    return 0;
}