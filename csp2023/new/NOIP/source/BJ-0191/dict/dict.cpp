#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n,k;
string s[3005],rs[3005];
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> s[i];
    for(int i = 1;i <= n;i++){
        sort(s[i].begin(),s[i].end());
        rs[i] = s[i];
        reverse(rs[i].begin(),rs[i].end());
    }
    sort(rs + 1,rs + n + 1);
    for(int i = 1;i <= n;i++){
        reverse(s[i].begin(),s[i].end());
        string x = rs[1];
        if(s[i] == x) x = rs[2];
        reverse(s[i].begin(),s[i].end());
        if(s[i] < x) cout << 1;
        else cout << 0;
    }
    return 0;
}