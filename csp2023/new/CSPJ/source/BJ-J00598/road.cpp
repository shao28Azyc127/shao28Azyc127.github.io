#include <bits/stdc++.h>
using namespace std;
int n,d,flag=1;
int dis[100100],disc[100100],pri[100100],ans=0,l=0;
int check(int j){
    for(int i=1;i<=n;i++){
        if(pri[i]<pri[j]){
            return i;
        }
    }
    return -1;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    dis[1]=0;
    for(int i=2;i<=n;i++){
        cin>>dis[i];
        disc[i]= dis[i]+disc[i-1];
    }
    for(int i=1;i<=n;i++){
        cin>>pri[i];
    }
    for(int i=1;flag<=n&&i<=n;){
        flag=check(i);
        //cout<<"flag="<<flag<<endl;
        if(flag==-1){
            ans+=ceil((disc[n]-disc[i]-l)*1.0/d)*pri[i];
            cout<<ans<<endl;
            return 0;
        }
        else{
            ans+=ceil((disc[flag]-disc[i]-l)*1.0/d)*pri[i];
            if(ceil((disc[flag]-disc[i]-l)*1.0/d)*d-(disc[flag]-disc[i]-l)>0){
                l=ceil((disc[flag]-disc[i]-l)*1.0/d)*d-(disc[flag]-disc[i]-l);
            }
            else{
                l=0;
            }
            i=flag;
        }
        //cout<<"ans="<<ans<<" l="<<l;

    }
    cout<<ans<<endl;
    return 0;
}

