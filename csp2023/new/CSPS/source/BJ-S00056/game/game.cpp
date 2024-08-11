#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    string a;
    long long n,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    while(n>0){
        for(long long i=0;i<n;i++){
            if(a[i]==a[i+1]){
                ans++;
                if(i==n-1){
                    n-=2;
                }
                else{
                    for(long long j=i;j<n;j++){
                        a[j]=a[j+2];
                    }
                    n-=2;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
