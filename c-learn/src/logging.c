#include "logging.h"
#include <stdio.h>

void log_error(const char *msg) {
    fprintf(stderr, "\033[31mError: %s\033[0m\n", msg);
}