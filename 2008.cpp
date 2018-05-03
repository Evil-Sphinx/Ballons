#include<iostream>
int main(){
	int minus=0,plus=0,zero=0;
	int n;
	int num;
	while(scanf("%d",&n)!=EOF){
		if(n==0)	
			getchar();
			continue;
		for(int i=0;i<n;i++){
			getchar();
			scanf("%d",&num);
			if(num<0){
				minus++;
			}
			else if(num==0){
				zero++;
			}
			else{
				plus++;
			}
		}
		printf("%d %d %d\n",minus,zero,plus);
		minus=plus=zero=0;
		getchar();
	}
	return 0;
}
