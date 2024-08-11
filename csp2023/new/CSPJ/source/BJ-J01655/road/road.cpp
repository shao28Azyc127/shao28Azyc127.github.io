#include <iostream>
#include <cstdio>
using namespace std;
int shang(double t){
	if(t == (int)t) return (int)t;
	else return (int)t + 1;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int price[100001], dis_to_front[100001] = {0};
	int n, d, t, last_chosen = 1, sum = 0;
	double oil_in_car = 0;
	double temp;
	scanf("%d%d", &n, &d);
	for(int i = 2; i <= n; i++){
		scanf("%d", &t);
		dis_to_front[i] = dis_to_front[i - 1] + t;
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &price[i]);
	}
	temp = (double)(dis_to_front[2] - dis_to_front[1]) / (double)d;
	sum += shang(temp) * price[1], oil_in_car = shang(temp);
	oil_in_car -= temp;
	for(int i = 2; i < n; i++){
		temp = shang((double)(dis_to_front[i + 1] - dis_to_front[i]) / (double)d - oil_in_car);
		oil_in_car += temp;
		if(price[i] <= price[last_chosen]) last_chosen = i;
		sum += temp * price[last_chosen];
		oil_in_car -= (double)(dis_to_front[i + 1] - dis_to_front[i]) / (double)d;
	}
	printf("%d", sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}