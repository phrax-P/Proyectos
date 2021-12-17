#include<stdio.h>
#include<math.h>
//Universidad de Costa Rica
//Escuela de Ingenieria Electrica
//Curso de Matematica superior IE-305
//Profesor: Marvin Coto Jimenes
//Estudiante: Kenny Wu Wen C08592 
// I-2021
float f(float x)
{
    return (x-42)*(x-42) - 3*x*log((x-100)*(x-100));
}
float df (float x)
{
    return (2*x-3*(log((x-100)*(x-100)))-(6*x)/(x-100)-84);
}
int main()
{
    int itr, maxmitr;
    float h, x0, x1,allerr;
    printf("\nIngrese x0, el error maximo y la cantidad de iteraciones\n");
    scanf("%f %f %d", &x0, &allerr, &maxmitr);
    for (itr=1; itr<=maxmitr; itr++)
    {
        h=f(x0)/df(x0);
        x1=x0-h;
        printf("%3d & %9.6f \\\\  \n", itr, x1);
        if (fabs(h) < allerr)
        {
            printf("Despues de  %3d iteraciones, raiz = %8.6f\n", itr, x1);
            return 0;
        }
        x0=x1;
    }
    printf(" No se encontro la solucion porque no converge o por insuficiente iteraciones\n");
    return 1;
}
