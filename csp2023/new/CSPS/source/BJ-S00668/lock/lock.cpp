#include<bits/stdc++.h>
using namespace std;
int n, cnt1, cnt2, num1, num2, a[6], b[6];
int main (){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin >>n;
    if (n==1) {
        cout << 81 ;
        return 0;
    }
    if (n==2) {
        for (int i=0;i <5; i++){
            cin >> a[i];
        }
        for (int i=0;i <5; i++){
            cin >> b[i];
            if (a[i]==b[i]) cnt1++;
        }
        num1=8*(5-cnt1);
        for (int i=0;i<4;i++){
            if (a[i]==b[i] && a[i+1]==b[i+1])
                cnt2++;
        }
        num2=2*(4-cnt2);
        cout << num1+num2;
        return 0;
    }
    return 0;
}