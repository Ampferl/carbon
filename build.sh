clang -g -fPIC -shared ./src/core/lexer.c ./src/core/lexerDebug.c ./src/core/lexerUtil.c ./src/core/parse.c ./src/core/parseDebug.c ./src/core/type.c ./src/core/parseUtil.c ./src/core/data.c ./src/core/dataUtil.c ./src/core/environ.c ./src/core/environBridge.c ./src/core/error.c -olibcarbon.so -ldl

clang -g ./src/core/lexer.c ./src/core/lexerUtil.c ./src/core/parse.c ./src/core/type.c ./src/core/parseUtil.c ./src/core/data.c ./src/core/dataUtil.c ./src/core/environ.c ./src/core/environBridge.c ./src/core/error.c ./src/core/main.c -o carbon
