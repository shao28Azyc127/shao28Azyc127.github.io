#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,s,d,ans;
    cin>>n;
    bool a[n+1];
    for(int i=0;i<=n;i++){
        a[i]=true;
    }
    for(d=1;a[0]==true;d++){
        s=2;
        a[0]=false;
        for(int i=1;i<=n;i++){
            if(a[i]==true){
                if(s==2){
                    if(i==n){
                        ans=d;
                    }
                    a[i]=false;
                    a[0]=true;
                    s=0;
                }
                else{
                    s++;
                }
            }
        }
    }
    cout<<d-2<<" "<<ans;
    return 0;
}
