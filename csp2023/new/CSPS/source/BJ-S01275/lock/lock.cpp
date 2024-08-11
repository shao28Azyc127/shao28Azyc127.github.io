#include<bits/stdc++.h>
using namespace std;
//vector<int> pos[10];
int a[10][10];
int cnt_a[10];
int fr[10];
    int n;
int ans = 0;
void dfs(int num){
  //  cout << num << endl;
    if(num == 5){
        //int fw = 0;
      //  cout << n << endl;
        for(int i = 1; i <= n; i++){
            int fw = 0;
            for(int j = 1; j <= 5; j++){
                if(cnt_a[j] != a[i][j]){
                    if(fw > 0){
                        if(fw < j - 1) return;
                        int onew = (cnt_a[j] - a[i][j] + 10) % 10;
                        int twow = (cnt_a[fw] - a[i][fw] + 10) % 10;
                        if(onew == twow) continue;
                        else return;
                    } else {
                        fw = j;
                    }
                }
            }
            if(fw == 0) return;
            //cout << "in" << i << "=" << fw << endl;
        }
    //    for(int i = 1; i <= 5; i++) cout << cnt_a[i] << " ";
    //    cout << endl;
        ans++;
        return;
    }
    for(int i = 0; i <= 9; i++){
        cnt_a[num + 1] = i;
    //    cout << num + 1 << "=" << i << endl;
        dfs(num + 1);
    }
}
int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 5; j++){
            cin >> a[i][j];
        }
    }
    dfs(0);
    cout << ans;
    return 0;
}
