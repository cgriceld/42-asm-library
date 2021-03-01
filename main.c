#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void		test_strlen(void)
{
	printf("\n");
	printf("-----------STRLEN-----------\n");
	errno = 42;
	printf("original : %lu, errno : %d\n", strlen(""), errno);
	errno = 42;
	printf("original : %lu, errno : %d\n", strlen("this is the house that jack built"), errno);
	errno = 42;
	printf("original : %lu, errno : %d\n", strlen("hello!"), errno);
	printf("\n");
}

static void		test_strdup(void)
{
	char *or;

	printf("\n");
	printf("-----------STRDUP-----------\n");
	errno = 42;
	printf("original : %s, errno : %d\n", or = strdup(""), errno);
	free(or);
	printf("original : %s, errno : %d\n", or = strdup("this is the house that jack built"), errno);
	free(or);
	printf("original : %s, errno : %d\n", or = strdup("hello!"), errno);
	free(or);
	printf("\n");
}

static void		test_write(void)
{
	int or;

	printf("\n");
	printf("-----------WRITE-----------\n");
	printf("\n");
	errno = 42;
	printf("   EMPTY STRING   \n");
	printf("original : %d, errno : %d\n", or = write(1, "", strlen("")), errno);
	printf("\n");
	errno = 42;
	printf("   NEGATIVE FD   \n");
	printf("original : %d, errno : %d\n", or = write(-21, "", strlen("")), errno);
	printf("\n");
	errno = 42;
	printf("   NULL STRING   \n");
	printf("original : %d, errno : %d\n", or = write(1, NULL, 21), errno);
	printf("\n");
	errno = 42;
	printf("   NEGATIVE LENGTH   \n");
	printf("original : %d, errno : %d\n", or = write(1, "hello", -21), errno);
	printf("\n");
	errno = 42;
	printf("   ZERO LENGTH   \n");
	printf("original : %d, errno : %d\n", or = write(1, "hello", 0), errno);
}

int				main(void)
{
	test_strlen();
	test_strdup();
	test_write();
	return (0);
}