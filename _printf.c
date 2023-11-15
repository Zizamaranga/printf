#include "main.h"
#include <unistd.h>

/**
 * _printf - Custom printf
 * @format: Format str
 * @...: Variable args
 *
 * Return: Number of chars printed (excluding null byte)
 */
int _printf(const char *format, ...) 
{
    
	int count = 0;
	
	va_list args;
	va_start(args, format);


    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c':
                    _putchar(va_arg(args, int));
                    count++;
                    break;
                case 's': {
                    char *str = va_arg(args, char *);
                    while (*str) {
                        _putchar(*str);
                        str++;
                        count++;
                    }
                    break;
                }
                case '%':
                    _putchar('%');
                    count++;
                    break;
                default:
                    _putchar('%');
                    count++;
                    _putchar(*format);
                    break;
            }
        } else {
            _putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);

    return count;
}

int _putchar(char c) {
    return write(1, &c, 1);
}

