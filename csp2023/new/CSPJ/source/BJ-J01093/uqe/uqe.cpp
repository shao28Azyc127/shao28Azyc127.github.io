#include <iostream>

using namespace std;

int t,m;
iny a,b,c;

int f(float x){
    float ans=1;
    if(x%1==0){
        for(int i=1;i<=x;i++){
            if(x%i==0){
                for(int j=2;j*j<=x;j++){
                    while(i%(j*j)==0) ans=ans*j;
                }
            }
        }
        return ans;
    }
    else{
        if((1/x)%1==0){
            x=1/x;
            for(int i=1;i<=x;i++){
                if(x%i==0){
                    for(int j=2;j*j<=x;j++){
                        while(i%(j*j)==0) ans=ans*j;
                    }
                }
            }
            return 1/ans;
        }
    }
}

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        cin>>a>>b>>c;
        if(b*b-4*a*c<0) cout<<"NO"<<endl;
        else{
            if(b!=0){
                cout<<-1*b/2<<"+";
            }
            float g=b*b-4*a*c;
            if(f(g)==1) cout<<"sqrt("<<g<<")"<<endl;
            else if(f(g)%1==0) cout<<f(g)<<"*"<<"sqrt("<<g/f(g)<<")"<<endl;
            else if((1/(f(g)*1.0))%1==0) cout<<"sqrt("<<g/f(g)<<")"/(1/(f(g)*1.0))<<endl;
            //else cout<<c<<"*sqrt("<<g/(f(g)*1.0)<<")/"<<
        }


    }

    return 0;
}
