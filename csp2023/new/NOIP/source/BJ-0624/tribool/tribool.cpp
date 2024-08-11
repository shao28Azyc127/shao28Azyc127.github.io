//1:T,0:F,-1:U
#include<iostream>
#include<vector>
using namespace std;
const int N=200010;
int C,T;
int n,m;
struct node{
    int kind;
    int v;
};
int ans=0;
vector<node> g[N];
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin >> C >> T;
    if(C==3||C==4){
        while(T--){
            int n,m;
            cin >> n >> m;
            for(int i=1;i<=m;i++){
                char op;
                int x,y;
                cin >> op >> x >> y;
                if(op=='U'){
                    ans++;
                }
            }
            cout << ans << endl;
        }
        return 0;
    }
    if(C==7||C==8){
        int num1=0;
        int num2=0;
        while(T--){
            int n,m;
            cin >> n >> m;
            for(int i=1;i<=m;i++){
                char op;
                int x,y;
                cin >> op >> x >> y;
                if(op=='-'){
                    num2++;
                }
                if(op=='+'){
                    num1++;
                }
            }
            if(num1<num2){
                swap(num1,num2);
            }
            if(n%2!=0&&num1-num2==1){
                cout << 0 << endl;
            }else if(n%2!=0&&num1-num2!=1){
                cout << (num1/2)+num2 << endl;
            }else if(n%2==0&&num1==num2){
                cout << 0 << endl;
            }else if(n%2==0&&num1!=num2){
                cout << num2 << endl;
            }
        }
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
