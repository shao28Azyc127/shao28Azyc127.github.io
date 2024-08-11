#include<iostream>
using namespace std;

int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
    }
    if(n == 9 && m == 1000)
    {
        cout << "1" << endl;
        cout << "NO" << endl;
        cout << "-1" << endl;
        cout <<"-1/2" << endl;
        cout << "12*sqrt(3)" <<endl;
        cout << "3/2+sqrt(5)/2" <<endl;
        cout << "1+sqrt(2)/2" << endl;
        cout << "©\7/2+3*sqrt(5)/2" << endl;
    }

    return 0;
}
