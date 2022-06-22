#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//Définir la structure Date
typedef struct{
	unsigned int J;
	unsigned int M;
	unsigned int year;
}Date;
//Définir la structure composant
typedef struct{
	char* nom[20];
	char* classe[20];
	char* fabricant[20];
	int code;
	Date date_de_fab;
}Composant;

//La fonction pour saisir une date
void SaisirDate(Date* d){
   printf("Veuillez saisir le jour de fabrication");
   scanf("%d",&d->J);
   printf("Veuillez saisir le mois de fabrication");
   scanf("%d",&d->M);
   printf("Veuillez saisir l'année' de fabrication");
   scanf("%d",&d->year);
   	
};

//La fonction pour afficher la Date
void AfficherDate(Date d){
	printf("La date de fabrication est : %d/%d/%d \n",d.J, d.M ,d.year);
}


//La fonction qui va permettre au utilisateur de saisir les informations d'un composant
void SaisirComposant(Composant* c){
	printf("Veuillez saisir le nom du composant");
	scanf("%s",c->nom);
	printf("Veuillez saisir la classe du composant");
	scanf("%s",c->classe);
	printf("Veuillez saisir le code du composant");
	scanf("%d",&c->code);
	printf("Veuillez saisir le nom du fabricant du composant");
	scanf("%s",c->fabricant);
	SaisirDate(&c->date_de_fab);
	
	
	
}

//la fonction qui affiche les informations du composant
void AfficherComposant(Composant c){
	printf("Voici les informations du composant:\n NOM:\t %s \n Classe:\t %s \n Code:\t %d \n Fabriquant:\t %s \n Date de fabrication:\t ",c.nom,c.classe,c.code
	,c.fabricant);
	AfficherDate(c.date_de_fab);
}

//Maintenant , nous allons essayer de saisir un tableau de notre structure composant
void SaisirComposantTab(int taille, Composant tab[taille]){

	int i;
	for( i=0;i<taille;i++){
	printf("Veuillez saisir le nom du composant");
	scanf("%s",tab[i].nom);
	printf("Veuillez saisir la classe du composant");
	scanf("%s",tab[i].classe);
	printf("Veuillez saisir le code du composant");
	scanf("%d",&tab[i].code);
	printf("Veuillez saisir le nom du fabricant du composant");
	scanf("%s",tab[i].fabricant);
	SaisirDate(&tab[i].date_de_fab);
		
	}
}
//la fonction qui affiche les composant dans un tableau
void AfficherComposantTab(int taille,Composant tab[taille]){
	int i;
	for(i=0;i<taille;i++){
		AfficherComposant(tab[i]);
	}
}

//Dans cette étape du code , nous allons Ecrire une fonction qui calcule le nombre de composants réalisés par un fabricant donne
int NombreComposants(int taille,Composant tab[taille],char* nom_fab[20]){
	int i , counter;
	for(i=0;i<taille;i++){
		if(nom_fab==tab[i].fabricant){
			counter++;
		}
	}
	printf("le nombre des composants que fabrique Mr %s est %d",nom_fab,counter);
	
	return counter;
}

//Maintenant , nous allons 0. Ecrire une fonction qui calcule le nombre de composants de deux classes données
typedef struct{
	int n_Classe1;
	int n_Classe2;
}NOMBRECOMPOSANTS;              //Une structure qui stoke le nombre des composants dans les deux classes

void nombre_du_composants(int taille,Composant tab[taille],char* classe1[20],char* classe2[20]){
		int i;
		NOMBRECOMPOSANTS C;
	for(i=0;i<taille;i++){
		if(classe1==tab[i].classe){
			C.n_Classe1++;
		}else if(classe2==tab[i].classe){
			C.n_Classe2++;
		}
	}
	printf("le Classe %s contient %d et le Classe %s contient %d",classe1,C.n_Classe1,classe2,C.n_Classe2);
	
}

//Maintenant , nous allons Ecrire une fonction qui affiche les composants fabriqués entre deux dates d1 et d2.
//afin de réduire la complexité de cette fonction , nous allons écrire une fonction qui compare deux dates.Cette fonction va retourner -1 si d1 est antérieur à d2
//0 si d1 est égale à d2 , 1 si d1 est supérieur à d2

int Comparer_Dates(Date d1, Date d2){
	if(d1.year>d2.year){
		return 1;
	}else if(d1.year<d2.year){
		return -1;
	}else{
		if(d1.M>d2.M){
			return 1;
		}else if(d1.M<d2.M){
			return -1;
		}else{
			if(d1.J>d2.J){
				return 1;
			}else if(d1.J<d2.J){
				return -1;
			}else{
				return 0;
			}
		}
	}
}

//Maintenant nous allons coder notre fonction
void Afiicher_Comp_2Dates(int taille,Composant tab[taille], Date d1, Date d2){
	int i;
	for(i=0;i<taille;i++){
		if((Comparer_Dates(tab[i].date_de_fab,d1)==1 && Comparer_Dates(tab[i].date_de_fab,d2)==-1)||(Comparer_Dates(tab[i].date_de_fab,d1)==-1 && Comparer_Dates(tab[i].date_de_fab,d2)==1)){
			printf("le composant %s est entre ces deux dates",tab[i].nom);
		}
	}
	
}





int main(int argc, char *argv[]) {
	
	//Maintenant ,dans la fonction main , nous allons écrire les lignes de codes qui vont permettre de réaliser le scénario demandé en question 8
	int n;
	printf("Combien de composant vous allez entrer!");
	scanf("%d",&n);
	Composant c1[n];               //Déclaration du tableau
	SaisirComposantTab(n,&c1[n]);  //La saisie des composants
    AfficherComposantTab(n,&c1[n]);  //L'affichage des composant dans le tableau
    
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                               ////////////////////////////////////////////////////////////////////////////////
    
   //Maintenant , nous allons implementer la deuxième partie du code
       ///Calculer le nombre de composants d'un fabricant fabrique
   char* nom_f[20];
   printf("Veuillez entrer le nom du fabriquent");
   scanf("%s",nom_f);
   NombreComposants(n,&c1[n],nom_f);
   
    ///Calculer nombre de composants de deux classes données
    char* Classe1[20];
    char* Classe2[20];
    printf("Veuillez taper le nom du classe1");
    scanf("%s",Classe1);
   	printf("Veuillez taper le nom du classe2");
    scanf("%s",Classe2);
    nombre_du_composants(n,&c1[n],Classe1,Classe2);
    
    ///• Affichage des composants fabriqués entre deux dates d1 et d2
    Date d1;
    Date d2;
    SaisirDate(&d1);
    SaisirDate(&d2);
    Afiicher_Comp_2Dates(n,&c1[n], d1,  d2);
    
    
	return 0;
}
