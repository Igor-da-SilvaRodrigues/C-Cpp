 #include <stdio.h>
int main() {

float sunda = 1.10, loncha= 1.50;
double ano;

ano = 0;

while (loncha >sunda) {

loncha = loncha + 0.02;

sunda = sunda + 0.05;

ano = ano + 1;

}

printf("Anos deverao ser necessarios para que loncha seja maior que sunda = %.2lf\n", ano);

printf(" A Altura de sunda final %f\n", sunda);

printf("A altura de loncha final %f\n",loncha);

return 0;

}
