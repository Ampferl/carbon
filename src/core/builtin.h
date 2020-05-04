#ifndef BUILTIN_H
#define BUILTIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "lexer.h"


Wrap *wrap_setValueWithKey(Wrap *wrap,char *key,Wrap *value);
Wrap *wrap_setValueWithIndex(Wrap *wrap,int index,Wrap *value);
Wrap *wrap_getValueWithKey(Wrap *wrap,char *key);
Wrap *wrap_getValueWithIndex(Wrap *wrap,int index);

Wrap *wrap_not(Wrap *wrap);
Wrap *wrap_reverse(Wrap *wrap);
Wrap *wrap_neggative(Wrap *wrap);

Wrap *wrap_mul(Wrap *wrap1,Wrap *wrap2);
Wrap *wrap_div(Wrap *wrap1,Wrap *wrap2);
Wrap *wrap_mod(Wrap *wrap1,Wrap *wrap2);
Wrap *wrap_add(Wrap *wrap1,Wrap *wrap2);
Wrap *wrap_sub(Wrap *wrap1,Wrap *wrap2);
Wrap *wrap_leftShift(Wrap *wrap1,Wrap *wrap2);
Wrap *wrap_rightShift(Wrap *wrap1,Wrap *wrap2);
Wrap *wrap_gr(Wrap *wrap1,Wrap *wrap2);
Wrap *wrap_ge(Wrap *wrap1,Wrap *wrap2);
Wrap *wrap_ls(Wrap *wrap1,Wrap *wrap2);
Wrap *wrap_le(Wrap *wrap1,Wrap *wrap2);
Wrap *wrap_eq(Wrap *wrap1,Wrap *wrap2);
Wrap *wrap_ne(Wrap *wrap1,Wrap *wrap2);
Wrap *wrap_xor(Wrap *wrap1,Wrap *wrap2);
Wrap *wrap_xand(Wrap *wrap1,Wrap *wrap2);
Wrap *wrap_xer(Wrap *wrap1,Wrap *wrap2);
Wrap *wrap_and(Wrap *wrap1,Wrap *wrap2);
Wrap *wrap_or(Wrap *wrap1,Wrap *wrap2);

Wrap *wrap_builtinNumber();
Wrap *wrap_builtinBoolean();
Wrap *wrap_builtinString();
Wrap *wrap_builtinList();
Wrap *wrap_builtinMap();
Wrap *wrap_builtinFunction();
Wrap *wrap_builtinClass();

Wrap *String_new(Wrap *data);
Wrap *String_length(Wrap *str);
Wrap *String_add(Wrap *str1,Wrap *str2);
Wrap *String_split(Wrap *str1,Wrap *data);
Wrap *String_setValue(Wrap *str,Wrap *c);
Wrap *String_getValue(Wrap *str);
Wrap *String_subString(Wrap *str,Wrap *start,Wrap *end);
Wrap *String_toString(Wrap *str);
Wrap *String_free(Wrap *str);

Wrap *List_new(Wrap *length);
Wrap *List_length(Wrap *list);
Wrap *List_push(Wrap *list,Wrap *value);
Wrap *List_pop(Wrap *list);
Wrap *List_indexOf(Wrap *list,Wrap *value);
Wrap *List_lastIndexOf(Wrap *list,Wrap *value);
Wrap *List_setValue(Wrap *list,Wrap *index,Wrap *value);
Wrap *List_getValue(Wrap *list,Wrap *index);
Wrap *List_toString(Wrap *list);
Wrap *List_free(Wrap *list);

Wrap *Map_new();
Wrap *Map_length(Wrap *map);
Wrap *Map_setValue(Wrap *map,Wrap *key,Wrap *value);
Wrap *Map_getValue(Wrap *map,Wrap *key);
Wrap *Map_hasKey(Wrap *map,Wrap *key);
Wrap *Map_keyArr(Wrap *map);
Wrap *Map_valueArr(Wrap *map);
Wrap *Map_toString(Wrap *map);
Wrap *Map_free(Wrap *map);






#ifdef __cplusplus
}
#endif

#endif







