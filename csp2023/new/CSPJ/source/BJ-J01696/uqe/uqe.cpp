#include <iostream>
#include <cmath>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,M;
    cin>>T>>M;
    while(T--){
        int a,b,c;
        cin>>a>>b>>c;
        int x=b*b-4*a*c;
        if(x<0){
            cout<<"NO"<<endl;
            continue;
        }
        int x1=(0-b+sqrt(x))/(2*a);
        int x2=(0-b-sqrt(x))/(2*a);
        cout<<max(x1,x2)<<endl;
    }
    return 0;
}
