#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 3050;
int n, m;
struct words{
    string si;
    int id;
    bool operator <(const words& x) const{
        return si < x.si;
    }
}c[MAXN], mxc[MAXN], mic[MAXN];
bool cmp1(char a, char b)
{
    return a < b;
}
bool cmp2(char a, char b)
{
    return a > b;
}
int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        cin >> c[i].si;
        c[i].id = i;
        mxc[i].si = c[i].si, mxc[i].id = i;
        mic[i].si = c[i].si, mxc[i].id = i;
        sort(mic[i].si.begin(), mic[i].si.end(), cmp1);
        sort(mxc[i].si.begin(), mxc[i].si.end(), cmp2);
        //cout << mic[i].si << "  " << mxc[i].si << "\n";
    }
    sort(mxc + 1, mxc + 1 + n);
    for(int i = 1; i <= n; i++){
        if(mic[i].si < mxc[1].si || (mic[i].id == mxc[1].id && mxc[1].si < mxc[2].si) || n == 1) printf("1");
        else printf("0");
    }
    return 0;
}