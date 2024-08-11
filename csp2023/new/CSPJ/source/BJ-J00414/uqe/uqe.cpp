#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,M;
    cin>>T>>M;
    while(T--){
        int a,b,c;
        cin>>a>>b>>c;
        int delta=b*b-4*a*c;
        if(delta<0){
            cout<<"NO\n";
            continue;
        }else if(delta==0||delta==(int)sqrt(delta)*(int)sqrt(delta)){
            int p=b*-1+sqrt(delta),q=2*a;
            int gc=__gcd(p,q);
            p/=gc;
            q/=gc;
            if(q==1)cout<<p;
            else if(q<0)cout<<-p<<'/'<<-q;
            else cout<<p<<'/'<<q;
        }else{
            int p=b*-1,q1=2*a,q2=2*a;
            int gc=__gcd(p,q1);
            p/=gc;
            q1/=gc;
            if(p!=0){
                if(q1==1)cout<<p;
                else if(q1<0)cout<<-p<<'/'<<-q1;
                else cout<<p<<'/'<<q1;
                cout<<'+';
            }
            int d=1;
            for(int i=2;i*i<delta;i++)
                if(delta%(i*i)==0)d=i;
            delta/=d*d;
            gc=__gcd(d,q2);
            d/=gc;
            q2/=gc;
            if(d>1)cout<<d<<'*';
            if(q2==1)cout<<"sqrt("<<delta<<')';
            else if(q2<0)cout<<"sqrt("<<delta<<')'<<'/'<<-q2;
            else cout<<"sqrt("<<delta<<')'<<'/'<<q2;
        }
        cout<<'\n';
    }
    return 0;
}
