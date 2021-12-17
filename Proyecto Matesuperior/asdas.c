#include<stdio.h>
#include<math.h>
float f(float x,float y);
int main(){
    float x0,y0,m1,m2,m3,m4,m,y,x,h,xn;
    printf("Matemática Superior, IE0305\n");
    printf("Autor original: Marvin Coto\n");
    printf("Modificado por: Karen Araya Solís\n");
    printf("Ingrese los valores de x0,y0,xn,h:");
    scanf("%f %f %f %f",&x0,&y0,&xn,&h);
    printf("\n\nX\t\tY\n");
    y=y0;
    x=x0;
    
    while(x<xn){
        m1=f(x0,y0);
        m2=f((x0+h/2.0),(y0+m1*h/2.0));
        m3=f((x0+h/2.0),(y0+m2*h/2.0));
        m4=f((x0+h),(y0+m3*h));
        m=((m1+2*m2+2*m3+m4)/6);
        y=y+m*h;
        x=x+h;
        printf("%f\t%f\n",x,y);
        y0 = y;
        x0 = x;
    }
}
float f(float x,float y){
    float m;
    m=pow(x,4)+(0.2*pow(x,2))-(6*x);
    return m;
}