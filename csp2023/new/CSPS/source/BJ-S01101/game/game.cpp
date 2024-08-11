#include<bits/stdc++.h>
using namespace std;
bool flag[2*1e6];
int come(int k){
    for(int i=k-1;i>=0;i--)
        if(flag[i]==true)
            return i;
    return -1;
}
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int answer=0;
    for(int i=0;i<n;i++)
        flag[i]=true;
    for(int i=0;i<n-1;i++){
        for(int j=1;j<=(n-i)/2;j++){
            for(int k=i;k<i+j*2;k++){
                if(k>i){
                    if(s[k]==s[come(k)])
                        flag[k]=false;
                        flag[come(k)]=false;
                    }
                }
            }
            bool f=true;
            for(int k=i;k<i+j*2;k++){
                if(flag[k]==true){
                    f=false;
                    break;
                }
            }
            if(f==true)
                answer++;
            for(int k=0;k<n;k++)
                flag[k]=true;
        }
    }
    cout<<answer;
    return 0;
}
