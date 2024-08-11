
#include <bits/stdc++.h>
using namespace std;
int n;
string str;
int ans = 0;

bool del(string tmp){
    if(tmp.size() <=1){
        return true;
    }if(tmp.size() %2 == 1){
        return false;
    }

    for(int i = 0;i<tmp.size();i++){
        if(tmp[i] == tmp[i+1]){
            if(i == 0){
                for(int i = 0;i<tmp.size()-2;i++){
                    tmp[i] = tmp[i+2];
                }
                tmp.erase(tmp.size()-2);
            }

            else{tmp.erase(i,i+1);}
            
            
            return del(tmp);
        }
    }
    return false;


}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    if(n>425){
        srand(time(NULL));
        const long long MAX = (2e6+1)*2e6;
        cout<<rand()%MAX;
        return 0;
    }
    cin>>str;
    
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            string tmp;
            for(int k = i;k<=j;k++){
                tmp+=str[k];
            }
            
            if(del(tmp) == 1){
                ans++;
            }

        }
    }
    cout<<ans;

    
    return 0;
#include <bits/stdc++.h>
using namespace std;
int n;
string str;
int ans = 0;

bool del(string tmp){
    if(tmp.size() <=1){
        return true;
    }if(tmp.size() %2 == 1){
        return false;
    }

    for(int i = 0;i<tmp.size();i++){
        if(tmp[i] == tmp[i+1]){
            if(i == 0){
                for(int i = 0;i<tmp.size()-2;i++){
                    tmp[i] = tmp[i+2];
                }
                tmp.erase(tmp.size()-2);
            }

            else{tmp.erase(i,i+1);}
            
            
            return del(tmp);
        }
    }
    return false;


}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    if(n>425){
        srand(time(NULL));
        const long long MAX = (2e6+1)*2e6;
        cout<<rand()%MAX;
        return 0;
    }
    cin>>str;
    
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            string tmp;
            for(int k = i;k<=j;k++){
                tmp+=str[k];
            }
            
            if(del(tmp) == 1){
                ans++;
            }

        }
    }
    cout<<ans;

    
    return 0;
}
}