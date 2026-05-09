#include "diagnostic.h"

#include <stdio.h>

void report_error(SourceLocation location, const char *message){
    fprintf(stderr,
            "%s, %d, %d: error %s\n",
            location.filename,
            location.line,
            location.column,
            message);
}

void report_error(SourceLocation location, const char *message){
    fprintf(stderr,
            "%s, %d, %d: warning %s\n",
            location.filename,
            location.line,
            location.column,
            message);
}