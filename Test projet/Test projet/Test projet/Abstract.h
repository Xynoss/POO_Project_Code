#pragma once
class Abstract
{
private:
	//variables à introduire
	string nom, prenom;
	int ID;
	

public:
	Abstract();//constructeur à modifier en fonction de la classe
	virtual void modifier()=0; //dans les paranthèses, rentrer les variables à utiliser
	virtual void supprimer()=0; //dans les paranthèses, rentrer les variables à utiliser
	virtual void ajouter()=0; //dans les paranthèses, rentrer les variables à utiliser
	virtual void afficher()=0; //dans les paranthèses, rentrer les variables à utiliser
	virtual ~Abstract();//destructeur à modifier en fonction de la classe (il sera utilisé dans la fonction supprimer)
};

