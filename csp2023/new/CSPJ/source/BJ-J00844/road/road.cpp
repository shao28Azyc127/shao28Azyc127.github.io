#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int SZ = 100005;
int v[SZ] , a[SZ];
long long sv[SZ] , f[SZ] , re[SZ];

int main()
{
    ifstream fin("road.in");
    ofstream fout("road.out");
    memset(f , 0x7f , sizeof(f));
    f[0] = f[1] = 0;
    int n , d;
    fin >> n >> d;
    for(int i = 2;i <= n;i++)
    {
        fin >> v[i];
        sv[i] = sv[i - 1] + v[i];
    }
    for(int i = 1;i <= n;i++) fin >> a[i];
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j < i;j++)
        {
            long long t1 = f[j] + ((sv[i] - sv[j] - re[j] - 1) / d + 1) * a[j];
            long long t2;
            if(sv[i] - sv[j] - re[j] > 0) t2 = ((sv[i] - sv[j] - re[j] - 1) / d + 1) * d - (sv[i] - sv[j] - re[j]);
            else t2 = re[j] - (sv[i] - sv[j]);
            if(f[i] > t1){f[i] = t1;re[i] = t2;}
            else if (f[i] == t1 && re[i] < t2) re[i] = t2;
        }
    }
    fout << f[n] << endl;
    /*for(int i = 1;i <= n;i++) cout << f[i] << " ";
    cout << endl;
    for(int i = 1;i <= n;i++) cout << re[i] << " ";
    cout << endl;*/
    return 0;
}