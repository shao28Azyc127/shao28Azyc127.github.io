#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m,a,b,c;
    cin >> t >> m;
    for(int i = 0;i<t;i++){
        cin >> a >> b >> c;
        int beita = b*b-4*a*c;
        if(beita < 0){
            cout<<"NO"<<endl;
            continue;
        }else if(beita == 0){
            cout<<-b/2/a<<endl;
            continue;
        }else{
            double bt = sqrt(beita);
            cout<<max((-b+bt)/a/2,(-b-bt)/a/2)<<endl;
        }

    }
    return 0;
}
