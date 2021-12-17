#include<stdio.h>
//Universidad de Costa Rica
//Escuela de Ingenieria Electrica
//Curso de Matematica superior IE-305
//Profesor: Marvin Coto Jimenes
//Estudiante: Kenny Wu Wen C08592 
// I-2021
float fun(float x,float y)
{
    float f;
    f=x*x*x*x+0.2*x*x-6*x;
    return f;
}
int main()
{
    float xs[255];
    float ys[255];
    float a,b,x,y,h,t,k;
    printf("\nIngrese x0,y0,h,xn: ");
    scanf("%f%f%f%f",&a,&b,&h,&t);
    x=a;
    y=b;
    xs[0] = x;
    ys[0] = y;
    printf("\n  x\t  y\n");
    int i=0;
    while(x<=t)
    {
        i++;
        k=h*fun(x,y);
        y=y+k;
        x=x+h;
        printf("%i & %0.3f & %0.3f \\\\ \n",i,x,y);
        xs[i] = x;
        ys[i] = y;
    }
    for (int j = 0; j < i+1; j++)
    {
        printf("%.3f,",xs[j]);
    }
    printf("\n\n");
    for (int j = 0; j < i+1; j++)
    {
        printf("%.3f,",ys[j]);
    }
    printf("\n\n");
}
