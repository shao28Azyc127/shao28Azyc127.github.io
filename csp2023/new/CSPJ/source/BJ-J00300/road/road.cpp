#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin >> n >> d;
    bool equali = true;
    int r[n + 10],pr[n + 10];
    int tag[n + 10];
    tag[1] = 0;
    tag[0] = 0;
    int all = 0;
    for(int i = 1;i < n;i++){
        cin >> r[i];
        tag[i + 1] = tag[i] + r[i];
        all += r[i];
        if(r[i] % d != 0){
            equali = false;
        }
    }
    int mi = INT_MAX;
    for(int i = 1;i <= n;i++){
        cin >> pr[i];
        mi = min(mi,pr[i]);
    }
    if(pr[1] == mi){
        if(all % d == 0){
            cout << all / d * pr[1];
        }
        else{
            cout << all / d * pr[1] + pr[1];
        }
        return 0;
    }
    if(equali){
        long long an = 0;
        int i = 1;
        int nowr = 0;
        while(pr[i] != mi && i < n){
            an += r[i] / d * pr[i];
            nowr += r[i];
            i += 1;
        }
        an += (n - i) * (all - nowr) / d * pr[i];
        cout << an;
        return 0;
    }
    int i = 1;
    long long an = 0;
    int canrun = 0;
    while(i != n){
        int nowp = pr[i];
        int z = i;
        while(i < n){
            i += 1;
            if(pr[i] < nowp){
                break;
            }
        }
        if((tag[i] - tag[z] - canrun) % d == 0){
            an += (tag[i] - tag[z] - canrun) / d * pr[z];
        }
        else{
            an += (tag[i] - tag[z] - canrun) / d * pr[z] + pr[z];
            canrun += ((tag[i] - tag[z] - canrun) / d + 1) * d - (tag[i] - tag[z]);
        }
    }
    cout << an;
    return 0;
}
