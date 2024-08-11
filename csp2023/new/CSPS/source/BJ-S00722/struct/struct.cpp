#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <map>
using namespace std;
const int NR = 2e6 + 5;
int pos = 0;
int main()
{
    //freopen("game2.in", "r", stdin);
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            
        }
        else if(op == 2)
        {
            string t, n;
            cin >>t>> n;
            int bt = 0;
            if(t == "byte") bt = 1;
            else if(t == "short") bt = 2;
            else if(t == "int") bt = 4;
            else bt = 8;
            pos = pos +(pos % bt);
            cout << pos << endl;
        }
        else if(op == 3)
        {
            string s;
            cin >> s;
        }
        else if(op == 4)
        {
            
        }
    }
    return 0;
}
