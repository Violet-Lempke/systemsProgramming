#include <stdio.h>
main() {
  float celsius;
  float fahrenheit;
  printf("Enter the temperature you would like to convert: ");
  scanf("%f", &celsius);
  fahrenheit = (celsius*(9.0/5.0)) + 32;
  printf("\nThe temperature %.2f in
  Celsius is %.2f in Fahrenheit\n", celsius, fahrenheit);
  return 0;
}
