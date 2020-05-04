#ifndef ERROR_H
#define ERROR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "enum.h"
#include "lexer.h"


typedef struct ErrorInfor{
    ErrorType type;

    unsigned int row;
    unsigned int column;

    char *data;

} ErrorInfor;

void error_throwError(ErrorType type,Token *token);


#ifdef __cplusplus
}
#endif

#endif
