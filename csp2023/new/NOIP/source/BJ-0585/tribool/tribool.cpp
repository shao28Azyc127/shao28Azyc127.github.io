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
int c,t;
const int MAXN = 114514;//>.<
int tri[MAXN];
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    c=rd();t=rd();
    while(t--){
        int n=rd(),m=rd();
        memset(tri,0,sizeof(tri));


        if(c == 3 or c == 4){
            for(int i = 1; i <= m ; i++){
               char a;int b;
                cin >> a >> b;
                if(a == 'T'){
                    tri[b] = 1;
                }
                if(a == 'F'){
                    tri[b] = 2;
                }
                if(a == 'U'){
                    tri[b] = 3;
                }
            }
            int ans = 0;
            for(int i = 1; i <= n ; i++){
                if(tri[i] == 3) ans++;
            }
            cout << ans <<endl;
           // cout <<2313131 <<endl;
        }
        else if(c == 5 or c == 6){
            //cout << n <<" " <<m <<endl;


            for(int i = 1; i <= m ; i++){
               char a;int b,c;
               cin >> a;
                if(a == '+'){
                    cin >> b >> c;
                }else{
                    cin >> b;
                }
                if(a == '+'){
                    tri[b] = c;
                }
                if(a == 'U'){
                    tri[b] = INT_MAX;
                    for(int i =1; i <= n;i++){
                        if(tri[i] == b) tri[i] = INT_MAX;
                    }
                }
                //cout << tri[i] << endl;
            }


            int ans = 0;
            for(int i = 1; i <= n ; i++){
                if(tri[i] == INT_MAX) {

                        ans++;
                        //cout << tri[i] << " " << i <<endl;
                }
            }
            cout << ans <<endl;
        }










        }
       return 0;
    }


