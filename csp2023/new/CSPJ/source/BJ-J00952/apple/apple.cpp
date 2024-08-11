#include <bits/stdc++.h>
using namespace std;
long long n,n1,a,cnt,ans2;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    n1=n;
    while(1){
        if(n1<3){
            cnt+=n1;
            break;
        }
        if(n1%3==0){
            a=n1/3;
            n1-=a;
            cnt++;
        }
        else {
            a=n1/3;
            a+=1;
            n1-=a;
            cnt++;
        }
    }
    if(n%3==1){
        ans2=1;
    }
    else if(n%3==0){
        ans2=n/3;
    }
    else if(n%3==2){
        ans2=n/3;
        ans2+=3;
    }
    cout << cnt << " " <<ans2;
    return 0;
}
