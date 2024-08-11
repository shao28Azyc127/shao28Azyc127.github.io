#include <iostream>
#include <vector>
using namespace std;

int x[100000010];
int n;

bool all_token(){
    bool flag=true;
    for(int i = 1;i<=n;i++){
        if(x[i]!=0) flag = false;
    }
    return flag;
}

int main(){

    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);

    cin >> n;
    for(int i = 1;i<=n;i++){
        x[i]=i;
    }
    int day=1,nday;
    while(!all_token()){
        for(int i = 1;i<=n;i = i + 3){
            while(x[i]==0) i++;
            if(x[i]==n){
                nday=day;
            }
            x[i]=0;
            /*for(int i = 1;i<=n;i++){
                cout << x[i] << " ";
            }cout <<endl;*/
        }
        day++;
    }
    cout << day <<" " << nday;
}
