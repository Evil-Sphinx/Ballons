#include<iostream>
#include<string> 
using namespace std;
int main(){
	int a,b;
	int sum;
	scanf("%d %d",&a,&b);
	sum=a+b;
	string rt=to_string(a+b);
	for(int i=0;i<rt.length();i++){
		cout<<rt[i];
		if(rt[i]=='-'||i==rt.length()-1)	continue;
		if((i+1)%3==rt.length()%3){
			cout<<",";
		}
	}
	return 0;
}
