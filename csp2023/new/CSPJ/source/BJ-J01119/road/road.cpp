#define li unsigned long long int

#ifdef OJ
#include <iostream>
#else
#include <fstream>
#endif
#include <vector>

using namespace std;

#ifndef OJ
ifstream cin("road.in");
ofstream cout("road.out");
#endif

li n, d, p[100001], w[100001];
vector<int> goo;

int main(int argc, char **argv)
{
    cin >> n >> d;
    if(n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    for(int i = 1; i < n; i++) cin >> p[i], p[i] += p[i-1];
    for(int i = 0; i < n; i++) cin >> w[i];
    goo.push_back(0);
    for(int i = 1; i < n; i++)
    {
        if(w[i] < w[goo[goo.size()-1]])
        {
            goo.push_back(i);
        }
    }
    if(goo[goo.size()-1] != n-1) goo.push_back(n-1);
    long double curgas = 0; li tmp;
    li res = 0;
    for(int i = 1; i < goo.size(); i++)
    {
        tmp = p[goo[i]] - p[goo[i-1]];
        if(tmp < curgas*d)
        {
            curgas -= tmp/d;
            continue;
        }
        tmp = ((tmp > curgas*d) ? (tmp - curgas*d) : 0);
        tmp = ((tmp%d == 0) ? tmp/d : (tmp/d+1));
        curgas += tmp;
        res += tmp*w[goo[i-1]];
        tmp = (p[goo[i]] - p[goo[i-1]]);
        curgas -= ((long double)tmp)/d;
    }

    cout << res << endl;
    return 0;
}