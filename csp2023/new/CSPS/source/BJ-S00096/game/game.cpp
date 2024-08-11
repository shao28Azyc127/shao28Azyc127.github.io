#include<bits/stdc++.h>
using namespace std;
int n;
char a[2000020], b[2000020];
int res;
int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin>>n>>a;
    for(int l=2;l<=(n&(-2));l+=2){
        for(int i=0;i+l<=n;++i){
            for(int j=0;j<l;++j){
                b[j]=a[j+i];
            }
                //cout<<"a:   \n";
                //for(int k=0;k<l;k++) cout<<b[k];
                //cout<<endl;
            int ans=0;
            while(1){
                int ggb=-1;
                for(int k=0;k+1<l-(ans<<1);++k){
                    if(b[k]==b[k+1]){
                        //cout<<"b[ "<<k<<" ] = "<<b[k]<<" | b[ "<<k+1<<" ] = "<<b[k+1]<<endl;
                        ggb=k;
                        ++ans;
                        break;
                    }
                }
                if(ggb==-1){
                    break;
                }
                for(int k=ggb;k<l-(ans<<1);k++){
                    swap(b[k], b[k+2]);
                }
                //for(int k=0;k<l;k++) cout<<b[k];
                //cout<<endl;
            }
            if(ans==(l>>1)){
                ++res;
                //cout<<"b:   \n";
                //cout<<"ans = "<<ans<<endl;
                //for(int k=0;k<l;k++) cout<<b[k];
                //cout<<endl;
                //cout<<i<<" "<<i+l-1<<endl;
                //cout<<"l = "<<l<<endl;
            }
        }
    }
    cout<<res;
    return 0;
}