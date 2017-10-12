#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void code(char* arr, char* st, char* ret, int b, int c){
    static int cnt = 0;
    int len = strlen(ret);

    if(!(*ret)){
        cnt++;
        printf("%d: %s \n", cnt, st);
        return;
    }

    for(int i=0; i<sizeof(arr); i++){
        if(i == 0){
            ret[0] = arr[i];
            int x = (c==0)?2:c;
            code(arr, st, ret+1, b, x);
        }
        if(i == 1 && b != 0){
            ret[0] = arr[i];
            int x = (c==0)?2:c;
            code(arr, st, ret+1, 0, x);

        }
        if(i == 2 && c != 0){
            ret[0] = arr[i];
            int x = (c==0)?2:c;
            code(arr, st, ret+1, b, c-1);
        }
    }

}

int main()
{
    char arr[] = {'a', 'b', 'c','d'};
    char* ret = new char[5];
    *(ret+5) = '\n';
    char* st = ret;
    memset(st, 'x', 5);

    code(arr, st, ret, 1, 2);

    return 0;
}
