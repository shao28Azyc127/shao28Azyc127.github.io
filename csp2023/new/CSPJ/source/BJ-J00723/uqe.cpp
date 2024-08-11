#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,m,a,b,c,delta,u;
pair<int,int>tmp,q1,q2;
void op(pair<int,int>&x){
    u=__gcd(x.first,x.second);
    x.first/=u;
    x.second/=u;
    if(x.second<0){
        x.first=-x.first;
        x.second=-x.second;
    }
}
int mp(int x){
    for(int i=1000;i>=1;i--){
        if(x%(i*i)==0){
            return i;
        }
    }
    return 0;
}
ostream&operator<<(ostream&a,pair<int,int>b){
    if(b.second==1){
        cout<<b.first;
    }else{
        cout<<b.first<<"/"<<b.second;
    }
    return a;
}
signed main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--){
        cin>>a>>b>>c;
        delta=b*b-4*a*c;
        if(a<0){
            a=-a;
            b=-b;
            c=-c;
        }
        if(delta<0){
            cout<<"NO";
        }else{
            if((int)sqrt(delta)==sqrt(delta)){
                tmp=make_pair(sqrt(delta)-b,2*a);
                op(tmp);
                cout<<tmp;
            }else{
                q1=make_pair(-b,2*a);
                q2=make_pair(mp(delta),2*a);
                op(q1);
                op(q2);
                delta/=mp(delta)*mp(delta);
                if(q1.first){
                    cout<<q1<<"+";
                }
                if(q2.first==1&&q2.second==1){
                    cout<<"sqrt("<<delta<<")";
                }else if(q2.second==1){
                    cout<<q2.first<<"*sqrt("<<delta<<")";
                }else if(q2.first==1){
                    cout<<"sqrt("<<delta<<")/"<<q2.second;
                }else{
                    cout<<q2.first<<"*sqrt("<<delta<<")/"<<q2.second;
                }
            }
        }
        cout<<endl;
    }
}
