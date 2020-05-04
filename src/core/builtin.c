#include "builtin.h"


Wrap *wrap_builtinList(){
    Wrap *wrap=NULL;
    Class *listClass=NULL;

    Wrap *lengthFunc=NULL;

    listClass=class_create("List", NULL);

    class_addInsField(listClass, "length", lengthFunc);




    return wrap;
}



Wrap *String_new(Wrap *data){

}

Wrap *String_length(Wrap *str){

}

Wrap *String_add(Wrap *str1,Wrap *str2){

}

Wrap *String_split(Wrap *str1,Wrap *data){

}

Wrap *String_setValue(Wrap *str,Wrap *c){

}
Wrap *String_getValue(Wrap *str){

}
Wrap *String_subString(Wrap *str,Wrap *start,Wrap *end){

}

Wrap *String_toString(Wrap *str){

}

Wrap *String_free(Wrap *str){

}

Wrap *List_new(Wrap *length){

}

Wrap *List_length(Wrap *list){

}

Wrap *List_push(Wrap *list,Wrap *value){

}

Wrap *List_pop(Wrap *list){

}

Wrap *List_indexOf(Wrap *list,Wrap *value){

}

Wrap *List_lastIndexOf(Wrap *list,Wrap *value){

}

Wrap *List_setValue(Wrap *list,Wrap *index,Wrap *value){

}

Wrap *List_getValue(Wrap *list,Wrap *index){

}

Wrap *List_toString(Wrap *list){

}

Wrap *List_free(Wrap  *list){

}

Wrap *Map_new(){

}

Wrap *Map_length(Wrap *map){

}

Wrap *Map_setValue(Wrap *map,Wrap *key,Wrap *value){

}

Wrap *Map_getValue(Wrap *map,Wrap *key){

}

Wrap *Map_hasKey(Wrap *map,Wrap *key){

}

Wrap *Map_keyArr(Wrap *map){

}

Wrap *Map_valueArr(Wrap *map){

}

Wrap *Map_toString(Wrap *map){

}

Wrap *Map_free(Wrap *map){

}
