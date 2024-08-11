#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb emplace_back
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x; cin >> x;
    int ans1, ans2 = 0;
    for (ans1 = 1; x; ans1++){
        if (x % 3 == 1 && !ans2) ans2 = ans1;
        x -= (x + 2) / 3;
    }
    cout << ans1 - 1 << ' ' << ans2 << '\n';
}
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb emplace_back
int N[] = {-1, 10, 10, 1000, 1000, 1000, 1000000, 1000000, 1000000, 1000000, (int)1e9};
char name[25];
int Rand(){
    if (RAND_MAX == 32767) return (rand() << 15) + rand();
    else return rand();
}
int main(){
    srand(time(0));
    for (int i = 1; i <= 10; i++){
        sprintf(name, "apple%d.in", i);
        freopen(name, "w", stdout);
        int t = Rand() % N[i] + 1;
        if (i == 6 || i == 7){
            while (t % 3 != 1 || t < N[i] / 2) t = Rand() % N[i] + 1;
        }
        else{
            while (t % 3 == 1 || t < N[i] / 2) t = Rand() % N[i] + 1;
        }
        cout << t;
        fclose(stdout);
    }
}


*/
