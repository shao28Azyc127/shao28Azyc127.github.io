#include <bits/stdc++.h>
using namespace std;
int T,M;
bool f1;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>T>>M;
    while(T--){
        int a,b,c;
        cin>>a>>b>>c;
        int del=b*b-4*a*c;
        if(del<0){
            cout<<"NO"<<endl;
            continue;
        }
        int zheng=-1,A=2*a;
        for(int i=0;i<=1001;i++)
            if(i*i==del){
                zheng=i;
                break;
            }
        if(zheng!=-1){
            int fenzi1=-b+zheng,fenzi2=-b-zheng;
            double xx1=(double)fenzi1/(double)A,xx2=(double)fenzi2/(double)A;
            if(fenzi1%A==0){
                if(fenzi2%A==0){
                    if(xx1>xx2)
                        cout<<(int)xx1<<endl;
                    else
                        cout<<(int)xx2<<endl;
                }
                else{
                    if(xx1>xx2)
                        cout<<(int)xx1<<endl;
                    else{
                        int a1=A,e1=fenzi2;
                        if(A<0)
                            a1=-A;
                        if(fenzi2<0)
                            e1=-fenzi2;
                        int g=__gcd(e1,a1);
                        int F=e1/g,Q=a1/g;
                        if(xx2<0)
                            cout<<"-";
                        cout<<F<<"/"<<Q<<endl;
                    }
                }
            }
            else{
                if(fenzi2%A==0){
                    if(xx2>xx1)
                        cout<<(int)xx2<<endl;
                    else{
                        int a1=A,e1=fenzi1;
                        if(A<0)
                            a1=-A;
                        if(fenzi1<0)
                            e1=-fenzi1;
                        int g=__gcd(e1,a1);
                        int F=e1/g,Q=a1/g;
                        if(xx1<0)
                            cout<<"-";
                        cout<<F<<"/"<<Q<<endl;
                    }
                }
                else{
                    if(xx1>xx2){
                        int a1=A,e1=fenzi1;
                        if(A<0)
                            a1=-A;
                        if(fenzi1<0)
                            e1=-fenzi1;
                        int g=__gcd(e1,a1);
                        int F=e1/g,Q=a1/g;
                        if(xx1<0)
                            cout<<"-";
                        cout<<F<<"/"<<Q<<endl;
                    }
                    else{
                        int a1=A,e1=fenzi2;
                        if(A<0)
                            a1=-A;
                        if(fenzi2<0)
                            e1=-fenzi2;
                        int g=__gcd(e1,a1);
                        int F=e1/g,Q=a1/g;
                        if(xx2<0)
                            cout<<"-";
                        cout<<F<<"/"<<Q<<endl;
                    }
                }
            }
        }
        else{
            int sqxs=1,d1=del;
            for(int i=2;i*i<=d1;i++){
                int k=i*i;
                if(d1%k==0){
                    sqxs*=i;
                    d1/=k;
                    i=2;
                }
            }
            int a1=A,e1=b,a2=A,e2=sqxs;
            if(A<0)
                a1=a2=-A;
            if(b<0)
                e1=-b;
            int g1=__gcd(a1,e1),g2=__gcd(a2,e2);
            int Q=a1/g1,W=e1/g1,E=a2/g2,R=e2/g2;
            if(b%A==0){
                if(b!=0)
                    cout<<-b/A;
                if(sqxs%A==0){
                    if(A>0){
                        if(b!=0){
                            if(sqxs/A==1)
                                cout<<"+sqrt("<<d1<<")"<<endl;
                            else
                                cout<<"+"<<sqxs/A<<"*sqrt("<<d1<<")"<<endl;
                        }
                        else{
                            if(sqxs/A==1)
                                cout<<"sqrt("<<d1<<")"<<endl;
                            else
                                cout<<sqxs/A<<"*sqrt("<<d1<<")"<<endl;
                        }
                    }
                    else{
                        if(sqxs/A==-1)
                            cout<<"-sqrt("<<d1<<")"<<endl;
                        else
                            cout<<"-"<<sqxs/A<<"*sqrt("<<d1<<")"<<endl;
                    }
                }
                else{
                    if(A>0){
                        if(b!=0){
                            if(R==1)
                                cout<<"+sqrt("<<d1<<")";
                            else
                                cout<<"+"<<R<<"*sqrt("<<d1<<")";
                            if(E==1)
                                cout<<endl;
                            else
                                cout<<"/"<<E<<endl;
                        }
                        else{
                            if(R==1)
                                cout<<"sqrt("<<d1<<")";
                            else
                                cout<<R<<"*sqrt("<<d1<<")";
                            if(E==1)
                                cout<<endl;
                            else
                                cout<<"/"<<E<<endl;
                        }
                    }
                    else{
                        if(R==1)
                            cout<<"-sqrt("<<d1<<")";
                        else
                            cout<<"-"<<R<<"*sqrt("<<d1<<")";
                        if(E==1)
                            cout<<endl;
                        else
                            cout<<"/"<<E<<endl;
                    }
                }
            }
            else{
                if(b!=0){
                    if(b*a>0)
                        cout<<"-"<<W<<"/"<<Q;
                    else
                        cout<<W<<"/"<<Q;
                }
                if(sqxs%A==0){
                    if(A>0){
                        if(b!=0){
                            if(sqxs/A==1)
                                cout<<"+sqrt("<<d1<<")"<<endl;
                            else
                                cout<<"+"<<sqxs/A<<"*sqrt("<<d1<<")"<<endl;
                        }
                        else{
                            if(sqxs/A==1)
                                cout<<"sqrt("<<d1<<")"<<endl;
                            else
                                cout<<sqxs/A<<"*sqrt("<<d1<<")"<<endl;
                        }
                    }
                    else{
                        if(sqxs/A==-1)
                            cout<<"-sqrt("<<d1<<")"<<endl;
                        else
                            cout<<"-"<<sqxs/A<<"*sqrt("<<d1<<")"<<endl;
                    }
                }
                else{
                    if(A>0){
                        if(b!=0){
                            if(R==1)
                                cout<<"+sqrt("<<d1<<")";
                            else
                                cout<<"+"<<R<<"*sqrt("<<d1<<")";
                            if(E==1)
                                cout<<endl;
                            else
                                cout<<"/"<<E<<endl;
                        }
                        else{
                            if(R==1)
                                cout<<"sqrt("<<d1<<")";
                            else
                                cout<<R<<"*sqrt("<<d1<<")";
                            if(E==1)
                                cout<<endl;
                            else
                                cout<<"/"<<E<<endl;
                        }
                    }
                    else{
                        if(R==1)
                            cout<<"-sqrt("<<d1<<")";
                        else
                            cout<<"-"<<R<<"*sqrt("<<d1<<")";
                        if(E==1)
                            cout<<endl;
                        else
                            cout<<"/"<<E<<endl;
                    }
                }
            }
        }
    }
    return 0;
}
