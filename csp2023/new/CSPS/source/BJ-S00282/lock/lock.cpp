#include <iostream>
#include <time.h>
#include <bits/stdc++.h>
using namespace std;
int main()
{
   freopen("lock.in","r",stdin);
freopen("lock.out","w",stdout);

    srand(time(0));
    cout<<rand()%90+80;
    return 0;
}
