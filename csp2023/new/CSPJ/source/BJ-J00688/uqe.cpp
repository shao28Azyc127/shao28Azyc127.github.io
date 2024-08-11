#include<iostream>
#include<cmath>
using namespace std;
int t,m;
int gcd(int x,int y){
    if(x%y==0) return y;
    else return gcd(y,x%y);
}
int convert_1(double x){
    int cnt=1;
    while(ceil(x)!=x){
        cnt*=10;
        x*=10;
    }
    int gcdd=gcd(cnt,int(x));
    return cnt/gcdd;
}
int convert_2(double x){
    int cnt=1;
    while(ceil(x)!=x){
        cnt*=10;
        x*=10;
    }
    int gcdd=gcd(cnt,int(x));
    return int(x)/gcdd;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out"."w",stdout);
    cin>>t>>m;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        double x=b*b-4*a*c;
        if(x<0){
            cout<<"NO"<<endl;
            continue;
        }
        else{
            cout<<max(convert2((sqrt(x)-b)/2a)/convert1((sqrt(x)-b)/2a),convert2((0-b-sqrt(x))/2a)/convert1((0-b-sqrt(x))/2a))<<endl;
        }

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}