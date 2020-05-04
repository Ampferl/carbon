#include "data.h"
#include <stdlib.h>

static Node *node_getNodeFromIndex(Node *head,int index,int length);
static Node *node_getNodeFormKey(Node *head,char *key,int length,int *flag);

void __map_setValue(Map *map,char *key,Wrap *value,int outFlag);


String *string_create(char *data){
    String *str=NULL;
    int length=0;

    str=(String *)calloc(1, sizeof(String ));

    length=strlen(data);
    str->length=length;
    str->capacity=length;
    str->data=data;

    return str;
}

int string_length(String *str){
    int length=0;

    if(str){
        length=str->length;
    }

    return length;
}

char *string_add(String *str1,char *data){


    return NULL;
}

List *string_split(String *str1,char *data){


    return NULL;
}

int string_setValue(String *str,char c){


    return 0;
}

char *string_getValue(String *str){


    return NULL;
}

char *string_subString(String *str,int start,int end){


    return NULL;
}


char *string_toString(String *str){
    char *str1=NULL;
    int len1=0;

    if(str){
        if(str->data){
            len1=strlen(str->data);
            str1=(char *)calloc(len1+5, sizeof(char ));

            strcpy(str1, str->data);


        }
    }

    return str1;
}

void string_free(String *str){

    if(str){
        free(str->data);
        free(str);
    }
}


List *list_create(int length){
    List *list=NULL;
    Node *head=NULL;
    Node *tail=NULL;

    Node *preNode=NULL;
    Node *curNode=NULL;

    list=(List *)calloc(1, sizeof(List ));
    head=(Node *)calloc(1, sizeof(Node ));
    tail=(Node *)calloc(1, sizeof(Node ));
    head->next=tail;
    tail->pre=head;

    list->length=length;
    list->capacity=length;

    preNode=head;
    if(length){
        for(int i=0;i<length;i++){
            curNode=(Node *)calloc(1, sizeof(Node ));
            curNode->data=wrap_wrapNull();

            preNode->next=curNode;
            curNode->pre=preNode;
            preNode=curNode;
        }
        preNode->next=tail;
        tail->pre=preNode;
    }

    list->head=head;
    list->tail=tail;

    return list;
}

int list_length(List *list){
    int length=0;

    if(list){
        length=list->length;
    }

    return length;
}

List *list_push(List *list,Wrap *value){
    int length=0;
    Node *head=NULL;
    Node *tail=NULL;

    Node *cur=NULL;
    Node *last=NULL;

    length=list->length;
    head=list->head;
    tail=list->tail;

    cur=(Node *)calloc(1, sizeof(Node ));
    wrap_retain(value);
    cur->data=value;

    if(length){
        last=tail->pre;

        last->next=cur;
        cur->pre=last;

        cur->next=tail;
        tail->pre=cur;
    }
    else{
        head->next=cur;
        cur->pre=head;

        cur->next=tail;
        tail->pre=cur;

    }

    length++;
    list->length=length;

    return list;
}

Wrap *list_pop(List *list){
    int length=0;
    Node *head=NULL;
    Node *tail=NULL;

    Node *last=NULL;
    Node *lastPre=NULL;
    Wrap *value=NULL;

    length=list->length;
    head=list->head;
    tail=list->tail;
    if(length){
        last=tail->pre;
        lastPre=last->pre;

        lastPre->next=tail;
        tail->pre=lastPre;


        length--;
    }

    list->length=length;

    return value;
}

int list_indexOf(List *list,Wrap *value){
    int index=-1;


    return index;
}

int list_lastIndexOf(List *list,Wrap *value){
    int index=-1;


    return index;
}

void list_setValue(List *list,int index,Wrap *value){
    int length=0;
    Node *head=NULL;
    Node *tail=NULL;

    Node *rNode=NULL;
    Node *preNode=NULL;
    Node *nextNode=NULL;
    Node *cur=NULL;

    length=list->length;
    if(index<length&&index>=0){
        head=list->head;
        tail=list->tail;

        cur=(Node *)calloc(1, sizeof(Node ));
        wrap_retain(value);
        cur->data=value;

        rNode=node_getNodeFromIndex(head, index, length);
        preNode=rNode->pre;
        nextNode=rNode->next;

        preNode->next=cur;
        cur->pre=preNode;

        cur->next=nextNode;
        nextNode->pre=cur;

        wrap_release(rNode->data);
        free(rNode->userData);
        free(rNode);
    }

}

Wrap *list_getValue(List *list,int index){
    int length=0;
    Node *head=NULL;
    Node *tail=NULL;

    Wrap *value=NULL;
    Node *rNode=NULL;

    length=list->length;
    if(index<length&&index>=0){
        head=list->head;
        tail=list->tail;

        rNode=node_getNodeFromIndex(head, index, length);
        value=rNode->data;
    }

    return value;
}

char *list_toString(List *list){
    char *str=NULL;
    int len=0;
    int length1=128;

    int length=0;
    Node *head=NULL;
    Node *tail=NULL;
    Node *cur=NULL;

    length=list_length(list);
    head=list->head;
    tail=list->tail;
    cur=head->next;

    str=(char *)calloc(length1, sizeof(char ));
    str[0]='[';
    len++;
    while(cur!=tail){
        int _len=0;
        char *_str=NULL;

        _str=wrap_toString(cur->data);
        _len=strlen(_str);
        if(_len+5>=length1-len){
            str=realloc(str, length1+_len+5);
            length1=length1+_len+5;
        }
        strcpy(str+len,_str);
        len+=_len;
        if(cur->next!=tail){
            str[len]=',';
            len++;
        }

        cur=cur->next;
    }
    str[len]=']';
    str[len+1]='\0';

    return str;
}

void list_free(List  *list){

}


Map *map_create(){
    Map *map=NULL;
    Node *head=NULL;
    Node *tail=NULL;

    map=(Map *)calloc(1, sizeof(Map ));
    head=(Node *)calloc(1, sizeof(Node ));
    tail=(Node *)calloc(1, sizeof(Node ));
    head->next=tail;
    tail->pre=head;

    map->head=head;
    map->tail=tail;

    return map;
}

int map_length(Map *map){
    int length=0;

    if(map){
        length=map->length;
    }

    return length;
}

void __map_setValue(Map *map,char *key,Wrap *value,int outFlag){
    int length=0;
    Node *head=NULL;
    Node *tail=NULL;

    Node *rNode=NULL;
    Node *preNode=NULL;
    Node *nextNode=NULL;
    Node *cur=NULL;

    int flag=-1;

    length=map->length;
    head=map->head;
    tail=map->tail;

    cur=(Node *)calloc(1, sizeof(Node ));
    wrap_retain(value);
    cur->data=value;

    rNode=node_getNodeFormKey(head,key,length,&flag);
    if(flag>-1){

        if(rNode->data){
            if(rNode->data->type==DataType_RefData&&outFlag){
                Wrap **ref=NULL;

                ref=(Wrap **)rNode->data->data;
                *ref=value;
            }
            else{
                rNode->data=value;
            }
        }
        else{
            rNode->data=value;
        }

    }
    else{
        Node *last=NULL;


        cur->userData=(char *)calloc(strlen(key)+1, sizeof(char ));
        strcpy((char *)cur->userData,key);
        if(length){
            last=tail->pre;

            last->next=cur;
            cur->pre=last;

            cur->next=tail;
            tail->pre=cur;
        }
        else{
            head->next=cur;
            cur->pre=head;

            cur->next=tail;
            tail->pre=cur;
        }

        length++;
    }

    map->length=length;
}

void map_setValue(Map *map,char *key,Wrap *value){

    __map_setValue(map,key,value,1);

}

void map_setRefValue(Map *map,char *key,Wrap *value){

    __map_setValue(map,key,value,0);

}

Wrap *map_getValue(Map *map,char *key){
    int length=0;
    Node *head=NULL;
    Node *tail=NULL;

    Node *rNode=NULL;
    Wrap *value=NULL;
    Wrap **ref=NULL;

    length=map->length;
    head=map->head;
    tail=map->tail;

    rNode=node_getNodeFormKey(head,key,length,NULL);
    if(rNode){
        value=rNode->data;
        if(value){
            if(value->type==DataType_RefData){
                ref=(Wrap **)value->data;
                value=*ref;
            }
        }

    }

    return value;
}

Wrap *map_getRefValue(Map *map,char *key){
    int length=0;
    Node *head=NULL;
    Node *tail=NULL;

    Node *rNode=NULL;
    Wrap *value=NULL;
    Wrap **ref=NULL;

    length=map->length;
    head=map->head;
    tail=map->tail;

    rNode=node_getNodeFormKey(head,key,length,NULL);
    if(rNode){
        ref=&rNode->data;
        value=wrap_wrapRefData(ref);
    }

    return value;
}

int map_hasKey(Map *map,char *key){
    int length=0;
    Node *head=NULL;
    Node *tail=NULL;

    Node *rNode=NULL;
    int flag=0;

    length=map->length;
    head=map->head;
    tail=map->tail;

    if(length){
        rNode=node_getNodeFormKey(head,key,length,&flag);
        flag=(flag>-1?1:0);
    }

    return flag;
}

char **map_keyArr(Map *map){
    char **keyArr=NULL;
    int len=0;

    int length=0;
    Node *head=NULL;
    Node *tail=NULL;
    Node *cur=NULL;

    length=map->length;
    head=map->head;
    tail=map->tail;
    cur=head->next;

    if(length){
        keyArr=(char **)calloc(length, sizeof(char *));
        while(cur!=tail){
            char *_key=NULL;
            int _len=0;

            _key=(char *)cur->userData;
            _len=strlen(_key)+1;

            keyArr[len]=(char *)calloc(_len+1, sizeof(char ));
            strcpy(keyArr[len],_key);

            len++;
            cur=cur->next;
        }
    }

    return keyArr;
}

List *map_valueArr(Map *map){
    List *list=NULL;

    int length=0;
    Node *head=NULL;
    Node *tail=NULL;
    Node *cur=NULL;

    length=map->length;
    head=map->head;
    tail=map->tail;
    cur=head->next;

    list=list_create(0);
    while(cur!=tail){
        list_push(list, cur->data);
        cur=cur->next;
    }

    return list;
}

char *map_toString(Map *map){
    char *str=NULL;
    int len=0;
    int length1=128;

    int length=0;
    Node *head=NULL;
    Node *tail=NULL;
    Node *cur=NULL;

    length=map_length(map);
    head=map->head;
    tail=map->tail;
    cur=head->next;

    str=(char *)calloc(length1, sizeof(char ));
    str[0]='{';
    len++;
    while(cur!=tail){
        int _len1=0;
        int _len2=0;
        char *_str1=NULL;
        char *_str2=NULL;

        _str1=cur->userData;
        _len1=strlen(_str1);
        _str2=wrap_toString(cur->data);
        _len2=strlen(_str2);
        if(_len1+_len2+5>=length1-_len1-_len2){
            str=realloc(str, length1+_len1+_len2+5);
            length1=length1+_len1+_len2+5;
        }

        strcpy(str+len,_str1);
        len+=_len1;

        str[len]=':';
        len++;

        strcpy(str+len,_str2);
        len+=_len2;

        if(cur->next!=tail){
            str[len]=',';
            len++;
        }

        cur=cur->next;
    }
    str[len]='}';
    str[len+1]='\0';

    return str;
}

void map_free(Map *map){

}


Function *function_create(char *name,char **argNameArr,int *outFlagArr,int length){
    Function *func=NULL;

    Map *dict=NULL;



    func=(Function *)calloc(1, sizeof(Function ));

    dict=map_create();

    func->name=name;
    func->dict=dict;
    func->argNameArr=argNameArr;
    func->argArrLength=length;
    func->outFlagArr=outFlagArr;



    return func;
}

void function_bind(Function *func,Wrap *obj){

    if(func&&obj){
        wrap_retain(obj);
        func->bindObj=obj;
    }
}

Wrap *function_unBind(Function *func){
    Wrap *obj=NULL;

    if(func){
        wrap_release(func->bindObj);
        obj=func->bindObj;
        func->bindObj=NULL;
    }

    return obj;
}

void function_setValue(Function *func,char *key,Wrap *value){

    if(func){
        if(func->dict){
            map_setValue(func->dict, key, value);
        }
    }
}

Wrap *function_getValue(Function *func,char *key){
    Wrap *value=NULL;

    if(func){
        if(func->dict){
            value=map_getValue(func->dict, key);
        }
    }

    return value;
}

void function_setInScopeValue(Function *func,char *name,Wrap *value){

    if(func){
        if(func->inScopeDict){
            map_setValue(func->inScopeDict, name, value);
        }
    }
}

Wrap *function_getInScopeValue(Function *func,char *name){
    Wrap *value=NULL;

    if(func){
        if(func->inScopeDict){
            value=map_getValue(func->inScopeDict, name);
        }
    }

    return value;
}

void function_setUpScopeValue(Function *func,char *name,Wrap *value){

    if(func){
        if(func->upScopeDict){
            map_setValue(func->upScopeDict, name, value);
        }
    }
}

Wrap *function_getUpScopeValue(Function *func,char *name){
    Wrap *value=NULL;

    if(func){
        if(func->upScopeDict){
            value=map_getValue(func->upScopeDict, name);
        }
    }

    return value;
}

char *function_toString(Function *func){
    char *str=NULL;

    char *str1="function ";
    char *str2=NULL;
    char *str3="{[code...]}";

    int len1=0;
    int len2=0;
    int len3=0;

    str2=func->name;
    len1=strlen(str1);
    if(str2){
        len2=strlen(str2);
    }
    len3=strlen(str3);

    str=(char *)calloc(len1+len2+len3+1, sizeof(char ));
    strcpy(str,str1);
    if(len2){
        strcpy(str+len1,str2);
    }
    strcpy(str+(len1+len2),str3);

    return str;
}

void function_free(Function *func){

}


Class *class_create(char *name,Class *base){
    Class *cls=NULL;

    Map *clsDescDict=NULL;
    Map *insDescDict=NULL;
    Map *dict=NULL;

    cls=(Class *)calloc(1, sizeof(Class ));
    clsDescDict=map_create();
    insDescDict=map_create();
    dict=map_create();

    cls->name=name;
    cls->base=base;

    cls->clsDescDict=clsDescDict;
    cls->insDescDict=insDescDict;
    cls->dict=dict;

    return cls;
}

void class_addClsField(Class *cls,char *name,Wrap *value){

    if(cls){
        if(cls->clsDescDict){
            map_setValue(cls->clsDescDict, name, value);
        }
    }

}

void class_addInsField(Class *cls,char *name,Wrap *value){

    if(cls){
        if(cls->insDescDict){
            map_setValue(cls->insDescDict, name, value);
        }
    }

}

void class_addClsWrapMethod(Class *cls,char *name,FieldDesc desc,int *outFlag,WrapMethod method){
    Wrap *value=NULL;
    Function *function=NULL;

    function=function_create(NULL, NULL, outFlag, 0);
    function->type=FunctionType_NativeFunction;
    function->code=method;

    value=wrap_wrapFunction(function);
    value->_fieldDesc=desc;

    class_addClsField(cls,name,value);
}

void class_addInsWrapMethod(Class *cls,char *name,FieldDesc desc,int *outFlag,WrapMethod method){
    Wrap *value=NULL;
    Function *function=NULL;

    function=function_create(NULL, NULL, outFlag, 0);
    function->type=FunctionType_NativeFunction;
    function->code=method;

    value=wrap_wrapFunction(function);
    value->_fieldDesc=desc;

    class_addInsField(cls,name,value);
}

void class_setValue(Class *cls,char *key,Wrap *value){
    Class *base=NULL;

    Map *dict=NULL;
    Map *clsDescDict=NULL;

    int flag=0;

    base=cls;
    dict=base->dict;
    while(base){
        clsDescDict=base->clsDescDict;

        flag=map_hasKey(clsDescDict, key);
        if(flag){
            map_setValue(dict, key, value);
            break;
        }
        base=base->base;
    }

}

Wrap *class_getValue(Class *cls,char *key,int isSuper){
    Wrap *value=NULL;
    Class *base=NULL;

    Map *dict=NULL;
    Map *clsDescDict=NULL;

    int flag=0;

    base=cls;
    if(!isSuper){
        while(base){
            clsDescDict=base->clsDescDict;
            dict=base->dict;

            flag=map_hasKey(dict, key);
            if(flag){
                value=map_getValue(dict, key);
                if(value){
                    break;
                }
            }

            flag=map_hasKey(clsDescDict, key);
            if(flag){
                value=map_getValue(clsDescDict, key);
                if(value){
                    break;
                }

            }
            base=base->base;
        }

        base=cls;
    }
    else{
        base=base->base;
        while(base){
            clsDescDict=base->clsDescDict;
            dict=base->dict;

            flag=map_hasKey(dict, key);
            if(flag){
                value=map_getValue(dict, key);
                if(value){
                    base=cls->base;
                    break;
                }
            }

            flag=map_hasKey(clsDescDict, key);
            if(flag){
                value=map_getValue(clsDescDict, key);
                if(value){
                    base=cls->base;
                    break;
                }

            }
            base=base->base;
        }

        if(!value){
            base=cls;
            dict=base->dict;

            flag=map_hasKey(dict, key);
            if(flag){
                value=map_getValue(dict, key);
            }

            if(!value){
                clsDescDict=cls->clsDescDict;

                flag=map_hasKey(clsDescDict, key);
                if(flag){
                    value=map_getValue(clsDescDict, key);
                }
            }
        }
    }

    if(value){
        if(value->type==DataType_Function){
            Function *_fun=NULL;

            _fun=value->data;
            function_bind(_fun, wrap_wrapClass(base));
        }
    }

    return value;
}

Class *class_base(Class *cls){
    Class *base=NULL;

    if(cls){
        base=cls->base;
    }

    return base;
}

char *class_toString(Class *cls){
    char *str=NULL;

    char *str1="class ";
    char *str2=NULL;
    char *str3="{[code...]}";

    int len1=0;
    int len2=0;
    int len3=0;

    str2=cls->name;
    len1=strlen(str1);
    if(str2){
        len2=strlen(str2);
    }
    len3=strlen(str3);

    str=(char *)calloc(len1+len2+len3+1, sizeof(char ));
    strcpy(str,str1);
    if(len2){
        strcpy(str+len1,str2);
    }
    strcpy(str+(len1+len2),str3);

    return str;
}

void class_free(Class *cls){

}


Wrap *instance_create(Class *cls,List *argList){
    Wrap *wrap=NULL;

    Instance *ins=NULL;
    Map *dict=NULL;

    if(cls->type==ClassType_NativeClass){
        Wrap *_value=NULL;
        Function *_func=NULL;
        WrapMethod _method=NULL;

        _value=map_getValue(cls->clsDescDict, "__new__");
        if(_value->type==DataType_Function){
            _func=_value->data;
            if(_func->type==FunctionType_NativeFunction){
                _method=_func->code;
                wrap=_method(NULL,argList);
            }
        }
    }
    else{
        ins=(Instance *)calloc(1, sizeof(Instance ));
        dict=map_create();

        ins->cls=cls;
        ins->dict=dict;

        wrap=wrap_wrapInstance(ins);
    }

    return wrap;
}

void instance_setValue(Instance *ins,char *key,Wrap *value){
    Class *cls=NULL;

    Map *dict=NULL;
    Map *insDescDict=NULL;

    int flag=0;

    cls=ins->cls;
    dict=ins->dict;
    while(cls){
        insDescDict=cls->insDescDict;

        flag=map_hasKey(insDescDict, key);
        if(flag){
            map_setValue(dict, key, value);
            break;
        }
        cls=cls->base;
    }
}

Wrap *instance_getValue(Instance *ins,char *key,int isSuper){
    Wrap *value=NULL;
    Class *cls=NULL;

    Map *dict=NULL;
    Map *insDescDict=NULL;

    int flag=0;

    cls=ins->cls;
    dict=ins->dict;

    if(!isSuper){
        flag=map_hasKey(dict, key);
        if(flag){
            value=map_getValue(dict, key);
        }

        if(!value){
            while(cls){
                insDescDict=cls->insDescDict;

                flag=map_hasKey(insDescDict, key);
                if(flag){
                    value=map_getValue(insDescDict, key);
                    if(value){
                        break;
                    }

                }
                cls=cls->base;
            }
        }
    }
    else{
        cls=cls->base;
        while(cls){
            insDescDict=cls->insDescDict;

            flag=map_hasKey(insDescDict, key);
            if(flag){
                value=map_getValue(insDescDict, key);
                if(value){
                    break;
                }

            }
            cls=cls->base;
        }

        if(!value){
            flag=map_hasKey(dict, key);
            if(flag){
                value=map_getValue(dict, key);
            }
        }

        if(!value){
            cls=ins->cls;
            insDescDict=cls->insDescDict;

            flag=map_hasKey(insDescDict, key);
            if(flag){
                value=map_getValue(insDescDict, key);
            }
        }
    }

    if(value){
        if(value->type==DataType_Function){
            Function *_fun=NULL;

            _fun=value->data;
            function_bind(_fun, wrap_wrapInstance(ins));
        }
    }

    return value;
}

Class *instance_class(Instance *ins){
    Class *cls=NULL;

    if(ins){
        cls=ins->cls;
    }

    return cls;
}

char *instance_toString(Instance *ins){
    char *str=NULL;

    char *str1="object ";
    char *str2=NULL;
    char *str3="{[code...]}";

    int len1=0;
    int len2=0;
    int len3=0;

    str2=ins->cls->name;
    len1=strlen(str1);
    if(str2){
        len2=strlen(str2);
    }
    len3=strlen(str3);

    str=(char *)calloc(len1+len2+len3+1, sizeof(char ));
    strcpy(str,str1);
    if(len2){
        strcpy(str+len1,str2);
    }
    strcpy(str+(len1+len2),str3);

    return str;
}

void instance_free(Instance *ins){

}


Wrap *wrap_wrapNull(){
    Wrap *wrap=NULL;

    wrap=(Wrap *)calloc(1,sizeof(Wrap ));

    wrap->type=DataType_Null;
    wrap->_referNum=1;

    return wrap;
}

Wrap *wrap_wrapTrue(){
    Wrap *wrap=NULL;

    wrap=(Wrap *)calloc(1,sizeof(Wrap ));

    wrap->type=DataType_True;
    wrap->_referNum=1;

    return wrap;
}

Wrap *wrap_wrapFalse(){
    Wrap *wrap=NULL;

    wrap=(Wrap *)calloc(1,sizeof(Wrap ));

    wrap->type=DataType_False;
    wrap->_referNum=1;

    return wrap;
}

Wrap *wrap_wrapByte(signed char c){
    return wrap_wrapLongLong(c);
}

Wrap *wrap_wrapUByte(unsigned char c){
    return wrap_wrapLongLong(c);
}

Wrap *wrap_wrapShort(short s){
    return wrap_wrapLongLong(s);
}

Wrap *wrap_wrapUShort(unsigned short s){
    return wrap_wrapLongLong(s);
}

Wrap *wrap_wrapInt(int i){
    return wrap_wrapLongLong(i);
}

Wrap *wrap_wrapUInt(unsigned int i){
    return wrap_wrapLongLong(i);
}

Wrap *wrap_wrapLong(long l){
    return wrap_wrapLongLong(l);
}

Wrap *wrap_wrapLongLong(long long l){
    Wrap *wrap=NULL;

    wrap=(Wrap *)calloc(1,sizeof(Wrap ));

    wrap->type=DataType_Int;
    wrap->_referNum=1;
    wrap->value.l=l;

    return wrap;
}

Wrap *wrap_wrapFloat(float d){
    return wrap_wrapDouble(d);
}

Wrap *wrap_wrapDouble(double d){
    Wrap *wrap=NULL;

    wrap=(Wrap *)calloc(1,sizeof(Wrap ));

    wrap->type=DataType_Float;
    wrap->_referNum=1;
    wrap->value.d=d;

    return wrap;
}

Wrap *wrap_wrapNativeFunction(NativeFunction *function){
    Wrap *wrap=NULL;

    wrap=(Wrap *)calloc(1,sizeof(Wrap ));

    wrap->type=DataType_NativeFunction;
    wrap->data=function;
    wrap->_referNum=1;

    return wrap;
}

Wrap *wrap_wrapOpaquePointer(void *data){
    Wrap *wrap=NULL;

    wrap=(Wrap *)calloc(1,sizeof(Wrap ));

    wrap->type=DataType_OpaquePointer;
    wrap->data=data;
    wrap->_referNum=1;

    return wrap;
}

Wrap *wrap_wrapString(String *str){
    Wrap *wrap=NULL;

    wrap=(Wrap *)calloc(1,sizeof(Wrap ));

    wrap->type=DataType_String;
    wrap->data=str;
    wrap->_referNum=1;

    return wrap;
}

Wrap *wrap_wrapList(List *list){
    Wrap *wrap=NULL;

    wrap=(Wrap *)calloc(1,sizeof(Wrap ));

    wrap->type=DataType_List;
    wrap->data=list;
    wrap->_referNum=1;

    return wrap;
}

Wrap *wrap_wrapMap(Map *map){
    Wrap *wrap=NULL;

    wrap=(Wrap *)calloc(1,sizeof(Wrap ));

    wrap->type=DataType_Map;
    wrap->data=map;
    wrap->_referNum=1;

    return wrap;
}

Wrap *wrap_wrapFunction(Function *func){
    Wrap *wrap=NULL;

    wrap=(Wrap *)calloc(1,sizeof(Wrap ));

    wrap->type=DataType_Function;
    wrap->data=func;
    wrap->_referNum=1;

    return wrap;
}

Wrap *wrap_wrapClass(Class *cls){
    Wrap *wrap=NULL;

    wrap=(Wrap *)calloc(1,sizeof(Wrap ));

    wrap->type=DataType_Class;
    wrap->data=cls;
    wrap->_referNum=1;

    return wrap;
}

Wrap *wrap_wrapInstance(Instance *ins){
    Wrap *wrap=NULL;

    wrap=(Wrap *)calloc(1,sizeof(Wrap ));

    wrap->type=DataType_Instance;
    wrap->data=ins;
    wrap->_referNum=1;

    return wrap;
}

Wrap *wrap_wrapRefData(Wrap **data){
    Wrap *wrap=NULL;

    wrap=(Wrap *)calloc(1,sizeof(Wrap ));

    wrap->type=DataType_RefData;
    wrap->data=data;
    wrap->_referNum=1;

    return wrap;
}

void wrap_retain(Wrap *wrap){

    if(wrap){
        wrap->_referNum++;
    }

}


void wrap_release(Wrap *wrap){

    if(wrap){
        wrap->_referNum--;
        if(!wrap->_referNum){
            if(wrap->type==DataType_String){
                string_free(wrap->data);
            }
            else if(wrap->type==DataType_List){
                list_free(wrap->data);
            }
            else if(wrap->type==DataType_Map){
                map_free(wrap->data);
            }
            else if(wrap->type==DataType_Function){
                function_free(wrap->data);
            }
            else if(wrap->type==DataType_Class){
                class_free(wrap->data);
            }
            else if(wrap->type==DataType_Instance){
                instance_free(wrap->data);
            }
        }
    }
}

char *wrap_toString(Wrap * wrap){
    char *str=NULL;

    if(wrap){
        if(wrap->type==DataType_Null){
            int _len=0;
            char *_str="null";

            _len=strlen(_str)+1;
            str=(char *)calloc(_len, sizeof(char ));
            strcpy(str,_str);
        }
        else if(wrap->type==DataType_True){
            int _len=0;
            char *_str="true";

            _len=strlen(_str)+1;
            str=(char *)calloc(_len, sizeof(char ));
            strcpy(str,_str);
        }
        else if(wrap->type==DataType_False){
            int _len=0;
            char *_str="false";

            _len=strlen(_str)+1;
            str=(char *)calloc(_len, sizeof(char ));
            strcpy(str,_str);
        }
        else if(wrap->type==DataType_Int){
            str=(char *)calloc(30, sizeof(char ));
            sprintf(str, "%lld",wrap->value.l);
        }
        else if(wrap->type==DataType_Float){
            str=(char *)calloc(30, sizeof(char ));
            str=gcvt(wrap->value.d, 30, str);
        }
        else if(wrap->type==DataType_String){
            str=string_toString(wrap->data);
        }
        else if(wrap->type==DataType_List){
            str=list_toString(wrap->data);
        }
        else if(wrap->type==DataType_Map){
            str=map_toString(wrap->data);
        }
        else if(wrap->type==DataType_Function){
            str=function_toString(wrap->data);
        }
        else if(wrap->type==DataType_Class){
            str=class_toString(wrap->data);
        }
        else if(wrap->type==DataType_Instance){
            str=instance_toString(wrap->data);
        }
        else if(wrap->type==DataType_NativeFunction){
            int _len=0;
            char *_str="NativeFunction";

            _len=strlen(_str)+1;
            str=(char *)calloc(_len, sizeof(char ));
            strcpy(str,_str);
        }
        else if(wrap->type==DataType_NativeData){
            int _len=0;
            char *_str="NativeData";

            _len=strlen(_str)+1;
            str=(char *)calloc(_len, sizeof(char ));
            strcpy(str,_str);
        }
        else if(wrap->type==DataType_OpaquePointer){
            int _len=0;
            char *_str="OpaquePointer";

            _len=strlen(_str)+1;
            str=(char *)calloc(_len, sizeof(char ));
            strcpy(str,_str);
        }
    }

    return str;
}

static Node *node_getNodeFromIndex(Node *head,int index,int length){
    Node *rNode=NULL;
    Node *cur=NULL;

    cur=head;
    for(int i=0;i<length;i++){
        cur=cur->next;
        if(index==i){
            rNode=cur;
            break;
        }
    }

    return rNode;
}

static Node *node_getNodeFormKey(Node *head,char *key,int length,int *flag){
    Node *rNode=NULL;
    Node *cur=NULL;
    int _flag=-1;

    cur=head;
    for(int i=0;i<length;i++){
        cur=cur->next;
        if(strcmp(key,(char *)cur->userData)==0){
            rNode=cur;
            _flag=i;
            break;
        }
    }

    if(flag){
        *flag=_flag;
    }

    return rNode;
}
