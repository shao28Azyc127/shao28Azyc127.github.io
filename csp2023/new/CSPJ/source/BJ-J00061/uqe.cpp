#include<bits/stdc++.h>
using namespace std;
void youlishugeshi(double v){
    freopen("uqe.out","w",stdout);
    double q=v;
    int s=10;
    int p=1;
    while(q!=int(q)){
        q*=10;
        p*=10;
    }
    int qq=(int)q;
    while(qq%2==0&&p%2==0){
        q=q/2;
        p=p/2;
    }
    while(qq%5==0&&p%5==0){
        q=q/5;
        p=p/5;
    }
    if(int(q)==1) cout<<p;
    else cout<<p<<"/"<<q;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,d;
    cin>>t>>d;
    while(t--){
        double a,b,c;
        cin>>a>>b>>c;
        int s=b*b-4*a*c;
        if(s<0){
            cout<<"NO";
        }
        if(sqrt(s)*sqrt(s)==s){
            double v=max((-b+sqrt(s))/(2*a),(-b-sqrt(s))/(2*a));
            youlishugeshi(v);
        }

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}


