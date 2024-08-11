#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e6+10;
int n, cnt, kt, p1, p2, p;
char s[MAX_N],t[MAX_N];

bool pop() {
    kt = -1;
    for (p=p1; p<=p2; p++) {
        if (kt != -1 && t[kt] == s[p]) {
            kt--;
        } else {
            kt++;
            t[kt] = s[p];
        }
    }
    if (kt == -1) return true;
    return false;
}


int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);


    scanf("%d\n", &n);
    for (int i=0; i<n; i++) {
        scanf("%s", s);
    }

    for (p1=0; p1<n; p1++) {
        for (p2=p1; p2<n; p2++) {
            if (pop()) {
                cnt++;
                //for (int p=p1; p<=p2; p++) {
                 //   cout << s[p];
                //}
                //cout<<endl;
            }
        }
    }

    printf("%d", cnt);
    return 0;
}
