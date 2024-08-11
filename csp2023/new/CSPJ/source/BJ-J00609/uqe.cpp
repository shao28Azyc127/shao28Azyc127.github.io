#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;


int main()
{

    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,M;
    cin >> T >> M;
    for (int i = 1; i <= T; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        if (b * b - 4 * a * c < 0)
        {
            cout <<"NO" << endl;
        }
        else
        {
            double b1= (-b + sqrt(b*b-4*a*c)) / (2 * a);
            double b2= (-b - sqrt(b*b-4*a*c)) / (2 * a);
            cout << max(b1,b2) << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}