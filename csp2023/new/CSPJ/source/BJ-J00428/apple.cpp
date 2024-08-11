#include <cstdio>
#include <iostream>
using namespace std;
int a[100005];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    bool f=1;
    int t=0,ans=0,cnt=0;
    while(f==1){
        t++;
        bool tf=0;
        cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]==0){
                tf=1;
                cnt++;
                if(cnt==3) cnt=0;
                if(cnt==1){
                    a[i]++;
                    if(i==n-1){
                        ans=t;
                    }
                }
            }
        }
        f=tf;
    }
    cout<<t-1<<' '<<ans;
    return 0;
}