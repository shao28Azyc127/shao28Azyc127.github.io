#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
/*
bool isok(long double n){
    for(long double i=0;i<=sqrt(n);i++)
        if(n==i*i){
            return true;
        }
    return false;
}
int main(){
    double a,b,c,x1,x2,T,M,y,out,tmp;
    string a="";
    cin>>T>>M;
    while(T--){
        a="";
        cin>>a>>b>>c;
        y=b*b-4*a*c;
        if(b*b-4*a*c<0){
            cout<<"NO"<<endl;
        }else{
            if(isok(y)){
                x1=(0-b+sqrt(y))*1.0/(2*a);
                x2=(0-b-sqrt(y))*1.0/(2*a);
                out=x1>x2?x1:x2;
                cout<<out<<endl;
            }else{
                if(b){
                    if()
                        string+=to_string((0-b)/2/a)+"+"+;
                }else{

                }
            }

        }
    }
    return 0;
}
*/
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    long long a,b,c,x1,x2,T,M,y;
    cin>>T>>M;
    while(T--){
        cin>>a>>b>w>c;
        if(b==0&&c==0){
            cout<<0<<endl;
        }else{
            y=b*b-4*a*c;
            if(b*b-4*a*c<0){
                cout<<"NO"<<endl;
                continue;
            }else{
                if(isok(y)){
                    x1=(0-b+sqrt(y))*1.0/(2*a);
                    x2=(0-b-sqrt(y))*1.0/(2*a);
                    out=x1>x2?x1:x2;
                    cout<<out<<endl;
                }else{
                    if(b){
                        if()
                            string+=to_string((0-b)/2/a)+"+"+;
                    }else{

                    }
                }
            }

        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
