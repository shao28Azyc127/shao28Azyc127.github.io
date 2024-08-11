#include <bits/stdc++.h>

using namespace std;

int zhan_zhuan(int a, int b)
{
    int c;
    while(b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

string i_s(int x)
{
    string s = "";
    stringstream ss;
    ss.clear();
    ss << x;
    ss >> s;
    return s;
}

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int T, M;
    cin >> T >> M;
    while(T--)
    {
        int i, j, k;
        int a, b, c;
        string ans = "";
        cin >> a >> b >> c;

        if(b * b - 4 * a * c < 0)
        {
            cout << "NO" << endl;
            continue;
        }

        int pbs = b * b - 4 * a * c;

        if((int)sqrt(pbs) * (int)sqrt(pbs) == pbs) // neng kai gen
        {
            int fz = -b + sqrt(pbs);
            int fm = 2 * a;

            if(a < 0) fz = -b - sqrt(pbs);


            if(fz % fm == 0)
            {
                ans += i_s(fz / fm);
            }
            else
            {
                int x = zhan_zhuan(fz, fm);

                //if(fz == -4 && fm == 8)
                //{
                    //cerr << x << endl;

                //}

                fz /= x;
                fm /= x;
                if(fm < 0 && fz > 0)
                {
                    fm = -fm;
                    fz = -fz;
                }
                string sfz = i_s(fz);
                string sfm = i_s(fm);
                ans = sfz + '/' + sfm;
            }
        }
        else
        {
            if(b != 0)
            {
                int fz = -b;
                int fm = 2 * a;
                if(fz % fm == 0)
                {
                    ans = i_s(fz / fm);
                }
                else
                {
                    int x = zhan_zhuan(fz, fm);
                    fz /= x;
                    fm /= x;

                    if(fm < 0 && fz > 0)
                    {
                        fz = -fz;
                        fm = -fm;
                    }
                    string sfz = i_s(fz);
                    string sfm = i_s(fm);
                    ans = sfz + '/' + sfm;
                }
                ans += "+";
            }

            int r = b * b - 4 * a * c;
            int xi_shu = 1;
            for(i=2; i<=sqrt(r); i++) // you li gen shi
            {
                if(r % (i * i) == 0)
                {
                    xi_shu *= i;
                    r /= i * i;
                    i--;
                }
            }

            if(a < 0) a = -a;
            double q2 = xi_shu * 1.0 / (2 * a);
            if(q2 == 1)
            {
                ans += "sqrt(" + i_s(r) + ")";
            }
            else if(xi_shu % (2 * a) == 0)
            {
                ans += i_s(xi_shu / (2 * a)) + "*sqrt(" + i_s(r) + ")";
            }
            else if((2 * a) % xi_shu == 0)
            {
                ans += "sqrt(" + i_s(r) + ")/" + i_s((2 * a) / xi_shu);
            }
            else
            {
                int fz = xi_shu;
                int fm = 2 * a;
                int x = zhan_zhuan(fz, fm);
                fz /= x;
                fm /= x;
                ans += i_s(fz) + "*sqrt(" + i_s(r) + ")/" + i_s(fm);
            }
        }

        cout << ans << endl;

    }

    return 0;
}
