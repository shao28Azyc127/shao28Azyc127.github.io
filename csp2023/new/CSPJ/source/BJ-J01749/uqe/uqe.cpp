#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int m,t,a,b,c,u,f;

int gcd(int x,int y){
    int r;
    r = a%b;
    if(r == 0){
        return b;
    }
    return gcd(b,r);
}

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);

    int i;
    cin>> t >>m;
    for(i=1;i<=t;i++){
        cin>> a >> b >> c;
        if(b*b-4*a*c < 0){
            cout<< "NO" << endl;
            continue;
        }
        cout<< 0 <<endl;

    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}