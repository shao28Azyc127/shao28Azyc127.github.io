# include <iostream>
# include <cmath>
using namespace std;

void dis();
void del(int i);
int n, len, ans = 1, lst[1000001], dayn = 0;
bool flag = true;

int main()
{
    cin >> n;
    len = n;
    for (int i = 0; i < len; i++) {
        lst[i] = i+1;
    }
    while (flag) {
        int i = 0;
        while (i < len) {
            del(i);
            i += 2;
        }
        int t = 0;
        bool findn = false;
        for (int i = 0; i < len; i++) {
            t += lst[i];
            if (lst[i] == len)
                findn = true;
        }
        if (t == 0) flag = false;
        else ans++;
        if (!findn) dayn = ans;
    }
    if (n % 3 == 1) dayn = 1;
    cout << ans << " " << dayn;
    return 0;
}

void del(int i) {
    for (int j = i; j < len; j++)
        lst[j] = lst[j+1];
    len--;
}
