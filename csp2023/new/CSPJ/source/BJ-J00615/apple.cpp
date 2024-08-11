#include<bits/stdc++.h>
using namespace std;
int n, cnt, ans2, a;
bool flag;
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    double b = n*1.0, c;
    while(b>0){
        a=ceil(b/3);
        if(b>3){
            b-=a;
        }else{
            b-=1;
        }
        cnt++;
        if(flag){
            continue;
        }else{
            if(ceil(b/3) == b/3){
                ans2 = cnt;
                flag = true;
            }
        }
    }
    if(flag)
        cout << cnt << " " << ans2;
    else
        cout<<cnt<<" " << cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}