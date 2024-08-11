#include <iostream>

using namespace std;

const int N = 8e3+5;

int n;
char a[N];
int f[N][N];
int ans = 0;

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    cin >> a+1;
    for(int len = 2;len <= n;len += 2){
        for(int l = 1;l <= n-len+1;l++){
            int r = l+len-1;
            for(int mid = l+1;mid < r-1;mid++){
                if(f[l][mid] && f[mid+1][r]) f[l][r] = 1;
            }
            if(a[l] == a[r] && (len==2 || f[l+1][r-1])) f[l][r] = 1;
        }
    }
    for(int len = 2;len <= n;len += 2){
        for(int l = 1;l <= n-len+1;l++){
            int r = l+len-1;
            if(f[l][r]) ans++;
            //printf("(%d,%d):%d ",l,r,f[l][r]);
        }
        //cout << endl;
    }
    printf("%d\n",ans);
    return 0;
}
