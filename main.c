#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "menu.h"
#include "Aluno.h"
#include "utilitarios.h"
#include "Lista.h"



int main(){
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));
    menu();
    return 0;
}
