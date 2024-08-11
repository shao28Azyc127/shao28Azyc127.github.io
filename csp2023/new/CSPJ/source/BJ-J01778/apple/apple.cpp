#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,a[N],sum,p=1,ans;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(1){
        int chk=0;
        for(int i=1;i<=n;i++) if(a[i]==1) chk++;
        if(chk==n) break;
        sum++;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                p=i;
                break;
            }
        }
        while(p<=n){
            if(a[p]==0){
                if(p==n) ans=sum;
                a[p]=1;
                int s=0;
                while(s<3){
                    p++;
                    if(p>n) break;
                    if(a[p]==0) s++;
                }
            }
        }
    }
    cout<<sum<<" "<<ans;
    return 0;
}
