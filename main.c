#include <stdio.h>
#include <libfts.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

void	ft_putstr(char *str)
{
	write(1, str, strlen(str));
}

void	test_bzero()
{
	char	*ptr1 = strdup("Hello\n");
	char	*ptr2 = strdup("Hello\n");
	(void)ptr1;
	printf("-------TEST BZERO-------\n");
	ft_bzero(ptr1, strlen(ptr1));
	bzero(ptr2, strlen(ptr2));
	printf("Test [0]: (two basic strings) -> ");
	if (strcmp(ptr1, ptr2))
		printf(RED "Failed\n" RESET);
	else
		printf(GREEN "Passed\n" RESET);
	ptr1 = "Hello\n";
	ptr2 = "Hello\n";
	ft_bzero(ptr1, 0);
	bzero(ptr2, 0);
	printf("Test [1]: (size == 0) -> ");
	if (strcmp(ptr1, ptr2))
		printf(RED "Failed\n" RESET);
	else
		printf(GREEN "Passed\n" RESET);
	ptr1 = NULL;
	ptr2 = NULL;
	ft_bzero(ptr1, 0);
	bzero(ptr2, 0);
	printf("Test [2]: (NULL string) -> ");
	if (ptr1 == NULL && ptr2 == NULL)
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
}

void	test_strcat()
{
	printf("\n-------TEST STRCAT-------\n");
	char	s1[50] = "Hello ";
	char	s2[] = "World\n";
	ft_strcat(s1, s2);
	ft_putstr("Test [0]: (basic strings) -> ");
	if (!strcmp(s1, "Hello World\n"))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
	char s3[] = "Hello ";
	char *s4 = "";
	ft_strcat(s3, s4);
	ft_putstr(RESET"Test [1]: (s2 is empty) -> ");
	if (!strcmp("Hello ", s3))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
}

void	test_isalpha()
{
	
	printf("\n-------TEST ISALPHA-------\n");

	ft_putstr(RESET"Test [0]: (A caracter) -> ");
	if (ft_isalpha('A') == isalpha('A'))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
	ft_putstr(RESET"Test [1]: (z caracter) -> ");
	if (ft_isalpha('z') == isalpha('z'))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
	ft_putstr(RESET"Test [2]: (V caracter) -> ");
	if (ft_isalpha('V') == isalpha('V'))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
	ft_putstr(RESET"Test [3]: (: caracter) -> ");
	if (ft_isalpha(':') == isalpha(':'))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
	ft_putstr(RESET"Test [4]: ({ caracter) -> ");
	if (ft_isalpha('{') == isalpha('{'))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
}

void	test_isdigit()
{
	printf("\n-------TEST ISALPHA-------\n");
	ft_putstr(RESET"Test [0]: (0 digit) -> ");
	if (ft_isdigit('0') == isdigit('0'))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
	ft_putstr(RESET"Test [1]: (9 digit) -> ");
	if (ft_isdigit('9') == isdigit('9'))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
	ft_putstr(RESET"Test [2]: (5 digit) -> ");
	if (ft_isdigit('5') == isdigit('5'))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
	ft_putstr(RESET"Test [3]: (c digit) -> ");
	if (ft_isdigit('c') == isdigit('c'))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
		
}

void	test_isalnum()
{
	printf("\n-------TEST ISALNUM-------\n");
	ft_putstr(RESET"Test [0]: (A carac) -> ");
	if (ft_isalnum('A'))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
	ft_putstr(RESET"Test [1]: (5 digit) -> ");
	if (ft_isalnum('5'))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
	ft_putstr(RESET"Test [2]: ({ carac) -> ");
	if (!ft_isalnum('{'))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
	ft_putstr(RESET"Test [3]: (* carac) -> ");
	if (!ft_isalnum('*'))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);

}

void	test_isascii()
{
	printf("\n-------TEST ISASCII-------\n");
	ft_putstr(RESET"Test [0]: (0 carac) -> ");
	if (ft_isascii(0) == isascii(0))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
	ft_putstr(RESET"Test [1]: (del carac) -> ");
	if (ft_isascii(127) == isascii(127))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
	ft_putstr(RESET"Test [2]: (50 carac) -> ");
	if (ft_isascii(50) == isascii(50))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
	ft_putstr(RESET"Test [3]: (50 carac) -> ");
	if (ft_isalnum(150) == isascii(150))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
}

void	test_isprint()
{
	printf("\n-------TEST ISPRINT-------\n");
	ft_putstr(RESET"Test [0]: (150 carac) -> ");
	if (ft_isprint(150) == isprint(150))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
	ft_putstr(RESET"Test [1]: (54 carac) -> ");
	if (ft_isprint(54) == isprint(54))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
	ft_putstr(RESET"Test [1]: (17 carac) -> ");
	if (ft_isprint(17) == isprint(17))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
}

void	test_toupper()
{
	printf("\n-------TEST TOUPPER-------\n");
	ft_putstr(RESET"Test [0]: (a carac) -> ");
	if (ft_toupper('a') == toupper('a'))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
	
	ft_putstr(RESET"Test [1]: (z carac) -> ");
	if (ft_toupper('z') == toupper('z'))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
	ft_putstr(RESET"Test [2]: (A carac) -> ");
	if (ft_toupper('A') == toupper('A'))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
	ft_putstr(RESET"Test [3]: (; carac) -> ");
	if (ft_toupper(';') == toupper(';'))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
}
void	test_tolower()
{
	printf("\n-------TEST TOLOWER-------\n");
	ft_putstr(RESET"Test [0]: (A carac) -> ");
	if (ft_tolower('A') == tolower('A'))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
	
	ft_putstr(RESET"Test [1]: (Z carac) -> ");
	if (ft_tolower('Z') == tolower('Z'))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
	ft_putstr(RESET"Test [2]: (a carac) -> ");
	if (ft_tolower('a') == tolower('a'))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
	ft_putstr(RESET"Test [3]: (; carac) -> ");
	if (ft_tolower(';') == tolower(';'))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
}

void	test_puts()
{
	printf("\n-------TEST PUTS-------\n");
	ft_putstr(RESET"Test [0]: (print basic string) ->\n");
	if (ft_puts("Hello World") == puts("Hello World"))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
	ft_putstr(RESET"Test [1]: (print null string) ->\n");
	if (ft_puts(NULL) == puts(NULL))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
}

void	test_strlen()
{
	printf("\n-------TEST STRLEN-------\n");
	ft_putstr(RESET"Test [0]: (basic string) -> ");
	if (ft_strlen("Hello World") == strlen("Hello World"))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
	ft_putstr(RESET"Test [1]: (empty string) -> ");
	if (ft_strlen("") == strlen(""))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
}

void	test_memset()
{
	printf("\n-------TEST MEMSET-------\n");
	char ptr[] = "Hello";
	char ptr2[] = "Hello";

	memset(ptr, 'c', 3);
	ft_memset(ptr2, 'c', 3);
	ft_putstr(RESET"Test [0]: (basic string) -> ");
	if (!strcmp(ptr, ptr2))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
	char ptr3[] = "";
	char ptr4[] = "";
	memset(ptr3, 's', 0);
	ft_memset(ptr4, 's', 0);
	ft_putstr(RESET"Test [1]: (emptry string) -> ");
	if (!strcmp(ptr3, ptr4))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
}

void	test_memcpy()
{
	char ptr[] = "Hello";
	char ptr2[] = "Salut";

	printf("\n-------TEST MEMCPY-------\n");
	ft_memcpy(ptr, ptr2, 3);
	ft_putstr(RESET"Test [0]: (basic string) -> ");
	if (!strcmp(ptr, "Sallo"))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
	ft_memcpy(ptr, "", 5);
	ft_putstr(RESET"Test [1]: (empty string) -> ");
	if (!strcmp(ptr, ""))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
}

void	test_strdup()
{
	printf("\n-------TEST STRDUP-------\n");
	char *s1 = ft_strdup("Hello World");
	char *s2 = strdup("Hello World");
	ft_putstr(RESET"Test [0]: (basic string) -> ");
	if (!strcmp(s1, s2))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
	char *s3 = ft_strdup("");
	char *s4 = strdup("");
	ft_putstr(RESET"Test [1]: (empty string) -> ");
	if (!strcmp(s3, s4))
		printf(GREEN "Passed\n" RESET);
	else
		printf(RED "Failed\n" RESET);
}

#include <fcntl.h>

void	test_cat()
{
	printf("\n-------TEST CAT-------\n");
	ft_putstr(RESET"Test [0]: (read from stdin) -> \n");
	ft_cat(0);
	ft_putstr(RESET"Test [1]: (read from a file) -> \n");
	int fd = open("src/ft_isdigit.s", O_RDONLY);
	ft_cat(fd);
	ft_putstr(RESET"Test [1]: (negative fd) -> \n");
	ft_cat(-78);
}

int		main()
{
	test_bzero();
	test_strcat();
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_toupper();
	test_tolower();
	test_puts();
	test_strlen();
	test_memset();
	test_memcpy();
	test_strdup();
	test_cat();
	return (0);
}
