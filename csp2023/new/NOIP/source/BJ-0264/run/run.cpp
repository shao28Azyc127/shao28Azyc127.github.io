#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    srand(time(0));
    cout << rand() % 20 << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

