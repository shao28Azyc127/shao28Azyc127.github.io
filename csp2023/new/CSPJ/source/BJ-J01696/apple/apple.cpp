#include <iostream>
using namespace std;
bool vis[1000000005];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int ans=n,x,days=0;
    while(ans>0){
        int cnt=2;
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                if(cnt==2){
                    cnt=0;
                    ans--;
                    if(i==n){
                        x=days;
                    }
                    vis[i]=1;
                }else{
                    cnt++;
                }
            }
        }
        days++;
    }
    cout<<days<<" "<<x+1;
    return 0;
}
