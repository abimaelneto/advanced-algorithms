#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		int GCD,LCM;			
		scanf("%d%d",&GCD,&LCM);
		if(LCM%GCD==0) // input = output if b is divisible by a
			printf("%d %d",GCD,LCM);
		else
			printf("-1");
		putchar('\n');
	}		
	return 0;
}

