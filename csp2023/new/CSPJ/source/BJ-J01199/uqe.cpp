#include<bits/stdc++.h>
using namespace std;
long long t,m;
long long a,b,c,x,w,s=1,cnt;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--){
        cin>>a>>b>>c;
        if(b==0&&c==0){
            cout<<0;
        }else if(b==0){
            w=(-c)/a;
            x=sqrt(w);
            if(x*x==w){
                cout<<x;
            }else{
                for(int i=2;i*i<=w;i++){
                    while(w%i==0){
                        w/=i;
                        cnt++;
                        if(cnt==2){
                            cnt=0;
                            s*=i;
                        }
                    }
                    if(cnt==1) w*=i;
                    cnt=0;
                }
                cout<<s<<"*sqrt("<<w<<")"<<endl;
                s=1;w=0;x=0;
            }
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}