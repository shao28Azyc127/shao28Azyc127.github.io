#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,m;
int a,b,c;
int sqr(int x){
    int l=0,r=1e4;
    while(l<=r){
        int mid=(l+r)/2;
        if(mid*mid<=x){
            if(mid*mid==x){
                return mid;
            }
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return -1;
}
int fqr(int x){
    int ret=1;
    for(int i=2;i*i<=x;i++){
        while(x%(i*i)==0){
            x/=i*i;
            ret*=i;
        }
    }
    return ret;
}
void fs(int x,int y){
    int gg=__gcd(x,y);
    if(y/gg==1){
        cout<<x/gg;
        return;
    }
    if(y/gg==-1){
        cout<<-x/gg;
        return;
    }
    if(y/gg<0){
        cout<<-x/gg<<'/'<<-y/gg;
        return;
    }
    else{
        cout<<x/gg<<'/'<<y/gg;
    }
}
signed main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--){
        cin>>a>>b>>c;
        int del=b*b-4*a*c;
        if(del<0){
            cout<<"NO\n";
            continue;
        }
        int qr=sqr(del);
        if(qr==-1){
            if(b!=0){
                fs(-b,2*a);
                cout<<'+';
            }
            int qq=fqr(del);
            del/=qq*qq;
            int lss=abs(__gcd(qq,2*a));
            int fm=abs(2*a);//
            if(fm==qq){
                cout<<"sqrt("<<del<<")"<<endl;
                continue;
            }
            if(lss==fm){
                cout<<qq/lss<<'*'<<"sqrt("<<del<<")"<<endl;
                continue;
            }
            if(lss==qq){
                cout<<"sqrt("<<del<<")/"<<fm/lss<<endl;
                continue;
            }
            cout<<qq/lss<<"*sqrt("<<del<<")/"<<fm/lss<<endl;
        }
        else{
            if(2*a>0)fs(-b+qr,2*a);
            else fs(-b-qr,2*a);
            cout<<endl;
        }
    }
    return 0;
}
