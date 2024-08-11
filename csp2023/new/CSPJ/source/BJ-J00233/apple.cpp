#include <bits/stdc++.h>
using namespace std;
int vis[1000000];
int main(){
    int n;
   freopen("apple.in","r",stdin);
   freopen("apple.out","w",stdout);
    cin>>n;
    int o=0;
    while(true){
            bool r=0;
        for(int i=1;i<=n;i++){
            if(vis[i]==0)
                r=1;
        }
    if(r==0)
        break;
        o++;
        int sum=0;
        int s;
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                s=i;
                break;
            }
        }
        vis[s]=o;
        //cout<<s<<" "<<o<<endl;
        for(int i=s+1;i<=n;i++){
            if(vis[i]==0)
                sum++;
                //cout<<sum<<" "<<o<<endl;
            if(sum==3){
                vis[i]=o;
                sum=0;
                //cout<<i<<" "<<o<<endl;
            }

        }
    }
    cout<<o<<" "<<vis[n];
    return 0;
}
