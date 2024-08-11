#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,a[10][8];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 5; j++) scanf("%d",&a[i][j]);
    }
    int ans = 0;
    for(int aa = 0; aa <= 9; aa++){
        for(int bb = 0; bb <= 9; bb++){
            for(int cc = 0; cc <= 9; cc++){
                for(int dd = 0; dd <= 9; dd++){
                    for(int ee = 0; ee <= 9; ee++){
                        int locker[7];
                        locker[1] = aa,locker[2] = bb,locker[3] = cc,locker[4] = dd,locker[5] = ee;
                        int unokcnt = 0;
                        for(int i = 1; i <= n; i++){
                            int same_thing = 0;
                            for(int j = 1; j <= 5; j++) same_thing += (locker[j] == a[i][j]);
                            if(same_thing != 3 && same_thing != 4) unokcnt++;
                            if(same_thing == 3){
                                bool nxt = 0;
                                for(int j = 1; j <= 4; j++) if(locker[j] != a[i][j] && locker[j+1] != a[i][j+1]) nxt = 1;
                                bool fudu_same = 0;
                                for(int j = 1; j <= 4; j++) if(locker[j] != a[i][j] && locker[j+1] != a[i][j+1] && (locker[j] - a[i][j] + 10) % 10 == (locker[j+1] - a[i][j+1] + 10) % 10) fudu_same = 1;
                                if(!nxt || !fudu_same)  unokcnt++;
                            }
                        }
                        if(!unokcnt) ans++;
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
8
1 2 3 4 5
1 2 3 4 5
1 2 3 4 6
1 2 3 4 6
1 2 3 4 7
1 2 3 4 6
1 2 3 4 7
1 2 3 4 7
*/
