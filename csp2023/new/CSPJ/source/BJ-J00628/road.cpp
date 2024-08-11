#include<bits/stdc++.h>
using namespace std;

int xiangshangquzheng(double d)
{
    if(int(d) < d) return int(d) + 1;
    else return d;
}

int main()
{
    ifstream fin("road.in", ios::in);
    ofstream fout("road.out", ios::out);
    int n, d;
    fin >> n >> d;
    int dis[n]; //距离下一站点的距离
    for(int i = 0;i < n - 1;i++) fin >> dis[i];
    dis[n - 1] = 1e9;
    int pri[n], ans = 0, l = -1234567;
    for(int i = 0;i < n;i++) fin >> pri[i];
    for(int i = 0;i < n;i++) //每一个加油站都要遍历
    {
        if(i == n - 1)
        {
            fout << ans << endl;
            return 0;
        }
        int xu_dis = dis[i], old_pri = pri[i], old_i = i;
        while(pri[i + 1] > old_pri)
        {
            xu_dis += dis[i + 1];
            i++;
            if(i == n - 2)
            {
                break;
            }
        }
        if(l != -1234567 && l > 0)
        {
            xu_dis -= l;
        }
        ans += xiangshangquzheng(xu_dis * 1.0 / d) * old_pri;
        l = xiangshangquzheng(xu_dis * 1.0 / d) * d - xu_dis;
    }
    return 0;
}
