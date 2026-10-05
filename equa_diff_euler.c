#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double f(double x,double y);
double pas_euler(double x,double y,double h);
double pas_heun(double x, double y,double h);
double pas_rk4(double x, double y,double h);

int main(){
	double x0 = 0.0;
	double y0 = 1.0;
	double h;
	double x;
	double y;
	double borne_x;
	double y_theo;
	FILE *fich_euler;
	FILE *fich_heun;
	FILE *fich_rk4;
	FILE *fich_err;
	fich_euler = fopen("euler.txt","w");
	fich_err = fopen("erreurs.txt","w");
	fich_heun = fopen("heun.txt","w");
	fich_rk4 = fopen("rk4.txt","w");
	for (h = 0.001; h < 1.0; h = h*1.2) {
	borne_x = 10.0;
	y_theo = exp(-10);
	x = x0;
	y = y0;
	do{
		y = pas_euler(x,y,h);
		x = x + h;
		fprintf(fich_euler,"%lf %lf\n",x,y);
	}while(x + h <= borne_x);
	double err_euler = fabs(y-y_theo);
	y = y0;
	x = x0;
	do{
		y = pas_heun(x,y,h);
		x = x + h;
		fprintf(fich_heun,"%lf %lf\n",x,y);
	}while(x + h <= borne_x);
	double err_heun = fabs(y-y_theo);
	y = y0;
	x = x0;
	do{
		y = pas_rk4(x,y,h);
		x = x + h;
		fprintf(fich_rk4,"%lf %lf\n",x,y);
	}while(x + h <= borne_x);
	double err_rk4 = fabs(y-y_theo);
	fprintf(fich_err,"%lf %lf %lf %lf\n",h,err_euler,err_heun,err_rk4);
}
fclose(fich_euler);
fclose(fich_rk4);
fclose(fich_err);
fclose(fich_heun);
}

double f(double x,double y){
	return -y;
}

double pas_euler(double x,double y,double h){
	double k1;
	k1 = h*f(x,y);
	return y + k1;
}

double pas_heun(double x, double y,double h){
	double k1,k2;
	k1 = h*f(x,y);
	k2 = h*f(x+h,y+k1);
	return y + (k1+k2)/2.0;
}

double pas_rk4(double x, double y,double h){
	double k1,k2,k3,k4;
	k1 = h*f(x,y);
	k2 = h*f(x+h/2.0,y+k1/2.0);
	k3 = h*f(x+h/2.0,y+k2/2.0);
	k4 = h*f(x+h,y+k3);
	return y + (k1+2.0*k2+2.0*k3+k4)/6.0;
}
