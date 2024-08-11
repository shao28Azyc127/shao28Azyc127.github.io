#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
using namespace std;
int t,m;
int gcd(int a,int b) {
    return b==0?a:gcd(b,a%b);
}
signed main(void) {
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    ios::sync_with_stdio(false);
    cin >> t >> m;
    for (int a,b,c;t--;) {
        cin >> a >> b >> c;
        int delta=b*b-4*a*c;
        int chu=2*a;
        double yy=(-b+sqrt(delta))/chu;
        if (yy==(int)yy) {
            cout << (int)yy << endl;
            continue;
        }
        if (delta<0) {
            cout << "NO\n";
            continue;
        }
        double yyy=(-b-sqrt(delta))/chu;
        //if (yyy>yy)
        int cheng=1;
        for (int i=2;i<=m;i++)
            if (delta%(i*i));
            else cheng=i;
        delta/=(cheng*cheng);
        if (delta==1) {
           cout << (-b+cheng) << "/" << chu << endl;
           continue;
        }
        if (delta==0) {
            if (b!=0) {
                int gc=gcd(-b,chu);
                int aa=(-b)/gc,bb=(chu)/gc;
                if (aa>0&&bb<0) {cout << "-";bb*=(-1);}
                if (aa<0&&bb>0) {cout << "-";aa*=(-1);}
                if (bb==1) cout << aa;
                else cout << aa << "/" << bb;
                cout << endl;
                continue;
            }
        }
        if (b!=0) {
            int gc=gcd(-b,chu);
            int aa=(-b)/gc,bb=(chu)/gc;
            if (aa>0&&bb<0) {cout << "-";bb*=(-1);}
            if (aa<0&&bb>0) {cout << "-";aa*=(-1);}
            if (bb==1) cout << aa << "+";
            else cout << aa << "/" << bb << "+";
        }
        int gc=gcd(cheng,chu);
        cheng/=gc; chu/=gc;
        if (cheng==1&&chu==1) cout << "sqrt(" << delta << ")";
        else if (cheng==1) {
            cout << "sqrt(" << delta << ")/" << chu;
        } else if (chu==1) {
            cout << cheng << "*sqrt(" << delta << ")";
        } else {
            cout << cheng << "*sqrt(" << delta << ")/" << chu;
        }
        cout << endl;
    }
    return 0;
}