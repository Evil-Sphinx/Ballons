#include<iostream>
#include<cmath>
using namespace std;
int main(){
	double x;
	while(scanf("%lf",&x)!=EOF){
		printf("%.2lf\n",abs(x));
		getchar();
	}
	return 0;
}
