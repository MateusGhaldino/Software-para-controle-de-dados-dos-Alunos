#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "utilitarios.h"
#include "Aluno.h"
#include "menu.h"
#include "Lista.h"



int lestring(char *s){
    int i;
    int j;
    char letra;
    char vogalSem[]="AEIOUAAEAEIOUAEIOUAEIOUAOAOAEIOUAEIOUCC", vogalCom[]="���������������������������������������";
    for (i = 0; i < (100 - 1); i++){
        letra = toupper(fgetc(stdin));
        if (((letra == '\n') && (i == 0)) || ((letra== ' ') && (i == 0))) {
            i = i - 1;
            continue;
        }
        if (letra == '\n'){
            break;
        }
        for(j=0;j<sizeof(vogalCom);j++){
            if(vogalCom[j]==letra) letra=vogalSem[j];
        }
        s[i] = letra;
    }
    s[i] = 0;
    return (i);

}
int valida_data(int dia, int mes, int ano){
    if ((dia >= 1 && dia <= 31) && (mes >= 1 && mes <= 12) && (ano >= 1900 && ano <= 2100)) //verifica se os n�meros s�o v�lidos
        {
            if ((dia == 29 && mes == 2) && ((ano % 4) == 0) && ((ano % 100)!=0) || ((ano % 400) ==0)) //verifica se o ano � bissexto
            {
                return 1;
            }
            if (dia <= 28 && mes == 2) //verifica o m�s de fevereiro
            {
                return 1;
            }
            if ((dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) //verifica os m�ses de 30 dias
            {
                return 1;
            }
            if ((dia <=31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes ==8 || mes == 10 || mes == 12)) //verifica os m�ses de 31 dias
            {
                return 1;
            }
            else
            {
                return 0;
            }
      }
       else
           {
                return 0;
           }
}
