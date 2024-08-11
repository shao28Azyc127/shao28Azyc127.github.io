#include <bits/stdc++.h>
#define N 2000010
using namespace std;
string a;
queue < pair <int, int> > que;
vector < pair <int, int> > vect;
map < pair <int, int> , int> ma;
bool cmp(pair <int, int> aa, pair <int, int> bb)
{
    if (aa.first != bb.first)
    {
        return aa.first < bb.first;
    }
    else
    {
        return aa.second < bb.second;
    }
}
int n;
void bfs()
{
    for (int i = 0; i < n-1; i ++)
    {
        if (a[i] == a[i + 1])
        {
            que.push({i, i + 1});
        }
    }
    while (que.size())
    {
        pair <int, int> tmp = que.front();
        vect.push_back(tmp);
        que.pop();
        if (a[tmp.first - 1] == a[tmp.second + 1])
        {
            que.push({tmp.first-1, tmp.second+1});
        }
    }
}
void pinjie()
{
    sort(vect.begin(), vect.end(), cmp);
    for (int i = 0; i < vect.size(); i ++)
    {
        for (int j = 0; j < vect.size(); j ++)
        {

            if (vect[j].first - 1 == vect[i].second && i != j && vect[j].second > vect[i].first) vect.push_back({vect[i].first, vect[j].second});
        }
    }
    //cout << "vect.size() = " << vect.size() << endl;
    //for (int i = 0; i < vect.size(); i ++) cout << "{"<<vect[i].first<<", "<<vect[i].second<<"}"<<endl;
}
int qvchong()
{
    for (int i = 0; i < vect.size(); i ++)//tongpaixv
    {
        ma[vect[i]] ++;
    }
     return ma.size();
}
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n;
    cin >> a;
    bool flag=0;
    if (n==2&&a[0]==a[1]){
        cout<<1<<endl;
        return 0;
    }
    for (int i = 0; i < n-1; i ++)
    {
        if (a[i] == a[i + 1])
        {
            flag=1;
        }
    }
    if (flag==0){
        cout<<0<<endl;
        return 0;
    }
    bfs();
    pinjie();
    cout << qvchong() << endl;
    return 0;
}
