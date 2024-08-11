#include <iostream>
#include <algorithm>
using namespace std;

int a[100005];
int v[100005];

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,t;
	cin>>n>>t;
	for(int i = 1;i<=n-1;i++){
		cin>>v[i];
	}
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		
	}

	int you = 0;
	int sum = 0;
	for(int i = 1;i<=n-1;i++){
		if(you*t <v[i+1]){
			bool flag = 0;
			int lc = 0;
			for(int j = i+1;j<=n-1;j++){
				lc+=v[j];
				if(a[j]<a[i]){
					if(lc%t != 0){
						sum += (lc/t+1)*a[i];
						you += (lc/t+1);
							
					}
					else{
						sum += lc/t*a[i];
						you += lc/t;
					}
					
					
					flag = 1;
					
					break;
				}
				
			}
			if(flag == 0){
				if(lc%t != 0){
					sum += (lc/t+1)*a[i];
					
						
				}
				else{
					sum += lc/t*a[i];
					
				}
				
				break;
			}
		}
		you -= v[i];
	}
	cout<<sum;
	return 0;
}
