#ifdef OJ
#include <iostream>
#else
#include <fstream>
#endif

using namespace std;

#ifndef OJ
ifstream cin("apple.in");
ofstream cout("apple.out");
#endif


int x, crsr, vis[1000001];

void next(int &n)
{
    n++;
    while(vis[n]) n++;
    n++;
    while(vis[n]) n++;
    n++;
    while(vis[n]) n++;
}

bool isempty()
{
    for(int i = 0; i < x; i++)
    {
        if(!vis[i]) return false;
    }
    return true;
}

int main(int argc, char **argv)
{
    cin >> x;
    crsr = 0;
    int gotlast, cnt = 0;
    while(!isempty())
    {
        cnt++;
        for(crsr = 0; crsr < x; next(crsr))
        {
            while(vis[crsr]) crsr++;
            if(crsr >= x) break;
            vis[crsr] = true;
            if(crsr == x-1) gotlast = cnt;
        }
    }
    cout << cnt << ' ' << gotlast << endl;
    return 0;
}