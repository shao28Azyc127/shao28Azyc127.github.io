#include<bits/stdc++.h>
using namespace std;
int cnt[26];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n,num = 0,flag,t;
    cin>>n;
    string a,temp,x,y,l;
    cin>>a;
    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            for(int k = 0;k<26;k++) cnt[k] = 0;
            temp = a.substr(i,j-i+1);
            l = temp;
            if(temp.size() % 2 == 1){
                continue;
            }
            for(int k = 0;k<temp.size();k++){
                cnt[temp[k]-'a']++;
            }
            t = 0;
            for(int k = 0;k<26;k++){
                if(cnt[k]%2!=0){
                    t = 1;
                    break;
                }
            }
            if(t==1){
                continue;
            }
            while(temp.size()!=0){
                flag = temp.size();
                for(int k = 0;k<temp.size()-1;k++){
                    if(temp[k] == temp[k+1]){
                        x = temp.substr(0,k);
                        y = temp.substr(k+2,temp.size()-k-1);
                        temp = x+y;
                        break;
                    }
                }
                if(flag == temp.size()) break;
            }
            if(temp.size() == 0){
                num++;
            }
        }
    }
    cout<<num;
    return 0;
}
