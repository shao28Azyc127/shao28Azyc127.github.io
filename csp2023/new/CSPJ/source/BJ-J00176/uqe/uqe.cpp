#include<bits/stdc++.h>
using namespace std;
int t,m;
struct p{
    double a;
    double b;
    double c;
    double tran,sqtran;
    double x,x1,x2;
    double p=1.0,q,q1,q2,q3;
}que[10000];
int gcd(int a,int b){
    for(int i=min(a,b);i>=1;i--){
        if(a%i==0&&b%i==0) return i;
    }
    return 1;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        cin>>que[i].a>>que[i].b>>que[i].c;
        que[i].tran=pow(que[i].b,2)-4*que[i].a*que[i].c;
        if(que[i].tran<0){
            cout<<"NO";
        }else {
            que[i].sqtran=sqrt(que[i].tran);
            que[i].x1=(que[i].b*-1+que[i].sqtran)/(2*que[i].a);
            que[i].x2=(que[i].b*-1-que[i].sqtran)/(2*que[i].a);
            que[i].x=max(que[i].x1,que[i].x2);
            if(que[i].x*1.0==que[i].x){
                while(gcd(que[i].q,que[i].p)!=1){
                    que[i].p=int(que[i].x)*que[i].q;
                    que[i].q++;
                }
                if(int(que[i].x)*1.0==que[i].x) cout<<que[i].x;
                else cout<<int(que[i].p)<<"/"<<int(que[i].q);
            }
        }
        cout<<endl;
    }
    return 0;
}
