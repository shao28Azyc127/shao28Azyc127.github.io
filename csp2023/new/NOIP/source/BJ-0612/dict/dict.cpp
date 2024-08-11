#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll MaxN = 3005;
ll n, m;

char s[MaxN][MaxN];
char s2[MaxN][MaxN];
char minchars[MaxN], maxchars[MaxN];

void init(){
    for (ll i = 0;i < n;i ++){
        char maxchar = 'a', minchar = 'z';
        for (ll j = 0;j < m;j ++){
            if (s[i][j] > maxchar) maxchar = s[i][j];
            if (s[i][j] < minchar) minchar = s[i][j];
        }
        minchars[i] = minchar;
        maxchars[i] = maxchar;
    }
}

bool strmin(ll d){
    for (int i = 0;i < n;i ++){
        if (i != d && minchars[d] >= maxchars[i]) return false;
    }
    return true;
}

int main(){
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    scanf("%lld %lld", &n, &m);
    for (ll i = 0;i < n;i ++){
        scanf("%s", &s[i]);
    }
    if (n == 1){
        printf("%d", 1);
        return 0;
    }
    if (m == 1){
        ll minnum = 0;
        for (ll i = 1;i < n;i ++){
            if (s[i][0] < s[minnum][0]) minnum = i;
        }
        for (ll i = 0;i < n;i ++){
            if (i != minnum) printf("%d", 0);
            else if(i == minnum) printf("%d", 1);
        }
        return 0;
    }
    init();
    for (ll i = 0;i < n;i ++){
        if (strmin(i)){
            printf("%d", 1);
        }else {
            printf("%d", 0);
        }
    }
    return 0;
}
