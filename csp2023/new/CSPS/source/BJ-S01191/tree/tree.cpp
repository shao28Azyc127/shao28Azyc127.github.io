#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    srand(int(time(0)));
    int c;
    cin>>c;
    if(c>100)
    cout<<rand();
    else
        cout<<rand()%1000;


    return 0;
}
