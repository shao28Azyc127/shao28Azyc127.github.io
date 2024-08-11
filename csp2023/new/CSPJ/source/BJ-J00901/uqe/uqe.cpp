#include<bits/stdc++.h>
using namespace std;
int n,a,b,c,M;
double x,y;
int main(){
    double p1,p2;
    cin >> n >> M;
    for (int i=1;i<=n;i++){
        cin >> a >> b >> c;
        if (pow(b) - 4*a*c < 0) cout << "NO",continue;
        else{
            if (sqrt(pow(b) - 4*a*c)/1 == sqrt(pow(b) - 4*a*c))
                p1 = -b + floor(sqrt(pow(b) - 4*a*c));
                p2 = -b - floor(sqrt(pow(b) - 4*a*c));
                q = 2 * a;
            else
                cout << -b << "+sqrt(" << pow(b) - 4*a*c<< ")";
            if (q==1) cout << max(p1,p2),continue;
            q1=q;
            for (int r=2;r<=sqrt(min(q,p1));r++){
                if (p1/r == q/r) p1/=p1/r,q/=q/r;
            }
            for (int r=2;r<=sqrt(min(q,p1));r++){
                if (p2/r == q1/r) p2/=p2/r,q/=q/r;
            }
            if (p1/q > p1/q1) cout << p1 << "/" << q;
            else cout << p2 <<"/"<< q1;
            continue;
        }
    }
    return 0;
}