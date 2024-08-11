#include <bits/stdc++.h>
using namespace std;
int t,m,a,b,c,d,tmp,num[5005] = {0,1},num2[5000005],q,q2,g,cnt;
int gcd(int x,int y){
    if(!y) return x;
    return gcd(y,x % y);
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    for(int i = 0;i <= 5000000;i++) num2[i] = 1;
    for(int i = 2;i <= 5000;i++){
        num[i] = i * i;
        for(int j = num[i];j <= 5000000;j += num[i]) num2[j] = num[i];
    }
    cin >> t >> m;
    while(t--){
        cnt++;
        cin >> a >> b >> c;
        d = b * b - 4 * a * c;
        if(d < 0){
            cout << "NO\n";
            continue;
        }
        tmp = lower_bound(num,num + 5000,d) - num;
        if(num[tmp] == d){
            if(tmp < 0 && 2 * a >= 0 || tmp >= 0 && 2 * a < 0) tmp = -tmp;
            if((-b + tmp) % (2 * a) == 0) cout << (-b + tmp) / (2 * a) << '\n';
            else{
                g = gcd(-b + tmp,2 * a);
                if(2 * a / g < 0) g = -g;
                cout << (-b + tmp) / g << '/' << 2 * a / g << '\n';
            }
        }else{
            if((-b) % (2 * a) == 0){
                if(-b / (2 * a) != 0) cout << -b / (2 * a) << '+';
            }else{
                g = gcd(-b,2 * a);
                if(2 * a / g < 0) g = -g;
                cout << -b / g << '/' << 2 * a / g << '+';
            }
            q = lower_bound(num,num + 5000,num2[d]) - num;
            q2 = 2 * a;
            if(q >= q2 && q % q2 == 0){
                if(abs(q / q2) == 1) cout << "sqrt(" << d / num2[d] << ")\n";
                else cout << abs(q / q2) << '*' << "sqrt(" << d / num2[d] << ")\n";
            }else if(q2 % q == 0 && abs(q2 / q) != 1) cout << "sqrt(" << d / num2[d] << ")/" << abs(q2 / q) << '\n';
            else{
                g = gcd(q,q2);
                if(q2 / g < 0) g = -g;
                cout << abs(q / g) << '*' << "sqrt(" << d / num2[d] << ")/" << q2 / g << '\n';
            }
        }
    }
    return 0;
}
