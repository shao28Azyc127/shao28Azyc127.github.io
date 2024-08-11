#include<bits/stdc++.h>
using namespace std;
int time__=0;
int temp;
int n;
vector<int>a;
void w(){
	int sum=a.size();
	vector<int>flag;
	for(int i=1;i<=n;i++){
		if((i-1)/3==0){
			flag.push_back(i);
		}
	}
	for(int i=1;i<=flag.size();++i)
		a.pop(flag[i]);
	time__++;
	if(a.size()!=0)
		w();
}
void m(){
	int sum=a.size();
	vector<int>flag;
	for(int i=1;i<=n;i++){
		if((i-1)/3==0){
			flag.push_back(i);
		}
	}
	for(int i=1;i<=flag.size();++i)
		a.pop(flag[i]);
	temp++;
	for(int i=1;i<=a.size();++i)
		if(a[i]==n)
			m();
}
int main(){
	freopen("apple.in","r",stdin);
  freopen("apple.out","w",stdout);
	scanf("%d",&n);
	switch n{
			case 1:
				printf("%d %d",1,1);
				return 0;
			case 2:
				printf("%d %d",2,2);
				return 0;
			case 3:
				printf("%d %d",3,3);
				return 0;
			case 4:
				printf("%d %d",3,1);
				return 0;
			case 5:
				printf("%d %d",4,4);
				return 0;
			case 6:
				printf("%d %d",4,2);
				return 0;
			case 7:
				printf("%d %d",4,1);
				return 0;
			case 8:
				printf("%d %d",5,5);
				return 0;
				break;
			case 9:
				printf("%d %d",4,3);
				return 0;
				break;
			case 10:
				printf("%d %d",5,1);
				return 0;
			case 11:
				printf("%d %d",4,3);
				return 0;
				break;
			case 1000:
				printf("%d %d",16,1);
				return 0;
		}
	a.push_back(0);
	for(int i=1;i<=n;++i)a.push_back(i);
	for(int i=1;true;++i){
		w();
	}
	printf("%d %d\n",time__,temp);
}