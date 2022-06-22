#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//////////////////////////////////////////////////S�rie de TP2//////////////////////////////////////////////////////////////////////////////////////////

///Premi�rement , nous allons commencer par d�finir les structures
             //1 �re structure : �tudiant
typedef struct{
	unsigned int* Code;
	char* nom[20];
	char* filiere[20];
}ETUDIANT;
            //2 �me structure : Enseignant
typedef struct{
	unsigned int* Code;
	char* nom[20];
	char* filiere[20];
}ENSEIGNANT;
           // 3�me structure
typedef struct{
    double* note_tp;
	double* note_controle;
	double* note_examen;
}NOTE;
          // 4 �me structure
typedef struct{
	unsigned int* code;
	char* nom[20];
	ENSEIGNANT prof;
	ETUDIANT etudiants[30];
	NOTE notes[30];
}MODULE;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Maintenant , nous allons coder les fonctions des saisies , nous allons commencer par la fonction qui permet de saisir un etudiant
 void SaisirEtudiant(ETUDIANT* d){
 	printf("Veuillez entrer le code de l'�tudiant'");
 	scanf("%d",&d->Code);
 	printf("Veuillez entrer le nom de l'�tudiant'");
 	scanf("%s",d->nom);
 	printf("Veuillez entrer la fili�re � laquelle l'�tudiant est inscrit");
 	scanf("%s",d->filiere);
 }
 
 //La fonction qui affiche un �tudiant
 void AfficherEtudiant(ETUDIANT d){
 	printf("l'�tudiant %s portant du code %d est inscrit � la fili�re %s",d.nom,d.Code,d.filiere);
 }
 
 //Maintenant , on r�p�te le meme logique avec l'enseignant. Nous commen�ons par la fonction qui permet de saisir un enseignat
  void SaisirEnseignant(ENSEIGNANT* s){
 	printf("Veuillez entrer le code de l'enseignant'");
 	scanf("%d",&s->Code);
 	printf("Veuillez entrer le nom de l'enseignant'");
 	scanf("%s",s->nom);
 	printf("Veuillez entrer la fili�re de laquelle l'eiseignant est charg�");
 	scanf("%s",s->filiere);
 }

//La fonction qui affiche un �tudiant
void AfficherEnseignant(ENSEIGNANT s){
 	printf("l'enseignant %s portant du code %d est charg� de la fili�re %s",s.nom,s.Code,s.filiere);
 }
 
//Encore une fois nous faisons la meme chose avec la structure du note commen�ons par la fonction du saisie
void SaisirNote(NOTE* n){
	printf("Veuillez entrer la note du TP");
	scanf("%lf",&n->note_tp);
	printf("Veuillez entrer la note du Controle Continue");
	scanf("%lf",&n->note_controle);
	printf("Veuillez entrer la note du d'examen final'");
	scanf("%lf",&n->note_examen);	
}

//la fonction qui affiche les notes
void AfficherNote(NOTE n){
	printf("Note du TP : %f \n Note du Controle : %f \n Note d'examen : %f \n",n.note_tp,n.note_controle,n.note_examen);
}

//Maintenant nous allons �crire une fonction qui permet de saisir un module
void SaisirModule(MODULE* m){
	printf("Veuillez taper le code du module");
	scanf("%d",&m->code);
	printf("Veuillez taper le Nom du module");
	scanf("%s",m->nom);
	int i;
	for(i=0;i<30;i++){
		SaisirEtudiant(&m->etudiants[i]);
	}
	for(i=0;i<30;i++){
		SaisirNote(&m->notes[i]);
	}
}

//Une fonction qui permet d'afficher un module
void AfficherModule(MODULE m){
	printf("Nom du module : %s \n",m.nom);
	printf("Code : %d \n",m.code);
	int i;
	for(i=0;i<30;i++){
		printf("L'�tudiant : %s \t Sa Note: \n",m.etudiants[i].nom);
		AfficherNote(m.notes[i]);
	}
}

//Maintenant , nous allons �crire une fonction qui nous permettre de saisir un tableau de module
void Saisir_Module_Tab(int taille, MODULE m[taille]){
	int i;
	for(i=0;i<taille;i++){
		SaisirModule(&m[i]);
	}
}
//La fonction qui affiche les module
void Afficher_Module_Tab(int taille,MODULE m[taille]){
	int i;
	for(i=0;i<taille;i++){
		AfficherModule(m[i]);
	}
}

//Nous allons calculer le nombre des �tudiants qui suivent un module
int Nombre_E(int taille,MODULE m[taille],char* Nom_Module[20]){
	int i,counter;
	for(i=0;i<taille;i++){
		if(m[i].nom==Nom_Module){
			counter=sizeof(m[i].etudiants);
		}
	}
	  return counter;
	}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                   /////////////////////////////////////////////////////////////////////////////////////////////////////
                                /////////////////////////////////////////////////////////////////
                                
int main(int argc, char *argv[]) {
          //Nous allons maintenant implementer ces fonctions afin de cr�er notre sc�nario principale
    int taille;
    printf("Veuillez sp�cifier le nombre de module que vous allez entrer");
    scanf("%d",&taille);
    MODULE m[taille];          //D�claration du tableau des modules
    Saisir_Module_Tab(taille,&m[taille]);       //Saisie du tableau du module
    Afficher_Module_Tab(taille,&m[taille]);      //Affichage du tableau du module
    
	return 0;
}
