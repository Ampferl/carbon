#ifndef TYPE_H
#define TYPE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

Wrap *String_new(Wrap *self,List *arglist);
Wrap *String_length(Wrap *self,List *arglist);
Wrap *String_add(Wrap *self,List *arglist);
Wrap *String_split(Wrap *self,List *arglist);
Wrap *String_setValue(Wrap *self,List *arglist);
Wrap *String_getValue(Wrap *self,List *arglist);
Wrap *String_subString(Wrap *self,List *arglist);
Wrap *String_toString(Wrap *self,List *arglist);
Wrap *String_free(Wrap *self,List *arglist);


Wrap *List_new(Wrap *self,List *arglist);
Wrap *List_length(Wrap *self,List *arglist);
Wrap *List_push(Wrap *self,List *arglist);
Wrap *List_pop(Wrap *self,List *arglist);
Wrap *List_indexOf(Wrap *self,List *arglist);
Wrap *List_lastIndexOf(Wrap *self,List *arglist);
Wrap *List_setValue(Wrap *self,List *arglist);
Wrap *List_getValue(Wrap *self,List *arglist);
Wrap *List_toString(Wrap *self,List *arglist);
Wrap *List_free(Wrap *self,List *arglist);


Wrap *Map_new(Wrap *self,List *arglist);
Wrap *Map_length(Wrap *self,List *arglist);
Wrap *Map_setValue(Wrap *self,List *arglist);
Wrap *Map_getValue(Wrap *self,List *arglist);
Wrap *Map_hasKey(Wrap *self,List *arglist);
Wrap *Map_keyArr(Wrap *self,List *arglist);
Wrap *Map_valueArr(Wrap *self,List *arglist);
Wrap *Map_toString(Wrap *self,List *arglist);
Wrap *Map_free(Wrap *self,List *arglist);

Class *wrap_createStringClass();
Class *wrap_createListClass();
Class *wrap_createMapClass();

Class *wrap_createFunctionClass();
Class *wrap_createClassClass();
Class *wrap_createMapClass();

Wrap *wrap_setValueWithKey(Wrap *wrap,char *key,Wrap *value);
Wrap *wrap_setValueWithIndex(Wrap *wrap,int index,Wrap *value);
Wrap *wrap_getValueWithKey(Wrap *wrap,char *key);
Wrap *wrap_getValueWithIndex(Wrap *wrap,int index);

#ifdef __cplusplus
}
#endif

#endif
