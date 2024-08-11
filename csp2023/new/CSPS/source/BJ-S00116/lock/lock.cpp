#include <iostream>
#include <cstdio>
#include <map>
#include <set>
using namespace std;
int n;
map<int,int> mp;
int aaa[10];
int main(void) {
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=1,a,b,c,d,e,g;i<=n;i++) {
        set<int> se;
        cin >> a >> b >> c >> d >> e;
        g=a*10000+b*1000+c*100+d*10+e;
        aaa[i]=g;
        se.insert(g);
        for (int i=1;i<=10;i++) {
            int aa=a,bb=b,cc=c,dd=d,ee=e;
            aa+=i+1000;
            bb+=i+1000;
            aa%=10;
            bb%=10;
            g=aa*10000+bb*1000+cc*100+dd*10+ee;
            if (!se.count(g)) {
                se.insert(g);
                mp[g]++;
            }
            aa=a,bb=b,cc=c,dd=d,ee=e;
            aa-=i;
            bb-=i;
            aa+=1000;
            bb+=1000;
            aa%=10;
            bb%=10;
            g=aa*10000+bb*1000+cc*100+dd*10+ee;
            if (!se.count(g)) {
                se.insert(g);
                mp[g]++;
            }
        }
        for (int i=1;i<=10;i++) {
            int aa=a,bb=b,cc=c,dd=d,ee=e;
            bb+=i+1000;
            cc+=i+1000;
            bb%=10;
            cc%=10;
            g=aa*10000+bb*1000+cc*100+dd*10+ee;
            if (!se.count(g)) {
                se.insert(g);
                mp[g]++;
            }
            aa=a,bb=b,cc=c,dd=d,ee=e;
            bb-=i;
            cc-=i;
            bb+=1000;
            cc+=1000;
            bb%=10;
            cc%=10;
            g=aa*10000+bb*1000+cc*100+dd*10+ee;
            if (!se.count(g)) {
                se.insert(g);
                mp[g]++;
            }
        }
        for (int i=1;i<=10;i++) {
            int aa=a,bb=b,cc=c,dd=d,ee=e;
            cc+=i+1000;
            dd+=i+1000;
            cc%=10;
            dd%=10;
            g=aa*10000+bb*1000+cc*100+dd*10+ee;
            if (!se.count(g)) {
                se.insert(g);
                mp[g]++;
            }
            aa=a,bb=b,cc=c,dd=d,ee=e;
            cc-=i;
            dd-=i;
            cc+=1000;
            dd+=1000;
            cc%=10;
            dd%=10;
            g=aa*10000+bb*1000+cc*100+dd*10+ee;
            if (!se.count(g)) {
                se.insert(g);
                mp[g]++;
            }
        }
        for (int i=1;i<=10;i++) {
            int aa=a,bb=b,cc=c,dd=d,ee=e;
            dd+=i+1000;
            ee+=i+1000;
            dd%=10;
            ee%=10;
            g=aa*10000+bb*1000+cc*100+dd*10+ee;
            if (!se.count(g)) {
                se.insert(g);
                mp[g]++;
            }
            aa=a,bb=b,cc=c,dd=d,ee=e;
            dd-=i;
            ee-=i;
            dd+=1000;
            ee+=1000;
            dd%=10;
            ee%=10;
            g=aa*10000+bb*1000+cc*100+dd*10+ee;
            if (!se.count(g)) {
                se.insert(g);
                mp[g]++;
            }
        }
        for (int i=0;i<=9;i++) {
            if (i==a) continue;
            g=i*10000+b*1000+c*100+d*10+e;
            mp[g]++;
            se.insert(g);
        }
        for (int i=0;i<=9;i++) {
            if (i==b) continue;
            g=a*10000+i*1000+c*100+d*10+e;
            mp[g]++;
            se.insert(g);
        }
        for (int i=0;i<=9;i++) {
            if (i==c) continue;
            g=a*10000+b*1000+i*100+d*10+e;
            mp[g]++;
            se.insert(g);
        }
        for (int i=0;i<=9;i++) {
            if (i==d) continue;
            g=a*10000+b*1000+c*100+i*10+e;
            mp[g]++;
            se.insert(g);
        }
        for (int i=0;i<=9;i++) {
            if (i==e) continue;
            g=a*10000+b*1000+c*100+d*10+i;
            mp[g]++;
            se.insert(g);
        }
    }
    int ans=0;
    for (auto it:mp) {
        bool is=false;
        for (int i=1;i<=n;i++) if (it.first==aaa[i]) is=true;
        if (is) continue;
        if (it.second==n) ans++;
    }
    cout << ans;
    return 0;
}