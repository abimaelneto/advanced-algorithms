#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define MIN(a,b,c) min(min(a,b),c)

#define MAX 100

char str1[MAX] = "mean";
char str2[MAX] = "name";

int len1 = strlen(str1);
int len2 = strlen(str2);

int delta = 2;

int MEMO[MAX+1][MAX+1];

void printMat(int M[][MAX+1]){
	for (int i = len1; i>=0 ; --i) {
		for (int j = 0; j <=len2; ++j) {
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
}

/*
    se ambos forem vogais ou consoantes, alpha = 1
    caso contrario, alpha = 3
*/
int alpha(int i, int j){
	char cx = str1[i];
	char cy = str2[j];

	if(cx == cy)
		return 0;

	if ( (cx=='a' || cx=='e' || cx=='i' || cx=='o' || cx=='u') &&  
         (cy=='a' || cy=='e' || cy=='i' || cy=='o' || cy=='u') )
     return 1;
    if ( !(cx=='a' || cx=='e' || cx=='i' || cx=='o' || cx=='u') &&  
         !(cy=='a' || cy=='e' || cy=='i' || cy=='o' || cy=='u') )
     return 1;

    return 3;

}


int alin(int i, int j){

    if (i == 0)
    	return j*delta;
    if (j == 0)
    	return i*delta;

	return MIN(alpha(i-1,j-1) + alin(i-1,j-1), delta + alin(i-1,j), delta + alin(i,j-1));
}

int alin2(int i, int j){

    if (i == 0){
    	MEMO[0][j] =  j*delta;
    	return MEMO[0][j];
    }
    if (j == 0){
    	MEMO[i][0] = i*delta;
    	return MEMO[i][0];
    }

    if (MEMO[i][j] != -1)
    	return MEMO[i][j];

	MEMO[i][j] =  MIN(alpha(i-1,j-1) + alin2(i-1,j-1), delta + alin2(i-1,j), delta + alin2(i,j-1));

	return MEMO[i][j];
}

int alin3(int m, int n){

   for (int i = 0; i <=len1; ++i)
    	MEMO[0][i] =  i*delta;

   for (int i = 0; i <=len2; ++i)
    	MEMO[i][0] =  i*delta;
    	
   
   for (int i = 1; i <=m; ++i)
  		for (int j = 1; j <=n; ++j)
	       MEMO[i][j] =  MIN(alpha(i-1,j-1) + MEMO[i-1][j-1], delta + MEMO[i-1][j], delta + MEMO[i][j-1]);

	return MEMO[m][n];
}



int main(int argc, char const *argv[])
{
	
	printf("A custo minimo de alinhamento eh %d\n", alin(len1,len2));


	memset(MEMO, -1, sizeof MEMO);
	printf("A custo minimo de alinhamento (REC PD) eh %d\n", alin2(len1,len2));
	printMat(MEMO);


	printf("A custo minimo de alinhamento (REC PD) eh %d\n", alin3(len1,len2));
	printMat(MEMO);
	return 0;
}