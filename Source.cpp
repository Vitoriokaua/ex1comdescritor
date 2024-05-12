/*Faça uma função que receba duas listas encadeadas e as concatene. 
A primeira lista deverá então possuir todos os elementos, 
enquanto a segunda ficará vazia. Analise os casos especiais (uma das duas listas, ou ambas, estando vazias).

*/

#include <iostream>
using namespace std;

struct nolista
{
	int dado;
	nolista* prox;
	nolista* ant;
};

struct descritor
{
	nolista* ini;
	nolista* fim;
	int tam;

};

descritor* criar_lista() {
	descritor* novo = new descritor;
	novo->ini = NULL;
	novo->fim = NULL;
	novo->tam = 0;
	return novo;

}

void inserirfinal(descritor* l, int dado) {
	nolista* novo = new nolista;
	novo->dado = dado;
	novo->ant = NULL;
	novo->prox = NULL;
	if (l->ini == NULL)
	{
		l->ini = novo;
		l->fim = novo;
		l->tam++;
	}
	else
	{
		l->fim->prox = novo;
		novo->ant = l->fim;
		l->fim = novo;
		l->tam++;
	}
	
}


descritor* juntar(descritor* l, descritor* l2) {

    if (l->ini == NULL)
        return l2;
    else if (l2->ini == NULL)
        return l;
    else {
        l->fim->prox = l2->ini;
        l2->ini->ant = l->fim;
        l->fim = l2->fim; 
        delete l2; 
        return l;
    }

}

void imprimir(descritor* l) {
	nolista* p = new nolista;
	p = l->ini;
	while (p != NULL)
	{
		cout << p->dado << "-";
		p = p->prox;
	}
	
}

int main() {
	descritor* lista = criar_lista();
	descritor* lista2 = criar_lista();

	int n;
	cout<< "informe o dado (-1, para!):";
	cin >> n;
	while (n != -1)
	{
		inserirfinal(lista, n);
		cout << "informe o dado (-1, para!):";
		cin >> n;

	}
	int n2;
	cout << "informe o dado (-1, para!):";
	cin >> n2;
	while (n2 != -1)
	{
		inserirfinal(lista2, n2);
		cout << "informe o dado (-1, para!):";
		cin >> n2;

	}
	cout << "lista1: ";
	imprimir(lista);
	cout << "lista2:";
	imprimir(lista2);

	descritor* concatenou = juntar(lista, lista2);
	cout << "concatenada: ";
	imprimir(concatenou);

}