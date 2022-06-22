#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//Ce troisième tp porte sur les listes chainées.Ces dernières est parmi les types des structures les plus importnates en structure de donées.Elle offre 
//beaucoup d'avantages par rapport au d'autres structures.Dans ce TP, nous allons apprendre à manipuler et travailler avec les listes chainées.
          /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                       /////////////////////////////////////////////////////////////////////////////////////
                                            /*EXERCICE1*/
    //Dans cet exercice, nous allons écrire un programme c qui permet de gérer les étudiant qui ont passés le controle unifié.Cela , en utilisant les 
    //listes chainées.
    //Tout d'abord , nous réecrons la structure de l'étudiant
typedef struct etudiant {
	char Nom[30];
	float Note;
	int CNE;
}Etudiant;
          //Maintenant , nous allons déclarer les tructures liste et maillon
typedef struct maillon {
    Etudiant e;
    struct maillon * suivant;
} }Maillon;

typedef maillon* liste;

         //Notre première tache sera d'écrire une fonction qu'on va l'appeler "Inserfin" qui va nous permettre d'insérer un étudiant à la fin de la liste
    int InsererFin (Maillon* L, Etudiant E) {
    Maillon *m, *ptr;
    m = (Maillon*)malloc(sizeof (Maillon) );
    if ( m != NULL ){
        m->etud = E;
        m->suivant = NULL;
        if( L  !=  NULL ){
            ptr = L;
            while ( ptr->suivant != NULL )
                ptr = ptr->suivant;
            ptr->suivant=m;
        } else
            L = m;
        return 1;
    }
    return 0;
}
         //la fonction "RechercherMajorant" qui permet de retourner l'étudiant ayant obtenu la meilleure note
Etudiant RechercherMajorant(liste l){
    Etudiant e;
    float max ;
    Mailon *m;
    e = l.e;
    max = e.note;
    m = l.suivant ;

    while ( m != NULL ) {
        if( max < m->e.note ) {
            max = m->e.note;
            E = m->e;
        }
        m=m->suivant;
    }
    return E ;
}
       //Parmi les choses interéssantes à afficher , la note moyenne de la promotion , nous allons écrire une fonction qui calcule cette moyenne et 
    //l'affiche
  void MoyennePromotion (liste *L) {
    float S=0, Moyenne;
    int N=0 ;
    Maillon *m ;
    if( L != NULL ) {
        m = L;
        while( m != NULL) {
            S += m->etud.note;
            N++;
            m = m->suivant;
        }
        Moyenne = S/N;
        printf("La moyenne de la promotion est : %f ", Moyenne) ;
    }
    else
    printf("\n Cette liste est vide ") ;

}
       //La fonction suivante est pour but de construire une nouvelle liste ordonnée de sorte que les étudiants qui ne sont pas validé le semestre est au début
void ConstruireListe (liste *L, liste * Nouvelle_liste) {
    liste * m;
    m = L;
    while ( m != NULL) {
        if( m->etud.note < 10 )
            InsererDebut( Nouvelle_liste, m->etud);
        else
            InsererFin( Nouvelle_liste, m->etud);
        m = m->suivant;
    }
}

void SupprimerNonValide (Maillon * L) {
    Maillon *m, *ptr, *pred ;

    while( L  != NULL  && L->etud.note < 10 ){

// suppression de tous les non validÃ©s successifs Au debut
        Ptr = L;
        L = L->suivant;
        free(ptr);
    }
    if (L  != NULL) {

// suppression des autres non validÃ©s aprÃ¨s avoir rencontrer au moins un validÃ©
        pred = L;
        ptr = L->suivant;
        while(ptr != NULL){
                if( ptr->etud.note<10 ) {
                        m = ptr;
                        pred->suivant = ptr->suivant;
                        ptr = ptr->suivant;
                         free(m);
                         }

                   else {
                            pred = ptr;
                            ptr = ptr->suivant;
                       }
               }
          }
}


int main(int argc, char *argv[]) {
	return 0;
}
