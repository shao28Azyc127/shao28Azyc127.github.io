#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;

string read()
{
    string an = "";
    char c = getchar();
    while (c < 'a' || c > 'z') c = getchar();
    while (c >= 'a' && c <= 'z')
    {
        an = an + c;
        c = getchar();
    }
    return an;
}

map<string, int> m;

int main()
{
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    m["234234"] = 1;
    cout << m["234234"];// << " " << sta.size();
    m["11"] = 2;
    cout << "    " << m["11"];
    return 0;
}