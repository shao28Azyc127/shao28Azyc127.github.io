#include <iostream>
using namespace std;

int main()
{
    int T, M;
    cin >> T >> M;
    while(T--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(b * b - 4 * a * c < 0)
        {
            cout << "NO\n";
            continue;
        }
    }
    return 0;
}