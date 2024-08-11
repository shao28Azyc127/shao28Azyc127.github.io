#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(a<b) return gcd(b,a);
    if(b==0) return a;
    return gcd(b,a%b);
}
int fj(int ln){
    int ret=1;
    for(int i=2;i*i<=ln;i++){
        int lcnt=0,lnum=1;
        while(ln%i==0){
            ln/=i;
            lnum*=i;
            lcnt++;
        }
        if(lcnt%2==1){
            lnum/=i;
        }
        ret*=lnum;
    }
    return ret;
}
struct R{
    int fz,fm,wls;
    void tf(){
        if(wls==0) fz=0;
        if(fz==0) return;
        int lfj=fj(wls);
        wls/=lfj,fz*=sqrt(lfj);
        int lg=gcd(abs(fz),abs(fm));
        fz/=lg,fm/=lg;
        if(fm<0) fz*=-1,fm*=-1;
        //if(fm<0) cout<<'!';
    }
    R(){}
    R(int _fz,int _fm,int _wls){
        fz=_fz,fm=_fm,wls=_wls;
        if(wls==0){
            fz=0;
        }
        int lsq=sqrt(wls);
        if(lsq*lsq==wls){
            wls=1;
            fz*=lsq;
        }
    }
    R operator +(const R &r)const{
        R lr;
        lr.fm=fm*r.fm;
        lr.fz=fz*r.fm+r.fz*fm;
        lr.tf();
        return lr;
    }
};
R sqt(R nr){
    nr.wls*=nr.fz;
    nr.fz=1;
    return nr;
}
int t,m;
void mprint(R lr){
    lr.tf();
    if(lr.fm==1){
        cout<<lr.fz;
    }else{
        cout<<lr.fz<<'/'<<lr.fm;
    }
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t>>m;
    int a,b,c;
    while(t--){
        cin>>a>>b>>c;
        if(b*b-4*a*c<0){
            cout<<"NO"<<'\n';
        }else{
            int lnum=(a<0)?-1:1;
            R ans1(0-b,2*a,1);
            R ans2(lnum,2*a,b*b-4*a*c);
            ans1.tf(),ans2.tf();
            //cout<<'@';
            if(ans2.wls==1||ans2.fz==0){
                //cout<<"1*";
                if(ans2.fz!=0){
                    ans1=ans1+ans2;
                }
                mprint(ans1);
                cout<<'\n';
            }else{
                //cout<<"2*";
                if(ans1.fz!=0){
                    mprint(ans1);
                    cout<<'+';
                }
                if(ans2.fz==1&&ans2.fm==1){
                    cout<<"sqrt("<<ans2.wls<<")"<<'\n';
                }else if(ans2.fm==1){
                    cout<<ans2.fz<<'*'<<"sqrt("<<ans2.wls<<")"<<'\n';
                }else if(ans2.fz==1){
                    cout<<"sqrt("<<ans2.wls<<")/"<<ans2.fm<<'\n';
                }else{
                    cout<<ans2.fz<<'*'<<"sqrt("<<ans2.wls<<")/"<<ans2.fm<<'\n';
                }
            }
        }
    }
    return 0;
}