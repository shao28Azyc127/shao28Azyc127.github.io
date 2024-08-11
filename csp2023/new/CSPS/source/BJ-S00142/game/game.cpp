#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	long long n,sum=0;
	string s,s2="";
	cin>>n;
	cin>>s;
	for(int i=0;i<n;i++){//，枚举s所有的子集字符串
		for(int j=0;j<n-i;j++){
			if((i+1)%2!=0){
				//只有字符串长度为偶数才可能消掉8
				continue;
			}
			for(int k=j;k<=j+i;k++){
				s2+=s[k];
			}
			long long z=s2.size();
			while(1){
				//如果都清空了字符字符串也会清空
				//cout<<s2<<endl;
				z=s2.size();
				int flag=0;
				for(int x=0;x<z;x++){
					if(s2[x]==s2[x+1]){//判断是否还可以消除
						flag=1;
						break;
					}
				}
				if(!flag){
					break;
				}
				for(int x=0;x<z;x++){//模拟消除
					if(s2[x]==s2[x+1]){
						//cout<<s2[x]<<" "<<s2[x+1]<<endl;
						s2[x]='-';//打上标记方便清除
						s2[x+1]='-';
						break;
					}
				}
				string s3="";
				for(int x=0;x<z;x++){
					if(s2[x]!='-'){//只要不是标记字符
						s3+=s2[x];
					}
				}
				s2=s3;
				
			}
			if(s2.size()==0){
				//cout<<1<<" ";
				//cout<<s4<<endl;
				sum++;
			}
			s2="";
		}	
	}
	cout<<sum<<endl;
	return 0;
}
