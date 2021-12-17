#include<stdio.h>
#include<math.h>
//Universidad de Costa Rica
//Escuela de Ingenieria Electrica
//Curso de Matematica superior IE-305
//Profesor: Marvin Coto Jimenes
//Estudiante: Kenny Wu Wen C08592 
// I-2021
double f(double x)
{
    return (x-42)*(x-42) - 3*x*log((x-100)*(x-100)); // f(x)= (x-42)^2-6xlog(x-100)
}
void main()
{
    double a,b,c,d,e;
    int count=1,n;
    printf("\n\nIngrese los dos valores iniciales:\n"); //dentro de a y b debe estar la solucion
    scanf("%lf%lf",&a,&b);
    printf("Ingrese el valor de error maximo y el numero de iteracioness:\n");
    scanf("%lf %d",&e,&n);
    do
    {
        if(f(a)==f(b))
        {
            printf("\nNo se puede encontrar solucion al ser a y b valores iguales.\n");
        return;
        }
        c=(a*f(b)-b*f(a))/(f(b)-f(a));
        a=b;
        b=c;
        printf("%d & %f \\\\ \n",count,c);
        count++;
        if(count==n)
        {
        break;
        }
    } while(fabs(f(c))>e);
    printf("\n La solucion encontrada es %lf\n",c);
    return;
}
