#include <unistd.h>
#include <stdarg.h>

void    putnbr(int number)
{
    if (number >= 0 && number <= 9)
    {
        number += 48;
        write(1, &number, 1);
    } else if (number > 9)
    {
        putnbr(number / 10);
        putnbr(number % 10);
    } else if (number < 0)
    {
        write(1, "-", 1);
        putnbr(number * (-1));
    }
}
void    putfnbr(double number)
{
    int a = (int) number;
    putnbr(a);
    write(1, ".", 1);
    int i = 6;
    while (i > 0)
    {
        number = (number - a) * (10);
        a = (int) number;
        putnbr(a);
        i--;
    }
}
void    putstr(char *str)
{
    int i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }

}

void    ft_printf(char *format, ...)
{
    int i = 0;
    va_list countPtr;
    _crt_va_start(countPtr, format);
    while(format[i])
    {
        if (format[i] != 37)
        {
            write(1, &format[i], 1);
        }
        else
        {
            switch (format[i + 1]) {
            case 's':
                putstr(_crt_va_arg(countPtr, char *));
                i++;
                break;
            case 'd':
                putnbr(_crt_va_arg(countPtr, int));
                i++;
                break;
            case 'f':
                putfnbr(_crt_va_arg(countPtr, double));
                i++;
                break;
            default:
                break;
            }
        }
        i++;
    }
    _crt_va_end(countPtr);
}


int main(void)
{

    ft_printf("My name is %s and I'm %d years old and I'm a %s, and my stuff dagree is %f", "Hssain", 23, "Programmer", 99.5);

    return (0);
}