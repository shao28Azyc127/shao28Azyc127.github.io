#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int NMAX=3e3+10;

char buff[NMAX];
bool ans[NMAX];
int a[NMAX][30];

int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++){
        scanf(" %s",buff);
        for (int j=0;j<m;j++){
            a[i][buff[j]-'a']++;
        }
    }
    for (int i=0;i<n;i++){
        ans[i]=1;
        for (int j=0;j<n;j++){
            if (i==j) continue;
            int mi=0,mj=25;
            while (a[i][mi]==0) mi++;
            while (a[j][mj]==0) mj--;
            if (mi>=mj){
                ans[i]=0;
                break;
            }
        }
    }
    for (int i=0;i<n;i++){
        printf(ans[i] ? "1" : "0");
    }
    printf("\n");
    return 0;
}
