#include<bits/stdc++.h>
using namespace std;

int n,c[30],cnt;
bool f;
string s;

int main(){
    int i,j,k;

    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);

    cin >> n;

    cin >> s;

    for(i = 0;i < n;i++){
        for(j = 1;j <= 26;j++){
            c[j] = 0;
        }
        for(j = i;j < n;j++){
            c[s[j] - 'a' + 1]++;
            f = true;
            for(k = 1;k <= 26;k++){
                if(c[k] % 2 == 1){
                    f = false;
                    break;
                }
            }
            if(f){
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}