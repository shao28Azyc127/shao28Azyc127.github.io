#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int t,m;
double a,b,c;
long long qu,qd,ru,ri,rd;
bool nor;
int tmp;
// ret={qu}/{qd}+{ru}*sqrt({ri})/{rd}
int main() {
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    if(m<=1) {
            cin>>a>>b>>c;
        cout<<0<<endl;
        return 0;
    }
    for(int i=0;i<t;i++) {
        nor=false;
        cin>>a>>b>>c;
        double delta=b*b-4*a*c;
        if(delta<0) {
            cout<<"NO"<<endl;
            continue;
        }
        if(a<0) {
            a=-a;
            b=-b;
            c=-c;
        }
        qu=-b;
        qd=2*a;
        ru=1;
        ri=b*b-4*a*c;
        rd=2*a;
        /*
        for(int i=2;i<=min(qu,qd);i++) {
            while(qu%i==0 && qd%i==0) {
                qu/=i;
                qd/=i;
            }
        }
        */
        tmp=ri;
        //cout<<qu<<" "<<qd<<" "<<ru<<" "<<ri<<" "<<rd<<endl;
        for(int i=2;i*i<=tmp;i++) {
            while(ri%(i*i)==0) {
                ri/=(i*i);
                ru*=i;
                //cout<<"--"<<qu<<" "<<qd<<" "<<ru<<" "<<ri<<" "<<rd<<endl;
            }
        }
        //cout<<qu<<" "<<qd<<" "<<ru<<" "<<ri<<" "<<rd<<endl;
        tmp=min(abs(ru),abs(rd));
        for(int i=2;i<=tmp;i++) {
            while(ru%i==0 && rd%i==0) {
                ru/=i;
                rd/=i;
            }
        }
        //cout<<qu<<" "<<qd<<" "<<ru<<" "<<ri<<" "<<rd<<endl;
        if(ri==1) {
            qu=qu*rd+qd*ru;
            qd*=rd;
            nor=1;
        }
        //cout<<qu<<" "<<qd<<" "<<ru<<" "<<ri<<" "<<rd<<endl;
        tmp=min(abs(qu),abs(qd));
        for(int i=2;i<=tmp;i++) {
            while(qu%i==0 && qd%i==0) {
                qu/=i;
                qd/=i;
            }
        }
        //cout<<qu<<" "<<qd<<" "<<ru<<" "<<ri<<" "<<rd<<endl;
        bool q=0;
        if(!qu==0) {
            q=1;
            if(qd==1) {
                cout<<qu;
            } else {
                cout<<qu<<"/"<<qd;
            }
        }
        if(!ri==0 && !nor) {
            if(q && ru>0) {
                cout<<"+";
            }

            if(ru>1) {
                cout<<ru<<"*";
            }
            cout<<"sqrt("<<ri<<")";
            if(rd>1) {
                cout<<"/"<<rd;
            }
        }
        cout<<endl;
    }
    return 0;
}
