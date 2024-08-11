    #include<cmath>
    #include<algorithm>
    #include<cstdio>
    #include<iostream>
    using namespace std;

    int t,m,a,b,c;

    int gcd(int a, int b){
        if(a%b==0){
            return a;
        }
        return gcd(b,a%b);
    }

    bool wqpfs(int m){
        for(int i = 1;i*i <= m;i++){
            if(m == i*i) return true;
        }
        return false;
    }

    void rational(int m, int delta, int a, int b){
        int fenzi = max(-b+sqrt(delta), -b-sqrt(delta));
        int fenmu = 2*a;
        if(fenzi == 0) cout << 0 << endl;
        int z = gcd(fenzi, fenmu);
        cout << fenzi/z << '/' << fenmu/z << endl;
    }

    int main(){
        freopen("uqe.in", "r", stdin);
        freopen("uqe.out", "w", stdout);
        cin >> t >> m;
        while(t--){
            cin >> a >> b >> c;
            int delta = b^2-4*a*c;
            if(delta < 0){
                cout << "NO" << endl;
                continue;
            }else if(wqpfs(delta)){
                int x11 = (-b+sqrt(delta))/2*a;
                int x22 = (-b-sqrt(delta))/2*a;
                rational(max(x11, x22),delta,a,b);
                continue;
            }else{

            }
        }
        return 0;
    }
