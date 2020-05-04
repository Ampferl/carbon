
int main(int argc, char **argv){
    char *fileName = NULL;
    FILE *file = NULL;
    int len = 0;

    char *data = NULL;
    char str[128];

    if(argc < 2){
        return 0;
    }

    fileName=argv[1];
    file=fopen(fileName, "r");
    data=(char *)calloc(100*1024, sizeof(char ));
    while(!feof(file)) {
        if(fgets(str,128,file)!=NULL){
            strncpy(data+len, str, strlen(str));
            len+=strlen(str);
        }
    }

    execStr(data);

    return 0;
}