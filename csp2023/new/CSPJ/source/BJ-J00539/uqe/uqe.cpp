#include<iostream>
#include<cmath>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        int a, b, c;
        cin>>a>>b>>c;
        if(b==0&&c==0){
            cout<<0<<endl;
            continue;
        }
        int r = b * b - (4 * a * c);
        if(r<0) {
            cout<<"NO"<<endl;
            continue;
        }
        int  rr = sqrt(r);
        if(rr*rr==r){
                double x;
                x = (-b + rr) / (2 * a);
                cout<<x<<endl;
                continue;
        }

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}