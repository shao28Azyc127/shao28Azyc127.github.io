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

int ch[100050][2];

int f[10050][10000];
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int c=rd(),t=rd();


    while(t--){
        memset(f,0,sizeof(f));
        int n=rd(),m=rd(),k=rd(),d=rd();
    for(int i = 1; i <= m; i++){
        cin >> ch[i][0] >> ch[i][1] >> ch[i][2];
    }
    for(int i = 1; i <= n ; i ++){
        for(int j = 1; j <= k ; j++){
            int cnt;
            bool fd=0;
            for(int k = 1; k <= m ; k++){
                if(i == ch[k][0] && j >= ch[k][1]){
                    cnt = k;
                     fd=1;
                    break;
                }
            }
            if(fd){
                f[i][j] = max(f[i][j],f[i][j-1] - d + ch[k][2]);
            }else{
                f[i][j] = max(f[i][j],f[i][j-1] - d);
            }


        }
    }
    int temp = 0;
    for(int i = 1; i  <= k; i ++){
         temp = max(temp,f[n][i]);

    }
    cout << temp << endl;
    }

    return 0;
}
//到此踌躇不能去
//对此如何不泪垂
