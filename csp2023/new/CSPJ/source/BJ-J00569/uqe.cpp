#include<bits/stdc++.h>
using namespace std;
int T,M;
int Prime(int a,int b){
    int max1=1;
    for(int i=2;i<=M;i++){
        int numa=0,numb=0;
        while(a%i==0){
            numa++;
            a=a/i;
        }
        while(a%i==0){
            numb++;
            b=b/i;
        }
        int num=min(numa,numb);
        while(num){
            max1=max1*i;
            num--;

        }
    }
    return max1;
}
/*pair<int,int> Nd(int a){
    int div=1;
    for(int i=2;i<=M;i++){
        int numa;
        while(a%i==0){
            numa++;
            a=a/i;
        }
        numa=numa>>1;
        if(numa>0){
            max1=max1*i;
        }
    }
    return max1;
}*/
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>T>>M;
    while(T--){
        int a,b,c;
        cin>>a>>b>>c;
        int d=(b*b)-4*a*c;
        if(d<0){
            cout<<"NO"<<endl;
        }
        else{
            if(d==0){
                cout<<-b<<endl;
            }
            //pair<int,int> d=Nd(d);
            int s=-b+abs(b),m=2*a;
            int ans=0;
            bool flag=0;
            if(s%m!=0){
                int div=Prime(s,m);
                s=s/div;
                m=m/div;
            }
            else{
                ans=s/m;
                flag=1;
            }
            /*else if(b==0){
                cout<<(-b+)
            }*/
             if(c==0){
                if(flag)cout<<ans<<endl;
                else cout<<s<<"/"<<m<<endl;
            }
        }
    }
    return 0;
}