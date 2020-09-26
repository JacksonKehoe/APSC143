/*	Program sphere.c
	This program finds the volume of a sphere.
	
	Try changing output text to be longer than 19 characters
*/

int main(int argc, char ** argv)
{
	int radius;
	float volume;
	float PI = 3.14;
	radius = 3; //put an integer value into the variable
	volume = 4 * PI * radius * radius * radius / 3;//compute
	printf("The sphere volume\n");
	printf("is %.2f\n", volume);
}
