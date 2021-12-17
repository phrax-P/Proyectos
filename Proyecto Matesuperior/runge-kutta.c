#include<stdio.h>
#include<math.h>
#include <stdlib.h>
//Universidad de Costa Rica
//Escuela de Ingenieria Electrica
//Curso de Matematica superior IE-305
//Profesor: Marvin Coto Jimenes
//Estudiante: Kenny Wu Wen C08592 
// I-2021
float f(float x,float y);
int main()
{
    float xs[255];
    float ys[255];
    float x0,y0,m1,m2,m3,m4,m,y,x,h,xn;
    printf("Ingrese x0,y0,xn,h:");
    scanf("%f %f %f %f",&x0,&y0,&xn,&h);
    x=x0;
    y=y0;
    printf("\n\nX\t\tY\n");
    int i=0;
    while(x<xn)
    {
        i++;
        m1=f(x0,y0);
        m2=f((x0+h/2.0),(y0+m1*h/2.0));
        m3=f((x0+h/2.0),(y0+m2*h/2.0));
        m4=f((x0+h),(y0+m3*h));
        m=((m1+2*m2+2*m3+m4)/6);
        y=y+m*h;
        x=x+h;
        printf("%f\t%f\n",x,y);
        xs[i] = x;
        ys[i] = y;
        y0=y;
        x0=x;
    }
    for (int j = 1; j < i+1; j++)
    {
        printf("%.3f,",xs[j]);
    }
    printf("\n\n");
    for (int j = 1; j < i+1; j++)
    {
        printf("%.3f,",ys[j]);
    }
    printf("\n\n");

}
float f(float x,float y)
{
    float m;
    m=x*x*x*x+0.2*x*x-6*x;
    return m;
}
