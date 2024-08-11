#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
int a[MAXN],b[MAXN];
int c,n,m,q;
int achp[MAXN];
int achv[MAXN];
int bchp[MAXN];
int bchv[MAXN];
//bool finding[MAXN][MAXN];
bool findab()
{
   // memset(finding,0,sizeof(finding));
    int cab1 = a[1] - b[1],cab2 = a[n] - b[m];
    //cout << endl << cab1 << " " << cab2 << endl;
    if((long long)(cab1)*(long long)(cab2) <= 0) return 0;
    if(cab1 < 0) swap(a,b);
/*
    for(int i = 1;i <= n;i++) cout << a[i] << " ";
    cout << endl;
    for(int i = 1;i <= m;i++) cout << b[i] << " ";
    cout << endl;
*/


    int nfp = 0;//no fog place 1->nfp+1 visuable
    for(int i = 1;i <= n;i++)
    {
        int farest = 0;
        for(int j = 1;j <= nfp+1 && j <= m;j++)
        {
            if(a[i] <= b[j])
                continue;
            farest = j;
            if(j == nfp+1) nfp++;

           // finding[i][j] = 1;

        }
        nfp = farest;
        if(nfp == 0)
        break;
    }
/*
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
            cout << finding[i][j];
        cout << endl;
    }*/
    if(cab1 < 0) swap(a,b);
    if(nfp == m) return 1;
    return 0;
}

int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin >> c >> n >> m >> q;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    for(int i = 1;i <= m;i++)
        cin >> b[i];
    cout << findab();
   // cout << endl;
    while(q--)
    {
        memset(achp,0,sizeof(achp));
        memset(achv,0,sizeof(achv));
        memset(bchp,0,sizeof(bchp));
        memset(bchv,0,sizeof(bchv));
        int kx,ky; cin >> kx >> ky;
        for(int i = 1;i <= kx;i++)
        {
            int px,vx; cin >> px >> vx;
            achp[i] = px; achv[i] = a[px];
            a[px] = vx;
        }
        for(int i = 1;i <= ky;i++)
        {
            int py,vy; cin >> py >> vy;
            bchp[i] = py; bchv[i] = b[py];
            b[py] = vy;
        }
        cout << findab();
       // cout << endl;
        for(int i = 1;i <= kx;i++)
            a[achp[i]] = achv[i];
        for(int i = 1;i <= ky;i++)
            b[bchp[i]] = bchv[i];
    }
    return 0;
}