#include<bits/stdc++.h>
using namespace std;
int n, m;
int a, b, c, derta;
char sqrtq[10],sqrth[10];
int sqrtm, sqrtxs;
void winzsqrt(int x){
    int rex = x, xs = 1;
    if(rex == 0){
        sqrtxs = 0;
        sqrtm = 0;
    }
    for(int i = 2; i*i<=x; i++){
        if(rex%(i*i) == 0){
            rex/=i*i;
            xs*=i;
        }
    }
    sqrtxs = xs;
    sqrtm = rex;
}
int gcd(int x,int y){
    int gcdd = 1;
    for(int i = 2; i<=min(abs(x),abs(y)); i++){
        if(x%i==0&&y%i==0){
            gcdd*=i;
        }
    }
    return gcdd;
}
int main(){
    ios::sync_with_stdio(false);
    freopen("uqe.in","r", stdin);
    freopen("uqe.out","w", stdout);
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        cin >> a >> b >> c;
        derta = b*b-4*a*c;
        if(derta<0){
            cout << "NO" << endl;
            continue;
        }
        winzsqrt(derta);
        int ra = 2*a, rb = 0-b;
        if(sqrtm == 0){
            int rr = gcd(ra, rb);
            if(rr !=ra)cout << rb/rr << "/" << ra/rr;
            else cout << rb/ra;
        }else if(sqrtm == 1){
            if(a<0&&sqrtxs>0){
                rb = 0-b-sqrtxs;
            }else if(a<0&&sqrtxs<0){
                rb = 0-b+sqrtxs;
            }else if(a>0&&sqrtxs>0){
                rb = 0-b+sqrtxs;
            }else{
                rb = 0-b-sqrtxs;
            }
            int rr = gcd(ra, rb);
            if(rr !=ra)cout << rb/rr << "/" << ra/rr;
            else cout << rb/ra;

        }else{
            //cout << "yes";
            if(b!=0){
                int rb = 0-b;
                int rr = gcd(ra, rb);
                if(rb/rr!=0&&ra/rr!=0&&rr!=0){
                    if(rr !=ra)cout << rb/rr << "/" << ra/rr;
                    else cout << rb/ra;
                    cout << "+";
                }

            }
            if(sqrtxs!=1){
                int rr = gcd(sqrtxs, ra);
                if(rr!=ra)cout << sqrtxs/rr << "*sqrt(" << sqrtm << ")/" << ra/rr;
                else cout << sqrtxs/ra << "*sqrt(" << sqrtm << ")";
            }else{
                cout << "sqrt(" << sqrtm << ")/" << ra;
            }
        }
        cout << endl;
    }
    return 0;
}
