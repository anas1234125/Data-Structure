#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//////////////////////////////////////Partie1/////////////////////////////////////////////////////////////////////////////////////////////////////
//Dans cette partie , nous allons essayer de se familiariser avec les piles , nous réalisons une implementation d'une pile à l'aide d'une liste chainée
                 ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Nous commençons par définir la structure PILE
typedef struct liste{
	int* valeur;
	struct liste* suivant;
}Liste;

typedef struct pile{
	Liste* premier_element;
	int taille;
}Pile;

//Maintenant, nous allons créer une fonction pour initialiser une pile
void initialiserPile(Pile *p){
	p->premier_element=NULL;
	p->taille=0;                    //On initialise la pile de telle sorte qu'elle soit vide en premier
}
//Ensuite , nous définissons une fonction afin de tester si une pile est vide ou pas , la fonction retourne 1 si la pile est vide et 0 sinon
int estVide(Pile *p){
	if(p->taille==0){
		return 1;
	}else{
		return 0;
	}
}

//Il est aussi intéressant de récupérer la valeur du sommet. En meme temps nous vérifions si la valeur est bien récupérer en retournant 1 si tout se passe bien
int Sommet(Pile *p){
	if(p->premier_element==NULL){
		return 0;
	}else{
		return 1;
	}
}

//A fin de bien manipuler les pile , il faut bien etre capable de réaliser les taches basiques (empilation , suppression,affichage...)
//Nous commençons par l'empilation
int empilerPile(Pile *p,int* v){
	Liste* l;
	l=(Liste*)malloc(sizeof(Liste));
	if(l==NULL){               //vérification
		return -1;
	}else{
	   l->valeur=v;
	   l->suivant=p->premier_element;
	   p->taille++;	
	}
}

//Maintenant , nous écrivons une fonction pour dépiler une pile
int depilerPile(Pile* p){
	Liste* l1;
	if(p->taille==0){
		return -1;
	}else{
		l1=p->premier_element;
		p->premier_element=p->premier_element->suivant;
		free(l1->valeur);
		free(l1);
		p->taille--;
	}
}

//Ensuite , il faut bien etre capable d'afficher la pile
void AfficherPile(Pile* p){
	Liste* l;
	int i;
	l=p->premier_element;
	for(i=0;i<p->taille;i++){
		printf("%d\n",l->valeur);
		l=l->suivant;
	}
}
int main(int argc, char *argv[]) {
	Pile* p=(Pile*)malloc(sizeof(Pile));
	int* n , i=0;
	estVide(p);
	Sommet(p);
	initialiserPile(p);
	for(i=0;i<3;i++ ){
		printf("Tapez une valeur!");
		scanf("%d",&n);
		empilerPile(p,n);
	}
	
	AfficherPile(p);
	return 0;
}
