# st-ft_printf (2020/07/31)

## INFO
Write a library that contains ft_printf, a function that will mimic the real printf.

- The prototype of ft_printf should be int ft_printf(const char *, ...);
- You have to recode the libc’s printf function
- It must not do the buffer management like the real printf
- It will manage the following conversions: cspdiuxX%
- It will manage any combination of the following flags: ’-0.*’ and minimum field width with all conversions
- It will be compared with the real printf
- You must use the command ar to create your librairy, using the command libtool is forbidden.

## MAKE

make

make clean

make fclean

## TESTS
cd 42TESTERS-PRINTF

bash runtest.sh

## Additional Information
man 3 printf
man 3 stdarg

https://ru.wikipedia.org/wiki/Printf

http://www.c-cpp.ru/content/printf
