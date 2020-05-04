#include <dirent.h>
#include <dlfcn.h>
#include "environ.h"

void environ_initDynamic(VanEnviron *env){
    char *dirName="./src/external/";

    DIR *dp=NULL;
    struct dirent *dirp=NULL;

    void *fp=NULL;
    void *handler=NULL;
    char *filePath=NULL;

    dp=opendir(dirName);
    if(dp){
        while((dirp = readdir(dp)) != NULL){
            if(dirp->d_type!=DT_DIR){
                int _len1=strlen(dirName);
                int _len2=strlen(dirp->d_name);

                filePath=(char *)calloc(_len1+_len2+1,sizeof(char ));
                strcpy(filePath,dirName);
                strcpy(filePath+_len1,dirp->d_name);

                fp=dlopen(filePath, RTLD_NOW);
                if(fp){
                    handler=dlsym(fp, "nativeFunction_Load");
                    if(handler){
                        void (*fc1)(VanEnviron *)=handler;

                        fc1(env);
                        printf("initDynamic is -----%s\n",dirp->d_name);
                    }
                }

                free(filePath);

            }
        }
    }

    closedir(dp);
}

void environ_brigeNativeFunction(VanEnviron *env,VanFunction *func){
    VanWrap *nativeWrap=NULL;

    char *name=NULL;

    name=func->name;
    nativeWrap=wrap_wrapFunction(func);

    map_setValue(env->scopeDict, name, nativeWrap);

}

void environ_brigeNativeClass(VanEnviron *env,VanClass *cls){
    VanWrap *nativeWrap=NULL;

    char *name=NULL;

    name=cls->name;
    nativeWrap=wrap_wrapClass(cls);

    map_setValue(env->scopeDict, name, nativeWrap);
}


void environ_initBuiltin(VanEnviron *env){
    VanClass *cls=NULL;

    cls=wrap_createListClass();
    environ_brigeNativeClass(env,cls);

    cls=wrap_createMapClass();
    environ_brigeNativeClass(env,cls);

}
