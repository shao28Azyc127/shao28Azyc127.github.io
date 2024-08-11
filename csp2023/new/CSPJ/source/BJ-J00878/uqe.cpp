#include <iostream>
using namespace std;
const int sq[35]={0,1,4,9,16,25,36,49,64,81,100,121,144,169,196,225,256,289,324,361,400,441,484,529,576,625,676,729,784,841,900,961};
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
//p/q
struct decimal{
    int p;
    int q;
    decimal(){
        p=1;
        q=1;
    }
    decimal(int _p,int _q){
        int g=gcd(_p,_q);
        p=_p/g;
        q=_q/g;
        if(q<0){
            p=-p;
            q=-q;
        }
    }
};
//psqrt(q)
struct sqt{
    int p;
    int q;
    sqt(int _p){
        p=1;
        for(int i=31;i>1;i--){
            if(_p%sq[i]==0){
                _p/=sq[i];
                p*=i;
            }
        }
        q=_p;
    }
};
//psqrt(q)
struct dsq{
    decimal p;
    int q;
    dsq(decimal _p,sqt _q){
        q=_q.q;
        p=decimal(_p.p*_q.p,_p.q);
    }
};
ostream& operator<<(ostream& os,decimal d){
    if(d.q==1){
        os<<d.p;
    }else{
        os<<d.p<<"/"<<d.q;
    }
    return os;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int _t,_m;
    cin>>_t>>_m;
    while(_t--){
        int a,b,c;
        cin>>a>>b>>c;
        int delta=b*b-4*a*c;
        if(delta<0){
            cout<<"NO\n";
            continue;
        }
        //-b/(2*a)+sqrt(delta)/(2*a)
        decimal p1=decimal(-b,2*a);
        dsq p2=dsq(decimal(1,2*a),sqt(delta));
        if(a>0){
            if(p2.q==0){
                cout<<p1<<"\n";
            }else if(p2.q==1){
                decimal p=decimal(-b+sqt(delta).p,2*a);
                cout<<p<<"\n";
            }else{
                if(p1.p!=0){
                    cout<<p1<<"+";
                }
                if(p2.p.p==1&&p2.p.q==1){
                    cout<<"sqrt("<<p2.q<<")\n";
                }else if(p2.p.q==1){
                    cout<<p2.p.p<<"*sqrt("<<p2.q<<")\n";
                }else if(p2.p.p==1){
                    cout<<"sqrt("<<p2.q<<")/"<<p2.p.q<<"\n";
                }else{
                    cout<<p2.p.p<<"*sqrt("<<p2.q<<")/"<<p2.p.q<<"\n";
                }
            }
        }else{
            p2=dsq(decimal(-1,2*a),sqt(delta));
            if(p2.q==0){
                cout<<p1<<"\n";
            }else if(p2.q==1){
                decimal p=decimal(-b-sqt(delta).p,2*a);
                cout<<p<<"\n";
            }else{
                if(p1.p!=0){
                    cout<<p1<<"+";
                }
                if(p2.p.p==1&&p2.p.q==1){
                    cout<<"sqrt("<<p2.q<<")\n";
                }else if(p2.p.q==1){
                    cout<<p2.p.p<<"*sqrt("<<p2.q<<")\n";
                }else if(p2.p.p==1){
                    cout<<"sqrt("<<p2.q<<")/"<<p2.p.q<<"\n";
                }else{
                    cout<<p2.p.p<<"*sqrt("<<p2.q<<")/"<<p2.p.q<<"\n";
                }
            }
        }
        //cout<<p1.p<<"/"<<p1.q<<"+"<<p2.p.p<<"sqrt("<<p2.q<<")/"<<p2.p.q<<"\n";
    }
    return 0;
}