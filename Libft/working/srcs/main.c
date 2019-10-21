#include <stdio.h>
#include "libft.h"

// ft_atoi.c
/*
#include <stdlib.h>

int main(void) {
	printf("%d\n", atoi("243"));
	printf("%d\n", atoi("ads"));

	printf("%d\n", ft_atoi("243"));
	printf("%d\n", ft_atoi("ads"));

}

*/

// ft_isalpha.c
/*
#include<ctype.h>

int main(void) {
	printf("%d\n", isalpha('s'));
	printf("%d\n", isalpha('4'));

	printf("%d\n", ft_isalpha('s'));
	printf("%d\n", ft_isalpha('4'));
}
*/

// ft_isdigit.c
/*
// #include<ctype.h>

int main(void) {
//	printf("%d\n", isdigit('s'));
//	printf("%d\n", isdigit('4'));

	printf("%d\n", ft_isdigit('s'));
	printf("%d\n", ft_isdigit('4'));
}

*/

// ft_isalnum.c
/*
 #include<ctype.h>

int main(void) {
	printf("%d\n", isalnum('s'));
	printf("%d\n", isalnum('4'));
	printf("%d\n", isalnum('+'));

	printf("%d\n", ft_isalnum('s'));
	printf("%d\n", ft_isalnum('4'));
	printf("%d\n", ft_isalnum('+'));
}
*/

// ft_isprint.c
/*
#include <ctype.h>

int main(void) {
	printf("%d\n", isprint(32));
	printf("%d\n", isprint(30));
	printf("%d\n", isprint(100));

	printf("%d\n", ft_isprint(32));
	printf("%d\n", ft_isprint(20));
	printf("%d\n", ft_isprint(112));
}
*/

// ft_isascii.c
/*
#include <ctype.h>

int main(void) {
	printf("%d\n", isascii(300));
	printf("%d\n", isascii(120));
	printf("%d\n", isascii(-3));

	printf("%d\n", ft_isascii(300));
	printf("%d\n", ft_isascii(120));
	printf("%d\n", ft_isascii(-3));
}
*/

// ft_toupper.c
/*
#include <ctype.h>

int main(void) {
	printf("%c\n", toupper('a'));
	printf("%c\n", toupper('A'));
	printf("%c\n", toupper(47)); 
	
	printf("%c\n", ft_toupper('a'));
	printf("%c\n", ft_toupper('A'));
	printf("%c\n", ft_toupper(47)); 

}
*/

// ft_tolower.c
/*
#include <ctype.h>

int main(void) {
	printf("%c\n", tolower('a'));
	printf("%c\n", tolower('A'));
	printf("%c\n", tolower(47)); 
	
	printf("%c\n", ft_tolower('a'));
	printf("%c\n", ft_tolower('A'));
	printf("%c\n", ft_tolower(47)); 

}

*/

// ft_strlen.c
/*
int main(void) {
	char *str = "abcd";
	printf("%lu\n", strlen(str));
	printf("%lu\n", ft_strlen(str));
}
*/

// ft_strdup.c;
/*
int main() {
	char *str = "hello";

	printf("%s\n", strdup(str));
	printf("%s\n", ft_strdup(str));
	return (0);
}
*/

// ft_strcpy.c
/*
int main(void) {
	char *s = "absd";
	char *d;	
printf("%s\n", strcpy(d, s));
//printf("%s\n", ft_strcpy(d,s));
}
*/

// ft_strncpy.c
/*
int main(void) {
	char *d = "desdfdf";

//	printf("%s\n", strncpy(d, "abc", strlen(d)));
	printf("%s\n", ft_strncpy(d, "abc", ft_strlen(d)));
}
*/

// ft_strcat.c
/*
int main(void)
{
	char *str1 = "abc";
	char str2[100] = "def";

	printf("%s\n", str1);
	printf("%s\n", str2);
	printf("%s\n", strcat(str2, str1));
	printf("%s\n", ft_strcat(str2,str1));
}
*/

// ft_strncat.c
/*
int main(void) {
	char *str1 = "abc";
	char str2[100] = "def";

	printf("%s\n", str1);
	printf("%s\n", str2);
	printf("%s\n", strncat(str2, str1, strlen(str1)));
	printf("%s\n", ft_strncat(str2, str1, strlen(str1)));
}
*/

// ft_memset.c
/*
int main(void) {
	char str[9];
	char str2[9];
	memset(str, 'A', 5);
	ft_memset(str2, 'a', 5);
	printf("%s\n", str);
	printf("%s\n", str2);
}
*/

// ft_strchr.c
/*
int main(void) {
	char *s = "abcgfdklsjglkdfjsg";

//	printf("%c\n", strchr(s, 'c'));
	printf("%s\n", strchr(s, 's'));
}
*/

// ft_memcpy.c
/*
int main(void) {
	char src[50] = "src only";
	char dst[50] = "d only";

//	printf("Before memcpy: \"%s\"\n", dst);
//	printf("After memcpy: \"%s\"\n", memcpy(dst, src, strlen(src) + 1));

	printf("Before memcpy: \"%s\"\n", dst);
	printf("After memcpy: \"%s\"\n", ft_memcpy(dst, src, strlen(src) + 1));
}
*/

// ft_memccpy.c  
/*
int main(void) {
	char src[50] = "https://www.geeksforgeeks.org/restrict-keyword-c/";
	char dst[50] = "Hello!";

	printf("Before memccpy: %s\n", dst);
//	printf("After memccpy: %s\n", memccpy(dst, src, 'w', strlen(src) + 1));
	printf("After memccpy: %s\n", ft_memccpy(dst, src, 'w', strlen(src) + 1));
}
*/

// ft_memmove.c
/*
int main(void) {
	char str1[] = "Geeks";
	char str2[]  = "Quiz";
	
	printf("str1 before memmove: %s\n",str1);
	//Copies contents of str2 to sr1
//	printf("str1 after memmove: %s\n", memmove(str1, str2, sizeof(str2)));
	printf("str1 after memmove: %s\n", ft_memmove(str1, str2, sizeof(str2)));
	return 0;
}
*/

//ft_bzero.c
/*
int main(void) {
	char str[50] = "abcdef";
	
	printf("Before bzero: %s\nAfter bzero: ", str);
//	bzero(str, sizeof(str));
	ft_bzero(str, sizeof(str));
	printf("%s\n", str);
}
*/

// ft_memchr.c
/*
int main(void) {
	char str[100] = "https://www.geeksforgeeks.org/restrict-keyword-c/";

	printf("%s\n", ft_memchr(str, 'w', sizeof(str)));
	printf("%s\n", memchr(str, 'w', sizeof(str)));
}
*/
/*
int main(void) {
	char s1[100] = "abcd";
	char s2[100] = "abcd";
	char s3[100] = "abd";

	printf("S1 and S2: %d\n", memcmp(s1, s2, sizeof(s1)));
	printf("S1 and S3: %d\n", memcmp(s1, s3, sizeof(s1)));
	printf("S1 and S2: %d\n", ft_memcmp(s1, s2, sizeof(s1)));
	printf("S1 and S3: %d\n", ft_memcmp(s1, s3, sizeof(s1)));
}
*/

// ft_strlcat.c
/*
int main(void)
{
	char s[50] = "abc";
	char s2[50] = "def";
	char s3[50] = "abc";
	char s4[50] = "def";

	printf("%lu\n", strlcat(s, s2, sizeof(s)));
	printf("%s\n", s);

	printf("%lu\n", ft_strlcat(s3, s4, sizeof(s4)));
	printf("%s\n", s3);
}
*/

////////////////////////////////////////////

// ft_memalloc.c
/*
#include "libft.h"

int main(void) {
	char *s;
	s = ft_memalloc(40);
	printf("%s\n40bit\n", s);
}
*/

// ft_memdel.c
/*
#include <stdlib.h>
#include "libft.h"

int main(void) {
	char *s;
	int i;
	void *p;
	
	p = &s;
	s = malloc(sizeof(char) * 40);
	for (i = 0; i < 40; i++)
		s[i] = 'a';
	printf("%s\n", s);
	ft_memdel(p);
	printf("%s\n", s);
}
*/

// ft_strnew.c
/*
#include "libft.h"

int main(void) {
	printf("%s\naaa\n", ft_strnew(40));
}
*/

// ft_strdel.c
/*
#include <stdlib.h>
#include "libft.h"

int main(void) {
	char *s;
	int i;
	void *p;
	
	p = &s;
	s = malloc(sizeof(char) * 40);
	for (i = 0; i < 40; i++)
		s[i] = 'a';
	printf("%s\n", s);
	ft_strdel(p);
	printf("%s\n", s);
}
*/

// ft_strclr.c
/*
int main(void) {
	char *s = "asdklfkasd";
	printf("%s\n", s);
	ft_strclr(s);
	printf("%s\n", s);
}
*/

//////////////////
/*
#include "libft.h"

int main(void) {
	char s[] = "aaaaa";
	void nextchar(char *c)
	{
		(*c)++;
	}

	ft_striter(NULL, &nextchar);
	ft_striter(s, &nextchar);

	if (strcmp(s, "kjpq"))
		return (1);
	printf ("ft_striter OK\n");
	return (0);
}
*/
///////////////////////


