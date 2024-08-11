#include<bits/stdc++.h>
using namespace std;
int n,i,j,c=2,f;
int main(){
   freopen("apple.in","r",stdin) ;
   freopen("apple.out","w",stdout) ;
    cin>>n;
    if(n<3)cout<<n<<" "<<n;
    for(i=3;i<=n;i++){
        for(j=i;j;j>2?j-=2:j--){
            c++;
            if(c==n){
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
    return 0;
}
