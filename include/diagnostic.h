#ifndef COOL_DIAGNOSTIC_H
#define COOL_DIAGNOSTIC_H

typedef struct {
    const char *filename;
    int line;
    int column;
} SourceLocation;

void report_error(SourceLocation location, const char *message);
void report_warning(SourceLocation location, const char *message);

#endif