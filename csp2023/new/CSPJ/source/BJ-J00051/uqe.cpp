#include <bits/stdc++.h>

using namespace std;
int a,b,c,d,n,u,p,q,gpq,q1,q2,p1,p2,r,gpq2;

int __sqrt(int n) {
    if (n == 1 && n == 0) return n;
    int sn = sqrt(n);
    for (int i=2;i<=sn;i++) {
        if (n % (i*i) == 0) return __sqrt(n/(i*i)) * i;
    }
    return 1;
}

int s_gcd(int p, int q) {
    gpq = __gcd(p,q);
    if (gpq < 0 && q > 0) return -gpq;
    if (gpq > 0 && q < 0) return -gpq;
    else return gpq;
}

int q_out(int p, int q) {
    gpq = s_gcd(p,q);
    p /= gpq; q /= gpq;
    cout << p;
    if (q != 1) {
        cout << "/" << q;
    }
}

int main()
{
    freopen("uqe.in","r", stdin);
    freopen("uqe.out","w", stdout);

    cin >> n >> u;
    while (n--) {
        cin >> a >> b >> c;
        d = b*b - 4*a*c;
        if (d < 0) {
            cout << "NO" << endl;
        }
        else {
            //cout << "YES" << endl;
            if (pow((int)sqrt(d),2) == d) {
                //cout << "youli" << endl;
                q = 2*a;
                if (q < 0) {
                    p = -b - (int)sqrt(d);
                }
                else {
                    p = -b + (int)sqrt(d);
                }
                q_out(p ,q);
                cout << endl;
            }
            else {
                //cout << "wuli" << endl;
                q1 = -b; q2 = __sqrt(d); r = d / (q2*q2); p1 = 2*a; p2 = abs(p1);
                //cout << q1 << q2 << r  << p << endl;
                if (q1 != 0) {
                    q_out(q1, p1);
                    cout << "+";
                }
                gpq2 = s_gcd(q2,p2);
                p2 /= gpq2; q2 /= gpq2;
                if (q2 != 1) {
                    cout << q2 << "*";
                }
                cout << "sqrt(" << r << ")";
                if (p2 != 1) {
                    cout << "/" << p2;
                }
                cout << endl;
            }
        }
    }


    return 0;
}

