#include <stdio.h>

int main()
{
	int a = 10;
	void *ptr = &a;
	printf("%d\n",*(int*)ptr); // ptr void tipinde bir pointer olduðu için onun iþaret ettiði yerdeki deðeri almadan önce pointer ile yýldýz arasýna istediðin tipe dönüþtür.
	double b = 1.12322;
	ptr = &b;
	
	printf("%.5f\n",*(double *)ptr);
	
	void *voidPtr = NULL;
	int *intPtr = NULL;
	float *floatPtr = NULL;
	double *doublePtr = NULL;
	char *charPtr = NULL;
	
	printf("size of void pointer = %d\n",sizeof(voidPtr));
	printf("size of int pointer = %d\n",sizeof(intPtr));
	printf("size of float pointer = %d\n",sizeof(floatPtr));
	printf("size of double pointer = %d\n",sizeof(doublePtr));
	printf("size of char pointer = %d\n",sizeof(charPtr));
	
}
//The size of a void pointer is similar to the size of the character pointer. According to C standard, the pointer to void shall have the same representation and alignment requirements as a pointer to a character type.
//Don’t perform the arithmetic operation on the void pointer. As per the C standard sizeof is not applicable on void but in GNU C we can calculate the size of the void and sizeof operator return 1.
//The C library function void *memcpy(void *dest, const void *src, size_t n) copies n characters from memory area src to memory area dest.
//The C library function void *memmove(void *str1, const void *str2, size_t n) copies n characters from str2 to str1, but for overlapping memory blocks, memmove() is a safer approach than memcpy().
