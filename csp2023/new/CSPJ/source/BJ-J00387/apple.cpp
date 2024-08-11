#include<iostream>
#include<cstdio>
using namespace std;
bool apple[int(1e9)];

int jia(int yuan){
    int jd=0,ret=0;
    do{
        ret++;
        if(!apple[ret+yuan]){
            jd++;
        }
    }while(jd!=3);
    return ret;
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int a,tian=0,c,nz=0,qs=0;
    std::cin>>a;
    while(nz<a){
        for(int i=0;i<a;i++){
            if(apple[i]==false){
                qs=i;
                break;
            }
        }
        tian++;
        for(int i=qs;i<a;){
            apple[i]=true;
            if(i==a-1)c=tian;
            i+=jia(i);
            nz++;
        }

    }
    std::cout<<tian<<' '<<c;
    return 0;
}
