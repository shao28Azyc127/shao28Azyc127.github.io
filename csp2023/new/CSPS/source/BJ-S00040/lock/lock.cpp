#include <bits/stdc++.h>

using namespace std;

int a[5], t[5], b[10][10][10][10][10], cnt,n;

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<5; j++) {
            cin >> a[j];
        }


        for (int k=0; k<5; k++) {
            for (int j=0; j<5; j++) t[j] = a[j];
            for (int j=1; j<10; j++) {
                t[k] = (a[k] + j) % 10;
                b[t[0]][t[1]][t[2]][t[3]][t[4]] += 1;
                if (b[t[0]][t[1]][t[2]][t[3]][t[4]] == n) {
                    cnt += 1;
                    for (int m=0;m<5;m++) cout << t[m] << " ";
                    cout << endl;
                }

            }
        }


        for (int k=0; k<4; k++) {
            for (int j=0; j<5; j++) t[j] = a[j];
            for (int j=1; j<10; j++) {
                t[k] = (a[k] + j) % 10;
                t[k+1] = (a[k+1] + j) % 10;
                b[t[0]][t[1]][t[2]][t[3]][t[4]] += 1;
                if (b[t[0]][t[1]][t[2]][t[3]][t[4]] == n) {
                    cnt += 1;
                    for (int m=0;m<5;m++) cout << t[m] << " ";
                    cout << endl;
                }
            }
        }
    }


    cout << cnt;

    return 0;
}
