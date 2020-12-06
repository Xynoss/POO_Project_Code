#pragma once
#include "Commande.h"

using namespace System;
namespace NS_Composants
{
	ref class Map_Stat :  Commande
	{
	private:int Panier_moyen;
		   int Chiffre_Affaire;
		   int MontantTA;
		   int ValComStock;
	       int ValAchatStock;
		   int QA= getQuantitéArticle();
		   int PU = getPrixUnitaire();

		  
	public:Map_Stat(void);
		  String^ SELECT(void);
		  String^ getPanier_moyen(void);
		  String^ getChiffre_Affaire(void);
		  String^ getMontantTA(void);
		  String^ getValComStock(void);
		  String^ getValAchatStock(void);
		  String^ get10PV(void);
		  String^ get10MV(void);
		  String^ getCalculMontantClient(void);
		  
		 
	};
}
