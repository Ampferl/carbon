#ifndef PARSE_H
#define PARSE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "lexer.h"
#include "error.h"

typedef struct ASTNode{
    ASTType type;
    ASTOp op;

    union {
        int outFlag;
        long long l;
        double d;
    } value;

    char *data;
    Wrap *wrap;

    struct ASTNode *parent;
    int childLength;
    struct ASTNode **childArr;

    struct ASTNode *next;

    unsigned int row;
    unsigned int column;

} ASTNode;


int parseToken(Token *token,ASTNode **node);

void freeASTNode(ASTNode *node);
void debugASTNode(ASTNode *node);


#ifdef __cplusplus
}
#endif

#endif







