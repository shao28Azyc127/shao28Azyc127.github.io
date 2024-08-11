#include <cstdio>
#include <vector>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,i;
    scanf("%d",&n);
    vector<int> v;
    for (i=1;i<=n;i++)
    {
        v.push_back(i);
    }
    int day=1,remove_day=-1;
    while (v.size())
    {

        for(i=1;i<=int(v.size());i+=2)
        {
            if (v[i-1]==n)
            {
                remove_day=day;
            }
            v.erase(v.begin()+(i-1));

        }
        day++;
    }
    printf("%d %d",day-1,remove_day);
    return 0;
}
