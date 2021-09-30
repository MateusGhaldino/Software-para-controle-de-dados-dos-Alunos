#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Lista.h"
#include "Aluno.h"
#include "menu.h"
#include "utilitarios.h"

lista criaLista_aluno(){
    lista l = (lista)malloc(sizeof(lista));
    if(l!=NULL){
        l->tamanho=0;
        l->first=NULL;
        l->current=NULL;
        return l;
    }
    else
        return 0;
}

void terminaLista_aluno(lista l){
    TNodo *p, *aux;
    if(l != NULL && (l->first) != NULL){
        p= l->first;

        while((l->first) != p->next){
            aux = p;
            p = p->next;
            free(aux);
        }
        free(p);
        free(l);
    }

}
int tamanholista_aluno(lista li){
    if(li == NULL || (li->first == NULL))
        return 0;
    int cont=0;
    TNodo *no= li->first;
    do{
        cont++;
        no = no->next;

    }while(no != li->first);

    return cont;

}
int insereInicio_aluno(lista li,Taluno a){
    if(li == NULL) return 0;

    TNodo *no,*aux;

    no=(TNodo*)malloc(sizeof(TNodo));

    if(no == NULL)  return 0;

    no->info = a;
    if(li->first == NULL){
        li->first=no;
        no->next = no;/*Fazendo ele apontar para ele mesmo*/
        no->prior = NULL;
        no->posicao = 1;
    }
    else{
        aux= li->first;
        while(aux->next != li->first){
            aux->posicao++;
            aux = aux->next;
        }
        /*Chegando ao ultimo elemento da lista para poder adiciona-lo*/
        aux->next=no;
        no->prior=aux;
        no->next=li->first;
        li->first=no;
    }
    li->tamanho++;
    return 1;

}
int insereFinal_aluno(lista li ,Taluno a){
    if(li == NULL) return 0;

    TNodo *no,*aux;

    no=(TNodo*)malloc(sizeof(TNodo));

    if(no == NULL) return 0;
    no->info=a;

    if(li->first == NULL){
        return insereInicio_aluno(li,a);
    }
    else{
        aux= li->first;
        while(aux->next != li->first){
            aux->posicao++;
            aux = aux->next;

        }
            aux = aux->next;

        aux->next=no;
        no->prior=aux;
        no->next=li->first;
    }
    li->tamanho++;
    return 1;


}
int removeElemento_aluno_inicio(lista li){
    if(li == NULL)  return 0;
    if(li->first == NULL) return 0;
    if(li->first == li->first->next){
        free(li->first);
        li->first=NULL;
        return 1;
    }

    TNodo *atual=li->first;
    while(atual->next != li->first)
        atual=atual->next;

    TNodo *no=li->first;
    atual->next = no->next;
    no->prior= NULL;
    li->first= no->next;
    free(no);
    return 1;
}

int removeElemento_aluno_final(lista li){
    if(li == NULL) return 0;
    if(li->first == NULL) return 0;

    if(li->first == li->first->next){
        free(li->first);
        li->first=NULL;
        return 1;
    }
    else{
        TNodo *ant, *no=li->first;
        while(no->next != li->first){
            ant=no;
            no= no->next;
        }
        ant->next = no->next;
        free(no);
        return 1;
    }

}
int removeElemento_aluno(lista li,int mat){
    if(li == NULL) return 0;
    if(li->first == NULL) return 0;

    TNodo *no=li->first;
    if(no->info.matricula == mat){
        if(no == no->next){
            free(no);
            li->first = NULL;
            return 1;
        }
        else{
            TNodo *ult=li->first;
            while(ult->next != li->first)
                ult=ult->next;
            ult->next = li->first->next;
            li->first->next->prior=ult;
            li->first= li->first->next;
            return 1;
        }
    }
    else{
        TNodo *ant= no;
        no = no->next;
        while(no != li->first && no->info.matricula !=mat){
            ant=no;
            no= no->next;
        }
        if(no ==li->first) return 0;
        ant->next = no->next;
        no->next->prior=ant;
        free(no);
        return 1;
    }

}

int consulta_lista_posicao(lista li,int pos,Taluno *a){
    if(li == NULL || li->first == NULL || pos <= 0)
        return 0;

    TNodo *no= li->first;

    int i=1;

    while(no->next != li->first && i < pos){
        no = no->next;
        i++;
    }
    if(i != pos) return 0;
    else{
        *a = no->info;
        return 1;
    }

}
int consulta_lista_matricula(lista li,int mat,int *cont,Taluno *a){
    if(li == NULL || li->first == NULL)
        return 0;
    TNodo *no = li->first;
    while(no->next != li->first && no->info.matricula != mat){
        no = no->next;
        cont++;
    }

    if(no->info.matricula != mat)
        return 0;
    else{
        li->current = no;
        *a=no->info;
        return 1;
    }
}
int consulta_lista_aluno_nome(lista li,char nome[],Taluno *a){
    int i;

    if(li == NULL || li->first == NULL)
    return 0;

    TNodo *no = li->first;

    for(i = 1 ;i <= li->tamanho; i++){

        if(strncmp(no->info.nome,nome,strlen(nome)) == 0)

            break;
        else
            no = no->next;
    }

    if(strncmp(no->info.nome,nome,strlen(nome)) != 0)
        return 0;

    else

    li->current = no;
    *a = no->info;

    return 1;
}

int consulta_lista_Mat_Alunos_lista_disciplinas(lista li,int pos){
    if(li == NULL || li->first == NULL)
    return 0;
    TNodo *no = li->first;
    while(no->next != li->first && no->posicao != pos)
        no = no->next;
    if(no->posicao != pos)
        return 0;
    else{
        li->current = no;
        return 1;
    }
}

int getCorrente_aluno(lista l,Taluno*e){
    if(l->current){
        *e=l->current->info;
        l->current = l->current->next;
        return 1;
    }
    else
        return 0;
}
int setCorrente(lista l,int posicao){
   int i;
   if(posicao<1 || posicao >l->tamanho)
      return 0;

    /*percorrer do início*/
    l->current = l->first;
    for(i=1;i<posicao ;i++)
    l->current = l->current->next;

   return 1;
}

disciplina_lista criaLista_disciplina(){
   disciplina_lista l = (disciplina_lista)malloc(sizeof(TLista_dis));
   if(l){/*if(l!=NULL)*/
     l->tamanho=0;
     l->inicio=NULL;
     l->fim=NULL;
   }
   return l;
}

void terminaLista_disciplina(disciplina_lista l){
   TNodo_dis *p;
   while(l->inicio){
      p= l->inicio;
      l->inicio= l->inicio->next;/*l->inicio = p->next;*/
      free(p);
   }
   free(l);
}
int insereFinal_disciplina(disciplina_lista l,Tdisciplina e){
   TNodo_dis *p;
   p=(TNodo_dis*)malloc(sizeof(TNodo_dis));
   /*verificando se conseguiu alocar espaço de memória*/
   if(p){
     p->info=e;
     p->next=NULL;
     if(l->inicio==NULL){/*if(!l->inicio)*/
       l->inicio=p;
     }
     else
     l->fim->next=p;
     l->fim =p;
     l->tamanho++;
     return 1;
   }
   else
     return 0;

}
int removeLista_disciplina(disciplina_lista l,char ch[],Tdisciplina*e){
   TNodo_dis *p,*ant;

   p=l->inicio;

   while(p){

      if(strncmp(p->info.Disciplina,ch,strlen(ch))==0){
         if(l->inicio ==p)
           l->inicio = l->inicio->next;
         else
           if(l->fim==p){
             l->fim=ant;
             l->fim->next = NULL;
           }
           else
             ant->next=p->next;
         *e=p->info;
         free(p);
         l->tamanho--;
         return 1;
      }
      else{
         ant = p;
         p=p->next;
      }
   }
   return 0;
}
int insereInicio_disciplina(disciplina_lista l,Tdisciplina e){
   TNodo_dis *p;
   p=(TNodo_dis*)malloc(sizeof(TNodo_dis));
   if(p){
      p->info=e;
      p->next=l->inicio;
      l->inicio = p;
      if(l->tamanho ==0){
        l->fim =p;
      }
      p->posicao++;
      l->tamanho++;

      return 1;
   }
   else
      return 0;
}

int inserePosicao_disciplina(disciplina_lista l,Tdisciplina e,int posicao){
   TNodo_dis *p,*pAux,*ant;;
   int i;

   if(posicao==1)
      return insereInicio_disciplina(l,e);
   else
      if(posicao==l->tamanho+1)
        return insereFinal_disciplina(l,e);
      else
         if(posicao<1 || posicao>l->tamanho)
           return 0;
         else{
            p=(TNodo_dis*)malloc(sizeof(TNodo_dis));
            if(!p)
              return 0;
            p->info =e;
            pAux=l->inicio;
            for(i=1;i<posicao;i++){
              ant=pAux;
             pAux=pAux->next;
            }
            p->next = pAux;
            ant->next=p;
            l->tamanho++;
            return 1;
         }
}

int getElemento_disciplina_posicao(disciplina_lista l,int posicao,Tdisciplina *e){
   int i;
   TNodo_dis *p;
   if(posicao<1 || posicao>l->tamanho)
      return 0;


   p=l->inicio;

   for(i=1;i<posicao;i++)
   p=p->next;
   *e = p->info;
   l->corrente = p;

   return 1;

}
int getElemento_disciplina_nome(disciplina_lista l,char nome[],Tdisciplina *e){
   TNodo_dis *p;
   int i;
   if(l->inicio == NULL)
      return 0;

   p=l->inicio;

   for(i=1;i<l->tamanho;i++){
        if(strncmp(p->info.Disciplina,nome,strlen(nome))== 0)
            break;
        else
            p=p->next;
   }
   if(strncmp(p->info.Disciplina,nome,strlen(nome)) != 0)
        return 0;
   else

   l->corrente = p;
   *e = p->info;
   return 1;
}

int listaVazia_disciplina(disciplina_lista l){
   return l->inicio == NULL;
}
int listaCheia_disciplina(disciplina_lista l){
   TNodo_dis *p;
   p=(TNodo_dis*)malloc(sizeof(TNodo_dis));

   if(p){/*if(p!=NULL)*/
      free(p);
      return 0;
   }
   else
      return 1;
}

int getTamanho_disciplina(disciplina_lista l){
   return l->tamanho;
}


lista_ava criaLista_avaliacao(){
   lista_ava l = (lista_ava)malloc(sizeof(TLista_ava));
   if(l){/*if(l!=NULL)*/
     l->tamanho=0;
     l->inicio=NULL;
     l->fim=NULL;
   }
   return l;
}

void terminaLista_avaliacao(lista_ava l){
   TNodo_ava *p;
   while(l->inicio){
      p= l->inicio;
      l->inicio= l->inicio->next;/*l->inicio = p->next;*/
      free(p);
   }
   free(l);
}
int insereFinal_avaliacao(lista_ava l,Tavaliacao e){
   TNodo_ava *p;
   p=(TNodo_ava*)malloc(sizeof(TNodo_ava));
   /*verificando se conseguiu alocar espaço de memória*/
   if(p){
     p->info=e;
     p->next=NULL;
     if(l->inicio==NULL){/*if(!l->inicio)*/
       l->inicio=p;
     }
     else
       l->fim->next=p;
     l->fim =p;
     l->tamanho++;
     return 1;
   }
   else
     return 0;

}
int removeLista_avaliacao(lista_ava l,char ch[],Tavaliacao*e){
   TNodo_ava *p,*ant;

   p=l->inicio;

   while(p){

      if(strncmp(p->info.nomeavaliacao,ch,strlen(ch))==0){
         if(l->inicio ==p)
           l->inicio = l->inicio->next;
         else
           if(l->fim==p){
             l->fim=ant;
             l->fim->next = NULL;
           }
           else
             ant->next=p->next;
         *e=p->info;
         free(p);
         l->tamanho--;
         return 1;
      }
      else{
         ant = p;
         p=p->next;
      }
   }
   return 0;
}
int insereInicio_avaliacao(lista_ava l,Tavaliacao e){
   TNodo_ava *p;
   p=(TNodo_ava*)malloc(sizeof(TNodo_ava));
   if(p){
      p->info=e;
      p->next=l->inicio;
      l->inicio = p;
      if(l->tamanho ==0){
        l->fim =p;
      }
      l->tamanho++;
      return 1;
   }
   else
      return 0;
}

int inserePosicao_avaliacao(lista_ava l,Tavaliacao e,int posicao){
   TNodo_ava *p,*pAux,*ant;;
   int i;

   if(posicao==1)
      return insereInicio_avaliacao(l,e);
   else
      if(posicao==l->tamanho+1)
        return insereFinal_avaliacao(l,e);
      else
         if(posicao<1 || posicao>l->tamanho)
           return 0;
         else{
            p=(TNodo_ava*)malloc(sizeof(TNodo_ava));
            if(!p)
              return 0;
            p->info =e;
            pAux=l->inicio;
            for(i=1;i<posicao;i++){
              ant=pAux;
             pAux=pAux->next;
            }
            p->next = pAux;
            ant->next=p;
            l->tamanho++;
            return 1;
         }
}

int getElemento_avaliacao(lista_ava l,int posicao,Tavaliacao *e){
   int i;
   TNodo_ava *p;
   if(posicao<1 || posicao>l->tamanho)
      return 0;


   p=l->inicio;
   for(i=1;i<posicao;i++)
     p=p->next;
    l->corrente =p;
   *e = p->info;
   return 1;

}
int getElemento_avaliacao_nome(lista_ava l,char nome[],Tavaliacao*e){
   TNodo_ava *p;
   int i;
   if(l->inicio == NULL)
      return 0;

   p=l->inicio;

   for(i=1;i<l->tamanho;i++){
        if(strncmp(p->info.nomeavaliacao,nome,strlen(nome))== 0)
            break;
        else
            p=p->next;
   }
   if(strncmp(p->info.nomeavaliacao,nome,strlen(nome)) != 0)
        return 0;
   else
   l->corrente = p;
   *e = p->info;
   return 1;
}
int getElemento_avaliacao_nome_troca_nota(lista_ava l,char nome[],Tavaliacao*e,int nota){

   TNodo_ava *p;
   int i;
   if(l->inicio == NULL)
      return 0;

   p=l->inicio;

   for(i=1;i<l->tamanho;i++){
        if(strncmp(p->info.nomeavaliacao,nome,strlen(nome))== 0)
            break;
        else
            p=p->next;
   }
   if(strncmp(p->info.nomeavaliacao,nome,strlen(nome)) != 0)
        return 0;
   else
   l->corrente = p;
   p->info.nota = nota;
   *e = p->info;
   return 1;

}
int getnota_disciplina_avaliacoes(lista_ava l){
   int valor = 0;
   TNodo_ava *p;
   int i;

   if(l->inicio == NULL)
      return 0;

   p=l->inicio;

   for(i=1;i<=l->tamanho;i++){
        valor = p->info.valor + valor;
        p = p->next;
   }
   return valor;
}
int getvalor_disciplina_avaliacoes(lista_ava l){
   int nota = 0;
   TNodo_ava *p;
   int i;

   if(l->inicio == NULL)
      return 0;

   p=l->inicio;

   for(i=1;i<=l->tamanho;i++){
        nota = p->info.nota + nota;
        p = p->next;
   }
   return nota;
}

int listaVazia_avaliacao(lista_ava l){
   return l->inicio == NULL;
}
int listaCheia_avaliacao(lista_ava l){
   TNodo_ava *p;
   p=(TNodo_ava*)malloc(sizeof(TNodo_ava));

   if(p){/*if(p!=NULL)*/
      free(p);
      return 0;
   }
   else
      return 1;
}

int getTamanho_avaliacao(lista_ava l){
   return l->tamanho;
}




