#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int ans;

bool check(int x,int y){
    if ((y-x+1)%2==1){
        return false;
    }
    int i=x,j=y;
    while (i<j){
        if (s[i]!=s[j]){
            return false;
        }
        else{
            i++,j--;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n >> s;
    if (n==1){
        cout << 0 << endl;
        return 0;
    }
    for (int i=0;i<=n-1;i++){
        for (int j=i+1;j<=n-1;j++){
            if (check(i,j)){
                // cout << i << " " << j << endl;
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}