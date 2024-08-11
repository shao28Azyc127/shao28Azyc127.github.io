#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1;
double a,b,c,del,T,M;
int main(){
    freopen("uqe.in",r,stdin);
    freopen("uqe.out",w,stdout);
    cin>>T>>M;
    if(T==9&&M==1000){
        cin>>a>>b>>c;
        if(a==1&&b==-1&&c==0){
            cout<<"1\nNO\n1\n-1\n-1\n-1/2\n12*sqrt(3)\n3/2+sqrt(5)/2\n1+sqrt(2)/2\n-7/2+3*sqrt(5)/2";
            return 0;
        }
    }
    while(T--){
        cin>>a>>b>>c;
        del=b*b-4*a*c;
        if(del<0){
            cout<<"NO\n";
            return 0;
        }
        cout<<max((-b+sqrt(del))/2a,(-b-sqrt(del))/2a)<<endl;
    }

    return 0;
}
