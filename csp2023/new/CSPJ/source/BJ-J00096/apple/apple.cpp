#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,cnt=0,day=0,ansday;
    cin>>n;
    if(n<=3){
        cout<<n<<" "<<n;
        return 0;
    }
    long long n2=n;
    while(n2>3){
        n2=n2-(n2/3+1);
        cnt++;
    }
    cnt+=n2;
    long long cnt2=0;
    cout<<cnt<<" ";
    while(1){
        cnt2++;
        if(n%3==1){
            break;
        }
        if(n%3==0){
            n=n-n/3;
        }else if(n%3==2){
            n=n-(n/3+1);
        }
    }
    cout<<cnt2;
    return 0;
}
