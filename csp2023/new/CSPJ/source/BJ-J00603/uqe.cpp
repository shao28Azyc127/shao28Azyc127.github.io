#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int a,b,c,s,x1,x2;
    int n,m;
    cin>>n>>m;
    while(n--){
        cin>>a>>b>>c;
        s=b*b-4*a*c;
        if(s<0){
            return 0;
        }
        x1=((0-b)*sprt(s))/2*a;
        x2=((0-b)*(0-sprt(s)))/2*a;
        if(x1==x2){
            cout<<x1;
        }else{
            cout<<x1<<" "<<x2;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
