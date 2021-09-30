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



void menu(){
    int op;
    FILE *dados;
    dados = fopen("dados.txt","r+");

    if(dados==NULL){
        dados = fopen("dados.txt","w+");
    };
    lista l1;
    //Definindo a lista de disciplinas
    /*Detalhe ela ser� inicializada na fun��o de fazer o parser e diferente da lista dos alunos que � criada aqui.*/



    l1=criaLista_aluno();
    if(l1!=NULL){
        do{

            printf("\nBem Vindo ao Sistema de controle de dados dos alunos");
            printf("\n1) Carregar \n2) Cadastrar aluno \n3) Cadastrar disciplina do aluno \n4) Cadastrar avalia��o da disciplina \n5) Verificar integridade \n6) Excluir aluno \n7) Excluir disciplina \n8) Excluir avalia��o \n9) Relat�rio de Alunos Aprovados \n10) Relat�rio de Alunos Reprovados \n11) Gravar \n12) Alterar nota \n13) Consulta Matr�cula \n14) Consulta Nome\n15) Sair \nO que voc� deseja fazer?:");

            scanf("%d",&op);


            switch(op){
            case 1:
                Parser(l1);
                break;
            case 2:
                Cadastro_aluno(l1);
                break;
            case 3:
                Cadastra_disciplina(l1);
                break;
            case 4:
                Cadastra_Avaliacao(l1);
                break;
            case 5:
                Verifica_integridade(l1);
                break;
            case 6:
                exclui_aluno(l1);
                break;
            case 7:
                exclui_disciplina(l1);
                break;
            case 8:
                exclui_avaliacoes(l1);
                break;
            case 9:
                imprimir_aprovados(l1);
                break;
            case 10:
                imprimi_reprovados(l1);
                break;
            case 11:
                gravacao(l1,dados);
                break;
            case 12:
                alteracao_nota(l1);
                break;
            case 13:
                Consulta_aluno_matricula(l1);
                break;
            case 14:
                consulta_lista_nome(l1);
                break;
            }
        }
        while(op!=15);
        terminaLista_aluno(l1);
        fclose(dados);
    }
    else{
        printf("\nN�o foi poss�vel criar a lista dos alunos");
    };

}
