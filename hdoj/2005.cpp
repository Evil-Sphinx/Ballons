#include<iostream>
bool judge(int year){
	if(year%4==0){
		if(year%100==0){
			if(year%400==0){
				return true;
			}
			else{
				return false;
			}
		}else{
			return true;
		}
	}
	else{
		return false;
	}
}

int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
	int year,month,day;
	int ans=0;
	while(scanf("%d/%d/%d",&year,&month,&day)!=EOF){
		for(int i=0;i<month;i++){
			ans+=days[i];
		}
		ans+=day;
		if(month>2&&judge(year)){
			ans+=1;
		}
		printf("%d\n",ans);
		ans=0;
	}
	return 0;
}
