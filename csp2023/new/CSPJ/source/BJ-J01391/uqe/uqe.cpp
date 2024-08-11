#include <iostream>
#include <cmath>
using namespace std;
int gcd(int a,int b) {return (b?gcd(b,a%b):a);}
struct Frac {
    int fm,fz;
    void simp() {
        int g=gcd(fm,fz);
        fm/=g,fz/=g;
        if(fm<0) fm=-fm,fz=-fz;
    }
    void print() {
        simp();
        if(fm==1) cout<<fz;
        else cout<<fz<<"/"<<fm;
    }
};
int main() {
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,M;
    cin>>T>>M;
    while(T--) {
        double a,b,c;
        cin>>a>>b>>c;
        double delta=b*b-4*a*c;
        if(delta<0) {cout<<"NO"<<endl; continue;}
        double sqDelta=sqrt(delta);
        if((int)sqDelta==sqDelta) {
            Frac fr;
            fr.fm=2*a,fr.fz=-b+(2*a<0?-sqDelta:sqDelta);
            fr.simp();
            fr.print();cout<<endl;
            continue;
        }
        int xs=1,idelta=delta;
        Frac fr;
        fr.fm=2*a;
        fr.fz=-b;
        fr.simp();
        if(fr.fz!=0) {fr.print();cout<<"+";}

        for(int i=2;i*i<=M;i++) {
            while(idelta%(i*i)==0) xs*=i,idelta/=(i*i);
        }
        Frac fr2;
        fr2.fm=abs(2*a);fr2.fz=xs;fr2.simp();
        if(fr2.fz!=1) {
            cout<<fr2.fz<<"*";
        }
        cout<<"sqrt("<<idelta<<")";
        if(fr2.fm!=1) {
            cout<<"/"<<fr2.fm<<endl;
        }
        else cout<<endl;
    }

    return 0;
}
