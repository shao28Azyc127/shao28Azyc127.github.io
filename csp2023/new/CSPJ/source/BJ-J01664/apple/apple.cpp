#include<bits/stdc++.h>

using namespace std;

long long n,day = 0,nday = 1,cnt = 0,i = 1,cnt2 = 0,cnt3 = 0;
bool flag[1000000005];

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    while(cnt < n){
        while(i <= n){
            if(flag[i] == true){
                i++;
                continue;
            }
            if(i > n){
                break;
            }
            flag[i] = true;
            cnt++;
            if(i == n){
                nday = day + 1;
            }
            //cout << "cnt " << cnt << " day " << day << " i " << i << endl;
            while(cnt3 < 2&&i <= n){
                if(flag[i + cnt2] == true){
                    cnt2++;
                    continue;
                }
                cnt3++;
                cnt2++;
            }
            i = i + cnt2;
            cnt2 = 0,cnt3 = 0;
        }
        day++;
        i = 1;
    }
    cout << day << " " << nday;
    return 0;
}