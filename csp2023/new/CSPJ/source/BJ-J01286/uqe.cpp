#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double a,b,c;
double d;
ll t,m;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--){
        cin>>a>>b>>c;
        d=b*b-4*a*c;
//        cout<<d;
        if(d<0){
            cout<<"NO"<<endl;
            continue;
        }
  //      if(d>=0){
        double x=max((-b+sqrt(d))/(2*a),(-b-sqrt(d))/(2*a));
//        if(x==0.5){
  //          cout<<1/2<<endl;
    //    }
      //  else if(x==-0.5){
        //    cout<<-1/2<<endl;
        //}
        cout<<max((-b+sqrt(d))/(2*a),(-b-sqrt(d))/(2*a))<<endl;
    //    }
    }

    return 0;
}
