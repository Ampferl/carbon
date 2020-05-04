#ifndef ENVIRON_H
#define ENVIRON_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "data.h"
#include "type.h"
#include "parse.h"
#include "parseUtil.h"

typedef struct {
    Map *scopeDict;

    Map *curScope;
    Wrap *curBindObj;
    Instance *curIns;

    List *callStack;
    List *instanceStack;

    Wrap *returnValue;
    int isReturn;
    int isBreak;
    int isContinue;

} Environ;


Environ *environ_create();

void environ_addNameSapce(Environ *env,char *str);
void environ_importNameSapce(Environ *env,char *str);

void environ_init(Environ *env);

void environ_initStatic(Environ *env);
void environ_initDynamic(Environ *env);
void environ_initBuiltin(Environ *env);

void environ_brigeNativeFunction(Environ *env,Function *func);
void environ_brigeNativeClass(Environ *env,Class *cls);

void environ_eval(Environ *env,ASTNode *astNode);
void environ_evalStr(Environ *env,char *str);

void environ_free(Environ *env);


#ifdef __cplusplus
}
#endif

#endif




