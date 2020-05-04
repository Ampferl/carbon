#ifndef DATA_H
#define DATA_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "enum.h"

typedef enum {
    FieldDesc_IsNull=0,

    FieldDesc_IsRead=1,
    FieldDesc_IsWrite=2,

    FieldDesc_IsGet=4,
    FieldDesc_IsSet=8,

    FieldDesc_IsCall=16,
    FieldDesc_IsNew=32,
    FieldDesc_IsBind=64,

} FieldDesc;

typedef enum {
    FunctionType_Normal=0,
    FunctionType_NativeFunction=1,

} FunctionType;

typedef enum {
    ClassType_Normal=0,
    ClassType_NativeClass=1,

} ClassType;

struct Class;

typedef struct Wrap{
    DataType type;
    union {
        signed char c1;
        unsigned char c2;

        short s1;
        unsigned short s2;

        int i1;
        unsigned int i2;

        float f;

        long long l;
        double d;

        int isSuper;
        FieldDesc fieldDesc;
    } value;

    FieldDesc _fieldDesc;
    int _referNum;

    void *data;

} Wrap;

typedef struct Node{
    Wrap *data;
    void *userData;

    struct Node *next;
    struct Node *pre;

} Node;

typedef struct String{
    struct Class *cls;

    int length;
    int capacity;

    char *data;
} String;

typedef struct List{
    struct Class *cls;

    int length;
    int capacity;

    Node *head;
    Node *tail;

} List;

typedef struct Map{
    struct Class *cls;

    int length;
    int capacity;


    Node *head;
    Node *tail;

} Map;

typedef Wrap *(*WrapMethod)(Wrap *self,List *list);

typedef struct Function{
    struct Class *cls;

    FunctionType type;
    char *name;
    Map *dict;

    Wrap *bindObj;
    struct Function *parent;

    List *argList;
    void *code;

    char **argNameArr;
    int argArrLength;
    int *outFlagArr;

    Map *globalScopeDict;
    Map *upScopeDict;
    Map *inScopeDict;
    List *chainScopeList;

} Function;

typedef struct Class{
    struct Class *cls;

    ClassType type;
    char *name;
    struct Class *base;

    Map *clsDescDict;
    Map *insDescDict;

    Map *dict;

} Class;

typedef struct Instance{
    Class *cls;

    Map *dict;

} Instance;


typedef struct NativeFunction{
    char *name;
    Map *dict;

    Wrap *bindObj;
    struct Function *parent;


    WrapMethod method;

    char **argNameArr;
    int argArrLength;
    int *outFlagArr;

} NativeFunction;

typedef struct NativeClass{
    char *name;

    NativeFunction *functionArr;

} NativeClass;

typedef struct NativeData{
    char *name;

} NativeData;


Wrap *wrap_wrapNull();
Wrap *wrap_wrapTrue();
Wrap *wrap_wrapFalse();

Wrap *wrap_wrapByte(signed char c);
Wrap *wrap_wrapUByte(unsigned char c);
Wrap *wrap_wrapShort(short c);
Wrap *wrap_wrapUShort(unsigned short c);

Wrap *wrap_wrapInt(int l);
Wrap *wrap_wrapUInt(unsigned int l);
Wrap *wrap_wrapLong(long l);
Wrap *wrap_wrapLongLong(long long l);

Wrap *wrap_wrapFloat(float d);
Wrap *wrap_wrapDouble(double d);

Wrap *wrap_wrapString(String *str);
Wrap *wrap_wrapList(List *list);
Wrap *wrap_wrapMap(Map *map);
Wrap *wrap_wrapFunction(Function *func);
Wrap *wrap_wrapClass(Class *cls);
Wrap *wrap_wrapInstance(Instance *ins);

Wrap *wrap_wrapNativeFunction(NativeFunction *func);
Wrap *wrap_wrapOpaquePointer(void *data);

Wrap *wrap_wrapRefData(Wrap **data);

void wrap_retain(Wrap *wrap);
void wrap_release(Wrap *wrap);
char *wrap_toString(Wrap * wrap);


String *string_create(char *data);
int string_length(String *str);
char *string_add(String *str1,char *data);
List *string_split(String *str1,char *data);
int string_setValue(String *str,char c);
char *string_getValue(String *str);
char *string_subString(String *str,int start,int end);

char *string_toString(String *str);
void string_free(String *str);


List *list_create(int length);
int list_length(List *list);
List *list_push(List *list,Wrap *value);
Wrap *list_pop(List *list);
int list_indexOf(List *list,Wrap *value);
int list_lastIndexOf(List *list,Wrap *value);
void list_setValue(List *list,int index,Wrap *value);
Wrap *list_getValue(List *list,int index);

char *list_toString(List *list);
void list_free(List *list);



Map *map_create();
int map_length(Map *map);
void map_setValue(Map *map,char *key,Wrap *value);
void map_setRefValue(Map *map,char *key,Wrap *value);
Wrap *map_getValue(Map *map,char *key);
Wrap *map_getRefValue(Map *map,char *key);
int map_hasKey(Map *map,char *key);
char **map_keyArr(Map *map);
List *map_valueArr(Map *map);

char *map_toString(Map *map);
void map_free(Map *map);



Function *function_create(char *name,char **argNameArr,int *outFlagArr,int length);
void function_bind(Function *func,Wrap *obj);
Wrap *function_unBind(Function *func);
void function_setValue(Function *func,char *key,Wrap *value);
Wrap *function_getValue(Function *func,char *key);
void function_setInScopeValue(Function *func,char *name,Wrap *value);
Wrap *function_getInScopeValue(Function *func,char *name);
void function_setUpScopeValue(Function *func,char *name,Wrap *value);
Wrap *function_getUpScopeValue(Function *func,char *name);

char *function_toString(Function *func);
void function_free(Function *func);



Class *class_create(char *name,Class *base);
void class_addClsField(Class *cls,char *name,Wrap *value);
void class_addInsField(Class *cls,char *name,Wrap *value);
void class_addClsWrapMethod(Class *cls,char *name,FieldDesc desc,int *outFlag,WrapMethod method);
void class_addInsWrapMethod(Class *cls,char *name,FieldDesc desc,int *outFlag,WrapMethod method);
void class_setValue(Class *cls,char *key,Wrap *value);
Wrap *class_getValue(Class *cls,char *key,int isSuper);
Class *class_base(Class *cls);

char *class_toString(Class *cls);
void class_free(Class *cls);


Wrap *instance_create(Class *cls,List *argList);
void instance_setValue(Instance *ins,char *key,Wrap *value);
Wrap *instance_getValue(Instance *ins,char *key,int isSuper);
Class *instance_class(Instance *ins);

char *instance_toString(Instance *ins);
void instance_free(Instance *ins);



Wrap *wrap_binaryCal(Wrap *leftWrap,Wrap *rightWrap,ASTOp op);



#ifdef __cplusplus
}
#endif

#endif




