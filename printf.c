#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - prinf
 * @format - format
 * Return: 0
 */
int _putchar(char c) {
    return write(1, &c, 1);
}

int _printf(const char *format, ...) {
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%' && *(format + 1) != '\0') {
            format++; // Move past the '%'
            switch (*format) {
                case 'c': {
                    char character = va_arg(args, int);
                    _putchar(character);
                    count++;
                    break;
                }
                case 's': {
                    char *str = va_arg(args, char *);
                    if (str != NULL) {
                        while (*str != '\0') {
                            _putchar(*str);
                            count++;
                            str++;
                        }
                    }
                    break;
                }
                case '%':
                    _putchar('%');
                    count++;
                    break;
                default:
                    _putchar('%');
                    _putchar(*format);
                    count += 2;
                    break;
            }
        } else {
            _putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);

    return (count);
}
