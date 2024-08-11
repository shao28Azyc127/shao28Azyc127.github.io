#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, int> visit;

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n, a, b, c, d, e;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
        string str(5, '\0');
        str[0] = a + '0';
        str[1] = b + '0';
        str[2] = c + '0';
        str[3] = d + '0';
        str[4] = e + '0';
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                char tmp = str[i];
                str[i] = j + '0';
                if (str[i] != tmp)
                {
                    visit[str]++;
                }
                str[i] = tmp;
            }
        }
        for (int i = 0; i < 4; ++i)
        {
            for (int dif = 1; dif < 10; ++dif)
            {
                int tmp1 = str[i] - '0', tmp2 = str[i + 1] - '0';
                int num1 = (tmp1 + dif) % 10;
                int num2 = (tmp2 + dif) % 10;
                str[i] = num1 + '0';
                str[i + 1] = num2 + '0';
                visit[str]++;
                str[i] = tmp1 + '0';
                str[i + 1] = tmp2 + '0';
            }
        }
    }
    int ans = 0;
    for (auto pr : visit)
    {
        if (pr.second == n)
        {
            ++ans;
        }
    }
    printf("%d\n", ans);

}
