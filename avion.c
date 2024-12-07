#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct gg {
	int id;//cheie este optional
	char nume[32];
	struct gg* next;
}nod;//nod->rezervare

typedef struct kk {
	nod *prim;
	nod *ultim;
}LIST;//lista->rezervari pentru zbor

typedef struct dd {
	LIST l;
	struct dd* urm;
}MULTILIST;

nod* make(int id, char* nume, nod* elem)
{
	nod* e = malloc(sizeof(nod));
	if (e == NULL)
	{
		perror("ERROR ALOC");
		exit(-1);
	}
	e->id = id;
	strcpy(e->nume, nume);
	e->next = elem;
}
void initializare(LIST* lista)
{
	lista->prim = NULL;
	lista->ultim = NULL;
}
void adaugare_rezervare(LIST* list, int id, char* nume)
{
	nod* e = make(id, nume,NULL);
	if (list->prim == NULL)
	{
		list->prim = e;
		list->ultim = e;
		return;
	}
	if (strcmp(e->nume, list->prim->nume) < 0)
	{
		e->next = list->prim;
		list->prim = e;
		return;
	}
	nod* p = NULL ,*st=list->prim;
	for (p = list->prim->next; p != NULL; p = p->next)
	{
		if (strcmp(e->nume, p->nume) < 0)
		{
			st->next = e;
			e->next = p;
			return;
		}
		st = p;
	}
	list->ultim->next = e;
	list->ultim = e;

}
void stergere(LIST* list, int id_tofind)
{
	if (list->prim == NULL)
		return;
	nod* st = NULL, * p = list->prim, * dr = NULL;
	for (; p != NULL; p = p->next)
	{
		dr = p->next;
		if (st == NULL)
		{
			if (p->id == id_tofind)
			{
				list->prim=list->prim->next;
				if (list->prim == NULL)
					list->ultim = NULL;
				free(p);
				return;
			}
		}
		else if (p->id == id_tofind)
		{
			if (p == list->ultim)
				list->ultim = st;
			st->next = dr;
			free(p);
			return;
		}
		st = p;
	}
}
void display(LIST* lista)
{
	nod* p = lista->prim;
	while (p != NULL)
	{
		printf("ID:%d Name:%s\n",p->id,p->nume);
		p = p->next;
	}
}
void cautare(LIST* lista, int id_tofind)
{
	nod* p = NULL;
	for (p = lista->prim; p != NULL; p = p->next)
		if (p->id == id_tofind)
			break;
	if (p != NULL)
		printf("%s\n", p->nume);
	else
		printf("NU S-A GASIT PASAGERUL!\n");
}
void display_cap_coada(LIST* lista)
{
	nod* p = lista->prim;
	printf("\nID:%d Name:%s\n", p->id, p->nume);
	nod* q= lista->ultim;
	printf("ID:%d Name:%s\n\n", q->id, q->nume);
}
MULTILIST *make2(LIST *lista,MULTILIST *elem)
{
	MULTILIST* e = malloc(sizeof(MULTILIST));
	if (e == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	e->l = *lista;
	e->urm = NULL;
	return e;
}
MULTILIST *add_back(LIST* lista, MULTILIST *m)
{
	if (m == NULL)
		return make2(lista, NULL);
	MULTILIST* p = m;
	for (; p->urm != NULL; p = p->urm);
	p->urm= make2(lista, NULL);
	return m;
}
void display2(MULTILIST* m)
{
	MULTILIST* p = m;
	int i = 0;
	while (p != NULL)
	{
		printf("LISTA %d\n",i++);
		display(&p->l);
		printf("\n");
		p = p->urm;
	}
}
void free1(LIST* lista)
{
	nod* p = lista->prim, * aux=NULL;
	while (p != NULL)
	{
		aux = p;
		p = p->next;
		free(aux);
	}
}
void free2(MULTILIST *m)
{
	MULTILIST* p = m, * aux = NULL;
	while (p != NULL)
	{
		aux = p;
		p = p->urm;
		free1(&aux->l);
		free(aux);
	}
}
int main()
{
	LIST l1,l2,l3;
	initializare(&l1);
	adaugare_rezervare(& l1, 0, "NUME3");
	adaugare_rezervare(&l1, 1, "NUME1");
	adaugare_rezervare(&l1, 2, "NUME2");
	adaugare_rezervare(&l1, 3, "NUME4");
	adaugare_rezervare(&l1, 4, "NUME0");
	//display(&l1);
	//display(&l1);
	//display_cap_coada(&l1);
	//stergere(&l1, 3);
	//display(&l1);
	//display_cap_coada(&l1);
	//cautare(&l1, 2);
	initializare(&l2);
	adaugare_rezervare(&l2, 3, "NU4");
	adaugare_rezervare(&l2, 2, "NU2");
	adaugare_rezervare(&l2, 4, "NU1");
	adaugare_rezervare(&l2, 0, "NU0");
	adaugare_rezervare(&l2, 1, "NU3");

	initializare(&l3);
	adaugare_rezervare(&l3, 1, "UME3");
	adaugare_rezervare(&l3, 2, "UME1");
	adaugare_rezervare(&l3, 0, "UME2");
	adaugare_rezervare(&l3, 4, "UME4");
	adaugare_rezervare(&l3, 3, "UME0");
	
	MULTILIST* m1 = NULL;
	m1 = add_back(&l1,m1);
	m1 = add_back(&l2,m1);
	m1 = add_back(&l3,m1);
	display2(m1);
	free2(m1);
	return 0; 
}