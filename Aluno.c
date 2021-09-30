#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "Aluno.h"
#include "menu.h"
#include "utilitarios.h"
#include "Lista.h"


void Parser(lista l1){

    Taluno a;
    Tdisciplina d;

    int mat,op,mes,dia,ano;
    char data[11],date[11];

    if(l1->first==NULL){
        printf("\nIniciando o Panser do arquivo");

        do{
            printf("\nForneça o número da matrícula:");
            scanf("%d",&mat);

            setbuf(stdin,NULL);
            if(mat <= 0){
                printf("\nNúmero de matrícula inválido");
                op=0;
            }
            else{
                op=1;
                a.matricula=mat;
            };
        }while(op!=1);


        printf("\nForneça o nome do aluno:");
        lestring(a.nome);

        do{
            printf("\nForneça a data de Nascimento do aluno.Exemplo(11/01/2002):");
            lestring(data);
                        date[0] = data[0];
                        date[1] = data[1];
                        date[2] = '\0';
                        dia = atoi(date);
                        date[0] = data[3];
                        date[1] = data[4];
                        date[2] = '\0';
                        mes = atoi(date);
                        date[0] = data[6];
                        date[1] = data[7];
                        date[2] = data[8];
                        date[3] = data[9];
                        date[4] = '\0';
                        ano = atoi(date);
                        if(valida_data(dia,mes,ano)==0){
                            op=0;
                            printf("Data de Nascimento inválida\n");
                        }
                        else{
                            op=1;
                            strcpy(a.dataNascimento,data);
                        };
        }while(op!=1);


        if(insereInicio_aluno(l1,a)==1){

            printf("\nA Lista dos alunos foi criada com sucesso!!");

            l1->first->l2=criaLista_disciplina();
            if(l1->first->l2 != NULL){

                printf("\nA lista de disciplinas foi criada com sucesso");

                printf("\nForneça o nome da disciplina que você deseja criar para iniciar a lista:");
                lestring(d.Disciplina);

                if(insereInicio_disciplina(l1->first->l2,d)==1){
                    printf("\nPrimeira disciplina adicionada com sucesso!!!");

                    l1->first->l2->inicio->l3 = criaLista_avaliacao();

                    if(l1->first->l2->inicio->l3 != NULL){
                        printf("\nTerceira Lista Criada com sucesso!!");
                    }
                    else{
                        printf("\nErro ao criar a Terceira lista:");
                    }
                }
                else{
                    printf("\nErro ao adicionar a primeira disciplina");
                }
            }
            else{
                printf("\nErro ao criar a segunda lista");
            };
        }
    }
    else{
        printf("\nA estrutura já foi carregada!!");
    }
    //system("cls");
}
void Cadastro_aluno(lista l1){
    int op,matricula,consult,dia,mes,ano,cont;
    Taluno a;
    char data[11],date[11];


    /*Verificando se a estrutura já foi inicializada*/
    if(l1->first != NULL){
        do{

            do{
                printf("\nForneça um número de matricula:");
                scanf("%d",&matricula);

                if(matricula <= 0){
                    printf("\nNúmero de matrícula inválido");
                    op=0;
                }
                else
                    op=1;

            }while(op != 1);

            /* Verificando se o número de matrícula já está cadastrado*/

            consult=consulta_lista_matricula(l1,matricula,&cont,&a);

            if(a.matricula != matricula || consult == 0){

                printf("\nPronto para seguir com o cadastro do aluno");
                op=1;

                a.matricula = matricula;

                printf("\nForneça o nome do aluno:");
                lestring(a.nome);
                do{
                    printf("\nForneça a data de Nascimento do aluno.Exemplo(11/01/2002):");
                    lestring(data);
                    date[0] = data[0];
                    date[1] = data[1];
                    date[2] = '\0';
                    dia = atoi(date);
                    date[0] = data[3];
                    date[1] = data[4];
                    date[2] = '\0';
                    mes = atoi(date);
                    date[0] = data[6];
                    date[1] = data[7];
                    date[2] = data[8];
                    date[3] = data[9];
                    date[4] = '\0';
                    ano = atoi(date);
                    if(valida_data(dia,mes,ano)==0){
                        op=0;
                        printf("Data de Nascimento inválida\n");
                    }
                    else{
                        op=1;
                        strcpy(a.dataNascimento,data);
                    };
                }while(op!=1);

                if(insereInicio_aluno(l1,a)==1){
                    printf("\nAluno Cadastrado com Sucesso!!");
                    printf("\n---Dados do Aluno Cadastrado---");
                    printf("\nNome: %s",a.nome);
                    printf("\nNúmero de Matrícula: %d",a.matricula);
                    printf("\nData de Nascimento:%s",a.dataNascimento);

                    consult=consulta_lista_matricula(l1,matricula,&cont,&a);

                    l1->current->l2=criaLista_disciplina();

                    if(l1->current->l2 != NULL){
                        printf("\nLista de disciplinas do aluno foi criada com sucesso!!");
                    }
                    else{
                        printf("\nErro ao criar a lista disciplinas do aluno");
                    };
                }
                else{
                    printf("\nErro ao Cadastrar os dados Aluno!!");
                };

            }
            else{
                printf("\nNúmero de matrícula já cadastrado!!");
                op=0;
            };

        }while(op!=1);
    }
    else{
        printf("\nA Estrutura não foi inicilizada!!");
        printf("\nPor Favor, retorne ao menu inicial e execute a função '1- Carregar'.");
    }

}
void Cadastra_disciplina(lista l1){
    int op,matricula,cont,sair;
    char disciplina[100];
    Taluno a;
    Tdisciplina d;

    /*Verificando se a estrutura já foi inicializada*/
    if(l1->first != NULL){
        do{

            do{
                printf("\nForneça o número de matrícula do aluno:");
                scanf("%d",&matricula);

                consulta_lista_matricula(l1,matricula,&cont,&a);
                if(a.matricula == matricula){
                    op = 1;
                    printf("\nDados do Aluno");
                    printf("\nNome do aluno: %s",a.nome);
                    printf("\nMatrícula: %d",a.matricula);
                    printf("\nData de Nascimento: %s",a.dataNascimento);

                }
                else{
                    op = 0;
                    printf("\nNúmero de matrículá não cadastrado!!!");
                }
            }while(op != 1);


            if(l1->current != NULL){

                do{
                    printf("\nForneça o nome da disciplina:");
                    lestring(disciplina);

                    if(l1->current->l2 != NULL){

                        if(getElemento_disciplina_nome(l1->current->l2,disciplina,&d)== 0){
                        strcpy(d.Disciplina,disciplina);
                        op = 1;

                            if(insereInicio_disciplina(l1->current->l2,d)==1){
                                printf("\nDisciplina Cadastrada com sucesso!!");

                                getElemento_disciplina_nome(l1->current->l2,disciplina,&d);

                                l1->current->l2->corrente->l3 = criaLista_avaliacao();

                                if(l1->current->l2->corrente->l3 != NULL){
                                    printf("\nLista avaliações criada com sucesso!!");
                                }
                                else{
                                    printf("\n Erro ao criar a lista de avaliações");
                                }
                            }
                            else{
                                printf("\nErro ao cadastrar a disciplina do aluno!!");
                            };

                        }
                        else{
                            printf("\nDisciplina já cadastrada!!");
                        op = 0;
                        };
                    }
                    else{
                        printf("\nErro ao acessar a lista de disciplinas");
                    }

                }while(op != 1);
            }
            else{
                printf("\nErro ao procurar o nodo corrente do aluno!!!");
            }

            printf("\nDeseja sair? \n1 - Sim \n2 - Não \nO que deseja fazer??");
            scanf("%d",&sair);
        }while(sair != 1);
    }
    else{
        printf("\nA Estrutura não foi inicilizada!!");
        printf("\nPor Favor, retorne ao menu inicial e execute a função '1- Carregar'.");
    }
}
void Cadastra_Avaliacao(lista l1){
    int op, sair,cont,matricula,valor,resultado;
    char disciplina[100],avaliacao[100];
    Taluno a;
    Tdisciplina d;
    Tavaliacao av;
    valor = 0;


    if(l1->first != NULL){

        do{

            do{
                printf("\nForneça o número de matrícula do aluno:");
                scanf("%d",&matricula);

                consulta_lista_matricula(l1,matricula,&cont,&a);

                if(a.matricula == matricula){
                    op = 1;
                    printf("\nDados do Aluno");
                    printf("\nNome do aluno: %s",a.nome);
                    printf("\nMatrícula: %d",a.matricula);
                    printf("\nData de Nascimento: %s",a.dataNascimento);

                }
                else{
                    printf("\nNúmero de matrícula não cadastrado!!");
                    op = 0;
                }
            }while(op != 1);


                if(l1->current->l2->inicio != NULL){

                    do{
                        printf("\nForneça o nome da disciplina que você cadastrar a avaliação:");
                        lestring(disciplina);
                        if(getElemento_disciplina_nome(l1->current->l2,disciplina,&d) == 1){
                            printf("\nPronto para cadastrar a avaliação da %s",d.Disciplina);
                            op = 1;
                        }
                        else{
                            op = 0;
                            printf("\nDisciplina não cadastrada!!!");
                        }
                    }while(op != 1);

                    do{
                        printf("\nForneça o nome da avaliação:");
                        lestring(avaliacao);

                        if(getElemento_avaliacao_nome(l1->current->l2->corrente->l3,avaliacao,&av) == 0){
                                printf("\nPronto para cadastrar o nome da avaliação!!");
                                strcpy(av.nomeavaliacao,avaliacao);

                                do{
                                    printf("\nForneça a valor da avaliação:");
                                    scanf("%d",&av.valor);
                                    /*Validando dados*/

                                    if(av.valor <= 0 && av.valor > 100){
                                        printf("\nValor da avaliação inválido!!!");
                                        op = 0;
                                    }
                                    else{
                                        valor = getnota_disciplina_avaliacoes(l1->current->l2->corrente->l3);

                                        if(valor == 100){
                                            printf("\nNão será possivel cadastrar essa avaliação pois os valores das demais avaliações atingiu o valor total de 100 pontos");
                                            op = 0;
                                        }
                                        else{
                                            resultado = valor + av.valor;


                                            if(resultado <= 100){
                                                op = 1;
                                                printf("\nValor Salvo com sucesso!!");
                                            }
                                            else{
                                                op = 0;
                                                printf("\nValor maior do que disponível para ser salvo!! \nValor disponivel %d",valor - 100);
                                            }
                                        }
                                    };

                                }while(op != 1);

                                do{
                                    printf("\nForneça a nota do(a) aluno(a) %s  na avaliação:",a.nome);
                                    scanf("%d",&av.nota);

                                    /*Validando dados*/

                                    if((av.nota <= 0) || (av.nota > av.valor)){
                                        printf("\nValor da nota  inválido!!!");
                                        op = 0;
                                    }
                                    else{
                                        op = 1;
                                    };

                                }while(op != 1);


                                if(insereInicio_avaliacao(l1->current->l2->corrente->l3,av)== 1){
                                    printf("\nAvaliação, nota, e valor cadastrado com sucesso!!!");
                                }
                                else{
                                    printf("\nNão foi possível salvar os dados da avaliação!!");
                                }
                        }
                        else{
                            printf("\nAvaliação já cadastrada!");
                        }

                    }while(op != 1);
                }
                else{
                    printf("\nO aluno não possui disciplinas cadastrada!!");
                };


        printf("\nDeseja sair? \n1 - Sim \n2 - Não \nO que deseja fazer?");
        scanf("%d",&sair);
        }while(sair != 1);
    }
    else{
        printf("\nA Estrutura não foi inicilizada!!");
        printf("\nPor Favor, retorne ao menu inicial e execute a função '1- Carregar'.");
    }
}

void Verifica_integridade(lista l1){
    int sair,matricula,cont,op,valor;
    char disciplina[100];
    Taluno a;
    Tdisciplina d;
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
                    printf("\nMatrícula: %d",a.matricula);
                    printf("\nData de Nascimento: %s",a.dataNascimento);

                }
                else{
                    printf("\nNúmero de matrícula não cadastrado!!!");
                    op = 0;
                }
            }while(op != 1);


            if(l1->current->l2->inicio != NULL){
                do{
                    printf("\nForneça o nome da disciplina que você cadastrar a avaliação:");
                    lestring(disciplina);

                    if(getElemento_disciplina_nome(l1->current->l2,disciplina,&d) == 1){
                        printf("\nVerificando integridade da disciplina de %s.",d.Disciplina);
                        valor = getnota_disciplina_avaliacoes(l1->current->l2->corrente->l3);
                        printf("\nA soma das avaliações dessa disciplina é :%d",valor);

                        op = 1;
                    }
                    else{
                        op = 0;
                        printf("\nDisciplina não cadastrada!!!");
                    };
                }while(op != 1);

                if(valor == 100){
                    printf("\nOs dados dessa disciplina estam corretos");
                }
                else{
                    printf("\nOs dados dessa disciplina não corretos");
                }
            }
            else{
                printf("\nEsse aluno não possui disciplinas cadastradas!!");
            };

        printf("\nDeseja Sair? \n1 - Sim \n2- Não \nO que deseja fazer?");
        scanf("%d",&sair);
        }while(sair !=1);
    }
    else{
        printf("\nA Estrutura não foi inicilizada!!");
        printf("\nPor Favor, retorne ao menu inicial e execute a função '1- Carregar'.");
    }
}
void exclui_aluno(lista l1){
    int matricula,cont,sair;
    Taluno a;
    if(l1->first != NULL){

        do{
            printf("\nForneça a matrícula do aluno que você deseja excluir:");
            scanf("%d",&matricula);

            consulta_lista_matricula(l1,matricula,&cont,&a);

            if(a.matricula == matricula){

                printf("\nExcluindo o aluno");

                if(l1->current->l2 != NULL){

                    terminaLista_disciplina(l1->current->l2);

                    if(removeElemento_aluno(l1,matricula)== 1){

                        printf("\nAluno excluido com sucesso!");
                    }
                    else{
                        printf("\nErro ao excluir o aluno");
                    };
                }
                else{

                    if(removeElemento_aluno(l1,matricula)== 1){
                    printf("\nAluno excluido com sucesso!");

                    }
                    else{
                    printf("\nErro ao excluir o aluno");
                    };
                };

            }
            else{
                printf("\nNúmero de matrícula não cadastrado!!");
            };

        printf("\nDeseja Sair? \n1 - Sim \n2- Não \nO que deseja fazer?");
        scanf("%d",&sair);
        }while(sair != 1);
    }
    else{
        printf("\nA Estrutura não foi inicilizada!!");
        printf("\nNão possui alunos cadastrados!!");
        printf("\nPor Favor, retorne ao menu inicial e execute a função '1- Carregar'.");
    }
}

void exclui_disciplina(lista l1){
    int matricula,cont,sair,op;
    Taluno a;
    Tdisciplina d;
    char disciplina[100];

    if(l1->first != NULL){
        do{

            do{
                printf("\nForneça a matrícula do aluno que você deseja excluir:");
                scanf("%d",&matricula);
                consulta_lista_matricula(l1,matricula,&cont,&a);

                if(a.matricula == matricula){
                    op = 1;
                }
                else{
                    printf("\nNúmero de matrícula não cadastrado!!!");
                    op = 0;
                };

            }while(op != 1);

            if(l1->current->l2->inicio != NULL){
                printf("\nForneça o nome da disciplina que você deseja excluir:");
                lestring(disciplina);

                if(getElemento_disciplina_nome(l1->current->l2,disciplina,&d) == 1){
                    printf("\nExcluido a disciplina de %s",d.Disciplina);

                    if(l1->current->l2->corrente->l3 != NULL){
                        printf("\nExcluindo lista avaliações dessa avaliações");
                        terminaLista_avaliacao(l1->current->l2->corrente->l3);
                    }
                    else{
                        printf("\nNão foi possível excluir a lista de avaliações dessa disciplina!!");
                    }

                    if(removeLista_disciplina(l1->current->l2,disciplina,&d)== 1){
                        printf("\nDisciplina excluída com sucesso!!!");


                    }
                    else{
                        printf("\nErro ao excluir disciplina do aluno");
                    };

                }
                else{
                    printf("\nDisciplina não cadastrada");
                };

            }
            else{
                printf("\nO aluno não possui disciplinas cadastradas!!");
            };

            printf("\nDeseja Sair? \n1 - Sim \n2- Não \nO que deseja fazer?");
            scanf("%d",&sair);
        }while(sair != 1);
    }
    else{
        printf("\nA Estrutura não foi inicilizada!!");
        printf("\nNão possui alunos cadastrados!!");
        printf("\nPor Favor, retorne ao menu inicial e execute a função '1- Carregar'.");
    }
}
void exclui_avaliacoes(lista l1){

    int matricula,cont,sair,op;
    Taluno a;
    Tdisciplina d;
    Tavaliacao av;
    char disciplina[100],avaliacao[100];

    if(l1->first != NULL){
        do{
            do{
                printf("\nForneça a matrícula do aluno que você deseja excluir:");
                scanf("%d",&matricula);
                consulta_lista_matricula(l1,matricula,&cont,&a);

                if(a.matricula == matricula){
                    op = 1;
                }
                else{
                    printf("\nNúmero de matrícula não cadastrado!!!");
                    op = 0;
                };
            }while(op != 1);

            if(l1->current->l2->inicio != NULL){

                do{
                    printf("\nForneça o nome da disciplina:");
                    lestring(disciplina);

                    if(getElemento_disciplina_nome(l1->current->l2,disciplina,&d) == 1){
                        op = 1;
                    }
                    else{
                        printf("\nDisciplina não cadastrada!!");
                        op = 0;
                    }
                }while(op != 1);


              if(l1->current->l2->corrente->l3->inicio != NULL){

                    do{
                        printf("\nForneça o nome da avaliação que você deseja excluir:");
                        lestring(avaliacao);

                        if(getElemento_avaliacao_nome(l1->current->l2->corrente->l3,avaliacao,&av) == 1){
                            printf("\nPronto para excluir a avaliação!!");

                            if(removeLista_avaliacao(l1->current->l2->corrente->l3,avaliacao,&av) == 1){
                                printf("\nDisciplina excluída com sucesso!!");
                            }
                            else{
                                printf("\nNão foi possível excluir essa avaliação!");
                            };
                        }
                        else{
                            printf("\nAvaliação não cadastrada!!");
                        }

                    }while(op != 1);
              }
              else{
                printf("\nO(a) aluno(a) não possui avaliações cadastradas!!");
              }
            }
            else{
                printf("\nO(a) aluno(a) não possui disciplinas cadastradas!!");
            };


        printf("\nDeseja Sair? \n1 - Sim \n2- Não \nO que deseja fazer?");
        scanf("%d",&sair);
        }while(sair != 1);

    }
    else{
        printf("\nA Estrutura não foi inicilizada!!");
        printf("\nNão possui alunos cadastrados!!");
        printf("\nPor Favor, retorne ao menu inicial e execute a função '1- Carregar'.");
    }

}
void imprimir_aprovados(lista l1){
    Taluno a;
    Tdisciplina d;
    int i,c,cont,nota,n,soma,media,materias;
    nota = 0;
    soma = 0;
    media = 0;
    /*Verificando se há alunos cadastrados na lista*/

    if(l1->first != NULL){

        for(i = 1;i <=l1->tamanho; i ++){

            /*Obtendo o nodo corrente que corresponde a aluno*/

            setCorrente(l1,i);
            getCorrente_aluno(l1,&a);
            consulta_lista_matricula(l1,a.matricula,&cont,&a);

            /*Verificando se há disciplinas cadastradas no nodo desse aluno*/
            if(l1->current->l2->inicio != NULL){

                int notas;

                for(c = 1;c <=l1->current->l2->tamanho; c ++){

                    getElemento_disciplina_posicao(l1->current->l2,c,&d);

                    materias = l1->current->l2->tamanho;

                    for(n = 1;n <= l1->current->l2->corrente->l3->tamanho; n++){
                        notas = getvalor_disciplina_avaliacoes(l1->current->l2->corrente->l3);
                        soma = notas + soma;
                    }


                }
                    media = soma / materias;

                    if(media >= 50){

                        printf("\nDados do aluno\n");
                        printf("\nMatrícula:%d\tNome:%s\tData de Nascimento:%s\n",a.matricula,a.nome,a.dataNascimento);


                        for(c = 1;c <=l1->current->l2->tamanho; c ++){
                            getElemento_disciplina_posicao(l1->current->l2,c,&d);
                            nota = getvalor_disciplina_avaliacoes(l1->current->l2->corrente->l3);
                            printf("\n%s:%d",d.Disciplina,nota);

                        }
                        printf("\n");

                        printf("\nMédia:%d \tSituação - APROVADO",media);


                    }
                    else{
                        printf("\nA lista não possui alunos aprovados");
                        /*O aluno reprovado;*/
                    }
                    soma = 0;
                    media = 0;
            }
            else{
                printf("\nO(a) aluno(a):%s não possui disciplinas cadastradas",a.nome);
                printf("\nDados do aluno");
                printf("\nMatrícula:%d\tNome:%s\tData de Nascimento:%s",a.matricula,a.nome,a.dataNascimento);
                printf("\n---------------");
            }

        }
    }
    else{
        printf("\nA Estrutura não foi inicilizada!!");
        printf("\nNão possui alunos cadastrados!!");
        printf("\nPor Favor, retorne ao menu inicial e execute a função '1- Carregar'.");
    }


}
void imprimi_reprovados(lista l1){
    Taluno a;
    Tdisciplina d;
    int i,c,cont,nota,n,soma,media,materias;
    nota = 0;
    soma = 0;
    media = 0;
    /*Verificando se há alunos cadastrados na lista*/

    if(l1->first != NULL){

        for(i = 1;i <=l1->tamanho; i ++){

            /*Obtendo o nodo corrente que corresponde a aluno*/

            setCorrente(l1,i);
            getCorrente_aluno(l1,&a);
            consulta_lista_matricula(l1,a.matricula,&cont,&a);

            /*Verificando se há disciplinas cadastradas no nodo desse aluno*/
            if(l1->current->l2->inicio != NULL){

                int notas;

                for(c = 1;c <=l1->current->l2->tamanho; c ++){

                    getElemento_disciplina_posicao(l1->current->l2,c,&d);

                    materias = l1->current->l2->tamanho;

                    for(n = 1;n <= l1->current->l2->corrente->l3->tamanho; n++){
                        notas = getvalor_disciplina_avaliacoes(l1->current->l2->corrente->l3);
                        soma = notas + soma;
                    }


                }
                    media = soma / materias;

                    if(media < 50){

                        printf("\nDados do aluno\n");
                        printf("\nMatrícula:%d\tNome:%s\tData de Nascimento:%s\n",a.matricula,a.nome,a.dataNascimento);


                        for(c = 1;c <=l1->current->l2->tamanho; c ++){
                            getElemento_disciplina_posicao(l1->current->l2,c,&d);
                            nota = getvalor_disciplina_avaliacoes(l1->current->l2->corrente->l3);
                            printf("\n%s:%d",d.Disciplina,nota);

                        }
                        printf("\n");

                        printf("\nMédia:%d \tSituação - REPROVADO",media);

                    }
                    else{
                        printf("\nA lista não possui alunos reprovados");
                        /*O aluno aprovado;*/
                    }
                    soma = 0;
                    media = 0;
            }
            else{
                printf("\nO(a) aluno(a):%s não possui disciplinas cadastradas",a.nome);
                printf("\nDados do aluno");
                printf("\nMatrícula:%d\tNome:%s\tData de Nascimento:%s",a.matricula,a.nome,a.dataNascimento);
                printf("\n---------------");
            }

        }
    }
    else{
        printf("\nA Estrutura não foi inicilizada!!");
        printf("\nNão possui alunos cadastrados!!");
        printf("\nPor Favor, retorne ao menu inicial e execute a função '1- Carregar'.");
    }


}


