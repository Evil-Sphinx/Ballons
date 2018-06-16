#include<cmath>
#include<iostream>
int main() {
    int st,ed;
    int even_rt=0,odd_rt=0;
    while(scanf("%d %d",&st,&ed)!=EOF) {
    	if(st>ed){
    		int t=st;
    		st=ed;
    		ed=t;
		}
        for(int i=st; i<=ed; i++) {
            if(i%2==0) {
                even_rt+=pow(i,2);
            }
            else {
                odd_rt+=pow(i,3);
            }
        }
        printf("%d %d\n",even_rt,odd_rt);
        even_rt=odd_rt=0;
    }
    return 0;
}
