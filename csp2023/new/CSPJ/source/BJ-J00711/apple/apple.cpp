#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,w,r,j=1,ans;
    cin>>n;
    bool a[n+1];
    w=n;
    for(int i=1;i<=n;i++)a[i]=1;
    while(w){
        r=0;
        for(int i=1;i<=n;i++){
            if(a[i]){
                if(r==0){
                    a[i]=0;
                    w--;
                    if(i==n)ans=j;
                }
                r++;
                r%=3;
            }
        }
        j++;
    }
    cout<<j-1<<" "<<ans;
    return 0;
}
