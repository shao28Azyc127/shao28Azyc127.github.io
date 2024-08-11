#include<bits/stdc++.h>
using namespace std;

int t, m;
int a, b, c;
int d;

int gcd(int a, int b){
    if(a == 0) return b;
    if(a == 1) return 1;
    return gcd(min(b-a,a), max(b-a,a));

}

int check(int x){
    for(int i=(int)(sqrt(x));i>1;i--){
        if(x%(i*i) == 0) return i;
    }
    return 0;
}

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> t >> m;
    while(t--){
        cin >> a >> b >> c;
        d = b*b-4*a*c;
        //printf("%d %d %d\n", a, b, c);
        if(d < 0){
            cout << "NO" << endl;
            continue;
        }
        else if(d == 0){

            int a1 = -b, a2 = 2*a;
            int f = gcd(min(abs(a1), abs(a2)), max(abs(a1), abs(a2)));
            if(a1 == 0) cout << 0 <<endl;
            else if(abs(a1) == abs(a2)) cout << a1/a2 << endl;
            else if(a2 == 1) cout << a1 << endl;
            else if(a2 == -1) cout << -a1 << endl;
            else{
                if(a1 < 0 && a2 < 0) cout << abs(a1/f) + "/" + abs(a2/f);
                else cout << a1/f << "/" << a2/f << endl;
            }
        }
        else{

            if((int)sqrt(d)*(int)sqrt(d) == d){
                int a1, a2;
                if((-b + (int)sqrt(d)) / 2*a > (-b - (int)sqrt(d)) / 2*a){
                    a1 = -b + (int)sqrt(d), a2 = 2*a;
                }else{
                    a1 = -b - (int)sqrt(d), a2 = 2*a;
                }
                int f = gcd(min(abs(a1), abs(a2)), max(abs(a1), abs(a2)));
                //cout << a1 << " " <<a2 << " ";
                if(a1 == 0) cout << 0 <<endl;
                else if(abs(a1) == abs(a2)) cout << a1/a2 << endl;
                else if(a2 == 1) cout << a1 << endl;
                else if(a2 == -1) cout << -a1 << endl;
                else{
                    if(a1 < 0 && a2 < 0) cout << abs(a1/f) + "/" + abs(a2/f);
                    else cout << a1/f << "/" << a2/f << endl;
                }
            }else{
                if(b != 0){
                    int f = gcd(min(abs(-b), abs(2*a)), max(abs(-b), abs(2*a)));
                    if(abs(-b) == abs(2*a)) cout << -b/(2*a);
                    else if(2*a == 1) cout << -b ;
                    else if(2*a == -1) cout << b ;
                    else{
                        if((-b) < 0 && 2*a < 0) cout << abs(-b/f) + "/" + abs(2*a/f);
                        else cout << -b/f << "/" << 2*a/f ;
                    }
                    if((-b + (int)sqrt(d)) / 2*a > (-b - (int)sqrt(d)) / 2*a){
                        cout << "+";
                    }else{
                        cout << "-";
                    }
                }
                int x = check(d) ;
                    if(x != 0 && x != 1){
                        int f = gcd(min(abs(x), abs(2*a)), max(abs(x), abs(2*a)));
                        if(abs(x) == abs(2*a)) printf("sqrt(%d)\n", d/(x*x));
                        else{
                            if(x < 0 && 2*a < 0){
                                if(abs(2*a/f) != 1) printf("%d*sqrt(%d)/%d\n", abs(x/f), d/(x*x), abs(2*a/f));
                                else printf("%d*sqrt(%d)\n", abs(x/f), d/(x*x));
                            }
                            else{
                                if(abs(2*a/f) != 1) printf("%d*sqrt(%d)/%d\n", x/f, d/(x*x), 2*a/f);
                                else printf("%d*sqrt(%d)/\n", x/f, d/(x*x));

                            }
                        }
                    }else{
                       printf("sqrt(%d)/%d\n", d, 2*a);
                    }
            }
        }

    }
    return 0;
}
