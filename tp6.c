#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//Nous commençons par la création de l'arbre
typedef struct noeud{
	int valeur;
	struct Noeud *gauche;
	struct Noeud *droite;
}Noeud;

typedef Noeud* arbre;

//Nous commençons par la création de l'arbre et l'insertion des valeurs, pour cela nous allons définir une fonction qu'on va la nommer "créerArbre"
arbre creerArbre(int v,arbre g ,arbre d){
	arbre n;
	n=(arbre)malloc(sizeof(arbre));
	if(n==NULL){
		printf("Impossible d'allouer cette mémoire");
		return NULL;
	}else{
		n->valeur=v;
		n->gauche=g;
		n->droite=d;
		return n;
	}
}

//Maintenant , nous allons parcourir notre arbre selon les trois méthodes
             //------------------------------Infixe------------------------------------------------------------//
void Infixe(arbre a){
	if(a!=NULL){
		Infixe(a->gauche);
		printf("%d",a->valeur);
		Infixe(a->droite);
	}
}
             //-----------------------------postfix-------------------------------------------------------------//
void Postfix(arbre a){
	if(a!=NULL){
		Postfix(a->gauche);
		Postfix(a->droite);
		printf("%d",a->valeur);
		
	}
}
            //-----------------------------prefix---------------------------------------------------------------//
void prefix(arbre a){
	if(a!=NULL){
		printf("%d",a->valeur);
		prefix(a->gauche);
		prefix(a->droite);
	}
}

//La fonction suivante est pour calculer le nombre totale des noeuds dans un arbre
int tailleArbre(arbre a){
	int conteur=0 , conteur1=0;
	if(a==NULL){
		return 0;
		
	}
	if(a->gauche==NULL && a->droite==NULL){
		return 1;
	}
	if(a->gauche!=NULL){
		conteur++;
		tailleArbre(a->gauche);
	}
	if(a->droite!=NULL){
		conteur1++;
		tailleArbre(a->droite);
	}
  return conteur+conteur1+1;
}

//Calculons le nombre des feuilles
int nombreFeuilles(arbre a){
	int counteur=0 , counteur1=0;
	if(a==NULL){
		return 0;
	}
	if(a->gauche==NULL && a->droite==NULL){
		return 1;
	}
	if(a->gauche!=NULL){
		counteur+=nombreFeuilles(a->gauche);
	}
	if(a->droite!=NULL){
		counteur1+=nombreFeuilles(a->droite);
	}
   return counteur+counteur1 ;              //En cas des feuilles , on ajoute pas un 1;
}

//Tester si un élement est dans l'arbre
Noeud* tester(arbre a , int v){
	Noeud* test;
	test=NULL;
	if(a!=NULL){
		if(a->valeur==v){
			test=a;
		}
	}else{
		test=tester(a->gauche,v);
		if(test==NULL){
			test=tester(a->droite,v);
		}
	}
	
}

int main(int argc, char *argv[]) {
	arbre a , r, l;
	arbre A33, A34,A53,A51,A68,A69;
	A34=creerArbre(34,NULL,NULL);
	A51=creerArbre(51,NULL,NULL);
	A69=creerArbre(69,NULL,NULL);
	A33=creerArbre(33,NULL,A34);
	l=creerArbre(38,A33,NULL);
	A53=creerArbre(53,A51,NULL);
	A68=creerArbre(68,NULL,A69);
	r=creerArbre(55,A53,A68);
	a=creerArbre(55,l,r);
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	printf("%d est la taille de l'arbre\n'",tailleArbre(a));
	printf("le nombre des feuilles est %d\n",nombreFeuilles(a));
	
	return 0;
}
