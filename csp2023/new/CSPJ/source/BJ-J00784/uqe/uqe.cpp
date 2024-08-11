#include<bits/stdc++.h>//uqe
using namespace std;
struct IO{
    IO(){
        freopen("uqe.in","r",stdin);
        freopen("uqe.out","w",stdout);
    }
    ~IO(){
        fclose(stdin);
        fclose(stdout);
    }
}io;
const int N=1e6+7;
int t,m,a,b,c;
int gcd(int a,int b){
    if(!b){
        return a;
    }
    return gcd(b,a%b);
}
int delta;
int main(){
    cin>>t>>m;
    while(t--){
        cin>>a>>b>>c;
        delta=b*b-4*a*c;
        if(delta<0){
            cout<<"NO"<<'\n';
            continue;
        }else{
            int sq=sqrt(delta);
            if(sq*sq==delta){//is rational
                int s,t;// s/t;
                s=-b+sq;
                t=2*a;
                if(t<0){
                    s=-b-sq;
                }
                if(s==0){
                    cout<<0;
                }else{
                    if((s<0&&t>0)||(s>0&&t<0)){
                        cout<<"-";
                    }
                    s=abs(s),t=abs(t);
                    int g=gcd(s,t);
                    s/=g,t/=g;
                    cout<<s;
                    if(t!=1){
                        cout<<"/"<<t;
                    }
                }
            }else{
                int q=1,yellowduck=1;
                for(int i=2;i*i<=delta;i++){
                    if(delta%i==0){
                        int cnt=0;
                        while(delta%i==0){
                            delta/=i;
                            yellowduck*=i;
                            cnt++;
                        }
                        if(cnt%2==1){
                            delta*=i;
                            yellowduck/=i;
                        }
                    }
                    q=sqrt(yellowduck);
                }
                int s=-b,t=2*a;
                if(s!=0){
                    if(t==1){
                        cout<<s;
                    }else{
                        if((s<0&&t>0)||(s>0&&t<0)){
                            cout<<"-";
                        }
                        s=abs(s),t=abs(t);
                        int g=gcd(s,t);
                        s/=g,t/=g;
                        cout<<s;
                        if(t!=1){
                            cout<<"/"<<t;
                        }
                    }
                    cout<<"+";
                }
                a*=2;
                int g=gcd(q,abs(a));
                q/=g;
                a/=g;
                if(q==abs(a)){//q2=1
                    cout<<"sqrt("<<delta<<")";
                }else if(gcd(abs(q),abs(a))==abs(a)){//q2!=1 and q2 is an integer
                    cout<<q/abs(a)<<"*"<<"sqrt("<<delta<<")";
                }else if(gcd(abs(q),abs(a))==abs(q)){
                    cout<<"sqrt("<<delta<<")"<<"/";
                    cout<<abs(a)/q;
                }else{
                    int c,d;
                    c=q;
                    d=abs(a);
                    cout<<c<<"*"<<"sqrt("<<delta<<")"<<"/"<<d;
                }
            }
        }
        cout<<'\n';
    }
    return 0;
}
