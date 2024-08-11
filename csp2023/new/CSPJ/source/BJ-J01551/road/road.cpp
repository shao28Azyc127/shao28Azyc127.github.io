#include<cstdio>
#include<iostream>
using namespace std;
int n, d;
struct point{
	long long place;
	int you;
};
int main(){
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  scanf("%d %d", &n, &d);
  for(int i=1;i<=n;++i)scanf("%d", &arr[i].you);
  long long temp;
  point arr[n];
  arr[1].place=0;
  for(int i=1;i<n;++i){
		scanf("%lld", &temp);
		arr[i].place = arr[i-1].place + temp;
	}
	delete &temp;
}