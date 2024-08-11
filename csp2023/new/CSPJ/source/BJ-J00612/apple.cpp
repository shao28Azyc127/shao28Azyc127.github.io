#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    cin>>n;
    int k=n,a,b,cnt=0;
    if(n<=3) b=n;
    else if(n%10==0) b=n/10;
    else if((n-1)%3==0) b=1;
    else b=n/4;
    while(k>0){
        if(k<=3){
            cnt+=k;
            break;
        }
        if(k%3==0&&k!=0) a=k/3;
        else a=k/3+1;
        if(a==2&&k<=4) cnt+=3;
        else{
            k-=a;
            cnt++;
        }
    }
    cout<<cnt<<" "<<b;
    return 0;
}
