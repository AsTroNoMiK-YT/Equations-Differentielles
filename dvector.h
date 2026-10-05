#include <vector>

using namespace std;

typedef vector<double> dvector;

void operator+=(dvector &a,const dvector &b){
  int i,n=a.size();
  for(i=0;i<n;i++) a[i]+=b[i];
}

void operator-=(dvector &a,const dvector &b){
  int i,n=a.size();
  for(i=0;i<n;i++) a[i]-=b[i];
}

void operator*=(dvector &a,double b){
  int i,n=a.size();
  for(i=0;i<n;i++) a[i]*=b;
}

void operator/=(dvector &a,double b){
  int i,n=a.size();
  for(i=0;i<n;i++) a[i]/=b;
}

dvector operator+(const dvector &a,const dvector &b){
  dvector x(a);
  x+=b;
  return x;
}

dvector operator-(const dvector &a,const dvector &b){
  dvector x(a);
  x-=b;
  return x;
}

dvector operator*(const dvector &a,double b){
  dvector x(a);
  x*=b;
  return x;
}

dvector operator*(double b,const dvector &a){
  dvector x(a);
  x*=b;
  return x;
}

// scalar product
double operator*(const dvector &a,const dvector &b){
  double sum=0;
  int i,n=a.size();
  for(i=0;i<n;i++) sum+=a[i]*b[i];
  return sum;
}

dvector operator/(const dvector &a,double b){
  dvector x(a);
  x/=b;
  return x;
}
