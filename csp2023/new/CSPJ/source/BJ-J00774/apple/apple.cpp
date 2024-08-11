# include<iostream>
# include<algorithm>
# include<cmath>
# define endl "\n"
# define int long long
using namespace std;
const int maxn=10000001;
int n, nex[maxn], last[maxn], now, lef, tmp;
signed main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    lef=n; now=1;
    for(int i=0; i<=n-1; i++) {
        nex[i]=i+1;
        last[i+1]=i;
    }
    nex[n]=0;
    last[1]=0;
    int i;
    for(i=1; lef>0; i++) {
        now=nex[0];
        while(true) {
            lef--;
            if(now==n) tmp=i;
            if(lef==0) break;
            int ll=last[now], nn=nex[now];
            nex[ll]=nn; last[nn]=ll;
            now=nex[now];
            if(now==0) break;
            now=nex[now];
            if(now==0) break;
            now=nex[now];
            if(now==0) break;
        }
    }
    cout << i-1 << " " << tmp << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
