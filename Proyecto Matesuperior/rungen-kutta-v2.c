#include<stdio.h>
#include<math.h>
#include <stdlib.h>
//Universidad de Costa Rica
//Escuela de Ingenieria Electrica
//Curso de Matematica superior IE-305
//Profesor: Marvin Coto Jimenes
//Estudiante: Kenny Wu Wen C08592 
// I-2021
float f(float x,float y)
{
    float m;
    m=x*x*x*x+0.2*x*x-6*x; //x^4+0.2*x^2-6x
    return m;
}

void rk4(float x0,float y0,float xn,float h)
{
    int d = xn/h+1;
    float xs[d];
    float ys[d];
    float m1,m2,m3,m4,m,y,x;
    x=x0;
    y=y0;
    printf("\n\nX\t\tY\n");
    int i=0;
    xs[i] = x0;
    ys[i] = y0;
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
    //Guardar los datos en un archivo para graficarlos
    FILE *fptr;
    
    fptr = fopen("./datos_rungen_kutta","a+");


    fprintf(fptr,"\nh=%f\n",h);

    for (int j = 0; j < i+1; j++)
    {
        if(j!=i)
        {
            fprintf(fptr,"%.3f,",xs[j]);
        }
        else
        {
            fprintf(fptr,"%.3f",xs[j]);
        }
    }

    fprintf(fptr,"\n");
    for (int j = 0; j < i+1; j++)
    {
        if(j!=i)
        {
            fprintf(fptr,"%.3f,",ys[j]);
        }
        else
        {
            fprintf(fptr,"%.3f",ys[j]);
        }
    }
    fclose(fptr);
}

int main()
{
    float x0, y0, xn, h;
    printf("Ingrese cuantos h quiere ingresar: \n");
    int cant;
    scanf("%d",&cant);
    for (int i = 0; i < cant; i++)
    {
        printf("Ingrese x0,y0,xn,h:");
        scanf("%f %f %f %f",&x0,&y0,&xn,&h);
        rk4(x0,y0,xn,h);
    }
    
    return 0;

}