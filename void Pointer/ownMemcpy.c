#include <stdio.h>
#include <stdlib.h>

void *memoryCopy(void *dst,void *src,unsigned int counter);
void *removeLastKey(void *dst,void *src);
void *removeLastKey2(void *dst,void *src);

int main(void)
{
	char dst[30];
	char dst2[30];
	char dst3[30];
	char src[30] = "Own Memory Copy";
	memoryCopy(dst,src,strlen(src)+1);
	removeLastKey(dst2,src);
	removeLastKey2(dst3,src);
	printf("%s\n",dst);
	printf("%s\n",dst2);
	printf("%s\n",dst3);
}
void *memoryCopy(void *dst,void *src,unsigned int counter)
{
	char *tempSrc = (char *)src;
	char *tempDst = (char *)dst;
	
	if(tempDst != NULL && tempSrc != NULL)
	{
		while(counter != 0)
		{
			*tempDst = *tempSrc;
			tempDst++;
			tempSrc++;
			counter--;
		}
	}
	return dst;
}

void *removeLastKey(void *dst,void *src)
{
	char *tempSrc = (char *)src;
	char *tempDst = (char *)dst;
	unsigned int counter = strlen(tempSrc)-1;
	
	if(tempDst != NULL && tempSrc != NULL)
	{
		while(counter != 0)
		{
			*tempDst = *tempSrc;
			tempDst++;
			tempSrc++;
			counter--;
		}
	}
	return dst;
}
void *removeLastKey2(void *dst,void *src) //Bir esprisi yok.Yukaridakinin karpuzlusu. 
{
	char *charSrc = (char *)src;
	char *charDst = (char *)dst;
	unsigned const int length = strlen(charSrc)-1;
	
	if(charDst != NULL && charSrc != NULL)
	{
		int i=0;
		for(i;i<length;i++)
		{
			*charDst = *charSrc;
			charDst++;
			charSrc++;
		}
	}
	return dst;
	
}




