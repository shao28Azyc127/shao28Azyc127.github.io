#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int t,m,a,b,c;
long long f(int i){
    return a*i*i+b*i+c;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        scanf("%d%d%d",&a,&b,&c);
        int derta=b*b-4*a*c;
        if(derta<0)printf("NO\n");
        else {
            for(int i=m;i>=-m;i--){
                if(f(i)==0){
                    printf("%d\n",i);
                    break;
                }
            }
        }
    }
    return 0;
}
