extern "C"
{
    #include <cmath>
    
}
#ifndef MATH_H_  

#define MATH_H_

const float PI = 3.14159265358979323846264338f;
const float E = 2.71828182845904523536028747;
const float Tau=PI*2;
const float Inf=INFINITY;
const float NegativeInf=-INFINITY;

float flerp(float a,float b,float c){
    return (c * a) + ((1-c) * b);
}


double flerp(double a,double b,double c){
    return (c * a) + ((1-c) * b);
}

int factorial(int x){
    int out=1;
    for(int i=1;i<=x;i++){
        out*=i;
    }

    return out;
}

float factorial(float x){
    float out=1;
    for(float i=1;i<=x;i++){
        out*=i;
    }

    return out;
}


double factorial(double x){
    double out=1;
    for(double i=1;i<=x;i++){
        out*=i;
    }

    return out;
}

double imax(double x,double y){
    return x>y ? x : y;
}

double imin(double x,double y){
    return x<y ? x : y;
}

int imax(int x,int y){
    return x>y ? x : y;
}

int imin(int x,int y){
    return x<y ? x : y;
}

double clamp(double val,double min,double max){
    return imin(imax(val,min),max);
}

float clamp(float val,float min,float max){
    return fmin(fmax(val,min),max);
}

int clamp(int val,int min,int max){
    return imin(imax(val,min),max);
}

float comb(float n,float k){
    return factorial(n) / (factorial(k) * factorial((n - k)));
}


#endif 