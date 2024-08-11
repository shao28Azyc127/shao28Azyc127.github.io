#include <bits/stdc++.h>
using namespace std;
int is_square(int x){
    for(int i=0;i*i<=x;i++){
        if(i*i==x)return 1;
    }
    return 0;
}
int yinshu(int x){
    int maxx=0;
    for(int i=1;i*i<=x;i++){
        if(x%i==0)maxx=max(i,maxx);
    }
    return maxx;
}
int derta=0;
int judge(int x){
    if(x==1)return 1;
    int ans=1;
    for(int i=2;i<=x;i++){
        int sqr=i*i;
        while(derta%sqr==0&&derta>1){
            derta/=sqr;
            ans*=i;
        }
    }
    return ans;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T,M;
    cin>>T>>M;
    while(T--){
        int a,b,c;
        cin>>a>>b>>c;
        derta=b*b-4*a*c;
        if(derta<0){
            cout<<"NO"<<"\n";
        }
        else if(is_square(derta)==1){
            int p=0;
            if(a<0)p=-b-sqrt(derta);
            else p=-b+sqrt(derta);
            int q=2*a;
            int beishu=__gcd(p,q);
            //cout<<beishu<<" "<<p<<" "<<q<<" ";
            p/=beishu;
            q/=beishu;
            if(q<0)p=-p,q=-q;
            if(q==1)cout<<p<<"\n";
            else cout<<p<<"/"<<q<<"\n";
        }
        else{
            int x1=-b,y1=2*a;
            int beishu=__gcd(-b,2*a);
            x1/=beishu;
            y1/=beishu;
            if(y1<0)x1=-x1,y1=-y1;
            if(x1!=0){
                if(y1==1)cout<<x1<<"+";
                else cout<<x1<<"/"<<y1<<"+";
            }
            int big=yinshu(derta);
            int q2=judge(big),y2=2*a;
            int d=__gcd(q2,y2);
            q2/=d;
            y2/=d;
            if(q2<0)q2=-q2;
            if(y2<0)y2=-y2;
            if(q2==1){
                if(y2==1){
                    cout<<"sqrt("<<derta<<")";
                }
                else{
                    cout<<"sqrt("<<derta<<")/"<<y2;
                }
            }
            else{
                if(y2==1){
                    cout<<q2<<"*"<<"sqrt("<<derta<<")";
                }
                else{
                    cout<<q2<<"*"<<"sqrt("<<derta<<")/"<<y2;
                }
            }
            cout<<"\n";
        }
    }
    return 0;
}
