#include<bits/stdc++.h>
using namespace std;
int n, ans;
int a[100005][2];
int b[100005];
int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
    cin >> n;
    int m = 0;
    char t1 = '#', t2; 
    for(int i = 1; i <= n; i++){
        cin >> t2;
		if(t2 != t1){
            a[++m][0] = t2;
            a[m][1] = 1;
        }
        if(t2 == t1){
            a[m][1]++;
        }
        
        t1 = t2;
    }
    for(int i = 1; i <= m; i++){
        if(a[i][1] >= 2){
            ans += (a[i][1] * (a[i][1] - 1)) / 2;
            b[i] += a[i][1] - 1;

            ans += b[i - 1] * (a[i][1] - 1);
            b[i] += b[i - 1];

            int x = i, y = i;
            while(1){
                if(x - 1 >= 1){
                    --x;
                } else {
                	break;
				} 
                if(y + 1 <= m){
                    ++y;
                } else {
                	break;
				}
                if(a[x][0] != a[y][0]){
                    break;
                }
                ans += a[x][1] * a[y][1];
                b[y] += a[x][1];

                ans += b[x - 1] * (a[y][1]);
                b[i] += b[i - 1];
            }
        }
    }
    cout << ans;

return 0;
}