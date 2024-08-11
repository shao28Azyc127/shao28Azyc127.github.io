//90pts
#include<bits/stdc++.h>
using namespace std;
int check1(int n){
    int cnt = 0;
    while(n > 0){
        cnt++;
        int iseated = n / 3;
        if(n % 3 != 0) iseated++;
        n -= iseated;
    }
    return cnt;
}
const int N = 1e6 + 1;
bool isout[N];
int check2(int n){
    if(n % 3 == 1){
        return 1;
    }
    memset(isout, false, sizeof(isout));
    if(n > N - 1){
        if(n % 3 == 1){
            return 1;
        }else{
            return check1(n);
        }
        return 0;
    }
    int fr = 1, day = 0, kft = check1(n);
    while(day != kft){
        day++;
        while(isout[fr] == true) fr++;
        for(int i = fr; i <= n; ){
            if(i == n){
                return day;
            }
            isout[i] = true;
            int k = 0, ans, noww = i + 1;
            while(true){
                //if(i == 4) cout << noww << " ";
                if(noww > n){
                    ans = -1;
                    break;
                }
                if(isout[noww] == false) k++;
                if(k == 3){
                    ans = noww;
                    break;
                }
                noww++;
            }
            if(ans == -1){
                break;
            }
            i = ans;
        }
    }
    return 0;
}
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    cout << check1(n) << " ";
    cout << check2(n) << endl;
    return 0;
}
