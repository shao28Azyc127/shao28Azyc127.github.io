#include<bits/stdc++.h>
using namespace std;
int a[1000099]={1};
int main(){
    int n,ans1,ans2,cnt=2,num=0,d=0;
    cin>>n;
    while(1){
        d++;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                continue;
            }else if(cnt==2){
                if(i==n) ans2=d;
                a[i]=0;
                cnt=0;
                num++;
            }else{
                cnt++;
                continue;
            }
        }
        cnt=2;
        if(num==n){
            ans1=d;
            break;
        }
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}
