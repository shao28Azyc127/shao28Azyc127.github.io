#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	long long n,sum=0;
	string s,s2="";
	cin>>n;
	cin>>s;
	for(int i=0;i<n;i++){//��ö��s���е��Ӽ��ַ���
		for(int j=0;j<n-i;j++){
			if((i+1)%2!=0){
				//ֻ���ַ�������Ϊż���ſ�������8
				continue;
			}
			for(int k=j;k<=j+i;k++){
				s2+=s[k];
			}
			long long z=s2.size();
			while(1){
				//�����������ַ��ַ���Ҳ�����
				//cout<<s2<<endl;
				z=s2.size();
				int flag=0;
				for(int x=0;x<z;x++){
					if(s2[x]==s2[x+1]){//�ж��Ƿ񻹿�������
						flag=1;
						break;
					}
				}
				if(!flag){
					break;
				}
				for(int x=0;x<z;x++){//ģ������
					if(s2[x]==s2[x+1]){
						//cout<<s2[x]<<" "<<s2[x+1]<<endl;
						s2[x]='-';//���ϱ�Ƿ������
						s2[x+1]='-';
						break;
					}
				}
				string s3="";
				for(int x=0;x<z;x++){
					if(s2[x]!='-'){//ֻҪ���Ǳ���ַ�
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
