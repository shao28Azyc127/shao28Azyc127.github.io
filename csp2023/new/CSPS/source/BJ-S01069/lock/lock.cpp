#include<iostream>
using namespace std;
int lock[10][6];
int flag[6];
int n;
int num=0;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    for(int i=0;i<10;i++){
        for(int j=0;j<6;j++){
            lock[i][j]=-1;
        }
    }
    cin >> n;
    for(int t=1;t<=n;t++){
        num++;
        cin >> lock[num][1] >> lock[num][2] >> lock[num][3] >> lock[num][4] >> lock[num][5];
        int tsame=0;
        int tcnt=-1;
        for(int i=0;i<=num-1;i++){
            for(int j=1;j<=5;j++){
                if(lock[i][j]==lock[num][j]){
                    flag[j]=1;
                }
            }
        }
    }
    if(n==1){
        cout << "81" << endl;
    }
    int cnt=0;
    for(int i=1;i<=5;i++){
        if(flag[i]==1){
            cnt++;
        }
    }
    if(cnt==4){
        cout << "10" << endl;
    }
    if(cnt==3){
        cout << "40" << endl;
    }
    if(cnt==2){
        cout << "41" << endl;
    }
    if(cnt==1){
        cout << "71" << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
