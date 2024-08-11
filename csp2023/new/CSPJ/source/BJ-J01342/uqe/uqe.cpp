#include<bits/stdc++.h>
using namespace std;
int n;
int maxn;
int num=0;
int g[1000];
int r;
int q1,q2;
bool check(int a,int b,int c){
    if(b*b-4*a*c<0) return false;
    else return true;
}
void fj(int a){
    int m;
    r=a;
    for(int i=2;i*i<=a;i++){
        if(a%i==0){
            while(a%i==0){
                num++;
                g[i]=num;
                a/=i;
            }
        }
        num=0;
    }
    for(int i=1;i*i<=a;i++){
        if(g[i]>=2){
            int tmp=g[i]/2;
            m=pow(i,tmp);
            q2*=m;
            r/=m;
        }
    }
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>n>>maxn;
    for(int i=1;i<=n;i++){
        int a,b,c;
        int dt=b*b-4*a*c;
        cin>>a>>b>>c;
        if(check(a,b,c)==false){
            cout<<"NO"<<endl;
            return 0;
        }
        else{
            q1=-b;
            if(q1!=0&&q1%(2*a)!=0) cout<<q1<<"/"<<2*a<<"+";
            if(q1!=0&&q1%(2*a)==0) cout<<q1/(2*a)<<"+";
            if(dt!=0){
                fj(dt);
                if(q2%(2*a)==0) cout<<q2/(2*a)<<"*"<<"sqrt("<<r<<")"<<endl;
                else cout<<q2<<"*"<<"sqrt("<<r<<")"<<"/"<<2*a<<endl;
            }
        }
    }
    return 0;
}
