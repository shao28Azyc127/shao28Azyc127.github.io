#include<bits/stdc++.h>
using namespace std;

long long n;
string s[10005];
map<string,long long> m;

int main()
{
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	cin>>n;
	long long used=-1;
	while(n--){
		long long opt;
		cin>>opt;
		if(opt==1){
		}
		else if(opt==2){
			string leix;
			string name;
			cin>>leix>>name;
			if(leix=="byte"){
				s[used+1]=name;
				m[name]=used+1;
				cout<<used+1<<endl;
				used+=1;
			}
			if(leix=="short"){
				long long duiqi;
				for(long long i=used+2;i<=10000;i++){
					if((i+1)%2==0){
						duiqi=i;
						break;
					}
				}
				s[duiqi]=name;
				s[duiqi-1]=name;
				m[name]=duiqi-1;
				cout<<duiqi-1<<endl;
				used=duiqi;
			}
			if(leix=="long long"){
				long long duiqi;
				for(long long i=used+4;i<=10000;i++){
					if((i+1)%4==0){
						duiqi=i;
						break;
					}
				}
				s[duiqi]=name;
				s[duiqi-1]=name;
				s[duiqi-2]=name;
				s[duiqi-3]=name;
				m[name]=duiqi-3;
				cout<<duiqi-3<<endl;
				used=duiqi;
			}
			if(leix=="long"){
				long long duiqi;
				for(long long i=used+8;i<=10000;i++){
					if((i+1)%8==0){
						duiqi=i;
						break;
					}
				}
				s[duiqi]=name;
				s[duiqi-1]=name;
				s[duiqi-2]=name;
				s[duiqi-3]=name;
				s[duiqi-4]=name;
				s[duiqi-5]=name;
				s[duiqi-6]=name;
				s[duiqi-7]=name;
				m[name]=duiqi-7;
				cout<<duiqi-7<<endl;
				used=duiqi;
			}
		}
		else if(opt==3){
			string name;
			cin>>name;
			cout<<m[name]<<endl;
		}
		else if(opt==4){
			long long addr;
			cin>>addr;
			if(addr>10000 || s[addr]==""){
				cout<<"ERR"<<endl;
			}
			else{
				cout<<s[addr]<<endl;
			}
		}
	}
	return 0;
}
