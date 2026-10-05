#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dvector.h"

dvector f(double x,dvector y);
dvector euler_vectorise(double x,dvector y,double h);
dvector add_et_mult_avec5(dvector a,dvector b);

int main(){
	dvector y(2);
	y[0] = 1.0; // y(0)
	y[1] = 0.0; // y'(0)
	double h = 0.001;
	double x0 = 0.0;
	double x;
	FILE *fich;
	fich = fopen("osc.txt","w");
	do{
		fprintf(fich,"%lf %lf %lf\n", x, y[0],h);
		y = euler_vectorise(x, y, h);
		x=x+h;
	}while(x<50.0);
	fclose(fich);
	return 0;
}

dvector f(double x, dvector y){
    double Wo = 2.0;
    dvector F(2);
    F[0] = y[1];
    F[1] = -(Wo*Wo)*y[0];
    return F;
}

dvector euler_vectorise(double x,dvector y,double h){
	int n=y.size();
	dvector k1(n);
	k1 = h*f(x,y);
	return y + k1;
}

