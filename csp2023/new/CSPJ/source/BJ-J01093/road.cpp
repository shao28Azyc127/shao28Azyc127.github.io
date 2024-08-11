#include <iostream>

using namespace std;


float n,d;
int a[100000];
int b[100000];
int zs1=0;

struct node{
    int yj,zd;
}c[100000];

int jl(int x,int y){
    int ans1=0;
    for(int i=0;i<=y-x-1;i++){
        ans1=ans1+a[x+i];
    }
    return ans1;
}

int main(){


    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin>>n>>d;
    for(int i=1;i<=n-1;i++) cin>>a[i];
    int u=0,h=0;
    for(int i=1;i<=n;i++){
        cin>>b[i];
        zs1=zs1+b[i];
        u=b[1];
        if(b[i]<u){
            h++;
            u=b[i];
            c[h].yj=b[i];
            c[h].zd=i;
        }
    }
    int zs2=0;
    int t=0;
    int ans2=0;
    while(ans2*d<zs1){
        t++;
        if(t==1){
             float jla=jl(c[1].zd,c[2].zd);
             ans2=ans2+ceil(jla/d*1.0);
        }
        else{
            float sz=ans2*d-jl(1,c[t].zd);
            float ml=jl(c[t].zd,c[t+1].zd)-sz;
            ans2=ans2+ceil(ml/(d*1.0));
        }
    }
    cout<<ans2;

    return 0;
}
