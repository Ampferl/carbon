#include "type.h"

// new String(""|true|false|null|1)
Wrap *String_new(Wrap *self,List *arglist){
    Wrap *wStr=NULL;
    String *vStr=NULL;

    char *cStr="";

    Wrap *_arg=NULL;

    if(!arglist){
        vStr=string_create(cStr);
        wStr=wrap_wrapString(vStr);

        return wStr;
    }

    _arg=list_getValue(arglist, 0);
    if(_arg->type==DataType_String){
        wStr=_arg;
    }
    else{
        cStr=wrap_toString(_arg->data);
        vStr=string_create(cStr);
        wStr=wrap_wrapString(vStr);
    }

    return wStr;
}

Wrap *String_length(Wrap *self,List *arglist){
    String *vStr=NULL;
    int length=0;

    Wrap *wLength=NULL;

    vStr=self->data;
    length=string_length(vStr);
    wLength=wrap_wrapLongLong(length);

    return wLength;
}

Wrap *String_add(Wrap *self,List *arglist){

    return NULL;
}


Wrap *String_split(Wrap *self,List *arglist){

    return NULL;
}

Wrap *String_setValue(Wrap *self,List *arglist){


    return NULL;
}

Wrap *String_getValue(Wrap *self,List *arglist){

    return NULL;
}

Wrap *String_subString(Wrap *self,List *arglist){

    return NULL;
}

Wrap *String_toString(Wrap *self,List *arglist){

    return NULL;
}
Wrap *String_free(Wrap *self,List *arglist){

    return NULL;
}

Wrap *List_new(Wrap *self,List *arglist){
    Wrap *wList=NULL;
    List *vlist=NULL;

    int length=-1;

    Wrap *_arg=NULL;

    if(!arglist){
        length=0;
    }
    else{
        _arg=list_getValue(arglist, 0);
        if(_arg->type==DataType_Int){
            length=_arg->value.i2;
        }
    }

    if(length>-1){
        vlist=list_create(length);
        wList=wrap_wrapList(vlist);
    }

    return wList;
}

Wrap *List_length(Wrap *self,List *arglist){
    List *wList=NULL;

    int length=0;

    Wrap *wLength=NULL;

    wList=self->data;
    length=list_length(wList);
    wLength=wrap_wrapLongLong(length);

    return wLength;
}

Wrap *List_push(Wrap *self,List *arglist){
    List *vList=NULL;

    Wrap *_arg=NULL;

    vList=self->data;

    if(!arglist){
        return self;
    }

    _arg=list_getValue(arglist, 0);

    list_push(vList,_arg);

    return self;
}

Wrap *List_pop(Wrap *self,List *arglist){
    List *vList=NULL;
    Wrap *wValue=NULL;

    vList=self->data;
    wValue=list_pop(vList);

    return wValue;
}

Wrap *List_indexOf(Wrap *self,List *arglist){


    return NULL;
}

Wrap *List_lastIndexOf(Wrap *self,List *arglist){


    return NULL;
}

Wrap *List_setValue(Wrap *self,List *arglist){


    return NULL;
}

Wrap *List_getValue(Wrap *self,List *arglist){


    return NULL;
}

Wrap *List_toString(Wrap *self,List *arglist){
    Wrap *wStr=NULL;

    String *vStr=NULL;
    char *cStr=NULL;

    cStr=wrap_toString(self);
    vStr=string_create(cStr);
    wStr=wrap_wrapString(vStr);

    return wStr;
}

Wrap *List_free(Wrap *self,List *arglist){


    return NULL;
}

Wrap *Map_new(Wrap *self,List *arglist){
    Wrap *wMap=NULL;
    Map *vMap=NULL;

    vMap=map_create();
    wMap=wrap_wrapMap(vMap);

    return wMap;
}

Wrap *Map_length(Wrap *self,List *arglist){
    Map *wMap=NULL;

    int length=0;

    Wrap *wLength=NULL;

    wMap=self->data;
    length=map_length(wMap);
    wLength=wrap_wrapLongLong(length);

    return wLength;
}

Wrap *Map_setValue(Wrap *self,List *arglist){


    return NULL;
}

Wrap *Map_getValue(Wrap *self,List *arglist){


    return NULL;
}

Wrap *Map_hasKey(Wrap *self,List *arglist){


    return NULL;
}

Wrap *Map_keyArr(Wrap *self,List *arglist){


    return NULL;
}

Wrap *Map_valueArr(Wrap *self,List *arglist){


    return NULL;
}

Wrap *Map_toString(Wrap *self,List *arglist){


    return NULL;
}

Wrap *Map_free(Wrap *self,List *arglist){


    return NULL;
}

Class *wrap_createStringClass(){
    Class *cls=NULL;

    cls=class_create("String",NULL);
    cls->type=ClassType_NativeClass;

    return cls;
}

Class *wrap_createListClass(){
    Class *cls=NULL;

    cls=class_create("List",NULL);
    cls->type=ClassType_NativeClass;

    class_addClsWrapMethod(cls,"__new__",FieldDesc_IsNull,NULL,List_new);

    class_addInsWrapMethod(cls,"length",FieldDesc_IsGet,NULL,List_length);
    class_addInsWrapMethod(cls,"push",FieldDesc_IsNull,NULL,List_push);
    class_addInsWrapMethod(cls,"pop",FieldDesc_IsNull,NULL,List_pop);
    class_addInsWrapMethod(cls,"indexOf",FieldDesc_IsNull,NULL,List_indexOf);
    class_addInsWrapMethod(cls,"lastIndexOf",FieldDesc_IsNull,NULL,List_lastIndexOf);
    class_addInsWrapMethod(cls,"toString",FieldDesc_IsNull,NULL,List_toString);
    class_addInsWrapMethod(cls,"__free__",FieldDesc_IsNull,NULL,List_free);

    return cls;
}

Class *wrap_createMapClass(){
    Class *cls=NULL;

    cls=class_create("Map",NULL);
    cls->type=ClassType_NativeClass;

    class_addClsWrapMethod(cls,"__new__",FieldDesc_IsNull,NULL,Map_new);

    class_addInsWrapMethod(cls,"length",FieldDesc_IsGet,NULL,Map_length);
    class_addInsWrapMethod(cls,"hasKey",FieldDesc_IsNull,NULL,Map_hasKey);
    class_addInsWrapMethod(cls,"keyArr",FieldDesc_IsGet,NULL,Map_keyArr);
    class_addInsWrapMethod(cls,"valueArr",FieldDesc_IsGet,NULL,Map_valueArr);
    class_addInsWrapMethod(cls,"toString",FieldDesc_IsNull,NULL,Map_toString);
    class_addInsWrapMethod(cls,"__free__",FieldDesc_IsNull,NULL,Map_free);

    return cls;
}

Class *wrap_createFunctionClass(){
    Class *cls=NULL;

    cls=class_create("Function",NULL);
    cls->type=ClassType_NativeClass;

    return cls;
}

Class *wrap_createClassClass(){
    Class *cls=NULL;

    cls=class_create("Type",NULL);
    cls->type=ClassType_NativeClass;

    return cls;
}

Wrap *wrap_setValueWithKey(Wrap *wrap,char *key,Wrap *value){

    return NULL;
}

Wrap *wrap_setValueWithIndex(Wrap *wrap,int index,Wrap *value){

    return NULL;
}

Wrap *wrap_getValueWithKey(Wrap *wrap,char *key){

    return NULL;
}

Wrap *wrap_getValueWithIndex(Wrap *wrap,int index){

    return NULL;
}










