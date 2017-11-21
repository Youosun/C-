#include <string.h>
#include <stdio.h>

void test0()
{
	char s1[]="hello";
	char s2[]=",world";

	printf("s1=%s\n",s1);
	printf("s2=%s\n",s2);

	printf("sizeof(s1)=%d\n",sizeof(s1));
	printf("sizeof(s2)=%d\n",sizeof(s2));

	strcat(s1,s2);
	printf("s1 = %s\n",s1);
	printf("s2 = %s\n",s2);
}

int main(void)
{
	test0();
	
	return 0;
}

