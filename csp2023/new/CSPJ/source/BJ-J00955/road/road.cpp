#include<bits/stdc++.h>
using namespace std;
int a,b;
int ditance[1000010],money[1000010];
int alldistance,small,allmoney,where,oil=0;
int main(){
	freopen("road.in","r","stdin");
	freopen("road.out","w","stdout");
	cin>>a>>b;
	where=1;
	for(int i=1;i<a;i++){
		cin>>ditance[i];
		alldistance+=ditance[i];
	}
	for(int i=1;i<=a;i++){
		cin>>money[i];
		if(i==1){
			small=money[i];
			continue;
		}
		small=min(small,money[i]);
	}
	if(small==money[1]){
		if(money[1]*alldistance%b==0){
			cout<<money[1]*alldistance/b;
		}else{
			cout<<money[1]*alldistance/b+1;
		}
	}else{
		while(where!=a){
			for(int i=where+1;i<=a;i++){
				if(money[where]>=money[i]){
					for(int j=1;j<i;j++){
						int f=ditance[j]/b;
						if(f*b>=ditance[j]){
							allmoney+=ditance[j]*money[where]/b;
						}else{
							allmoney+=(ditance[j]/b+1)*money[where];
						}	
					}
					where=i;
				}
			}
		}
		cout<<allmoney;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}