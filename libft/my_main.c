#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

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
	printf("str1 after memmove: %s\n", (char*)ft_memmove(str1, str2, sizeof(str2)));
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

// ft_strchr.c
/*
int main(void) {
	char s[] = "found!";
	printf("%s\n", strchr(s, 'u'));
	printf("%s\n", ft_strchr(s, 'u'));
	printf("%s\n", strchr(s, '\0'));
	printf("%s\n", ft_strchr(s, '\0'));
}
*/

// ft_strrchr.c
/*
int main(void) {
	char s[] = "found you sound!";
	
	printf("%s\n", strrchr(s, 'u'));
	printf("%s\n", ft_strrchr(s, 'u'));
	printf("%s\n", strrchr(s, '\0'));
	printf("%s\n", ft_strrchr(s, '\0'));
}
*/

// ft_strstr.c
/*
int main(void) {
	char s[] = "found you sound!";
	
	printf("%s\n", strstr(s, "un"));
	printf("%s\n", ft_strstr(s, "un"));
	printf("%s\n", strstr(s, "\0"));
	printf("%s\n", ft_strstr(s, "\0"));
}
*/

// ft_strnstr.c
/*
int main(void) {
	char s[] = "found you sound!";
	
	printf("%s\n", strnstr(s, "un", 10));
	printf("%s\n", ft_strnstr(s, "un", 10));
	printf("%s\n", strnstr(s, "un", 3));
	printf("%s\n", ft_strnstr(s, "un", 3));
}
*/

// ft_strcmp.c
/*
int main(void) {
	char s1[] = "abcd";
	char s2[] = "abcd";
	char s3[] = "abc";
	char s4[] = "ade";
	char s5[] = "ced";
	char s6[] = "aed";

	printf("%d\n", strcmp(s1, s2));
	printf("%d\n", ft_strcmp(s1, s2));
	printf("%d\n", strcmp(s3, s4));
	printf("%d\n", ft_strcmp(s3, s4));
	printf("%d\n", strcmp(s5, s6));
	printf("%d\n", ft_strcmp(s5, s6));
}
*/

// ft_strncmp.c
/*
int main(void) {
	char s1[] = "aaaaabcd";
	char s2[] = "aaaaabcd";
	char s3[] = "aaaabc";
	char s4[] = "aaaade";
	char s5[] = "cccced";
	char s6[] = "accccced";

	printf("%d\n", strncmp(s1, s2, 5));
	printf("%d\n", ft_strncmp(s1, s2, 5));
	printf("%d\n", strncmp(s3, s4, 3));
	printf("%d\n", ft_strncmp(s3, s4, 3));
	printf("%d\n", strncmp(s3, s4, 6));
	printf("%d\n", ft_strncmp(s3, s4, 6));
	printf("%d\n", strncmp(s5, s6, 6));
	printf("%d\n", ft_strncmp(s5, s6, 6));
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

// ft_striter.c
/*
#include "libft.h"

void ftt_toupper(char *c) {
	if (*c >= 'a' && *c <= 'a') 
		*c -= 32;
	else
		*c = *c;
}

int main(void) {
	char s[] = "aaaa";

	ft_striter(s, ftt_toupper);
	printf("%s", s);
}
*/

// ft_striteri.c
/*

#include "libft.h"

void ftt_toupper(unsigned int , char *c) {
	if (*c >= 'a' && *c <= 'a') 
		*c -= 32;
	else
		*c = *c;
}

int main(void) {
	char s[] = "aaaa";

	ft_striteri(s, ftt_toupper);
	printf("%s", s);
}
*/

//////////////////////////// 23.10 From School

// ft_putnbr.c
/*
int main(void) {
	ft_putnbr(32);
	ft_putnbr(-423);
}
*/

// ft_putchar_fd.c
/*
int main(void) {
	ft_putchar_fd('c', 1);
}
*/

// ft_putstr_fd.c
/*
int main(void) {
	ft_putstr_fd("abc", 1);
}
*/

// ft_putendl_fd.c
/*
int main(void) {
	ft_putendl_fd("abc", 1);
}
*/

// ft_putnbr.c
/*
int main(void) {
	ft_putnbr_fd(32, 2);
	ft_putnbr_fd(-423, 1);
}
*/

// ft_strequ.c
/*
int main(void)
{
	char *s1 = "abc";
	char *s2 = "abc";
	char *s3 = "abd";

	printf("%d\n", ft_strequ(s1, s2));
	printf("%d\n", ft_strequ(s1, s3));
}
*/

// ft_strnequ.c
/*
int main(void)
{
	char *s1 = "abcdef";
	char *s2 = "abcegd";

	printf("%d\n", ft_strnequ(s1, s2, 2));
	printf("%d\n", ft_strnequ(s1, s2, 5));
}
*/

// ft_strsub.c
/*
int main(void)
{
	char *s = "Ham followed now ecstatic use speaking exercise may repeated. Himself he evident oh greatly my on inhabit general concern. It earnest amongst he showing females so improve in picture. Mrs can hundred its greater account. Distrusts daughters certainly suspected convinced our perpetual him yet. Words did noise taken right state are since.";

	printf("%s\n", ft_strsub(s, 7, 50));
}
*/

// ft_strjoin.c
/*
int main(void) {
	printf("%s\n", ft_strjoin("abc", "def"));
	printf("%s\n", ft_strjoin("abc","" ));
   	printf("%s\n", ft_strjoin("edf", ""));
   	printf("%s\n", ft_strjoin("", ""));
}
*/

// ft_strtrim.c
/*
int main(void) {
	printf("%s\n", ft_strtrim("     asdjaslkdjlkas     "));
	printf("%s\n", ft_strtrim("asdjaslkdjlkas     "));
	printf("%s\n", ft_strtrim("     asdjaslkdjlkas"));
    	printf("%s\n", ft_strtrim(NULL));

}
*/

// ft_strsplit.c
/*
int main(void) {
	char **s;
	int i;

	i = 0;
	s = ft_strsplit("*hello*fellow***students*", '*');
	while (s[i])
	{
		printf("%s\n", s[i]);
		i++;
	}
}

*/
// ft_itoa.c
/*
int main(void) {
    printf("%s\n", ft_itoa(9));
    printf("%s\n", ft_itoa(0));
    printf("%s\n", ft_itoa(109));
    printf("%s\n", ft_itoa(-9));
}
*/

// Bones part

// ft_lstnew.c
/*
int main(void) {
	t_list *list = 0;

	list = ft_lstnew("abcds", 6);
	list->next = ft_lstnew("basd", 5);
	list->next->next = ft_lstnew("jsad", 5);
	printf("%s\n", (char*)list->content);
	printf("%s\n", (char*)list->next->content);
	printf("%s\n", (char*)list->next->next->content);
}
*/

// ft_lstelone.c
/*
void	freefunct(void *d, size_t s)
{
	free(d);
	(void)s;
}

int	main(void)
{
	t_list *begin;
	size_t v;

	v = 1;
	begin = ft_lstnew(&v, sizeof(void *));
	begin->next = ft_lstnew(&v, sizeof(void *));
	begin->next->next = ft_lstnew(&v, sizeof(void *));
	ft_lstdelone(&begin->next->next, freefunct);
	if (begin->next->next != NULL)
	{
		printf( "It doesn't work\n");
		return (0);
	}
	ft_lstdelone(&begin->next, freefunct);
	if (begin->next != NULL)
	{
		printf("It doesn't work\n");
		return (0);
	}
	ft_lstdelone(&begin, freefunct);
	if (begin != NULL)
	{
		printf("It doesn't work\n");
		return (0);
	}
	printf("It works\n");
//	return (1);
}
*/

// ft_lstiter.c
/* NOTE: THIS TEST IS SEGMENTATION FAIL need to fix the main
void ft_hello(t_list *elem) {
	ft_strcpy((char*)elem, "hello");
}


int main(void) {
	t_list *list = 0;

	list = ft_lstnew("abcde", sizeof(char*));
	list->next = ft_lstnew("afdfe", sizeof(char*));
	list->next->next = ft_lstnew("aswre", sizeof(char*));
	printf("%s\n", (char*)list->content);
	printf("%s\n", (char*)list->next->content);
	printf("%s\n", (char*)list->next->next->content);
	ft_lstiter(list, ft_hello);
	printf("%s\n", (char*)list->content);
	printf("%s\n", (char*)list->next->content);
	printf("%s\n", (char*)list->next->next->content);
}
*/
/*
void	iterfunct(t_list *v)
{
	*(size_t*)v->content = *(size_t*)v->content + 1;
}

int		main(void)
{
	t_list	*begin;
	size_t	i;
	size_t	j;

	i = 1;
	j = 2;
	begin = ft_lstnew(&i, sizeof(size_t));
	begin->next = ft_lstnew(&j, sizeof(size_t));
	ft_lstiter(begin, iterfunct);
	printf("%zu\n", *(size_t*)begin->content);
	printf("%zu\n", *(size_t*)begin->next->content);
	if (*(size_t*)begin->content != 2)
	{
		printf("It doesn't work\n");
		return (0);
	}
	if (*(size_t*)begin->next->content != 3)
	{
		printf("It doesn't work\n");
		return (0);
	}
	free(begin->next);
	free(begin);
	printf("It works\n");
	return (1);
}
*/

// ft_lstmap.c
/*

t_list	*ft_tooupp(t_list *elem)
{
	int i;
	t_list *new_elem;

	new_elem = ft_lstnew(elem->content, elem->content_size);
	i = 0;
	while (((char*)new_elem->content)[i])
	{
	       ((char*)new_elem->content)[i] -= 32;
	       i++;
	}
	return (new_elem);
}


int main(void) {
	t_list *start;
	t_list *new;

	start = ft_lstnew("aaa", sizeof("aaa"));
	start->next = ft_lstnew("bbb", sizeof("bbb"));
	start->next->next = ft_lstnew("ccc", sizeof("ccc"));
	printf("%s\n", (char*)start->content);
	printf("%s\n", (char*)start->next->content);
	printf("%s\n", (char*)start->next->next->content);
	new = ft_lstmap(start, &ft_tooupp);
	printf("%s\n", (char*)new->content);
	printf("%s\n", (char*)new->next->content);
	printf("%s\n", (char*)new->next->next->content);

}
*/
