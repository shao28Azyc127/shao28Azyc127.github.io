#include<bits/stdc++.h>
using namespace std;
int t,m;
int gcdx(int x,int y){
    if(y==0||x==0)return 1;
    if(x%y==0)return y;
    return gcdx(max(y,x%y),min(y,x%y));
}
int SQ(int &x){
    int ans=1;
    for(int i=2;i<=x;i++){
        while(x%(i*i)==0){
            x/=(i*i);
            ans*=i;
        }
    }
    return ans;
}
void Output(int x,int y){
    int k=gcdx(max(abs(x),abs(y)),min(abs(x),abs(y)));
    x=x/k;
    y=y/k;
    if(x==0){
       cout<<"0";
       return;
    }
    if(y==1||y==-1){
        cout<<x/y;
    }else{
        if(y<0)cout<<-x<<'/'<<-y;
        else cout<<x<<'/'<<y;
    }
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--){
        double a,b,c;
        cin>>a>>b>>c;
        double d=b*b-4*a*c;
        //cout<<d<<endl;
        if(d<0)cout<<"NO";
        else if(d==0){
            int p=int(-b);
            int q=int(2*a);
            Output(p,q);
        }else{
            int h=int(d);
            int tt=SQ(h);
            int p=int(-b);
            int q=int(2*a);
            if(h==1){
                if(q>0)p=p+tt;
                else p-=tt;
                //cout<<p<<endl;
                Output(p,q);
            }else{
                if(p!=0)Output(p,q);
                if(p!=0)cout<<"+";
                int k=gcdx(max(abs(tt),abs(q)),min(abs(tt),abs(q)));
                //cout<<k<<' '<<tt<<' '<<q<<' '<<h<<endl;
                tt/=k;
                q/=k;
                if(tt==1&&abs(q)==1){
                    cout<<"sqrt("<<h<<")";
                }else if(tt==1){
                    cout<<"sqrt("<<h<<")/"<<abs(q);
                }else if(abs(q)==1){
                    cout<<tt<<'*'<<"sqrt("<<h<<")";
                }else{
                    cout<<tt<<'*'<<"sqrt("<<h<<")/"<<abs(q);
                }

            }
        }
        cout<<endl;
    }
    return 0;
}
