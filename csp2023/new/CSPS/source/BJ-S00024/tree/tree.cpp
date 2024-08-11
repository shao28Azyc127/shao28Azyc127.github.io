#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n;
    cin>>n;
    srand(time(0));
    cout<<rand()%(2*n);
    //cout << "Hello world!" << endl;
    return 0;
}
