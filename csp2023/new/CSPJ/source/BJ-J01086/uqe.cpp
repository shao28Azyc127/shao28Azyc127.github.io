#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        int delta=b*b-4*a*c;
        if(delta<0){
            cout<<"NO"<<endl;
            continue;
        }
        if((int)sqrt(delta)*(int)sqrt(delta)==delta){
            int p;
            if(a<0) p=-b-sqrt(delta);
            else p=-b+sqrt(delta);
            int q=2*a;
            int t=__gcd(p,q);
            p/=t;
            q/=t;
            if(q<0&&q!=1){
                q=-q;
                p=-p;
            }
            if(q==1){
                cout<<p<<endl;
            }else{
                cout<<p<<"/"<<q<<endl;
            }
            continue;
        }
        int q1_p=-b;
        int q1_q=2*a;
        int q1_t=__gcd(q1_p,q1_q);
        q1_p/=q1_t;
        q1_q/=q1_t;
        if(q1_q<0&&q1_q!=1){
            q1_q=-q1_q;
            q1_p=-q1_p;
        }
        if(q1_p!=0){
            if(q1_q==1) cout<<q1_p<<"+";
            else cout<<q1_p<<"/"<<q1_q<<"+";
        }
        int q2_p=delta;
        int q2_p1=1;
        int q2_q=2*a;
        int vt=0;
        for(int i=sqrt(q2_p);i>=2;i--){
            if(q2_p%(i*i)==0){
                vt=i;
                break;
            }
        }
        if(vt>0){
            q2_p/=(vt*vt);
            q2_p1=vt;
        }
        if(a<0) q2_p1=-q2_p1;
        int q2_t=__gcd(q2_p1,q2_q);
        q2_p1/=q2_t;
        q2_q/=q2_t;
        if(q2_q==1){
            if(q2_p1==1) cout<<"sqrt("<<q2_p<<")"<<endl;
            else cout<<q2_p1<<"*sqrt("<<q2_p<<")"<<endl;
        }else if(q2_p1==1){
            cout<<"sqrt("<<q2_p<<")/"<<q2_q<<endl;
        }else{
            cout<<q2_p1<<"*sqrt("<<q2_p<<")/"<<q2_q<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
