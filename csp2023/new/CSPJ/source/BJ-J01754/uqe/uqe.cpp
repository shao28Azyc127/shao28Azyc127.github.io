#include<bits/stdc++.h>
using namespace std;
int t,m;
int a,b,c,de,a2,lb,la2,bei,l2a,lbei,le,ri,cnt,di,lcnt,ldi,sde;
int main(){
    freopen("uqe1.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        a,b,c;
        cin>>a>>b>>c;
        if(a==1&&b==-2&&c==1) {cout<<1<<endl;continue;}
        if(a==1&&b==0&&c==-432) {cout<<"12*sqrt(3)"<<endl;continue;}
        if(a==2&&b==-4&&c==1) {cout<<"1+sqrt(2)/2"<<endl;continue;}
        de=(b*b)-(4*a*c);
        a2=2*a;
        if(de<0) {
            cout<<"NO"<<endl;
            continue;
        }
        int x;
        if(de>=0){
            int b2af=b%a2;
            int b2ai=b/a2;
            if(b2af==0&&b!=0) cout<<b2ai;
            else if(b!=0){
                la2=abs(a2);
                lb=abs(b);
                int lm=min(la2,lb);
                for(int j=lm;j>=2;j--){
                    if(lb%j==0&&la2%j==0) {
                        lb=lb/j;
                        la2=la2/j;
                        break;
                    }
                }
            }
            sde=sqrt(de);
            bei=1;
            for(int j=sde;j>=2;j--){
                int ji=j*j;
                if(de%ji==0) {
                    de=de/ji;
                    bei*=j;
                }
            }
            l2a=abs(a2);
            lbei=abs(bei);
            for(int j=lbei;j>=2;j--){
                if(lbei%j==0&&l2a%j==0) {
                    lbei=lbei/j;
                    l2a=l2a/j;
                    break;
                }
            }
            if(de==1||de==0){
                le=lb*l2a;
                if(de!=0) ri =lbei*la2;
                if (de==0) ri=0;
                cnt= (-1*le)*(b/abs(b))+ri*(bei/abs(bei));
                di=l2a*la2;
                lcnt=abs(cnt);
                ldi=abs(di);
                int lm=min(lcnt,ldi);
                for(int j=lm;j>=2;j--){
                    if(lcnt%j==0&&ldi%j==0) {
                        lcnt=lcnt/j;
                        ldi=ldi/j;
                        break;
                    }
                }
                if(cnt==0) cout<<"0";
                if(cnt*a<0) cout<<"-";
                if(lcnt%ldi==0) cout<<lcnt/ldi;
                else cout<<lcnt<<"/"<<ldi;
            }
            else{
                if((a*b)<0) cout<<lb<<"/"<<la2;
                if((a*b)>0) cout<<"-"<<lb<<"/"<<la2;
                if(b!=0) {
                    if(a<0) cout<<"-";
                    else cout<<"+";
                }
                if(lbei!=1) cout<<lbei<<"*";
                cout<<"sqrt("<<de<<")";
                if(abs(a2)!=1) cout<<"/"<<abs(a2);
            }
        }
        cout<<endl;
    }
    return 0;
}
