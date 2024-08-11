#include<bits/stdc++.h>
using namespace std;
int n;
int cnt=1,ans;
int day;
int a[10000005];
bool flag=1;
int t=3;
bool fp=0;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(flag==1){
        day++;
        flag=0;
        t=3;
        while(cnt<=n){
            if(a[cnt]==0&&t>=3){
                t=1;
                a[cnt]=1;
                flag=1;
                cnt++;
                if(--cnt==n)ans=day;
            }else{
                t++;
                if(a[cnt]==1)t--;
                cnt++;
            }
        }
        cnt=1;
    }
    cout<<--day<<" "<<ans;
}
