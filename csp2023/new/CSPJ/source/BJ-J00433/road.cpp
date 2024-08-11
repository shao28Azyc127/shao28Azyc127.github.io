// 2023/10/21 10:40
// By Jerry1031
//freopen checked!
// ע��Ӧ����д���İɣ�

#include <iostream>
#include <cmath>
using namespace std;

#define int long long
// ����OIһ���գ�����long long ������

int v[100005], a[100005];
int s[100005]; // ·��ǰ׺��
bool f[100005]; // �ͼ��Ƿ�Ϊ��ǰ��Сֵ
signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, d;
    cin >> n >> d;
    int l = 0, mina = 1e9;
    for(int i = 1; i < n; i++)
    {
        cin >> v[i];
        l += v[i];
        s[i] = s[i - 1] + v[i - 1];
    }
    s[n] = s[n - 1] + v[n - 1];
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(a[i] < mina)
        {
            mina = a[i];
            f[i] = true;
        }
    }

    f[n] = true;

    if(mina == a[1]) // A
    {
        cout << (long long)(ceil(1. * l / d)) * mina << endl;
        return 0;
    }

    int ans = 0;
    double lft = 0; //Ŀǰ��ʣ����
    for(int i = 1; i < n; i++) // ��Ȼ���һ��վ�㲻�ü���
    {
        if(f[i]) // ��ǰΪ�ͼ���Сֵ����Ҫ����
        {
            int j = i + 1;
            while(!f[j])
                j++;
            int k = s[j] - s[i]; // ������һ�����͵��·��

            int need = ceil(((k - lft * d) / d)); //Ŀǰ��Ҫ�����
            ans += need * a[i]; // �����ͼ�
            lft += need - 1. * k / d;
        }
    }
    cout << ans << endl;
    return 0;
}
