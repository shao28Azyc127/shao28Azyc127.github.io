#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
int n,d;
struct dx{
int far;
int mony;
};
dx a[100005];
bool cmb(dx c,dx b){
return c.mony<b.mony;
}
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
cin>>n>>d;
a[1].far=0;
for(int i=2;i<=n;i++){
cin>>a[i].far;
a[i].far+=a[i-1].far;
}
for(int i=1;i<=n;i++){
cin>>a[i].mony;
}
int you=0;
int money=0x3f3f3f3f,arf=0,ans=0;
for(int i=1;i<=n-1;i++){
if(a[i].mony<money){

    if((a[i].far-arf-you)%d==0){
        ans+=(a[i].far-arf-you)/d*money;
    }
    else{
        ans+=((a[i].far-arf-you)/d+1)*money;
        you=(a[i].far-arf-you)%d;
    }
    money=a[i].mony;
    arf=a[i].far;
}
}
if(arf!=a[n].far){
if((a[n].far-arf-you)%d==0){
        ans+=(a[n].far-arf-you)/d*money;
    }
    else{
        ans+=((a[n].far-arf-you)/d+1)*money;
        you=(a[n].far-arf-you)%d;
    }
}
cout<<ans;
return 0;
}
