#include<bits/stdc++.h>
using namespace std;

int rd(){
    int x=0,f=1;
    char b = getchar();
    while(!isdigit(b)){
        if(b == '-') f=-1;
        b = getchar();
    }



    while(isdigit(b)){
        x = (x << 1) + (x << 3) + (b^48);
        b = getchar();
    }
    return x*f;
}

int n,m;
char word[3090][3090];
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    n=rd();m=rd();
    if(n == 1){
        cout << 1;
        return 0;
    }
    if(m == 1){
        char tmp = 'z';
        int cnt;
        char b;
        for(int i = 1 ; i <= n ; i ++){
            cin >> b;
            if(b < tmp){
                tmp = b;
                cnt = i;
                //cout << tmp <<endl;
            }
        }
       //cout << cnt <<endl;
        for(int i = 1; i <= n ; i++){
            if(i == cnt){
                cout << 1;
            }else cout << 0;
        }
        return 0;
    }

    for(int i = 1; i <= n;i++){
        for(int j = 1; j <= m; j++){
            cin >> word[i][j];
        }
    }//input

    for(int i = 1; i <= n ; i++){
        char temp = 'z';
        bool fla = 0;
        for(int j = 1; j <= m ; j++){
            if(word[i][j] < temp){
                temp = word[i][j];
            }
        }//replace it to input later
        for(int j = 1; j <= n ; j++){
            bool flag = 0;
            for(int k = 1; k <= m ;k++){
                if(i != j){
                    if(word[j][k] > temp){
                        flag = 1;
                        break;
                    }
                }else flag = 1;
            }
            if(flag == 0){
                cout << 0;
                fla = 1;
                break;
            }
        }
        if(fla == 0){
            cout << 1;
        }
    }



    return 0;
}
