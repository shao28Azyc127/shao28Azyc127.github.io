#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int v[N],a[N];
bool r1 = true;

int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    int n,d,vz = 0,need = 0;
    scanf("%d%d",&n,&d);
    for(int i = 1;i < n;i++) {
        scanf("%d",&v[i]);
        vz += v[i];
    }
    for(int i = 1;i <= n;i++) {
        scanf("%d",&a[i]);
    }

    //1 lowest
    for(int i = 1;i <= n;i++) {
        if(a[i] < a[0]) {
            r1 = false;
        }
    }
    if(r1 == true) {
        if(vz % d == 0) {
            need = vz / d;
        }else if(d > vz){
            need = 1;
        }else {
            int need = (vz / d) + 1;
        }
        int mi = need * a[1];
        cout << mi;
        return 0;
    }
    if(r1 == false) {

    }



    return 0;
}
