#include<iostream>
using namespace std;
int c, n, m, p;
int a[3] = {0};
int b[3] = {0};
int qa[3] = {0};
int qb[3] = {0};
int data1, data2;
int data3, data4;
int main(){
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    cin >> c >> n >> m >> p;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> b[i];
    }
    if(c == 1){
        //cout << a[1] << b[1] << endl;
        if(a[1] != b[1]){
            cout << "1";
        }else{
            cout << "0";
        }
        for(int i = 1; i <= p; i++){
            for(int j = 1; j <= n; j++){
                qa[j] = a[j];
            }
            for(int j = 1; j <= m; j++){
                qb[j] = b[j];
            }
            cin >> data1 >> data2;
            for(int j = 1; j <= data1; j++){
                cin >> data3 >> data4;
                qa[data3] = data4;
            }
            for(int j = 1; j <= data2; j++){
                cin >> data3 >> data4;
                //cout << data3 << data4 << endl;
                qb[data3] = data4;
                //cout << qa[1] << qb[1] << endl;
            }
            if(qa[1] != qb[1]){
                cout << "1";
            }else{
                cout << "0";
            }
        }
        cout << endl;
    }/*5pts*/else if(c == 2){
        if(n == 1){
            a[2] = a[1];
        }
        if(m == 1){
            b[2] = b[1];
        }
        if((a[1] - b[1]) * (a[2] - b[2]) > 0){
            cout << "1";
        }else{
            cout << "0";
        }
        for(int i = 1; i <= p; i++){
            for(int j = 1; j <= n; j++){
                qa[j] = a[j];
            }
            for(int j = 1; j <= m; j++){
                qb[j] = b[j];
            }
            cin >> data1 >> data2;
            for(int j = 1; j <= data1; j++){
                cin >> data3 >> data4;
                qa[data3] = data4;
            }
            for(int j = 1; j <= data2; j++){
                cin >> data3 >> data4;
                //cout << data3 << data4 << endl;
                qb[data3] = data4;
                //cout << qa[1] << qb[1] << endl;
            }
            if(n == 1){
                qa[2] = qa[1];
            }
            if(m == 1){
                qb[2] = qb[1];
            }
            if((qa[1] - qb[1]) * (qa[2] - qb[2]) > 0){
                cout << "1";
            }else{
                cout << "0";
            }
        }
        cout << endl;
    }
    return 0;
}