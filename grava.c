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

void gravacao(lista l1,FILE * arquivo){
    Taluno a;
    Tdisciplina d;
    Tavaliacao av;
    int cont;

    if(l1->first != NULL){

            for(int i = 1;i <=l1->tamanho; i++){

            /*Obtendo o nodo corrente que corresponde a aluno*/

                setCorrente(l1,i);
                getCorrente_aluno(l1,&a);
                consulta_lista_matricula(l1,a.matricula,&cont,&a);

                if(l1->current->l2->inicio != NULL){

                    int c,j;

                    fprintf(arquivo,"%d#%s#%s@",a.matricula,a.nome,a.dataNascimento);

                    for(c = 1;c <=l1->current->l2->tamanho; c ++){
                        getElemento_disciplina_posicao(l1->current->l2,c,&d);

                        fprintf(arquivo,"%s#",d.Disciplina);

                        for(j = 1; j <= l1->current->l2->corrente->l3->tamanho; j++){

                            getElemento_avaliacao(l1->current->l2->corrente->l3,j,&av);
                            fprintf(arquivo,"%s#%d#%d",av.nomeavaliacao,av.valor,av.nota);
                        }

                    }
                    fprintf(arquivo,"\n");
                    printf("\nDados gravados com sucesso!!");

                }
                else{
                    /*Aluno sem disciplinas cadastradas*/
                    printf("\nDados do aluno Salvo com sucesso!!");
                    fprintf(arquivo,"%d#%s#%s\n",a.matricula,a.nome,a.dataNascimento);
                    /*Imprimindo os dados do aluno no arquivo*/
                }

            }


            //matricula#nome#dataNascimento@disciplina1#nomeavaliacao1#valor#nota
            //fprintf(arquivo,);

    }
    else{
        printf("\nA Estrutura não foi inicilizada!!");
        printf("\nPor Favor, retorne ao menu inicial e execute a função '1- Carregar'.");
    }

}

void alteracao_nota(lista l1){
    int op, sair,cont,matricula,nota;
    char disciplina[100],avaliacao[100];
    Taluno a;
    Tdisciplina d;
    Tavaliacao av;



    if(l1->first != NULL){

            do{


                do{
                    printf("\nForneça a matrícula do aluno:");
                    scanf("%d",&matricula);

                    consulta_lista_matricula(l1,matricula,&cont,&a);

                    if(a.matricula == matricula){

                        op =1;
                        printf("\nDados do Aluno");
                        printf("\nNome do aluno: %s",a.nome);

                    }
                    else{
                        printf("\nNúmero de matrícula não cadastrado!!!");
                        op = 0;
                    }

                }while(op != 1);

                if(l1->current->l2->inicio != NULL){

                    for(int c = 1;c <=l1->current->l2->tamanho; c ++){
                        getElemento_disciplina_posicao(l1->current->l2,c,&d);
                        printf("\nDisciplinas do aluno");
                        printf("\n%s",d.Disciplina);
                    }

                    do{
                        printf("\nQual disciplina que você deseja ver as avaliações e alterar as notas:");
                        lestring(disciplina);

                        if(getElemento_disciplina_nome(l1->current->l2,disciplina,&d)==1){
                            op = 1;

                            if(l1->current->l2->corrente->l3->inicio != NULL){

                                for(int j=1;j <= l1->current->l2->corrente->l3->tamanho; j++){
                                    getElemento_avaliacao(l1->current->l2->corrente->l3,j,&av);
                                    printf("\nNome da avaliação:%s\nValor:%d\nNota:%d",av.nomeavaliacao,av.valor,av.nota);
                                }

                                do{
                                    printf("\nForneça o nome da avaliação que você deseja alterar a nota do aluno:");
                                    lestring(avaliacao);

                                    if(getElemento_avaliacao_nome(l1->current->l2->corrente->l3,avaliacao,&av) == 1){
                                        op = 1;
                                        printf("\nNota do aluno:%d",av.nota);

                                        do{
                                            printf("\nForneça a nota que você alterar agora:");
                                            scanf("%d",&nota);

                                            if((nota <= 0) || (nota > av.valor)){
                                                 printf("\nValor da nota  inválido!!!");
                                                op = 0;
                                            }
                                            else{
                                                op =1;
                                            }
                                        }while(op != 1);
                                        /*Salvar no nodo*/

                                        if(getElemento_avaliacao_nome_troca_nota(l1->current->l2->corrente->l3,avaliacao,&av,nota)== 1){
                                            printf("\nNota alterada com sucesso");
                                            printf("\n%d",av.nota);
                                        }
                                        else{
                                            printf("\nErro ao alterar a nota");
                                        }
                                    }
                                    else{
                                        op = 0;
                                        printf("\nAvaliação não encontrada!!");
                                    }
                                }while(op != 1);
                            }

                            else{
                                printf("\nO aluno não possui avaliações cadastradas");
                            }

                        }
                        else{
                            printf("\nDisciplina não cadastrada!!!");
                            op = 0;
                        }
                    }while(op != 1);

                    do{
                        printf("\nForneça o nome da avaliação que você deseja alterar a nota do aluno:");
                    }while(op != 1);


                }
                else{
                    printf("\nO Aluno não possui disciplinas cadastradas!!!");
                }
            printf("\nDeseja Sair? \n1 - Sim \n2- Não \nO que deseja fazer?");
            scanf("%d",&sair);
            }while(sair != 1);

            do{
                printf("\nForneça a matrícula do aluno:");
                scanf("%d",&matricula);

                consulta_lista_matricula(l1,matricula,&cont,&a);

                if(a.matricula == matricula){

                    op =1;
                    printf("\nDados do Aluno");
                    printf("\nNome do aluno: %s",a.nome);
                    printf("\nMatrícula: %d",a.matricula);
                    printf("\nData de Nascimento: %s",a.dataNascimento);

                }
                else{
                    printf("\nNúmero de matrícula não cadastrado!!!");
                    op = 0;
                }
            }while(op != 1);


    }
    else{

        printf("\nA Estrutura não foi inicilizada!!");
        printf("\nPor Favor, retorne ao menu inicial e execute a função '1- Carregar'.");


    }


}
void Consulta_aluno_matricula(lista l1){
    int matricula,cont,op;
    Taluno a;
    Tdisciplina d;
    Tavaliacao av;
    if(l1->first != NULL){

        do{
            printf("\nForneça a matrícula do aluno:");
            scanf("%d",&matricula);

            consulta_lista_matricula(l1,matricula,&cont,&a);

            if(a.matricula == matricula){
                op = 1;
                    printf("\nDados do Aluno\n");
                    printf("\n%s\tMatrícula:%d\tData de Nascimento:%s\n",a.nome,a.matricula,a.dataNascimento);
            }
            else{
                printf("\nMatrícula não cadastrada!!!!");
                op = 0;
            }
        }while(op != 1);

        if(l1->current->l2->inicio != NULL){

            for(int h = 1;h <= l1->current->l2->tamanho;h++){
                getElemento_disciplina_posicao(l1->current->l2,h,&d);

                printf("\n\t\t\tDisciplina:%s\n",d.Disciplina);

                if(l1->current->l2->corrente->l3->inicio != NULL){

                    for(int u = 1; u<= l1->current->l2->corrente->l3->tamanho; u++){

                        getElemento_avaliacao(l1->current->l2->corrente->l3,u,&av);
                        printf("\n%sValor:%d Nota:%d\n",av.nomeavaliacao,av.valor,av.nota);

                    }
                }
                else{
                    printf("\nEssa disciplina não possui avaliações cadastradas!!");
                }
            }
        }
        else{
            printf("\nO aluno não possui disciplinas cadastradas!!!");
        }
        printf("\n--------");
    }
    else{
        printf("\nA Estrutura não foi inicilizada!!");
        printf("\nPor Favor, retorne ao menu inicial e execute a função '1- Carregar'.");

    }
}
void consulta_lista_nome(lista l1){
    int op;
    Taluno a;
    Tdisciplina d;
    Tavaliacao av;
    char nome[100];
    if(l1->first != NULL){

        do{
            printf("\nForneça a matrícula do aluno:");
            lestring(nome);

            consulta_lista_aluno_nome(l1,nome,&a);

            if(consulta_lista_aluno_nome(l1,nome,&a)==1){
                op = 1;
                    printf("\nDados do Aluno\n");
                    printf("\n%s\tMatrícula:%d\tData de Nascimento:%s\n",a.nome,a.matricula,a.dataNascimento);
            }
            else{
                printf("\nMatrícula não cadastrada!!!!");
                op = 0;
            }
        }while(op != 1);

        if(l1->current->l2->inicio != NULL){

            for(int h = 1;h <= l1->current->l2->tamanho;h++){
                getElemento_disciplina_posicao(l1->current->l2,h,&d);

                printf("\n\t\t\tDisciplina:%s\n",d.Disciplina);

                if(l1->current->l2->corrente->l3->inicio != NULL){

                    for(int u = 1; u<= l1->current->l2->corrente->l3->tamanho; u++){

                        getElemento_avaliacao(l1->current->l2->corrente->l3,u,&av);
                        printf("\n%sValor:%d Nota:%d\n",av.nomeavaliacao,av.valor,av.nota);

                    }
                }
                else{
                    printf("\nEssa disciplina não possui avaliações cadastradas!!");
                }
            }
        }
        else{
            printf("\nO aluno não possui disciplinas cadastradas!!!");
        }
        printf("\n--------");
    }
    else{
        printf("\nA Estrutura não foi inicilizada!!");
        printf("\nPor Favor, retorne ao menu inicial e execute a função '1- Carregar'.");

    }
}
