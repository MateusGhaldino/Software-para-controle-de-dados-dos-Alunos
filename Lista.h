#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct{
   char nomeavaliacao[100];
   int valor,nota;

}Tavaliacao;

typedef struct Nodo_ava{
   Tavaliacao info;
   struct Nodo_ava *next;
}TNodo_ava;

typedef struct{
   TNodo_ava *inicio,*fim,*corrente;
   int tamanho;
}TLista_ava;

typedef TLista_ava *lista_ava;


typedef struct{
   char Disciplina[100];
}Tdisciplina;


typedef struct Nodo_dis{
   Tdisciplina info;
   lista_ava l3;
   int posicao;
   struct Nodo_dis *next;
}TNodo_dis;

typedef struct{
   TNodo_dis *inicio,*fim,*corrente;
   int tamanho;
}TLista_dis;

typedef TLista_dis *disciplina_lista;

typedef int Tmatricula;

typedef struct{
    Tmatricula matricula;
    char nome[100],dataNascimento[11];
} Taluno;

typedef struct Nodo{
    Taluno info;
    disciplina_lista l2;
    int posicao;
    struct Nodo *next,*prior;
}TNodo;

typedef struct{
    TNodo *first,*current;
    int tamanho;
} TLista;

typedef TLista *lista;


lista criaLista_aluno();
void terminaLista_aluno(lista);
int tamanholista_aluno(lista li);
int insereInicio_aluno(lista,Taluno);
int insereFinal_aluno(lista,Taluno);
int inserePosicao_aluno(lista,Taluno,int);
int removeElemento_aluno_inicio(lista);
int removeElemento_aluno_final(lista);
int removeElemento_aluno(lista,int);
int consulta_lista_posicao(lista,int,Taluno*);
int consulta_lista_matricula(lista,int,int*,Taluno*);
int consulta_lista_aluno_nome(lista,char[],Taluno*);
int consulta_lista_Mat_Alunos_lista_disciplinas(lista,int);
int getCorrente_aluno(lista l,Taluno*e);
int setCorrente(lista l,int posicao);


disciplina_lista criaLista_disciplina();
void terminaLista_disciplina(disciplina_lista);
int inserePosicao_disciplina(disciplina_lista,Tdisciplina,int);
int insereInicio_disciplina(disciplina_lista,Tdisciplina);
int getElemento_disciplina_posicao(disciplina_lista,int,Tdisciplina*);
int getElemento_disciplina_nome(disciplina_lista,char[],Tdisciplina*);
int listaVazia_disciplina(disciplina_lista);
int listaCheia_disciplina(disciplina_lista);
int insereFinal_disciplina(disciplina_lista,Tdisciplina);
int removeLista_disciplina(disciplina_lista,char*,Tdisciplina*);
int getTamanho_disciplina(disciplina_lista);


lista_ava criaLista_avaliacao();
void terminaLista_avaliacao(lista_ava);
int inserePosicao_avaliacao(lista_ava,Tavaliacao,int);
int insereInicio_avaliacao(lista_ava,Tavaliacao);
int getElemento_avaliacao(lista_ava,int,Tavaliacao*);
int getElemento_avaliacao_nome(lista_ava,char[],Tavaliacao*);
int getElemento_avaliacao_nome_troca_nota(lista_ava,char[],Tavaliacao*,int);
int getnota_disciplina_avaliacoes(lista_ava);
int getvalor_disciplina_avaliacoes(lista_ava l);
int listaVazia_avaliacao(lista_ava);
int listaCheia_avaliacao(lista_ava);
int insereFinal_avaliacao(lista_ava,Tavaliacao);
int removeLista_avaliacao(lista_ava,char[],Tavaliacao*);
int getTamanho_avaliacao(lista_ava);



#endif // LISTA_H_INCLUDED
