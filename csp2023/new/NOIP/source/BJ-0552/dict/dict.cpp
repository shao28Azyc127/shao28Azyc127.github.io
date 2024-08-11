#include <bits/stdc++.h>
using namespace std;

const int MAXN=3005;

int bukkit_small[MAXN][27];

int main(){
    int n,m;
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    if (n == 1){
        cout << 1 << endl;
        return 0;
    }
    string s_small[n];
    string s_big[n];
    for (int i=0;i<n;i++){
        string tmp;
        cin >> tmp;
        bukkit_small[i][0] = i;
        for (int j=0;j<tmp.size();j++){
            bukkit_small[i][tmp[j]-'a'+1]++;
        }
    }
    for (int i=0;i<n;i++){
        for (int j=1;j<=26;j++){
            for (int k=0;k<bukkit_small[i][j];k++){
                s_small[i] += 'a'-1+j;
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int j=26;j>=1;j--){
            for (int k=0;k<bukkit_small[i][j];k++){
                s_big[i] += 'a'-1+j;
            }
        }
    }

    for (int i=0;i<n;i++){
        for (int j=i;j<n;j++){
            if (s_big[j] < s_small[i]){
                cout << 0;
                goto end;
            }
        }
        cout << 1;
        end:;
    }
    cout << endl;
    return 0;
}