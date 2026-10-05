#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dvector.h"

dvector f(double x,dvector y);
dvector euler_vectorise(double x,dvector y,double h);

int main(){
	dvector L(12); //Ou L est le vecteur d'etat a 12 composantes.
	L[0] = -1.613238e-3; // xsoleil(0)
	L[1] = -2.3674938e-3; // ysoleil(0)
	L[2] = -3.49999e-5; // zsoleil(0)
	L[3] = 6.0453208e-6; // vxsoleil(0)
	L[4] = -1.8980631e-6; // vysoleil(0)
	L[5] = -1.3060634e-7; // vzsoleil(0)
	L[6] = 6.8900355e-1; // xterre(0)
	L[7] = 7.0799513e-1; // yterre(0)
	L[8] = -5.4762805e-5; // zterre(0)
	L[9] = -1.2606830e-2; // vxterre(0)
	L[10] = 1.1932472e-2; // vyterre(0)
	L[11] = -5.3326343e-7; // vzterre(0)
	double t = 0.0;
	double h = 0.15;
	FILE *fich;
	fich = fopen("orbite.txt","w");
	do{
		fprintf(fich,"%lf %lf %lf %lf %lf %lf %lf\n",t,L[0],L[1],L[2],L[6],L[7],L[8]);
		L = euler_vectorise(t,L,h);
		t = t + h;
	}while(t<2000.0);
	fclose(fich);
}
dvector f(double x, dvector y){
    dvector F(12); // Vecteur de sortie, à 12 composantes.
    double G = 2.959122e-4; // Constante gravitation
    double Ms = 1.000000; // Masse du Soleil (en M/M.)
    double Mt = 3.0032e-6; // Masse de la Terre
    double xS = y[0];
    double yS = y[1];
    double zS = y[2];
    double vxS = y[3];
    double vyS = y[4];
    double vzS = y[5];
    double xT = y[6];
    double yT = y[7];
    double zT = y[8];
    double vxT = y[9];
    double vyT = y[10];
    double vzT = y[11];
    // Calcul de r³
    double r = sqrt((xT-xS)*(xT-xS)+(yT-yS)*(yT-yS)+(zT-zS)*(zT-zS));
    double r3 = r*r*r;
    F[0] = vxS; //xsoleil' = vxsoleil
    F[1] = vyS;
    F[2] = vzS;
    F[3] = G*Mt*(xT-xS)/r3; // calcul de l'accélération en x (vxsoleil')
    F[4] = G*Mt*(yT-yS)/r3;
    F[5] = G*Mt*(zT-zS)/r3;
    F[6] = vxT;
    F[7] = vyT;
    F[8] = vzT;
    F[9] = -G*Ms*(xT-xS)/r3;
    F[10] = -G*Ms*(yT-yS)/r3;
    F[11] = -G*Ms*(zT-zS)/r3;
    return F;
}

dvector euler_vectorise(double x,dvector y,double h){
	int n=y.size();
	dvector k1(n);
	k1 = h*f(x,y);
	return y + k1;
}
