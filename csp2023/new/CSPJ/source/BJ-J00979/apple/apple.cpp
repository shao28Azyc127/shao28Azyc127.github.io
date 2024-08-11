#include<bits/stdc++.h>
using namespace std;
int a[1000000005];
int main(){
    freopen("apple.in","r",strdin);
    freopen("apple.out","w",stdout);
    int i,j,n,d,ans,cnt=n,pos;
    cin>>n;
    while(cnt){
        ans=2;
        for(int i=0;i<n;i++){
            if(!a[i]){
                if(ans==2){
                    ans=0;
                    cnt--;
                    a[i]=1;
                    if(i==n-1) pos=d+1;
                }
                else ans++;
            }
        }
        d++;
    }
    cout<<d<<" "<<pos;
    frcolse(strin);
    frcolse(stdout);
    return 0;
}
