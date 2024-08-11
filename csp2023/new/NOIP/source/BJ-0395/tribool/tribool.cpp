#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,num,v[100001],cnt,num1,num2;
char temp;
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    if(c == 3 || c == 4){
        for(int k = 0;k<t;k++){
            for(int i = 1;i<100001;i++){
                v[i] = 1;
            }
            cnt = 0;
            cin>>n>>m;
            for(int i = 0;i<m;i++){
                cin>>temp>>num;
                if(temp == 'T') v[num] = 1;
                else if(temp == 'U') v[num] = 0;
                else if(temp == 'F') v[num] = -1;
            }
            for(int j = 1;j<=n;j++){
                if(v[j] == 0) cnt++;
            }
            cout<<cnt<<endl;
        }
        return 0;
    }
    else if(c == 5 || c == 6){
        for(int k = 0;k<t;k++){
            for(int i = 1;i<100001;i++){
                v[i] = 1;
            }
            cnt = 0;
            cin>>n>>m;
            for(int i = 0;i<m;i++){
                cin>>temp;
                if(temp == 'U'){
                    cin>>num;
                    v[num] = 0;
                }
                else if(temp == '+'){
                    cin>>num1>>num2;
                    v[num1] = v[num2];
                }
            }
            for(int j = 1;j<=n;j++){
                if(v[j] == 0) cnt++;
            }
            cout<<cnt<<endl;
        }
        return 0;
    }
    return 0;
}

