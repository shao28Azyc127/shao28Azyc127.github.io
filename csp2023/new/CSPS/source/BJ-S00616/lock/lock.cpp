#include <bits/stdc++.h>
using namespace std;
int l[10][7];
unordered_map<int, int> mp;
unordered_map<int, int>::iterator it;


int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n, tmp;
    scanf("%d", &n);
    for (int i=1; i<=n; i++) for (int j=1; j<=5; j++) scanf("%d", &l[i][j]);
    for (int i=1; i<=n; i++){
        //turn only one pos
        for (int j=1; j<=5; j++){
            for (int k=1; k<10; k++){
                l[i][j] = (l[i][j] + 1) % 10; tmp = 0;
                for (int p=1; p<=5; p++) tmp = tmp * 10 + l[i][p];
                mp[tmp]++;
            }
            l[i][j] = (l[i][j] + 1) % 10;
        }
        //turn two at a time
        for (int j=1; j<5; j++){
            for (int k=1; k<10; k++){
                l[i][j] = (l[i][j] + 1) % 10;
                l[i][j + 1] = (l[i][j + 1] + 1) % 10;
                tmp = 0;
                for (int p=1; p<=5; p++) tmp = tmp * 10 + l[i][p];
                mp[tmp]++;
            }
            l[i][j] = (l[i][j] + 1) % 10;
            l[i][j + 1] = (l[i][j + 1] + 1) % 10;
        }
    }
    int ans = 0;
    for (it=mp.begin(); it!=mp.end(); it++) if ((*it).second == n) ans++;
    printf("%d\n", ans);
    return 0;
}
