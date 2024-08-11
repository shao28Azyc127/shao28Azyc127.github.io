#include<bits/stdc++.h>
using namespace std;
long long gcd(long long x,long long y){
    if(y == 0){
        return x;
    }
    return gcd(y,x % y);
}
long long p[5000010];
long long vis[5000010];
long long n = 0;
long long check(long long x){
    long long ans = 1;
    for(int i = 1;i <= n;i++){
        while(x % (p[i] * p[i]) == 0){
            ans *= p[i];
            x /= (p[i] * p[i]);
        }
        if(!vis[x]){
            return ans;
        }
    }
    return ans;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    long long t,m;
    cin >> t >> m;
    for(int i = 2;i <= 5 * m * m + 5;i++){
        vis[i] = 0;
    }
    for(int i = 2;i <= 5 * m * m + 5;i++){
        if(!vis[i]){
            n++;
            p[n] = i;
            for(int j = i * 2;j <= 2 * m * m + 5;j += i){
                vis[j] = 1;
            }
        }
    }
    while(t--){
        long long a,b,c,cnt,v,u;
        cin >> a >> b >> c;
        cnt = b * b - 4 * a * c;
        if(cnt < 0){
            cout << "NO" << endl;
        }
        else{
            long long scnt = sqrt(cnt);
            if(scnt * scnt == cnt){
                if(2 * a < 0){
                    u = min(scnt - b,-scnt - b);
                    if(max(u,-u) % (-2 * a) == 0){
                        cout << u / (2 * a) << endl;
                    }
                    else{
                        v = gcd(max(u,-u),-2 * a);
                        cout << u / v << "/" << 2 * a / v << endl;
                    }
                }
                else{
                    u = max(scnt - b,-scnt - b);
                    if(max(u,-u) % (2 * a) == 0){
                        cout << u / (2 * a) << endl;
                    }
                    else{
                        v = gcd(max(u,-u),2 * a);
                        cout << u / v << "/" << 2 * a / v << endl;
                    }
                }
            }
            else{
                u = check(cnt);
                //cout << u << "   ";
                if(b != 0){
                    if(max(b,-b) % max(2 * a,-2 * a) == 0){
                        cout << -b / (2 * a) << "+";
                    }
                    else{
                        v = gcd(max(b,-b),2 * a);
                        if((-b < 0 && 2 * a < 0) || (-b > 0 && 2 * a > 0))cout << max(-b,b) / v << "/" << max(2 * a,-2 * a) / v << "+";
                        else cout << "-" << max(-b,b) / v << "/" << max(2 * a,-2 * a) / v << "+";
                    }
                }

                cnt /= (u * u);
                if(u == max(2 * a,-2 * a)){
                    cout << "sqrt(" << cnt << ")" << endl;
                }
                else if(u % (2 * a) == 0){
                    cout << max(u / (2 * a),-u / (2 * a)) << "*sqrt(" << cnt << ")" << endl;
                }
                else if((2 * a) % u == 0){
                    cout << "sqrt(" << cnt << ")/" << max(2 * a / u,-2 * a / u) << endl;
                }
                else{
                    v = gcd(u,max(-2 * a,2 * a));
                    cout << u / v << "*sqrt(" << cnt << ")/" << max(2 * a,-2 * a) / v << endl;
                }
            }
        }
    }
    return 0;
}

