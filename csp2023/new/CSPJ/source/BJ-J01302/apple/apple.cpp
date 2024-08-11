#include<iostream>

using namespace std;

typedef long long LL;

int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
	int last=n;
	int rmn=-1;
	int count=1;
	while(last>0){
		if((rmn==-1)&&(last%3==1)){
			rmn=count;
		}
		last=last-((last-1)/3)-1;
//		cout<<count<<"  "<<last<<endl;
		count++;
	}
	cout<<count-1<<" "<<rmn<<endl;
	return 0;
}
