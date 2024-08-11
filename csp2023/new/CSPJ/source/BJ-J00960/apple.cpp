#include<iostream>
using namespace std;

bool a[1000005];

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n; cin >> n;
    if(n > 10000005){
        int b = n;
    int cnt = 0;
    while(b > 1){
        cnt++;
        if(b % 3 == 0) b -= b / 3;
        else b -= (b/3+1);
    }
    int a = n;
    int ans = 0;
    while(a % 3 != 1){
        if(b % 3 == 0) b -= b / 3;
        else b -= b/3+1;
        ans++;
    }
    cout << cnt+1 << " " << ans+1;
    return 0;
    }
    int cnt = n;
    int ans = 0;
    int ans2;
    int pos = 1;
    int last = 1;
    while(cnt > 0){
        ans++;
        for(int i = last; i <= n; i++){
            if(!a[i]) {pos = i;break;}
        }
        last = pos;
        //cout << pos << endl;
        int o = 2;
        for(int i = pos; i <= n; i++){
            if(!a[i]) o++;
            if(o == 3){
                if(i == n) ans2 = ans;
                a[i] = true;
                cnt--;
                o = 0;
                //cout << i << " ";
            }
        }
        //cout << endl;
    }
    cout << ans << " " << ans2 << endl;
    return 0;
}