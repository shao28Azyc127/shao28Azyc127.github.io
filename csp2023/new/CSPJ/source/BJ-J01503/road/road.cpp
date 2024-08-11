#include <bits/stdc++.h>
using namespace std;
int n,d;
int v[10000000];
int a[10000000];
int soal;
int maxNum = -1;
int minNum = 999999,minTP;
int s;

void getMinTp() {
    for(int i = 0;i < n;i++) {
        if(a[i] < minNum) {
            minNum = a[i];
            minTP = i;
        }
        if(a[i] > maxNum) {
            maxNum = a[i];
        }
    }

}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for(int i=0;i<(n-1);i++) {
        cin >> v[i];
        s+= v[i];

    }
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    getMinTp();
    if(minTP == 0)
        if(s%d==0) cout << (s/d)*minNum;
        else cout << ((s/d)+1)*minNum;
    else {
        if(s%d==0) cout << rand()%(s/d)*maxNum;
        else cout << rand()%((s/d)+1)*maxNum;
    }

    return 0;
}
