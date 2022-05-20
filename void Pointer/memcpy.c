#include <stdio.h>
#include <string.h> //memcpy
#include <stdlib.h> //malloc

int main(void)
{
	struct Person{
		int age;
		char name[30];
	};
	struct Person *firstPerson =(struct Person * )calloc(1,sizeof(struct Person));
	struct Person *secondPerson =(struct Person * )calloc(1,sizeof(struct Person));
	
	char tempName[30] = "Alan Turing";
	int tempAge = 30;
	
	printf("------------------------------\n");
	printf("firstPerson NODE\n");
	printf("firstPerson : %d\n",firstPerson);
	printf("firstPerson->name (dizinin ilk elemaninin adresi) : %d\n",&(firstPerson->name[0]));
	printf("firstPerson->age : %d\n",firstPerson->age);
	printf("&(firstPerson->age): %d\n",&(firstPerson->age));
	printf("------------------------------\n");
	printf("secondPerson NODE\n");
	printf("secondPerson : %d\n",secondPerson);
	printf("secondPerson->name(dizinin ilk elemaninin adresi) :%d\n",&secondPerson->name[0]);
	printf("secondPerson->age : %d\n",secondPerson->age);
	printf("&(secondPerson->age): %d\n",&(secondPerson->age));
	printf("------------------------------\n");
	
	memcpy(&(firstPerson->name)[0],&tempName[0],strlen(tempName)+1);
	memcpy(&firstPerson->age,&tempAge,sizeof(tempAge));
	
	printf("%d\n",firstPerson);
	printf("%s\n",firstPerson->name);
	printf("%d\n",firstPerson->age);
	
	memcpy(secondPerson,firstPerson,sizeof(struct Person));//Burada sizeof() içerisine ne kadar ayný tipte olsa da firstPerson veyahutta secondPerson yazmak derleme hatasýna sebep vermemekte fakat iþlem istenilen sonuçta gerçekleþmemekte.
	
	printf("firstPerson: name = %s , age = %d\n",firstPerson->name,firstPerson->age);
	printf("secondPerson: name = %s , age = %d\n",secondPerson->name,secondPerson->age);
	
	free(firstPerson);
	free(secondPerson);
	
//	char src[20] = "String to copy";
//	char dst[20] = {0};
//	printf("%d\n",sizeof(src));
//	printf("dst address = %d\nsrc address = %d\n",dst,src);
//	memcpy(&dst[0],&src[0],sizeof(src)); // proof of memcpy(dst,src,sizeof(src));
//	printf("dst = %s",dst);
	return 0;
}
////The C library function void *memcpy(void *dest, const void *src, size_t n) copies n characters from memory area src to memory area dest.
//The size of the destination buffer must be greater than the number of bytes you want to copy.
//memcpy does not check the terminating null character, so carefully use with strings.
//memcpy() works on the byte level.

