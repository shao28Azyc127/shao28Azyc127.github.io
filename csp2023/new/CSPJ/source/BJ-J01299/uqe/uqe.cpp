#include <bits/stdc++.h>
using namespace std;
double a,b,c,n,maxa,dt,x;
int main(){
    freopen("uqe1.in","r",stdin);
    freopen("uqe1.out","w",stdout);
    cin>>n>>maxa;
    while(n--){
        cin>>a>>b>>c;
        dt=b*b-4*a*c;
        if(dt>=0){
            x=(0-b+sqrt(dt))/(2*a);
            if(x-int(x)!=0){
                if((0-b)/2*a-int((0-b)/2*a)!=0){
                    if(sqrt(dt)-int(sqrt(dt))!=0){
                        cout<<0-b<<"/"<<2*a<<'+'<<"sqrt("<<dt<<")/"<<2*a<<endl;
                    }else if (sqrt(dt)/2*a-int(sqrt(dt)/2*a)==0) cout<<0-b/2*a<<'+'<<sqrt(dt)/2*a<<endl;
                }else{
                    if(sqrt(dt)-int(sqrt(dt))!=0){
                        cout<<0-b/2*a<<'+'<<"sqrt("<<dt<<")/"<<2*a<<endl;
                    }else if (sqrt(dt)/2*a-int(sqrt(dt)/2*a)==0) cout<<0-b/2*a<<'+'<<sqrt(dt)/2*a<<endl;
                }
            }else cout<<x<<endl;
        }else cout<<"NO"<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
