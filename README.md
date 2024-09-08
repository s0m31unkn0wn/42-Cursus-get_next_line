Base is just a copy of bonus, because bonus, functionally, includes base. 

Passes ordinary francinette, has circa 20% KOs in the strict but moulinette doesn't care (humans grading you - might).

If i were to write "base only" the only difference is that static char leftov in the char *get_next_line is not an array, correspondingly in 4 spots where
you see "leftov[fd]" you'll have simply leftov because there's just one, and you don't need to specify MAX_FD in the macros in .h

My libft ft_calloc calls ft_memset, and ft_strdup calls ft_strcpy, but i only had 7 spots for utils while i wanted 9, so i had to rewrite calloc to put memset in it, as well as rewrite strdup to incorporate strcpy.

For later use, such as in pipex, the bonus version and MAX_FD macros is included into libft.h to directly use the already existing functions.
