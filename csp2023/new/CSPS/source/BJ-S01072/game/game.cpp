#include <bits/stdc++.h>
/*
    long long
    freopen
*/
using namespace std;

int const N = 2e6 + 10;

int n, ans;
char a[N];

bool f(int l, int r){
    stack <char> st;
    st.push(a[l]);
    for (int i = l + 1;i <= r;++i){
        if (st.size() != 0){
            char t = st.top();
            if (a[i] == t)
                st.pop();
            else st.push(a[i]);
        }
        else st.push(a[i]);
    }
    return st.empty();
}

int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d", &n);
    scanf("%s", a);
    for (int i = 0;i < n;++i){
        for (int j = i;j < n;++j){
            if (f(i, j) == 1) ans ++;
        }
    }
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
