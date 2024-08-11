#include<bits/stdc++.h>
using namespace std;
int derta;
int t,m;
int gcd(int a,int b){
    int ans=1;
    a=abs(a);
    b=abs(b);
    for(int i=1;i<=min(a,b);i++){
        if(a%i==0&&b%i==0)
            ans=i;
    }
    return ans;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        int a,b,c;
        cin>>a>>b>>c;
        derta=b*b-4*a*c;
        int yuanderta=derta;
        if(derta<0){
            cout<<"NO"<<endl;
        }else{
            int fm=2*a;
            int gender=0;
            int bj=1;
            int fzleft=-b;
            if(derta==1)
                gender=1,bj=1;
            else{
                for(int j=2;j*j<=derta;j++){
                    if(derta%(j*j)==0){
                        //gd=j*sqrt(derta/(j*j));
                        derta/=(j*j);
                        bj*=j;
                    }
                }
                for(int j=2;j*j<=derta;j++){
                    if(derta%(j*j)==0){
                        //gd=j*sqrt(derta/(j*j));
                        derta/=(j*j);
                        bj*=j;
                    }
                }
            }
            int dgy;
            if(derta==0){
                dgy=gcd(fm,fzleft);
                fm/=dgy;
                fzleft/=dgy;
                bj/=dgy;
                if(fzleft%fm==0){
                    cout<<fzleft/fm<<endl;
                }else{
                    cout<<fzleft<<"/"<<fm<<endl;
                }
                continue;
            }
            dgy=gcd(fm,gcd(bj,fzleft));
            fm/=dgy;
            fzleft/=dgy;
            int jj=bj;
            bj/=dgy;
            if(fzleft==0){
                if(fm==1){
                    cout<<bj<<"*"<<"sqrt("<<derta<<")"<<endl;
                }else{
                    if(bj%fm==0)
                        cout<<bj/fm<<"*"<<"sqrt("<<derta<<")"<<endl;
                    else
                        cout<<bj<<"*"<<"sqrt("<<derta<<")/"<<fm<<endl;
                }
                continue;
            }
            if(jj*jj==yuanderta){
                if((jj+fzleft)%fm==0)
                    cout<<(jj+fzleft)/fm<<endl;
                else
                    cout<<jj+fzleft<<"/"<<fm<<endl;
            }else{
                if(bj==1){
                    if(fzleft%fm==0)
                        cout<<fzleft/fm<<"+sqrt("<<derta<<")"<<"/"<<fm<<endl;
                    else
                        cout<<fzleft<<"/"<<fm<<"+sqrt("<<derta<<")"<<"/"<<fm<<endl;
                }else{
                    derta-=jj*jj;
                    if(fzleft%fm==0)
                        cout<<fzleft/fm<<"+"<<bj<<"*sqrt("<<derta<<")"<<"/"<<fm<<endl;
                    else
                        cout<<fzleft<<"/"<<fm<<"+"<<bj<<"+sqrt("<<derta<<")"<<"/"<<fm<<endl;
                }
            }
        }
    }

}
