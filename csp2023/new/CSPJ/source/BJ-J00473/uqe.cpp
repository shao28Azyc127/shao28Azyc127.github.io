#include<bits/stdc++.h>
using namespace std;
int T,M,ansa,ansdelta=1,chu=2,flag[12000],cifang;
int gcd(int a,int b){
    if(b==a){
        return a;
    }
    if(b>a){
        for(int i =a;i>=2;i--){
            if(b%i==0&&a%i==0){
                return i;
            }
        }
    }else{
        for(int i =b;i>=2;i--){
            if(b%i==0&&a%i==0){
                return i;
            }
        }
    }
}
int sqr(int a){
    int flag2=1;
    for(int i = 1;i*i<=a;i++){
        if(a%(i*i)==0){
            flag2=0;
        }
    }
    return flag2;
}
int main(){
    //freopen("uqe.in","r",stdin);
    //freopen("uqe.out","w",stdout);
    cin>>T>>M;
    for(int i= 1;i<=T;i++){
        int a,b,c;
        cin>>a>>b>>c;
        int delta=b*b-4*a*c;
        if(delta<0){
            cout<<"NO"<<endl;
        }else if(delta>0){
            if(a==0){
                if(b==0){
                    cout<<"NO"<<endl;
                    break;
                }else{
                    if(c==0){
                        cout<<0<<endl;
                        break;
                    }else{
                        if(b==gcd(-c,b)){
                            cout<<-c/b<<endl;
                            break;
                        }else{
                            cout<<-c/gcd(-c,b)<<"/"<<b/gcd(-c,b)<<endl;

                        }
                    }
                }
            }else{
                if(b==0&&c==0){
                    cout<<0<<endl;

                }
                if(b==0&&c!=0){
                    cout<<0<<endl;

                }
                if(b!=0&&c==0){
                    if(b>0&&a>0){
                        cout<<0<<endl;

                    }
                    if(a>0&&b<0){
                        if(a==gcd(a,-b)){
                            cout<<-b/a<<endl;

                        }else{
                            cout<<-b/gcd(-b,a)<<"/"<<a/gcd(-b,a)<<endl;

                        }
                    }
                    if(b>0&&a<0){
                        if(a==gcd(a,-b)){
                            cout<<-b/a<<endl;

                        }else{
                            cout<<-b/gcd(-b,a)<<"/"<<a/gcd(-b,a)<<endl;

                        }
                    }
                    if(b<0&&a<0){
                        cout<<0<<endl;

                    }
                }
            }
        }else if(delta=0){
            if(a==0&&b==0&&c!=0){
                cout<<"NO"<<endl;

            }
            if(2*a==gcd(2*a,-b)){
                cout<<-b/2*a<<endl;
            }else{
                cout<<-b/gcd(2*a,-b)<<"/"<<2*a/gcd(2*a,-b)<<endl;
            }
        }
    }
    return 0;
}
