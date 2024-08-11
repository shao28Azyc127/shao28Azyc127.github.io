#include<bits/stdc++.h>
using namespace std;
int t,m,a,b,c,a1,a2,a3,a4,a5,sr[2310];
int cz(int q,int w){
    if(q==0||w==0) return 1;
    if(q<w) swap(q,w);
    while(q%w!=0){
        q=q%w;
        swap(q,w);
    }
    return w;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    for(int i=1;i<=2300;i++) sr[i]=i*i;
    scanf("%d%d",&t,&m);
    for(int i=1;i<=t;i++){
        scanf("%d%d%d",&a,&b,&c);
        a1=a2=a3=a4=a5=0;
        if(b*b<4*a*c){
            cout<<"NO"<<endl;
            continue;
        }
        a4=b*b-4*a*c;
        for(int j=2300;j>=1;j--) if(a4%sr[j]==0){
            a3=j,a4/=sr[j];
            break;
        }
        if(a4==0) a3=0;
        if(a4==1){
            if(a>0) b-=a3,a3=0;
            else b+=a3,a3=0;
        }
        a1=cz(2*abs(a),abs(b)),a2=abs(2*a)/a1,a1=abs(b)/a1,a5=cz(2*abs(a),abs(a3)),a3=abs(a3)/a5,a5=abs(2*a)/a5;
        if(a*b>0) a1=-a1;
        if(a1!=0||a3==0) cout<<a1;
        if(a2!=1&&a1!=0) cout<<"/"<<a2;
        if(a1!=0&&a3!=0) cout<<"+";
        if(a3!=0&&a3!=1) cout<<a3<<"*";
        if(a3!=0){
            cout<<"sq"<<"rt("<<a4;
            cout<<")";
        }
        if(a3!=0&&a5!=1) cout<<"/"<<a5;
        cout<<endl;
    }
    return 0;
}