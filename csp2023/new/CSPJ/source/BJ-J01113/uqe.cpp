#include<iostream>
using namespace std;

int main()
{
    int T,M;
    cin >> T >> M;
    for(int i = 1; i <= T; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        double derta = b * b - 4 * a * c;
        if(derta < 0)
        {
            cout << "NO" << endl;
            break;
        }
        else
        {
            if(sqrt(derta) * sqrt(derta) == derta) cout << (sqrt(derta) - b) / 2 / a << endl;
            else cout << "(sqrt(derta) - b) / 2 / a" << endl;
        }
    }
    return 0;
}
