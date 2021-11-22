#include "arvore.h"
#include "lista.h"
#include <cstddef>

Lista::Lista(NoLista* inicio, int qtd)
{
  this->Inicio = inicio;
  this->Qtd = qtd;
}

NoArvore* NoLista::GetNo(NoLista* no)
{
  return this->no;
}

NoLista* Lista::NovoNoLista(NoArvore* noArv)
{
  NoLista* novo = new NoLista();
  if (novo == NULL) 
    return NULL;
    
  novo->no = noArv;
  novo->prox = NULL;

  return novo;
}

void Lista::SetInicio(NoLista *inicio)
{
  this->Inicio = inicio;
}

void Lista::SetQtd(int qtd)
{
  this->Qtd = qtd;
}

NoLista* Lista::GetInicio()
{
  return this->Inicio;
}

int Lista::GetQtd()
{
  return this->Qtd;
}

NoLista* NoLista::GetProxLigada(NoLista* no)
{
  return this->prox;
}

void NoLista::SetProx(NoLista* no)
{
  this->prox;
}

void Lista::InsereNoFila1(NoLista* n, Lista* l)
{
  if(!l->GetInicio())
    l->SetInicio(n);

  else if(n->no->GetFreq() < l->Inicio->no->GetFreq())
  {
    n->prox = l->GetInicio();
    l->SetInicio(n);
  }
  else
  {
    NoLista *aux = new NoLista();
    aux = l->GetInicio()->GetProxLigada(n);

    NoLista *aux2 = new NoLista();
    aux2 = l->GetInicio();

    while(aux && aux->no->GetFreq() <= n->no->GetFreq())
    {
      aux2 = aux;
      aux = aux2->GetProxLigada(aux);
    }

    aux2->prox = n;
    n->prox = aux;
  }

  int qtd = l->GetQtd();
  l->SetQtd(qtd++);
}

NoArvore* Lista::CriaSubarvore(Lista *list)
{
  NoLista *noLista = new NoLista();
  noLista = list->GetInicio();

  NoArvore *noArv = new NoArvore();
  noArv = noLista->GetNo(noLista);

  list->SetInicio(noLista->GetProxLigada(noLista));

  delete(noLista);
  noLista = nullptr ;

  int quant = list->GetQtd();
  list->SetQtd(quant--);

  return noArv;
}