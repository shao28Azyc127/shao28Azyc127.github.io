#include <iostream>
using namespace std;
int n, cnt;
bool shinianOIyichangkongshuzukaidajianzuzong[2000005];
string a;
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n;
    cin >> a;
    int x = 1, y = x + 1;
    bool flag = false;
    while(y < n - 1) {
        if(!shinianOIyichangkongshuzukaidajianzuzong[x] && shinianOIyichangkongshuzukaidajianzuzong[y]) {
            y++;
        }
        if(shinianOIyichangkongshuzukaidajianzuzong[x] && !shinianOIyichangkongshuzukaidajianzuzong[y]) {
            x++;
            y++;
        }
        if(shinianOIyichangkongshuzukaidajianzuzong[x] && shinianOIyichangkongshuzukaidajianzuzong[y]) {
            x = x + 2;
            y = y + 2;
        }
        if(!shinianOIyichangkongshuzukaidajianzuzong[x] && !shinianOIyichangkongshuzukaidajianzuzong[y]) {
            cnt++;
            shinianOIyichangkongshuzukaidajianzuzong[x] = true;
            shinianOIyichangkongshuzukaidajianzuzong[y] = true;
        }
    }

    cout << cnt << endl;
    return 0;
}
