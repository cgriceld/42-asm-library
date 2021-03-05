#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "libasm.h"

static void		test_strlen(void)
{
	printf("\033[1;35m\n-----------STRLEN-----------\n\n\033[0m");

	printf("\033[1;36m   EMPTY STRING   \n\n\033[0m");
	errno = 42;
	printf("original : %1lu, errno : %d\n", strlen(""), errno);
	errno = 42;
	printf("my : %7lu, errno : %d\n\n", ft_strlen(""), errno);

	printf("\033[1;36m   LONG STRING   \n\n\033[0m");
	errno = 42;
	printf("original : %1lu, errno : %d\n", strlen(LONG_STRING), errno);
	errno = 42;
	printf("my : %9lu, errno : %d\n\n", ft_strlen(LONG_STRING), errno);

	printf("\033[1;36m   MEDIUM STRING   \n\n\033[0m");
	errno = 42;
	printf("original : %1lu, errno : %d\n", strlen(MEDIUM_STRING), errno);
	errno = 42;
	printf("my : %8lu, errno : %d\n\n", ft_strlen(MEDIUM_STRING), errno);

	printf("\033[1;36m   SHORT STRING   \n\n\033[0m");
	errno = 42;
	printf("original : %1lu, errno : %d\n", strlen("hello!"), errno);
	errno = 42;
	printf("my : %7lu, errno : %d\n\n", strlen("hello!"), errno);
}

static void		test_strcpy(void)
{
	char original[200];
	char my[200];

	printf("\033[1;35m\n-----------STRCPY-----------\n\n\033[0m");

	printf("\033[1;36m   EMPTY STRING   \n\n\033[0m");
	bzero(original, 200);
	bzero(my, 200);
	errno = 42;
	printf("original : [%s]\n", strcpy(original, ""));
	printf("errno : %d\n\n", errno);
	errno = 42;
	printf("my :       [%s]\n", ft_strcpy(my, ""));
	printf("errno : %d\n\n", errno);
	if (!strcmp(original, my))
		printf("\033[1;32mCHECK COPY USING STRCMP - OK!\033[0m\n\n");

	printf("\033[1;36m   LONG STRING   \n\n\033[0m");
	bzero(original, 200);
	bzero(my, 200);
	errno = 42;
	printf("original : [%s]\n", strcpy(original, LONG_STRING));
	printf("errno : %d\n\n", errno);
	errno = 42;
	printf("my :       [%s]\n", ft_strcpy(my, LONG_STRING));
	printf("errno : %d\n\n", errno);
	if (!strcmp(original, my))
		printf("\033[1;32mCHECK COPY USING STRCMP - OK!\033[0m\n\n");

	printf("\033[1;36m   MEDIUM STRING   \n\n\033[0m");
	bzero(original, 200);
	bzero(my, 200);
	errno = 42;
	printf("original : [%s]\n", strcpy(original, MEDIUM_STRING));
	printf("errno : %d\n\n", errno);
	errno = 42;
	printf("my :       [%s]\n", ft_strcpy(my, MEDIUM_STRING));
	printf("errno : %d\n\n", errno);
	if (!strcmp(original, my))
		printf("\033[1;32mCHECK COPY USING STRCMP - OK!\033[0m\n\n");

	printf("\033[1;36m   SHORT STRING   \n\n\033[0m");
	bzero(original, 200);
	bzero(my, 200);
	errno = 42;
	printf("original : [%s]\n", strcpy(original, "hello!"));
	printf("errno : %d\n\n", errno);
	errno = 42;
	printf("my :       [%s]\n", ft_strcpy(my, "hello!"));
	printf("errno : %d\n\n", errno);
	if (!strcmp(original, my))
		printf("\033[1;32mCHECK COPY USING STRCMP - OK!\033[0m\n\n");
}

static void		test_strcmp(void)
{
	printf("\033[1;35m\n-----------STRCMP----------\n\n\033[0m");
	printf("\033[1;35mCOMPARE RETURN VALUES OF STRCMP AND FT_STRCMP\n\n\033[0m");
	printf("\033[1;36m   BOTH EMPTY   \n\n\033[0m");
	if (!strcmp("", "") && !ft_strcmp("", ""))
		printf("\033[1;32mBOTH VALUES ARE ZERO - OK!\033[0m\n\n");
	errno = 42;
	strcmp("", "");
	printf("original errno : %d\n", errno);
	errno = 42;
	ft_strcmp("", "");
	printf("my errno : %8d\n\n", errno);

	printf("\033[1;36m   FIRST EMPTY   \n\n\033[0m");
	if (strcmp("", "bla") < 0 && ft_strcmp("", "bla") < 0)
		printf("\033[1;32mBOTH VALUES ARE NEGATIVE - OK!\033[0m\n\n");
	errno = 42;
	strcmp("", "bla");
	printf("original errno : %d\n", errno);
	errno = 42;
	ft_strcmp("", "bla");
	printf("my errno : %8d\n\n", errno);

	printf("\033[1;36m   SECOND EMPTY   \n\n\033[0m");
	if (strcmp("hello", "") > 0 && ft_strcmp("hello", "") > 0)
		printf("\033[1;32mBOTH VALUES ARE POSITIVE - OK!\033[0m\n\n");
	errno = 42;
	strcmp("hello", "");
	printf("original errno : %d\n", errno);
	errno = 42;
	ft_strcmp("hello", "");
	printf("my errno : %8d\n\n", errno);

	printf("\033[1;36m   EQUAL, BOTH SHORT   \n\n\033[0m");
	if (!strcmp("hello", "hello") && !ft_strcmp("hello", "hello"))
		printf("\033[1;32mBOTH VALUES ARE ZERO - OK!\033[0m\n\n");
	errno = 42;
	strcmp("hello", "hello");
	printf("original errno : %d\n", errno);
	errno = 42;
	ft_strcmp("hello", "hello");
	printf("my errno : %8d\n\n", errno);

	printf("\033[1;36m   NOT EQUAL, BOTH SHORT   \n\n\033[0m");
	if (strcmp("hello", "hi") < 0 && ft_strcmp("hello", "hi") < 0)
		printf("\033[1;32mBOTH VALUES ARE NEGATIVE - OK!\033[0m\n\n");
	errno = 42;
	strcmp("hello", "hi");
	printf("original errno : %d\n", errno);
	errno = 42;
	ft_strcmp("hello", "hi");
	printf("my errno : %8d\n\n", errno);

	printf("\033[1;36m   NOT EQUAL, BOTH SHORT (SWITCH)  \n\n\033[0m");
	if (strcmp("hi", "hello") > 0 && ft_strcmp("hi", "hello") > 0)
		printf("\033[1;32mBOTH VALUES ARE POSITIVE - OK!\033[0m\n\n");
	errno = 42;
	strcmp("hi", "hello");
	printf("original errno : %d\n", errno);
	errno = 42;
	ft_strcmp("hi", "hello");
	printf("my errno : %8d\n\n", errno);

	printf("\033[1;36m   EQUAL, BOTH LONG  \n\n\033[0m");
	if (!strcmp(LONG_STRING, LONG_STRING) && !ft_strcmp(LONG_STRING, LONG_STRING))
		printf("\033[1;32mBOTH VALUES ARE ZERO - OK!\033[0m\n\n");
	errno = 42;
	strcmp(LONG_STRING, LONG_STRING);
	printf("original errno : %d\n", errno);
	errno = 42;
	ft_strcmp(LONG_STRING, LONG_STRING);
	printf("my errno : %8d\n\n", errno);

	printf("\033[1;36m   NOT EQUAL, BOTH LONG  \n\n\033[0m");
	if (strcmp(LONG_STRING, LONG_STRING1) < 0 && ft_strcmp(LONG_STRING, LONG_STRING1) < 0)
		printf("\033[1;32mBOTH VALUES ARE NEGATIVE - OK!\033[0m\n\n");
	errno = 42;
	strcmp(LONG_STRING, LONG_STRING1);
	printf("original errno : %d\n", errno);
	errno = 42;
	ft_strcmp(LONG_STRING, LONG_STRING1);
	printf("my errno : %8d\n\n", errno);

	printf("\033[1;36m   NOT EQUAL, BOTH LONG (SWITCH)  \n\n\033[0m");
	if (strcmp(LONG_STRING1, LONG_STRING) > 0 && ft_strcmp(LONG_STRING1, LONG_STRING) > 0)
		printf("\033[1;32mBOTH VALUES ARE POSITIVE - OK!\033[0m\n\n");
	errno = 42;
	strcmp(LONG_STRING1, LONG_STRING);
	printf("original errno : %d\n", errno);
	errno = 42;
	ft_strcmp(LONG_STRING1, LONG_STRING);
	printf("my errno : %8d\n\n", errno);

	printf("\033[1;36m   NOT EQUAL, SHORT LONG  \n\n\033[0m");
	if (strcmp("test string", LONG_STRING) > 0 && ft_strcmp("test string", LONG_STRING) > 0)
		printf("\033[1;32mBOTH VALUES ARE POSITIVE - OK!\033[0m\n\n");
	errno = 42;
	strcmp("test string", LONG_STRING);
	printf("original errno : %d\n", errno);
	errno = 42;
	ft_strcmp("test string", LONG_STRING);
	printf("my errno : %8d\n\n", errno);

	printf("\033[1;36m   NOT EQUAL, LONG SHORT \n\n\033[0m");
	if (strcmp(LONG_STRING, "test string") < 0 && ft_strcmp(LONG_STRING, "test string") < 0)
		printf("\033[1;32mBOTH VALUES ARE NEGATIVE - OK!\033[0m\n\n");
	errno = 42;
	strcmp(LONG_STRING, "test string");
	printf("original errno : %d\n", errno);
	errno = 42;
	ft_strcmp(LONG_STRING, "test string");
	printf("my errno : %8d\n\n", errno);
}

static void		test_write(void)
{
	int fd;
	ssize_t byor, bymy;

	fd = open("write.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);

	printf("\033[1;35m\n-----------WRITE----------\n\n\033[0m");

	printf("\033[1;36m   EMPTY STRING   \n\n\033[0m");
	errno = 42;
	printf("original : %zd, errno : %d\n\n", write(fd, "", strlen("")), errno);
	errno = 42;
	printf("my : %7zd, errno : %d\n\n", ft_write(fd, "", strlen("")), errno);

	printf("\033[1;36m   ZERO LENGTH   \n\n\033[0m");
	errno = 42;
	printf("original : %zd, errno : %d\n\n", write(fd, "hello", 0), errno);
	errno = 42;
	printf("my : %7zd, errno : %d\n\n", ft_write(fd, "hello", 0), errno);

	printf("\033[1;36m   NEG LENGTH   \n\n\033[0m");
	errno = 42;
	printf("original : %zd, errno : %d\n\n", write(fd, "hello", -21), errno);
	errno = 42;
	printf("my : %8zd, errno : %d\n\n", ft_write(fd, "hello", -21), errno);

	printf("\033[1;36m   NULL STRING   \n\n\033[0m");
	errno = 42;
	printf("original : %zd, errno : %d\n\n", write(fd, NULL, 21), errno);
	errno = 42;
	printf("my : %8zd, errno : %d\n\n", ft_write(fd, NULL, 21), errno);

	printf("\033[1;36m   NEG FD   \n\n\033[0m");
	errno = 42;
	printf("original : %zd, errno : %d\n\n", write(-21, "error", strlen("error")), errno);
	errno = 42;
	printf("my : %8zd, errno : %d\n\n", ft_write(-21, "error", strlen("error")), errno);

	printf("\033[1;35mRESULTS OF BELOW 3 TESTS YOU CAN SEE IN WRITE.TXT FILE\n\n\033[0m");

	printf("\033[1;36m   WRITE SHORT   \n\n\033[0m");
	errno = 42;
	printf("original : %zd, errno : %d\n\n", write(fd, MEDIUM_STRING, strlen(MEDIUM_STRING)), errno);
	write(fd, "\n", 1);
	errno = 42;
	printf("my : %8zd, errno : %d\n\n", ft_write(fd, MEDIUM_STRING, strlen(MEDIUM_STRING)), errno);

	write(fd, "\n", 1);

	printf("\033[1;36m   WRITE LONG   \n\n\033[0m");
	errno = 42;
	printf("original : %zd, errno : %d\n\n", write(fd, LONG_STRING, strlen(LONG_STRING)), errno);
	write(fd, "\n", 1);
	errno = 42;
	printf("my : %9zd, errno : %d\n\n", ft_write(fd, LONG_STRING, strlen(LONG_STRING)), errno);

	write(fd, "\n", 1);

	printf("\033[1;36m   WRITE SPACES   \n\n\033[0m");
	errno = 42;
	printf("original : %zd, errno : %d\n\n", write(fd, "              ", strlen("              ")), errno);
	write(fd, "\n", 1);
	errno = 42;
	printf("my : %8zd, errno : %d\n\n", ft_write(fd, "              ", strlen("              ")), errno);

	close(fd);

	printf("\033[1;36m   STDOUT SHORT   \n\033[0m");
	printf("\n");
	errno = 42;
	write(1, "[", 1);
	byor = write(1, MEDIUM_STRING, strlen(MEDIUM_STRING));
	write(1, "]", 1);
	printf("\noriginal : %zd, errno : %d\n\n", byor, errno);
	errno = 42;
	write(1, "[", 1);
	bymy = ft_write(1, MEDIUM_STRING, strlen(MEDIUM_STRING));
	write(1, "]", 1);
	printf("\nmy : %8zd, errno : %d\n\n", bymy, errno);

	printf("\033[1;36m   STDOUT LONG   \n\033[0m");
	printf("\n");
	errno = 42;
	write(1, "[", 1);
	byor = write(1, LONG_STRING, strlen(LONG_STRING));
	write(1, "]", 1);
	printf("\noriginal : %zd, errno : %d\n\n", byor, errno);
	errno = 42;
	write(1, "[", 1);
	bymy = ft_write(1, LONG_STRING, strlen(LONG_STRING));
	write(1, "]", 1);
	printf("\nmy : %9zd, errno : %d\n\n", bymy, errno);

	printf("\033[1;36m   STDOUT EMPTY   \n\033[0m");
	printf("\n");
	errno = 42;
	write(1, "[", 1);
	byor = write(1, "", strlen(""));
	write(1, "]", 1);
	printf("\noriginal : %zd, errno : %d\n\n", byor, errno);
	errno = 42;
	write(1, "[", 1);
	bymy = ft_write(1, "", strlen(""));
	write(1, "]", 1);
	printf("\nmy : %7zd, errno : %d\n\n", bymy, errno);
}

static void		test_read(void)
{
	int fd;
	char bufor[200];
	char bufmy[200];
	ssize_t byor, bymy;

	printf("\033[1;35m\n-----------READ----------\n\n\033[0m");
	printf("\033[1;35mREAD.TXT IS CREATED AND USED FOR READING\n\n\033[0m");
	printf("\033[1;36m   ZERO LENGTH   \n\n\033[0m");
	fd = open("read.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	write(fd, LONG_STRING, strlen(LONG_STRING));
	errno = 42;
	bzero(bufor, 200);
	bzero(bufmy, 200);
	printf("original : %zd, errno : %d\n", read(fd, bufor, 0), errno);
	printf("[%s]\n", bufor);
	close(fd);
	fd = open("read.txt", O_RDWR);
	errno = 42;
	printf("my : %7zd, errno : %d\n", ft_read(fd, bufmy, 0), errno);
	printf("[%s]\n\n", bufmy);
	close(fd);

	printf("\033[1;36m   NEG LENGTH   \n\n\033[0m");
	fd = open("read.txt", O_RDWR);
	errno = 42;
	bzero(bufor, 200);
	bzero(bufmy, 200);
	printf("original : %zd, errno : %d\n", read(fd, bufor, -21), errno);
	printf("[%s]\n", bufor);
	close(fd);
	fd = open("read.txt", O_RDWR);
	errno = 42;
	printf("my : %8zd, errno : %d\n", ft_read(fd, bufmy, -21), errno);
	printf("[%s]\n\n", bufmy);
	close(fd);

	printf("\033[1;36m   NULL STRING   \n\n\033[0m");
	fd = open("read.txt", O_RDWR);
	errno = 42;
	bzero(bufor, 200);
	bzero(bufmy, 200);
	printf("original : %zd, errno : %d\n", read(fd, NULL, 21), errno);
	printf("[%s]\n", bufor);
	close(fd);
	fd = open("read.txt", O_RDWR);
	errno = 42;
	printf("my : %8zd, errno : %d\n", ft_read(fd, NULL, 21), errno);
	printf("[%s]\n\n", bufmy);
	close(fd);

	printf("\033[1;36m   NEG FD   \n\n\033[0m");
	fd = open("read.txt", O_RDWR);
	errno = 42;
	bzero(bufor, 200);
	bzero(bufmy, 200);
	printf("original : %zd, errno : %d\n", read(-42, bufor, 21), errno);
	printf("[%s]\n", bufor);
	close(fd);
	fd = open("read.txt", O_RDWR);
	errno = 42;
	printf("my : %8zd, errno : %d\n", ft_read(-42, bufmy, 21), errno);
	printf("[%s]\n\n", bufmy);
	close(fd);

	printf("\033[1;36m   READ SHORT   \n\n\033[0m");
	fd = open("read.txt", O_RDWR);
	errno = 42;
	bzero(bufor, 200);
	bzero(bufmy, 200);
	printf("original : %zd, errno : %d\n", read(fd, bufor, 21), errno);
	printf("[%s]\n", bufor);
	close(fd);
	fd = open("read.txt", O_RDWR);
	errno = 42;
	printf("my : %8zd, errno : %d\n", ft_read(fd, bufmy, 21), errno);
	printf("[%s]\n\n", bufmy);
	close(fd);

	printf("\033[1;36m   READ LONG   \n\n\033[0m");
	fd = open("read.txt", O_RDWR);
	errno = 42;
	bzero(bufor, 200);
	bzero(bufmy, 200);
	printf("original : %zd, errno : %d\n", read(fd, bufor, 200), errno);
	printf("[%s]\n", bufor);
	close(fd);
	fd = open("read.txt", O_RDWR);
	errno = 42;
	printf("my : %9zd, errno : %d\n", ft_read(fd, bufmy, 200), errno);
	printf("[%s]\n\n", bufmy);
	close(fd);

	printf("\033[1;36m   STDOUT SHORT   \n\n\033[0m");
	errno = 42;
	bzero(bufor, 200);
	bzero(bufmy, 200);
	printf("%s\n", "Enter short string and press Enter : ");
	byor = read(0, bufor, 200);
	printf("original : %zd, errno : %d\n", byor, errno);
	printf("[%s]\n", bufor);
	printf("%s\n", "Enter exactly same short string and press Enter : ");
	bymy = read(0, bufmy, 200);
	printf("my : %8zd, errno : %d\n", bymy, errno);
	printf("[%s]\n\n", bufmy);

	printf("\033[1;36m   STDOUT LONG   \n\n\033[0m");
	errno = 42;
	bzero(bufor, 200);
	bzero(bufmy, 200);
	printf("%s\n", "Enter long string and press Enter : ");
	byor = read(0, bufor, 200);
	printf("original : %zd, errno : %d\n", byor, errno);
	printf("[%s]\n", bufor);
	printf("%s\n", "Enter exactly same long string and press Enter : ");
	bymy = read(0, bufmy, 200);
	printf("my : %zd, errno : %d\n", bymy, errno);
	printf("[%s]\n\n", bufmy);

	printf("\033[1;36m   STDOUT EMPTY   \n\n\033[0m");
	errno = 42;
	bzero(bufor, 200);
	bzero(bufmy, 200);
	printf("%s\n", "Just press Enter : ");
	byor = read(0, bufor, 200);
	printf("original : %zd, errno : %d\n", byor, errno);
	printf("[%s]\n", bufor);
	printf("%s\n", "Again just press Enter : ");
	bymy = read(0, bufmy, 200);
	printf("my : %zd, errno : %d\n", bymy, errno);
	printf("[%s]\n\n", bufmy);
}

static void		test_strdup(void)
{
	char *ordup;
	char *mydup;

	printf("\033[1;35m\n-----------STRDUP----------\n\n\033[0m");

	printf("\033[1;36m   EMPTY STRING   \n\n\033[0m");
	errno = 42;
	printf("original : [%s]\n", ordup = strdup(""));
	printf("errno : %d\n", errno);
	errno = 42;
	printf("my :       [%s]\n", mydup = ft_strdup(""));
	printf("errno : %d\n\n", errno);
	if (!strcmp(ordup, mydup))
		printf("\033[1;32mCHECK DUPLICATE USING STRCMP - OK!\033[0m\n\n");
	free(ordup);
	free(mydup);

	printf("\033[1;36m   LONG STRING   \n\n\033[0m");
	errno = 42;
	printf("original : [%s]\n", ordup = strdup(LONG_STRING));
	printf("errno : %d\n", errno);
	errno = 42;
	printf("my :       [%s]\n", mydup = ft_strdup(LONG_STRING));
	printf("errno : %d\n\n", errno);
	if (!strcmp(ordup, mydup))
		printf("\033[1;32mCHECK DUPLICATE USING STRCMP - OK!\033[0m\n\n");
	free(ordup);
	free(mydup);

	printf("\033[1;36m   MEDIUM STRING   \n\n\033[0m");
	errno = 42;
	printf("original : [%s]\n", ordup = strdup(MEDIUM_STRING));
	printf("errno : %d\n", errno);
	errno = 42;
	printf("my :       [%s]\n", mydup = ft_strdup(MEDIUM_STRING));
	printf("errno : %d\n\n", errno);
	if (!strcmp(ordup, mydup))
		printf("\033[1;32mCHECK DUPLICATE USING STRCMP - OK!\033[0m\n\n");
	free(ordup);
	free(mydup);

	printf("\033[1;36m   SHORT STRING   \n\n\033[0m");
	errno = 42;
	printf("original : [%s]\n", ordup = strdup("hello"));
	printf("errno : %d\n", errno);
	errno = 42;
	printf("my :       [%s]\n", mydup = ft_strdup("hello"));
	printf("errno : %d\n\n", errno);
	if (!strcmp(ordup, mydup))
		printf("\033[1;32mCHECK DUPLICATE USING STRCMP - OK!\033[0m\n\n");
	free(ordup);
	free(mydup);
}

int				main(void)
{
	test_strlen();
	test_strcpy();
	test_strcmp();
	test_write();
	test_read();
	test_strdup();

	return (0);
}