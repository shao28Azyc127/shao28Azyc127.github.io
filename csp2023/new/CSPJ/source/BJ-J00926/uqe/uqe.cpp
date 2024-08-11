#include<bits/stdc++.h>
using namespace std;

int q,m;
int num[40];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin >> q >> m;
    while(q--){
        int a,b,c;
        cin >> a >> b >> c;
        int d = b*b-4*a*c;
        if(d < 0){
            cout << "NO" << endl;
            continue;
        }
        int sq = sqrt(d);
        if(sq*sq == d){
            int sum = -b+sq;
            if(a*2 < 0){
                sum = -b-sq;
            }
            if(sum == 0){
                cout << 0 << endl;
                continue;
            }
            if(2*a < 0 && sum > 0 || 2*a > 0 && sum < 0){
                cout << "-";
            }
            int zi = abs(sum/__gcd(sum,2*a));
            int mu = abs(2*a/__gcd(sum,2*a));
            if(mu == 1){
                cout << zi << endl;
            }
            else{
                cout << zi << "/" << mu << endl;
            }
        }
        else{
            if(2*a < 0 && -b > 0 || 2*a > 0 && -b < 0){
                cout << "-";
            }
            if(-b != 0){
                int zi = abs(-b/__gcd(-b,2*a));
                int mu = abs(2*a/__gcd(-b,2*a));
                if(mu == 1){
                    cout << zi << "+";
                }
                else{
                    cout << zi << "/" << mu << "+";
                }
            }
            int kk = 1;
            for(int i = 2;i <= sqrt(d);i++){
                while(d%(i*i) == 0){
                    kk *= i;
                    d /= (i*i);
                }
            }
            if(2*a < 0){
                kk = -kk;
            }
            int zi = abs(kk/__gcd(kk,2*a));
            int mu = abs(2*a/__gcd(kk,2*a));
            if(zi == 1 && mu == 1){
                cout << "sqrt(" << d << ")" << endl;
            }
            else if(zi == 1){
                cout << "sqrt(" << d << ")/" << mu << endl;
            }
            else if(mu == 1){
                cout << zi << "*sqrt(" << d << ")" << endl;
            }
            else{
                cout << zi << "*sqrt(" << d << ")/" << mu << endl;
            }
        }
    }
}
