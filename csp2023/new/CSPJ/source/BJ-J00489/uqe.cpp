#include <iostream>
#include <cmath>
using namespace std;

int z[5010][3];

int gcd(int a,int b){
    int x = max(a,b);
    for(int i=sqrt(x);i>=0;i--){
        if(a%i==0&&b%i==0) return i;
    }
}


int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
   int T,M;
   cin >> T >> M;
   for(int i = 1;i<=T;i++){
        cin >> z[i][0] >>z[i][1] >> z[i][2];
   }
   for(int i = 1;i<=T;i++){
        int a=z[i][0],b=z[i][1],c=z[i][2];
        int delta = b*b-4*a*c;
        if(delta<0){
            cout << "NO";
            continue;
        }
        double partb = sqrt(delta)/(2*a);
        bool sqrtandint = true;
        if(partb != (int)partb){
           sqrtandint = false;
        }

        double parta;
        if(sqrtandint) parta = (-b+partb)/(2*a);
        else parta = -b/(2*a);
        if(parta=(int)parta) cout << parta;
        else{
            int t = 2*a;
            if(gcd(abs(b),abs(t))==1){
                if(t*b>0){
                    cout << abs(b) << "/" << abs(t);
                }
                else{
                    cout << "-" << abs(b) << "/" << abs(t);
                }
            }
            else{
                int gcd1 = gcd(abs(b),abs(t));
                int _a = (t)/gcd1,_b=b/gcd1;
                if(t*_b>0){
                    cout << abs(_b/2) << "/" << abs(_a/2);
                }
                else{
                    cout << "-" << abs(_b/2) << "/" << abs(_a/2);
                }
            }
        }

   }
   return 0;
}

