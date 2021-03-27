#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

struct lista {
	int tam;
	void **vet;
	int ini,fin,corr;
};

#define TAM 10

Lista *lst_cria(void) {
	Lista* lst = (Lista*) malloc(sizeof(Lista));
	if(lst == NULL) {
		printf("PROBLEMA DE MEMORIA!\n");
		exit(1);
	}

	lst->vet = (void**) malloc(TAM * sizeof(void *));

	if(lst->vet == NULL) {
		printf("PROBLEMA DE MEMORIA!\n");
		exit(1);
	}

	lst->tam = 0;
	lst->ini = 0;
	lst->fin = 0;
	lst->corr = -1;

	return lst;
}

int lst_vazia(Lista *lst) {
	if(lst->tam == 0) {
		return 1;
	} else {
		return 0;
	}
}

void lst_insIni(Lista *lst, void *v) {

	if(lst->tam == TAM) {
		printf("LISTA CHEIA\n");
	} else if (lst->tam == 0) {
		lst->vet[lst->ini] = v;
		lst->tam++;
	} else {
		if(lst->ini == 0) {
			lst->vet[TAM - 1] = v;
		} else {
			lst->vet[lst->ini - 1] = v;
			lst->tam++;
			lst->ini--;
		}

	}

}

void lst_insFin(Lista *lst,void *v) {

	if(lst->tam == TAM) {
		printf("LISTA CHEIA\n");
	} else if(lst->tam == 0) {
		lst->vet[lst->fin] = v;
		lst->tam++;
	} else {
		if(lst->fin == TAM - 1) {
			lst->vet[0] = v;
		} else {
			lst->vet[lst->fin + 1] = v;
			lst->tam++;
			lst->fin++;
		}
	}
}

void *lst_retIni(Lista *lst) {
	void* v;
	if(lst_vazia(lst)) {
		return NULL;
	}
	if(lst->corr == lst->ini) {
		lst->corr = -1;
	}
	v = lst->vet[lst->ini];
	lst->vet[lst->ini] = NULL;
	lst->tam--;
	if(lst->ini == TAM - 1) {
		lst->ini = 0;
	} else {
		lst->ini++;
	}

	return v;

}
void *lst_retFin(Lista *lst) {
	void* v;
	if(lst_vazia(lst)) {
		return NULL;
	}
	if(lst->corr == lst->fin) {
		lst->corr = -1;
	}
	v = lst->vet[lst->fin];
	lst->vet[lst->fin] = NULL;
	lst->tam--;
	if(lst->fin == 0) {
		lst->fin = TAM - 1;
	} else {
		lst->fin--;
	}

	return v;
}

void lst_posIni(Lista *lst) {
	if(lst_vazia(lst)) {
		lst->corr = -1;
	} else {
		lst->corr = lst->ini;
	}
}	

void lst_posFin(Lista *lst) {
	if(lst_vazia(lst)){
	       	lst->corr = -1;
	} else {
		lst->corr = lst->fin;
	}
}

void *lst_prox(Lista *lst) {
	if(lst->corr == TAM - 1){
	       	lst->corr = 0;
		return lst->vet[TAM - 1];
	} else if (lst->corr == -1) {
		return NULL;
	} else {
		lst->corr++;
		return lst->vet[lst->corr - 1];
	}
}


void *lst_ant(Lista *lst) {
	if(lst->corr == 0){
	       	lst->corr = TAM - 1;
		return lst->vet[0];
	} else if (lst->corr == -1) {
		return NULL;
	} else {
		lst->corr--;
		return lst->vet[lst->corr + 1];
	}

}

void lst_libera(Lista *lst) {
	for(int i = 0; i < TAM; i++) {
		free(lst->vet[i]);
	}
	free(lst->vet);
	free(lst);
}
