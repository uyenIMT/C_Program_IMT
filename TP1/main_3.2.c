#include <stdio.h>
#include "logical.h"

int main() {
    char a;
    printf("Type A if you want logical AND table\nType O if you want logical OR table\nType X if you want logical XOR table\n");
    scanf("%c", &a); //Get input value
    logical_operator_use(a); //Call the function logical_operator_use()
    return 0;
}