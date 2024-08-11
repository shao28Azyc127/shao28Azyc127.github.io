#include <bits/stdc++.h>
#include <cmath>
using namespace std;
const int N = 1e5 + 10;
string ans[N];
int gcd(int a,int b) {
    bool f1 = true;
    for(int i = 17;i >= 2;i--) {
            if(a % i == 0 && b % i == 0) {

            }
    }
    return 1;
}


string yuefen(string s) {
    string r;
    int c1;
    int chupos = s.find("/");
    int fupos = s.find("-");
    if(chupos != -1) {
        if(fupos == -1) {
            int x1 = stoi(s.substr(0,chupos-1));
            int x2 = stoi(s.substr(chupos+1));
            while(1) {
                int c = gcd(x1,x2);
                if(c != 1) {
                    x1 /= c;
                    x2 /= c;

                }
                if(c == 1) {
                    r += to_string(x1);
                    r += "/";
                    r += to_string(x2);
                    break;
                }
            }
            if(c1 == 1) {
                r = s;
            }

        }
    }
    return r;
}


int main() {
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);

    int T,M,delta;
    scanf("%d",&T,&M);

    for(int i = 1;i <= T;i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a == 0 && b == 0 && c == 0) {
            cout << 0 << endl;
        }
        /*
        delta = b * b - 4 * a * c;
        if(delta < 0) {
            ans[i] = "NO";
        }else if(delta = 0) {

        }
        */
    }

    //cout << gcd(18,12);
    return 0;
}
