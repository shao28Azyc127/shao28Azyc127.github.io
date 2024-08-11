#include<bits/stdc++.h>
using namespace std;
int t,m,deta,a,b,c;
int pf[6000],g[6000],cnt;

int gcd(int a,int b){
    if(b==1) return a;
    else return gcd(b,a%b);
}

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    int x=m*m+4*m*m;
    for(int i=1;i*i<=x;i++){
            pf[i]=i*i;
            g[i]=i;
            cnt++;
    }
    while(t--){
        cin>>a>>b>>c;
        deta=b*b-4*a*c;
        if(deta<0) cout<<"NO"<<endl;
        else{
            if(deta==0){
                if(b==0) cout<<0<<endl;
                else{
                    if(a>0){
                        if(b>0) cout<<"-";
                        else b*=-1;
                    }
                    else{
                        a*=-1;
                        if(b<0){
                                b*=-1;
                                cout<<"-";
                        }
                    }
                    int s=2*a;
                    int k=gcd(s,b);
                    if(s/k==1) cout<<b/k<<endl;
                    else  cout<<b/k<<"/"<<s/k<<endl;
                }
                continue;
            }
            int q2=1;
            for(int i=cnt;i>=2;i--){
                if(deta % pf[i] == 0){
                    if(deta == 1) break;
                    deta /= pf[i];
                    q2*=g[i];
                    if(deta == 1) break;
                }
            }
            int tmp=0;
            if(deta == 1) tmp=1;
            cout<<tmp;

            if(a>0){
                if(tmp==1){
                    b=q2-b;
                    if(b>0){
                        int k=gcd(2*a,b);
                        if(2*a/k == 1){
                            cout<<b/k<<endl;
                            continue;
                        }
                        cout<<b/k<<"/"<<2*a/k<<endl;
                    }
                    else if(b==0){
                        cout<<0<<endl;
                    }
                    else{
                        b=-1*b;
                        int k=gcd(2*a,b);
                        if(2*a/k == 1){
                            cout<<"-"<<b/k<<endl;
                            continue;
                        }
                        cout<<"-"<<b/k<<"/"<<2*a/k<<endl;
                    }
                    continue;
                }

                if(b>0){
                    int k=gcd(2*a,b);
                    if(2*a/k == 1){
                        cout<<"-"<<b/k<<"+";
                    }
                    else cout<<"-"<<b/k<<"/"<<2*a/k<<"+";
                }
                else if(b<0){

                    b=-1*b;
                    int k=gcd(2*a,b);
                    if(2*a/k == 1){
                        cout<<b/k<<endl;
                    }
                    else cout<<b/k<<"/"<<2*a/k<<"+";
                }

                int kk=gcd(2*a,q2);
                a=2*a/kk;
                q2=q2/kk;
                if(a==1 && q2==1){
                    cout<<"sqrt("<<deta<<")"<<endl;
                    continue;
                }
                else if(a==1){
                    cout<<q2<<"*sqrt("<<deta<<")"<<endl;
                    continue;
                }
                else if(q2==1){
                    cout<<"sqrt("<<deta<<")/"<<a<<endl;
                    continue;
                }
                else{
                    cout<<q2<<"*sqrt("<<deta<<")/"<<a<<endl;
                    continue;
                }
            }
            else if(a<0){

                if(tmp==1){
                    b=0-q2-b;
                    if(b>0){
                        a=-1*a;
                        int k=gcd(2*a,b);
                        if(2*a/k == 1){
                            cout<<"-"<<b/k<<endl;
                            continue;
                        }
                        cout<<"-"<<b/k<<"/"<<2*a/k<<endl;
                    }
                    else if(b==0){
                        cout<<0<<endl;
                    }
                    else{
                        b=-1*b;
                        a=-1*a;
                        int k=gcd(2*a,b);
                        if(2*a/k == 1){
                            cout<<b/k<<endl;
                            continue;
                        }
                        cout<<b/k<<"/"<<2*a/k<<endl;
                    }
                    continue;
                }



                if(b>0){
                    a=-1*a;
                    int k=gcd(2*a,b);
                    if(2*a/k == 1){
                        cout<<b/k<<endl;
                    }
                    else cout<<b/k<<"/"<<2*a/k<<"+";
                }
                else if(b<0){
                    a=-1*a;
                    b=-1*b;
                    int k=gcd(2*a,b);
                    if(2*a/k == 1){
                        cout<<"-"<<b/k<<endl;
                    }
                    else cout<<"-"<<b/k<<"/"<<2*a/k<<"+";
                }

                int kk=gcd(2*a,q2);
                a=2*a/kk;
                q2=q2/kk;
                if(a==1 && q2==1){
                    cout<<"sqrt("<<deta<<")"<<endl;
                    continue;
                }
                else if(a==1){
                    cout<<q2<<"*sqrt("<<deta<<")"<<endl;
                    continue;
                }
                else if(q2==1){
                    cout<<"sqrt("<<deta<<")/"<<a<<endl;
                    continue;
                }
                else{
                    cout<<q2<<"*sqrt("<<deta<<")/"<<a<<endl;
                    continue;
                }
            }
        }
    }
    return 0;
}
