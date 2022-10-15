extern "C"
{
    #include <cmath>
    
}
#ifndef MATH_H_  

#define MATH_H_

const float PI = 3.14159265358979323846264338f;

float flerp(float a,float b,float c){
    return (c * a) + ((1-c) * b);
}

double flerp(double a,double b,double c){
    return (c * a) + ((1-c) * b);
}



double dmax(double x,double y){
    return x>y ? x : y;
}

double dmin(double x,double y){
    return x<y ? x : y;
}

int imax(int x,int y){
    return x>y ? x : y;
}

int imin(int x,int y){
    return x<y ? x : y;
}

double clamp(double val,double min,double max){
    return dmin(dmax(val,min),max);
}

float clamp(float val,float min,float max){
    return fmin(fmax(val,min),max);
}

int clamp(int val,int min,int max){
    return imin(imax(val,min),max);
}

#endif 