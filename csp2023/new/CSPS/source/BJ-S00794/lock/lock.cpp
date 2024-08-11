#include <bits/stdc++.h>
using namespace std;
int n,c[2][105][10],cnt,cnt2,cnt3,tmp,a[10];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= 5;i++) cin >> a[i];
    for(int i = 1;i <= 5;i++)
        for(int j = 0;j <= 9;j++){
            if(j == a[i]) continue;
            ++cnt;
            for(int k = 1;k <= 5;k++){
                if(k == i) c[tmp][cnt][k] = j;
                else c[tmp][cnt][k] = a[k];
            }
        }
    for(int i = 1;i < 5;i++)
        for(int j = 1;j <= 9;j++){
            ++cnt;
            for(int k = 1;k <= 5;k++){
                if(k == i || k == i + 1) c[tmp][cnt][k] = (a[k] + j) % 10;
                else c[tmp][cnt][k] = a[k];
            }
        }
    n--;
    while(n--){
        cnt2 = 0;
        tmp = !tmp;
        for(int i = 1;i <= 5;i++) cin >> a[i];
        for(int i = 1;i <= cnt;i++){
            cnt3 = 0;
            for(int j = 1;j <= 5;j++) if(a[j] != c[!tmp][i][j]) cnt3++;
            if(cnt3 == 1){
                ++cnt2;
                for(int j = 1;j <= 5;j++) c[tmp][cnt2][j] = c[!tmp][i][j];
            }else if(cnt3 == 2){
                int flag = 0;
                for(int j = 2;j <= 5;j++)
                    if(a[j] != c[!tmp][i][j] && a[j - 1] != c[!tmp][i][j - 1]){
                        if((a[j] - c[!tmp][i][j] + 10) % 10 == (a[j - 1] - c[!tmp][i][j - 1] + 10) % 10) flag = 1;
                        break;
                    }
                if(flag){
                    ++cnt2;
                    for(int j = 1;j <= 5;j++) c[tmp][cnt2][j] = c[!tmp][i][j];
                }
            }
        }
        cnt = cnt2;
    }
    cout << cnt;
    return 0;
}
