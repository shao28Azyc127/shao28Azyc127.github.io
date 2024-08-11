#include<bits/stdc++.h>

using namespace std;

int T,M,a,b,c,delta;

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin >> T >> M;
    for(int i = 1;i <= T;i++){
        cin >> a >> b >> c;
        delta = b * b - 4 * a * c;
        if(b * b - 4 * a * c < 0){
            cout << "NO" << endl;
            continue;
        }
        if(b * b - 4 * a * c >= 0){
            if(ceil(sqrt(b * b - 4 * a * c)) == floor(sqrt(b * b - 4 * a * c))){
                int p = sqrt(b * b - 4 * a * c) - b;
                int pp = p,f = 1;
                if(p < 0){
                    pp = -p;
                    f = -1;
                }
                int aa = a;
                if(pp % 2 == 0){
                    pp /= 2;
                }
                else{
                    aa *= 2;
                }
                int ppp = pp;
                pp /= __gcd(ppp,aa);
                aa /= __gcd(ppp,aa);
                if(aa == 1){
                    cout << pp * f << endl;
                    continue;
                }
                cout << pp * f << "/" << aa << endl;
                continue;
            }
            int r,q1,q2,f=1,aaa = a,aa = a;
            for(int j = sqrt(b * b - 4 * a * c);j>=1;j--){
                if((b * b - 4 * a * c)%(j*j) == 0){
                    r = (b * b - 4 * a * c) / (j*j);
                    q2 = j;
                    break;
                }
            }
            q1 = -b;
            int qq1 = q1,ff = 1;
            if(q1!=0){
                if(q1 < 0){
                    qq1 = -q1;
                    ff = -1;
                }
                if(qq1 % 2 == 0){
                    qq1 /= 2;
                }
                else{
                    aaa *= 2;
                }
                int qqq1 = qq1;
                qq1 /= __gcd(qqq1,aaa);
                aaa /= __gcd(qqq1,aaa);
                if(aaa == 1){
                    cout << qq1 * ff << "+";
                }
                else{
                    cout << qq1 * ff << "/" << aaa << "+";
                }
            }
            if(q2 == 2 * a){
                cout << "sqrt(" << r << ")" << endl;
                continue;
            }

            if(q2 % (2 * a) == 0){
                if(q2/(2*a) == 1||q2/(2*a) == -1){
                    cout << "sqrt(" << r << ")" << endl;
                    continue;
                }
                if(q2/(2*a) < 0){
                    cout << -(q2 / (2 * a)) << "*sqrt(" << r << ")" << endl;
                    continue;
                }
                cout << (q2 / (2 * a)) << "*sqrt(" << r << ")" << endl;
                continue;
            }
            if((2 * a) % q2 == 0){
                if(q2/(2*a) < 0){
                    cout << "sqrt(" << r << ")/" << -((2 * a) / q2) << endl;
                    continue;
                }
                cout << "sqrt(" << r << ")/" << ((2 * a) / q2) << endl;
                continue;
            }
            int c,d;
            c = q2,d = a;
            if(c % 2 == 0){
                c /= 2;
            }
            else{
                d *= 2;
            }
            int cc = c;
            c /= __gcd(cc,d);
            d /= __gcd(cc,d);
            cout << c << "*sqrt(" << r << ")/" << d << endl;
        }
    }
    return 0;
}
