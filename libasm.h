#ifndef LIBASM_H
# define LIBASM_H

#include <stdlib.h>

#define LONG_STRING "Never imagine yourself not to be otherwise than what it "\
"might apper to other that what you were or might have been was not otherwise"\
" than what you had been would have appeared to them to be otherwise"

#define LONG_STRING1 "Never imagine yourself not to be otherwise than what it "\
"might apper to other that what you were or might have been was not otherwise"\
"That lay in the house that Jack built"

#define MEDIUM_STRING "this is the house that jack built"

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);

#endif