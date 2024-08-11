#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
void fc(int a,int b,int c){
    int ret;
    if(b==0){
        ret=sqrt((-c)/a);
        if(int(ret)*int(ret)==(-c)/a){
            std::cout<<ret;
        }
        else{
            if((-c)/a<0)cout<<"NO";
            else std::cout<<"sqrt("<<(-c)/a<<")";
        }
    }
    else {
        std::cout<<"NO";
    }
    std::cout<<endl;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,M;
    int a,b,c;
    std::cin>>T>>M;
    for(int i=0;i<T;i++){
        std::cin>>a>>b>>c;
        fc(a,b,c);
    }
    return 0;
}
