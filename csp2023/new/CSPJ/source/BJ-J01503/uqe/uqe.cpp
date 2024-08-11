#include <bits/stdc++.h>
using namespace std;
int T,M;
int a[5000],b[5000],c[5000];

int panbieshi(int a1,int b1,int c1) {
    int derta = b1*b1-4*(a1*c1);
    if(derta < 0)
        return 0;
    if(derta == 0)
        return 1;
    if(derta > 0) {
        return 2;
    }
}
int jisuan(int a1,int b1,int c1) {
    int x1 = (-1*b1+sqrt(b1*b1-4*(a1*c1)))/2*a1;
    int x2;
    if(b1*b1-4*(a1*c1)==0) {
        x2 = x1;
    }
    else {
        x2 = (-1*b1-sqrt(b1*b1-4*(a1*c1)))/2*a1;
    }
    return max(x1,x2);
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin >> T >> M;
    for(int i = 0;i < T;i++) {
        cin >> a[i] >> b[i]  >> c[i];
    }
    for(int i = 0;i < T;i++) {
        if(panbieshi(a[i],b[i],c[i]) == 0) {
            cout << "NO";
        }
        else {
            cout << jisuan(a[i],b[i],c[i]);
        }
        cout << endl;
    }
    return 0;
}
