#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double f(double x,double y);
double pas_euler(double x,double y,double h);
double pas_heun(double x, double y,double h);
double pas_rk4(double x, double y,double h);

int main(){
	double x0 = 0.2;
	double u0;
	double h = 0.001;
	double x;
	double u;
	FILE *fich;
	fich = fopen("ventsolaire.txt","w");
	// Vents supersoniques
	for(u0=3.65;u0<=4.0;u0+=0.1){
		x = x0;
		u = u0;
		do{
			fprintf(fich,"%lf %lf\n",x,u);
			u = pas_rk4(x,u,h);
			x = x+h;
		}while(x<5.0);
		fprintf(fich, "\n");
	}
	
    	// Brises solaires
    	for(u0=0.003;u0<=0.0052;u0+=0.001){
        	x = x0;
        	u = u0;
        	do{
            	fprintf(fich,"%lf %lf\n",x,u);
            	u = pas_rk4(x,u,h);
            	x = x+h;
        		}while(x<5.0);
        	fprintf(fich, "\n");
    	}
    fclose(fich);
}

double f(double x,double y){
	double f;
	f = 2.0*(1.0/x-1.0/(x*x))/(y-1.0/y);
	return f;
}

double pas_rk4(double x, double y,double h){
	double k1,k2,k3,k4;
	k1 = h*f(x,y);
	k2 = h*f(x+h/2.0,y+k1/2.0);
	k3 = h*f(x+h/2.0,y+k2/2.0);
	k4 = h*f(x+h,y+k3);
	return y + (k1+2.0*k2+2.0*k3+k4)/6.0;
}
