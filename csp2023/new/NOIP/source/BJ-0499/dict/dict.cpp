#include<iostream>
#include<algorithm>
using namespace std;

struct node{
    string s;
    int b[26];
    int i;
};

node a[3005];
int n,m;
int c[3005];

bool cmp(node x, node y){
    for(int i = 0; i < m; i++){
        if(x.s[i] != y.s[i]) return x.s[i] < y.s[i];
    }
    return x.i < y.i;
}

bool check(string s1, string s2){
    for(int i = 0; i < m; i++){
        if(s1[i] != s2[i]){
            return s1[i] < s2[i];
        }
    }
    return false;
}

int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        a[i].i = i;
        cin >> a[i].s;
        for(int j = 0; j < m; j++){
            a[i].b[a[i].s[j]-'a']++;
        }
    }
    sort(a+1,a+n+1,cmp);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[j].i == i){
                c[i] = j;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        int j = c[i];
        if(j == 1) {cout << 1;continue;}
        string s = "";
        for(int p = 0; p < 26; p++){
        for(int q = 1; q <= a[j].b[p]; q++){
            s += p+'a';
        }
        }
        if(check(s,a[1].s)) cout << 1;
        else cout << 0;
    }
    return 0;
}
