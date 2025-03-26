#define F_LOW 0
#define F_MAX 250
#define STEP 25
#include <stdio.h>

int main(){
    typedef float REAL ;
    REAL fahrenheit,celsius ;

    fahrenheit = F_LOW ;
    printf("Fahrenheit Celsius\n\n");
    while (fahrenheit <= F_MAX)
    {
        celsius = (fahrenheit - 32.0)/1.8;
        printf("%5.2f %7.2f\n", fahrenheit, celsius);
        fahrenheit = fahrenheit + STEP;
    }
    
}