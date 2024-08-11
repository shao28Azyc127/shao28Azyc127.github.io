    #include<bits/stdc++.h>
    #include<stdio.h>

    using namespace std;

    int gcd(int p, int q)
    {
        int z = 1;
        if ( p >= q){
            for (int i = q; i >= 1; i--){
                if (p % i == 0 && q % i == 0){
                    z = i;
                    break;
                }
            }
        }else{
            for (int i = p; i >= 1; i--){
                if (p % i == 0 && q % i == 0){
                    z = i;
                    break;
                }
            }
        }
        return z;
    }

    int main(){
        freopen("uqe.in", "r", stdin);
        freopen("uqe.out", "w", stdout);
        int m, t;
        cin >> t >> m;
        int a, b, c;
        int delta, q1, q2, q3, r, d, s, p, q;
        for (int i = 1; i <= t; i++)
        {
            cin >> a >> b >> c;
            delta = (b*b) - (4*a*c);
            if (b/a >= 0 && c == 0)
                cout << 0 << endl;
            else if(delta < 0)
                cout << "NO" << endl;
            else
            {
                s = sqrt(delta);
                if (s^2 == delta)
                {
                    p = s-b;
                    q = 2*a;
                    if (gcd(p, q) == q)
                        cout << p/q;
                    else
                        cout << p/gcd(p, q) << "/" << q/gcd(p, q);
                }
                else{
                    if (b != 0)
                        cout << -b/(2*a) << "+" << "sqrt(" << delta << ")/" << (2*a);
                    else
                        cout << "sqrt(" << delta << ")/" << (2*a);
                }
            }
        }
        fclose(stdin);
        fclose(stdout);
        return 0;
    }

