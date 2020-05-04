#ifndef ERRORENUM_H
#define ERRORENUM_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    ErrorType_LexError=1,

    ErrorType_ExprSyntaxError,
    ErrorType_AssignSyntaxError,
    ErrorType_ContinueSyntaxError,
    ErrorType_BreakSyntaxError,
    ErrorType_ReturnSyntaxError,
    ErrorType_UpSyntaxError,
    ErrorType_GlobalSyntaxError,
    ErrorType_FieldSyntaxError,
    ErrorType_YieldSyntaxError,
    ErrorType_StaticSyntaxError,
    ErrorType_ImportSyntaxError,
    ErrorType_PrintSyntaxError,

    ErrorType_IfSyntaxError,
    ErrorType_WhileSyntaxError,
    ErrorType_ForSyntaxError,
    ErrorType_FunctionSyntaxError,
    ErrorType_ClassSyntaxError,

    ErrorType_SubscriptError,
    ErrorType_PropertyError,
    ErrorType_CallError,
    ErrorType_NewError,
    ErrorType_OperateError,

} ErrorType;


#ifdef __cplusplus
}
#endif

#endif




