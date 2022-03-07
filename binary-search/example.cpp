#include <iostream>
#include <cstdio>
#include <iomanip>

#define ERRO 0.001

using namespace std;

double f (double x){
	return x*x*x - x*x +2;
	// return -x;
}


// versao iterativa....
double bisecao(double min, double max){
	double mid = min;
	while (max-min >= ERRO){
		mid = (max+min)/2.0;
		printf("min = %f *** max = %f **** mid = %f *** result = %f\n", min, max, mid, f(mid));
		//double result = f(mid);
		if ( f(mid)*f(max) > 0  )  // AQUI SIM.. FUnciona para  QQ função...
			max = mid;      // o valor está muito grande... diminui !!!!
		else min =  mid;    // o valor esta muito baixo... aumenta !!!!
	}

	return mid;
}


double bisecaoE(double min, double max){
	double mid = min;
	while (max-min > ERRO){
		mid = (max+min)/2.0;
		printf("min = %f *** max = %f **** mid = %f *** result = %f\n", min, max, mid, f(mid));
		double result = f(mid);
		if ( result > 0  )   // CUIDADO !!! ISSO aqui nao funciona para QQ funcao
			max = mid;      // o valor está muito grande... diminui !!!!
		else min =  mid;    // o valor esta muito baixo... aumenta !!!!
	}

	return mid;
}



int main(int argc, char const *argv[])
{
	double a,b;

	cin >> a >> b;

	if (f(a) * f(b) > 0){
		cout << "opa.. nao ha raiz neste intervalo..." << endl;
		exit(0);
	}

	cout << "A raiz da equacao neste intervalo = " << fixed << setprecision(2) << bisecao(a, b) << endl;

	return 0;
}