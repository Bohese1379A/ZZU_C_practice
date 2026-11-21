#ifndef ZZU_LAB_INPUT_H
#define ZZU_LAB_INPUT_H

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* Consume the entire token, including any bytes that exceed the buffer. */
static inline int lab_read_token(char *buffer, size_t capacity)
{
    if (capacity == 0)
        return 0;
    int ch;
    do {
        ch = getchar();
    } while (ch != EOF && isspace(ch));
    if (ch == EOF)
        return 0;

    size_t length = 0;
    int fits = 1;
    do {
        if (length + 1 < capacity && ch != '\0')
            buffer[length++] = (char)ch;
        else
            fits = 0;
        ch = getchar();
    } while (ch != EOF && !isspace(ch));
    buffer[length] = '\0';
    return fits;
}

static inline int lab_parse_int(const char *text, int *value)
{
    char *end;
    errno = 0;
    long parsed = strtol(text, &end, 10);
    if (end == text || *end != '\0' || errno == ERANGE ||
        parsed < INT_MIN || parsed > INT_MAX)
        return 0;
    *value = (int)parsed;
    return 1;
}

static inline int lab_parse_double(const char *text, double *value)
{
    char *end;
    errno = 0;
    double parsed = strtod(text, &end);
    if (end == text || *end != '\0' || errno == ERANGE || !isfinite(parsed))
        return 0;
    *value = parsed;
    return 1;
}

static inline int lab_read_int(int *value)
{
    char token[64];
    return lab_read_token(token, sizeof token) && lab_parse_int(token, value);
}

static inline int lab_read_double(double *value)
{
    char token[128];
    return lab_read_token(token, sizeof token) && lab_parse_double(token, value);
}

static inline int lab_read_float(float *value)
{
    char token[128], *end;
    if (!lab_read_token(token, sizeof token))
        return 0;
    errno = 0;
    float parsed = strtof(token, &end);
    if (end == token || *end != '\0' || errno == ERANGE || !isfinite(parsed))
        return 0;
    *value = parsed;
    return 1;
}

/* Read one text line, preserving spaces and accepting a final line without LF. */
static inline int lab_read_line(char *buffer, size_t capacity)
{
    if (capacity == 0)
        return 0;
    int ch;
    size_t length = 0;
    int fits = 1;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch == '\r') {
            int next = getchar();
            if (next == EOF || next == '\n') {
                ch = next;
                break;
            }
            ungetc(next, stdin);
        }
        if (length + 1 < capacity && ch != '\0')
            buffer[length++] = (char)ch;
        else
            fits = 0;
    }
    buffer[length] = '\0';
    return fits && (ch != EOF || length != 0);
}

#endif
