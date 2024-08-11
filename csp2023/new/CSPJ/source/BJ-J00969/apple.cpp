#include<bits/stdc++.h>
using namespace std;
const int N=1e9+10;
long long n,cnt,ans1,ans2;
bool a[N];
bool f=true;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(f){
        for(int i=1;i<=n;i++){
            if(a[i]==false){
                a[i]=true;
                if(i==n){
                    ans2=ans1+1;
                }
                cnt++;
                if(cnt==n){
                    f=false;
                    break;
                }
                if(n-i<3) break;
                long long cnt1=0;
                bool f1=true;
                for(int j=i+1;j<=n;j++){
                    if(!a[j]) cnt1++;
                    if(cnt1==2){
                        if(j==n) f1=false;
                        i=j;
                        break;
                    }
                }
                if(!f) break;
                if(cnt1!=2) break;
            }
        }
        ans1++;
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}
