#include <stdio.h>
#include <math.h>

FILE *fp;

int k,c,a=100,n=256;
float l=28;//left border
float r=98;//right border
float h,j,y,d,sum,sum1,y_l,y_r;

int methodRect()//method of rectangles
{
    for(c=1;c<=3;c++)
    {
        switch(c)
        {
            case 1://left rectangles
                fp=fopen("left_rectangles.txt","w");
                for(k=1;k<=n;k++)
                {
                    h=(r-l)/k;
                    sum=0;
                    for(j=l;j<=r-h;j+=h)
                    {
                        y=1/(sqrt(pow(a,2)-pow(j,2)));
                        sum=sum+y;
                    }
                    d=h*sum;
                    fprintf(fp,"%d %f\n",k,d);
                }
                fclose(fp);
                break;
            case 2://right rectangles
                fp=fopen("right_rectangles.txt","w");
                for(k=1;k<=n;k++)
                {
                    h=(r-l)/k;
                    sum=0;
                    for(j=l+h;j<=r;j+=h)
                    {
                        y=1/(sqrt(pow(a,2)-pow(j,2)));
                        sum=sum+y;
                    }
                    d=h*sum;
                    fprintf(fp,"%d %f\n",k,d);
                }
                fclose(fp);
                break;
            case 3://center rectangles
                fp=fopen("center_rectangles.txt","w");
                for(k=1;k<=n;k++)
                {
                    h=(r-l)/k;
                    sum=0;
                    for(j=l+h;j<=r;j+=h)
                    {
                        y=1/(sqrt(pow(a,2)-pow(j-h/2,2)));//????????????????????
                        sum=sum+y;
                    }
                    d=h*sum;
                    fprintf(fp,"%d %f\n",k,d);
                }
                fclose(fp);
                break;
        }
    }
}

int methodTrap()//trapezium method
{
    fp=fopen("trapezium.txt","w");
    for(k=1;k<=n;k++)
    {
        h=(r-l)/k;
        sum=0;
        for(j=l+h;j<=r-h;j+=h)
        {
            y=1/(sqrt(pow(a,2)-pow(j,2)));
            sum=sum+y;
        }
        y_l=1/(sqrt(pow(a,2)-pow(l,2)));
        y_r=1/(sqrt(pow(a,2)-pow(r,2)));
        d=h*((y_l+y_r)/2+sum);
        fprintf(fp,"%d %f\n",k,d);
    }
    fclose(fp);
}

int methodPar()//parabola method
{
    fp=fopen("parabola.txt","w");
    for(k=1;k<=n;k++)
    {
        h=(r-l)/k;
        sum=0;
        sum1=0;
        for(j=2*(l+h);j<=2*(h/2-h);j+=h)
        {
            y=1/(sqrt(pow(a,2)-pow(j,2)));
            sum=sum+y;
        }
        for(j=2*(l+h)+h;j<=2*(h/2-h)+h;j+=h)
        {
            y=1/(sqrt(pow(a,2)-pow(j,2)));
            sum1=sum1+y;
        }
        y_l=1/(sqrt(pow(a,2)-pow(l,2)));
        y_r=1/(sqrt(pow(a,2)-pow(r,2)));
        d=h/3*(y_l+y_r+2*sum+4*sum1);
        fprintf(fp,"%d %f\n",k,d);
    }
    fclose(fp);
}

int main()
{
    float f,x;

    fp=fopen("function.txt","w");
    for(x=0;x<=99;x+=0.1)
    {
        f=1/(sqrt(pow(a,2)-pow(x,2)));
        fprintf(fp,"%f %f\n",x,f);
    }
    fclose(fp);

    methodRect();
    methodTrap();
    methodPar();

    return 0;
}
