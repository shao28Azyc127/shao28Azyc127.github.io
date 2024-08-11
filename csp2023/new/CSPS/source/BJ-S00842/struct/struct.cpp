#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int n;
long long t = 0;
vector<pair<long long, pair<string, int> > > x;
int main(){
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    cin >>n;
    while(n--){
        int op;
        cin >> op;
        if(op == 2){
            string a, b;
            cin >> a >> b;
            if(a == "byte"){
                x.push_back(make_pair(t, make_pair(b, 1)));
                cout << t << endl;
                t++;
            }
            if(a == "short"){
                if(t % 2 == 0){
                    x.push_back(make_pair(t, make_pair(b, 2)));
                    cout << t << endl;
                    t = t + 2;
                } else{
                    x.push_back(make_pair(t / 2 * 2 + 2, make_pair(b, 2)));
                    cout << t / 2 * 2 + 2 << endl;
                    t = t / 2 * 2 + 4;
                }
            }
            if(a == "int"){
                if(t % 4 == 0){
                    x.push_back(make_pair(t, make_pair(b, 4)));
                    cout << t << endl;
                    t = t + 4;
                } else{
                    x.push_back(make_pair(t / 4 * 4 + 4, make_pair(b, 4)));
                    cout << t / 4 * 4 + 4 << endl;
                    t = t / 4 * 4 + 8;
                }
            }
            if(a == "long"){
                if(t % 8 == 0){
                    x.push_back(make_pair(t, make_pair(b, 8)));
                    cout << t << endl;
                    t = t + 8;
                } else{
                    x.push_back(make_pair(t / 8 * 8 + 8, make_pair(b, 8)));
                    cout << t / 8 * 8 + 8 << endl;
                    t = t / 8 * 8 + 16;
                }
            }
        }
        if(op == 3){
                string a;
        cin >> a;
            for(int i = 0; i < x.size(); i++){
                if(x[i].second.first == a){
                    cout << x[i].first << endl;
                    break;
                }
            }
        }
        if(op == 4){
                long long a;
        cin >> a;
            long long d = -1;
            for(int i = 0; i < x.size(); i++){
                if(x[i].first > a){
                    d = i - 1;
                    break;
                }
            }
            if(d != -1){
                if(x[d].first + x[d].second.second > a)
                    cout << x[d].second.first << endl;
                else
                    cout << "ERR\n";
            } else{
                cout << "ERR\n";
            }
        }
    }
    return 0;
}
