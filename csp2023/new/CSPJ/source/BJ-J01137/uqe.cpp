#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define longlong ld
int gcd(int x,int y){
    int ans=1;
    for(int i=1;i<=max(x,y);i++){
        if(x%i==0&&y%i==0){
            ans=i;
        }
    }
    return ans;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int a,b,c;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){

        scanf("%d%d%d",&a,&b,&c);
        long long dert=b*b-4*a*c;
        if(dert<0){
        cout<<"NO"<<endl;
        continue;
        }
                if(dert==0){

                    if(b%(2*a)==0){
                        cout<<-1*b/(2*a)<<endl;
                    }
                    else{
                        int l=gcd(2*a,b);
                        cout<<-1*b/l<<'/'<<2*a/l<<endl;
                    }

                    continue;
                }
        bool flag=true;
        int xx=1,lin=dert;
        while(flag&&lin!=1){
            flag=false;
            for(int j=2;j*j<=lin;j++){
                if(lin%(j*j)==0){
                    lin/=(j*j);
                    xx*=j;
                    flag=true;
                }
            }
        }
            if((-1*b+xx)%(2*a)==0&&lin==1){
                cout<<(-1*b+xx)/(2*a)<<endl;
            }

            else{
                if(lin==1){
                        int l=gcd(-1*b+xx,2*a);
                    cout<<(-1*b+xx)/l<<'/'<<(2*a)/l<<endl;
                continue;
                }
                    if(b%(2*a)==0&&b!=0){
                        cout<<-1*b/(2*a)<<'+';
                    }
                    else{
                            if(b!=0){
                                    int l=gcd(-1*b,2*a);
                        cout<<-1*b/l<<'/'<<2*a/l<<'+';
                            }
                    }
                    if(xx%(2*a)==0){
                        if(abs(xx/(2*a))!=1){
                        cout<<abs(xx/(2*a))<<'*'<<"sqrt("<<lin<<")"<<endl;
                        }
                    else{
                        cout<<"sqrt("<<lin<<")"<<endl;
                    }
                    }
                    else{
                            int l=gcd(xx,2*a);
                            if(xx/l!=1)
                        cout<<abs(xx/l)<<"*"<<"sqrt("<<lin<<")/"<<abs(2*a/l)<<endl;
                        else{
                            cout<<"sqrt("<<lin<<")/"<<abs(2*a/l)<<endl;
                        }
                    }
            }
    }
    //81 378 117
return 0;
}

