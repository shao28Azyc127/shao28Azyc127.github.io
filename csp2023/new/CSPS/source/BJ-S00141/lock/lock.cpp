#include <bits/stdc++.h>

using namespace std;
int a[8][5];
int q[5];
void print(){
    for(int i = 0;i < 5;i++){
        cout << q[i] << " ";
    }
    cout << endl;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4];
    }
    int cnt2 = 0;
    bool flag;
    for(q[0] = 0;q[0] <= 9;q[0]++){
        for(q[1] = 0;q[1] <= 9;q[1]++){
            for(q[2] = 0;q[2] <= 9;q[2]++){
                for(q[3] = 0;q[3] <= 9;q[3]++){
                    for(q[4] = 0;q[4] <= 9;q[4]++){
                        int cnt = 0;
                        flag = false;
                        for(int j = 0;j < n;j++){
                            cnt = 0;
                            for(int i = 0;i < 5;i++){
                                if(q[i] != a[j][i]){
                                    if(i + 1 < 5 && a[j][i + 1] - q[i + 1] == a[j][i] - q[i]){
                                        cnt++;
                                        i++;
                                    }
                                    //else if(i == 4){
                                    //    if(a[j][i] - q[i] != a[j][0] - q[0] || a[j][0] - q[0] == a[j][1] - q[1]){
                                    //            cnt++;
                                    //    }
                                    //    else{
                                    //    }
                                    //}
                                    else{
                                        cnt++;
                                    }
                                }
                            }
                            if(cnt != 1){
                                flag = true;
                            }
                        }
                        if(!flag){
                            //print();
                            cnt2++;
                        }
                    }
                }
            }
        }
    }
    cout << cnt2;
    return 0;
}
