#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<cstdio>
using namespace std;
int n,cnt,pd;
string s,sa,sb,sc;
int res[2000006],num=1;
int dv(string zz){
	string u=zz;
    pd=1;
    while(pd==1){
		    if(u==""){
        return 1;
    }
        pd=0;
        for(int i = 0;i<u.size()-1;i++){
           if(u[i]==u[i+1]){
                sa="";
                sb="";
                for(int j = 0;j<i;j++){
					//if(u[j]>='a'&&u[j]<='z')
                    sa+=u[j];
                }
                for(int j = i+2;j<u.size();j++){
					//if(u[j]>='a'&&u[j]<='z')
                    sb+=u[j];
                }
                //cout<<sa<<" "<<sa.size()<<"    "<<sb<<" "<<sb.size()<<"     ";
                u=sa+sb;
               // cout<<u<<" "<<u.size()<<endl;
             //   i-=2;
                pd=1;
                break;
           }
        }
    }
    if(u==""){
        return 1;
    }
   // cout<<"u:"<<u<<" "<<u.size()<<endl;
        return 0;
    
}
int main(){
freopen("game.in","r",stdin);
freopen("game.out","w",stdout);
//string tst="accabccb";
//cout<<dv(tst);
cin>>n;
cin>>s;
if(n>200){
	for(int i = 0 ;i<n-1;i++){
    if(s[i]==s[i+1]){
        res[i]=num;
        res[i+1]=num;
        cnt++;
        for(int j = 1;i-j>=0&&i+1+j<n;j++){
            if(s[i-j]==s[i+1+j]){
                cnt++;
                res[i-j]=num;
                res[i+1+j]=num;
            }
        }
        num++;
    }
}
int ans=0;
for(int i = 0;i<=n;i++){
    if(i==n||res[i]==0){
        cnt+=(ans+1)*ans/2;
        cnt-=ans;
        ans=0;
    }else if(i==0||res[i]!=res[i-1]){
        ans+=1;
    }
}
cout<<cnt;
return 0;
	}
for(int i = 0;i<n-1;i++){
    for(int j = i+1;j<n;j++){
        sc="";
        for(int k = i;k<=j;k++){
			//if(s[k]<='z'&&s[k]>='a')
            sc+=s[k];
        }
       // cout<<sc<<" "<<sc.size()<<endl;
        cnt+=dv(sc);
    }
}
cout<<cnt;
return 0;
}

