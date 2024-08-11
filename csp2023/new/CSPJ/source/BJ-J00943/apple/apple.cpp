#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,id=1,nday[100000000+90];
bool vis[100000000+50],ok=1;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    //1  2  3  4  5  6  7  8
    //v        v        v
    //   v            v
    //      v
    //            v
    //                      v
    for(int i=1;;i++){
        if(!vis[i])
        {
            int cnt=0;
            for(int j=i;j<=n;j+=3){
                vis[j]=1;
                nday[j]=i;

            }
            for(int k=1;k<=n;k++){
                if(vis[k]==0){
                  cnt++;
                  break;
                }
               else continue;
             }
             //cout<<cnt<<endl;
           if(cnt==0){
              cout<<i<<" "<<nday[n]<<endl;
              return 0;
           }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
