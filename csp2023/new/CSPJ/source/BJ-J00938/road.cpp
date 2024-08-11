#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+ 10;
struct node{
        int p, w;
}a[N];
long long nx[N], r[N], ans;
int n, d;

int main(){
        freopen("road.in","r",stdin);
        freopen("road.out", "w", stdout);

        cin >> n >> d;
        for(int i = 1; i < n; i++){
                cin >> r[i];
                r[i] += r[i - 1];
        //      cout << r[i] << '\n';
        }
        for(int i = 0; i < n; i++){
                cin >>a[i].p;
                a[i].w = -1;
        }
        for(int i = n - 1; i > 0; i--){
                for(int j = i - 1; j >= 0; j--){
                        if(a[i].p < a[j].p) a[j].w = i;
                }
        }
        bool flag = true;
        for(int i = 0; i < n, flag; i++){
                nx[i] = r[a[i].w] - r[i];
        //      cout << nx[i]<<'\n';
                if(a[i + 1].w == -1) flag = false;
        }

        int o = 0;
        for(int i = 0; i < n - 1; i++){
                if(a[i].w < 0) break;
                if(o < r[i]){
                //      cout << nx[i] <<' ' << o<<'\n';
                        long long v = (nx[i] - o  + d - 1) / d;
                        ans += v * a[i].p;
                        o =  o + v * d - nx[i];
                //      cout << v <<' '<< ans <<' '<< i <<'\n';
                }
                else{
                        o -= r[i];
                }
        }

        cout << ans <<'\n';
        return 0;
 }
                                                                                                                                                                                                                                                                                                                                                                                 