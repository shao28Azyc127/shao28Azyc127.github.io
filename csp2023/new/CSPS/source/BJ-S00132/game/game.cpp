#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int read()
{
    register int x = 0, f = 1;
    register char c = getchar();
    while(c < '0' || c > '9')
    {
        if(c == '-')f = -1;
        c = getchar();
    }
    while(c <= '9' && c >= '0')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

//��һ���뵽��չ
//���ݷ�Χֻ֧��O(n)�������ǾͶ���ÿһ����ɾ���ģ�ֻ�������Σ�ɾ��+��ԣ�
//�о�����д���ȿ�T3
//�������ת�����ж��������Ŀ�ɾ������
//��Ҫ�������ҵ�һ�����ɾ��֮�����ͳ�ƴ𰸣��ܼ򵥣��˷�ԭ��
//�ȿ������������T3
//����������ʵ������ַ����Ĳ���

//�۲췢��ɾ��˳��Ӱ���


//15:22 ������Ҫ�����������һ����Ѫ��ϣ���ĵ�ǰ��д��
//ûд�꣬����û�й�ϵ����ʱ��
//��Ҫ��30minд����Ȼ�󿴺����

//������17��39���һ���0��
//�ҿ�ʼ��50������

//50pts:O(1)���ÿһ���Ĵ�
//����O(1)��ǰ����Ƴ�������Ĵ�
//��ô˵�أ����Ƿ���һ�����Ե����䲻һ���п��Ե������䣿
//һ����ֻ��������
//so how??????
//nnd��д35��
//35��û��
//�棡
//���Էֲ�Ƕ��
//ʧ�ܣ�дdfs
//д�꣬��������������С����

char c[2000010];

int ans;

bool f[8018][8018];

bool daoguo[8010][8018];

bool dfs(int l, int r)
{
    if(l >= r)
    {
        f[l][r] = 0;
        return 0;
    }
    if(l + 1 == r)
    {
        if(c[l] == c[r])f[l][r] = 1;
        return f[l][r];
    }
    if(f[l][r])
    {
        return f[l][r];
    }
    for(int i = l;i < r - 1;i++)
    {
        if(dfs(l, i) && dfs(i + 1, r))
        {
            //cout << l << " " << r << " " << i << "\n";
            f[l][r] = 1;
        }
    }
    if(c[l] == c[r] && dfs(l + 1, r - 1))f[l][r] = 1;
    return f[l][r];
}

signed main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    srand(time(0) + 2327);
    int n = read();
    scanf("%s", c + 1);
    dfs(1, n);
    for(int i = 1;i <= n;i++)
    {
        for(int j =i + 1;j <= n;j++)
        {
            if(f[i][j])
            {
                //cout << i << " " << j << "\n";
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}