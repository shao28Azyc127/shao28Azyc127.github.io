#include<bits/stdc++.h>
using namespace std;
int u[100009];
/*struct no{
    int a1,b;
}*/
int a[100009];
//queue<int>q;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,ans=0,co=0,l=1,w=1;
    double g=0;
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>u[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i]/*.a1*/;
        //a[i].b=i;
    }
    while(w<=n){
        l=0;
        //ans=0;
        for(int i=w;i<=n;i++){
            if(a[w]>a[i]){
                l+=u[i];
                break;
            }else{
                ans++;
                l+=u[i];
            }
            //cout<<"i"<<i<<"i"<<endl;
        }
        if(w==1){
            l=l-u[1];
        }
        if(l%d!=0){
            //cout<<ans<<" "<<(l+d)/d<<endl;
            co+=((l+d)/d-g)*a[w];
            if((l+d)/d>g){
                g=0;
                break;
            }else{
                g-=(l+d)/d;
                break;
            }
            g+=(l+d)-l;
        }else{
            //cout<<ans<<" "<<l/d<<endl;
            co+=(l/d-g)*a[w];
            if(l/d>g){
                g=0;
                break;
            }else{
                g-=l/d;
                break;
            }
        }
        w+=ans;
    }
    cout<<co<<" "<<g;
    return 0;
}
