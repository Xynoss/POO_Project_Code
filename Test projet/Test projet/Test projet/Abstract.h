#pragma once
class Abstract
{
private:
	//variables � introduire
	string nom, prenom;
	int ID;
	

public:
	Abstract();//constructeur � modifier en fonction de la classe
	virtual void modifier()=0; //dans les paranth�ses, rentrer les variables � utiliser
	virtual void supprimer()=0; //dans les paranth�ses, rentrer les variables � utiliser
	virtual void ajouter()=0; //dans les paranth�ses, rentrer les variables � utiliser
	virtual void afficher()=0; //dans les paranth�ses, rentrer les variables � utiliser
	virtual ~Abstract();//destructeur � modifier en fonction de la classe (il sera utilis� dans la fonction supprimer)
};

