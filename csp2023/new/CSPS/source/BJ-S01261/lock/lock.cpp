#include <iostream>

using namespace std;

int n;
int a[10][10];
int b[10][10][10][10][10];

void baoli(){
    int ans = 0;
    for(int i = 1;i <= n;i++){
        //just turn 1
        int aa = a[i][1], bb = a[i][2], c = a[i][3], d = a[i][4], e = a[i][5];
        for(int t = 1;t <= 9;t++){  //the times to turn
            b[(aa+t)%10][bb][c][d][e]++;
            b[aa][(bb+t)%10][c][d][e]++;
            b[aa][bb][(c+t)%10][d][e]++;
            b[aa][bb][c][(d+t)%10][e]++;
            b[aa][bb][c][d][(e+t)%10]++;
        }
    }
    for(int i = 1;i <= n;i++){
        //just turn 1
        int aa = a[i][1], bb = a[i][2], c = a[i][3], d = a[i][4], e = a[i][5];
        for(int t = 1;t <= 9;t++){  //the times to turn
            b[(aa+t)%10][(bb+t)%10][c][d][e]++;
            b[aa][(bb+t)%10][(c+t)%10][d][e]++;
            b[aa][bb][(c+t)%10][(d+t)%10][e]++;
            b[aa][bb][c][(d+t)%10][(e+t)%10]++;
        }
    }
    for(int aa = 0;aa <= 9;aa++){
        for(int bb = 0;bb <= 9;bb++){
            for(int c = 0;c <= 9;c++){
                for(int d = 0;d <= 9;d++){
                    for(int e = 0;e <= 9;e++){
                        if(b[aa][bb][c][d][e] == n) ans++;
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
}

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= 5;j++){
            scanf("%d",&a[i][j]);
        }
    }
    //baoli();
    if(n == 1) printf("%d\n",81);
    else if(n == 2){
        int cnt = 0;
        for(int i = 1;i <= 5;i++){
            //printf("%d:%d %d\n",i,a[1][i],a[2][i]);
            if(a[1][i] != a[2][i]){
                cnt++;
                //printf("++\n");
            }
        }
        //cout << cnt;
        if(cnt == 1) printf("%d\n",10);
        else{
            baoli();
        }
    }
    else{
        baoli();
    }
    //else printf("%d\n",10-n);
    return 0;
}
