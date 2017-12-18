#include <stdio.h>

#define ABSOLUTE_ZERO 273.15
#define KELVIN 'K'
#define CELSIUS 'C'
#define FAHRENHEIT 'F'


		float toCel(char from, float value) {
		if (from == KELVIN)
		return value - ABSOLUTE_ZERO;
		if (from == FAHRENHEIT)
		return (value - 32) / 1.8;
		return 0;
}

		float toKel(char from, float value) {
		if (from == CELSIUS)
		return value + ABSOLUTE_ZERO;
		if (from == FAHRENHEIT)
		return toKel(CELSIUS, toCel(FAHRENHEIT, value));
		return 0;
}

		float toFar(char from, float value) {

		if (from == CELSIUS)
		return (value * 1.8) + 32;
		if (from == KELVIN)
		return toFar(CELSIUS, toCel(KELVIN, value));
		return 0;
}

int main(int argc, const char * argv[]) 
{
	char scale;
	float value;

		printf("Enter the unit of temperature\n");
		printf("C - Celsius\n");
		printf("F - Fahrenheit\n");
		printf("K - Kelvin\n");
		printf("\n");

		scale = getchar();
		printf("Enter the temperature value\n");
		scanf("%.2lf", &value);

	switch (scale) {
		case KELVIN:
	{
		printf("Degrees Celsius: %.2lf\n", toCel(KELVIN, value));
		printf("Degrees Fahrenheit: %.2lf\n", toFar(KELVIN, value));
	break;
	}
		case CELSIUS:
	{
		printf("Degrees Kelvin: %.2lf\n", toKel(CELSIUS, value));
		printf("Degrees Fahrenheit: %.2lf\n", toFar(CELSIUS, value));
	break;
	}
		case FAHRENHEIT:
	{
		printf("Degrees Celsius: %.2lf\n", toCel(FAHRENHEIT, value));
		printf("Degrees Kelvin: %.2lf\n", toKel(FAHRENHEIT, value));
	break;
	}
		default:
	{
		printf("Units of measurement are not recognized, try again\n");
	break;

	}
	return 0;
}
}
