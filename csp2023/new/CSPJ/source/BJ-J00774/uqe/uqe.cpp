# include<iostream>
# include<algorithm>
# include<cmath>
# define endl "\n"
# define int long long
using namespace std;
int t, m, a, b, c, d;
int mu, zi, sq, ti;
bool is_square(int a) {
    int b=sqrt(a);
    return b*b==a;
}
int gcd(int x, int y) {
    if(y==0) return x;
    return gcd(y, x%y);
}
void yuefen(int m, int z) {
    int g=gcd(m, z);
    mu=m/g; zi=z/g;
    if(mu<0) {
        mu=-mu;
        zi=-zi;
    }
}
void yuesqrt(int x) {
    ti=1, sq=x;
    for(int i=2; i<=sqrt(x); i++) {
        while(sq%(i*i)==0) {
            ti*=i;
            sq/=i*i;
        }
    }
}
signed main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> t >> m;
    while(t--) {
        cin >> a >> b >> c;
        d=b*b-4*a*c;
        if(d<0) cout << "NO" << endl;
        else if(is_square(d)) {
            int t;
            if(a>0) t=-b+sqrt(d);
            else t=-b-sqrt(d);
            yuefen(2*a, t);
            if(mu==1) cout << zi << endl;
            else cout << zi << "/" << mu << endl;
        } else {
            if(b!=0) {
                int x=-b, y=2*a;
                yuefen(2*a, -b);
                if(mu==1) cout << zi << "+";
                else cout << zi << "/" << mu << "+";
            }
            yuesqrt(d);
            yuefen(2*a, ti);
            if(zi<0) zi=-zi;
            // zi*sqrt(sq)/mu
            if(zi==1 && mu==1) cout << "sqrt(" << sq << ")" << endl;
            else if(zi==1) cout << "sqrt(" << sq << ")/" << mu << endl;
            else if(mu==1) cout << zi << "*sqrt(" << sq << ")" << endl;
            else cout << zi << "*sqrt(" << sq << ")/" << mu << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

