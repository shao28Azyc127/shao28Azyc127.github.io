#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],b[N],jump[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    int n,d;
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    int z=0,ans=0,l=0,t=0,cnt=0;;
    for(int i=1;i<n;i++){

            if(i<cnt)continue;
                for(int j=i+1;j<=n;j++){
                    if(b[i]>b[j]){
                            cnt=j;

                            t+=a[j-1];

                        break;
                    }else{

                        t+=a[j-1];
                        cnt=j;

                    }
                }

            t-=l;

        if(t%d==0){
            z=t/d;
        }else{
            z=t/d+1;
        }

        ans+=b[i]*z;

        l=z*d;
        l-=t;
    t=0;

    }
    cout<<ans;
           return 0;

}
