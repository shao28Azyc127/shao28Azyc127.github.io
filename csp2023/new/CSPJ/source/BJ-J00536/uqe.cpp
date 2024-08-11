#include<bits/stdc++.h>
using namespace std;
int t, m;
int find(int searchh){
    for(int i = sqrt(searchh); i >= 1; i --){
        if(searchh % (i * i) == 0){
            return i;
        }
    }
}
int anotherfind(int x, int y){
    int minn = min(abs(x), abs(y));
    for(int i = minn; i >= 1; i --){
        if(abs(x) % i == 0){
            if(abs(y) % i == 0){
                return i;
            }
        }
    }
}
int main(){
    freopen("uqe.in" ,  "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> t >> m;
    while(t--){
        int derta, a, b, c, q, qq, sq;
        bool neg = false;
        cin >> a >> b >>c;
        derta = b *b - 4 * a * c;
        if(derta < 0){
            cout << "No" << endl;
        }
        else{
            if(b != 0){
                if(abs(b) % abs(2*a) == 0){
                    q = -b/(2*a);
                    cout <<q;
                }
                else{
                    if(b < 0){
                        if(neg == false){
                            neg = true;
                        }
                        else{
                            neg = false;
                        }
                    }
                    if(a < 0){
                        if(neg == false){
                            neg = true;
                        }
                        else{
                            neg = false;
                        }
                    }
                    int x = anotherfind(b, 2*a);
                    if(x != 1){
                        if(neg = true){
                            cout <<"-" <<abs(b)/x <<"/"<<abs(2 * a)/x;
                        }
                        else{
                            cout <<abs(b)/x <<"/"<<abs(2 * a)/x;
                        }
                    }
                    else{
                        if(neg = true){
                            cout <<"-" <<abs(b) <<"/"<<abs(2 * a);
                        }
                        else{
                            cout <<abs(b) <<"/"<<abs(2 * a);
                        }
                    }

                }
            }
            if(derta != 0){
                qq = find(derta);
                sq = derta / (qq *qq);
                if(qq % (a*2) == 0){
                    if(qq / (a*2) != 1){
                        if(sq == 1){
                            cout <<"+"<< qq<<endl;
                        }else{
                            cout <<"+"<< qq << "*sqrt(" << sq << ")"<<endl;
                        }
                    }else{
                        if(sq == 1){
                            cout <<"+"<< 1<<endl;
                        }else{
                            cout<<"+sqrt("<<sq<<")"<<endl;
                        }
                    }
                }
                else{
                    if(qq != 1){
                        if(sq == 1){
                            cout <<"+"<< qq << "/" << abs(2*a)<<endl;
                        }else{
                            cout <<"+"<< qq << "*sqrt(" << sq << ")/" << abs(2*a)<<endl;
                        }

                    }else{
                        if(sq == 1){
                            cout<<"+"<<sq<<"/"<<abs(2*a)<<endl;
                        }else{
                            cout<<"+sqrt("<<sq<<")/"<<abs(2*a)<<endl;
                        }

                    }
                }
            }else{
                cout << endl;
            }
        }
    }

    return 0;
}