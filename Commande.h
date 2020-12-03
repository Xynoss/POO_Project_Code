#pragma once

using namespace System;
namespace NS_Composants
{
	ref class Commande
	{
	private:int ID_Article;
		   int ID_Facture;
		   String^ DateLivraison;
		   String^ DatePaiment;
		   String^ MoyenPayment;
		   String^ DateSolde;
		   String^ RefCommande;
		   int MontantPayment;
		   int Remise;
		   int QuantitéArticle;
		   int MontantTVA;
		   int PrixUnitaire;
	public:Commande(void);
		  String^ SELECT(void);
		  String^ INSERTCommande(int, int);
		  String^ INSERTFacture(int);
		  String^ INSERTDate(int);
		  String^ UPDATE(void);
		  String^ DELETE(void);
		  void setID_Article(int);
		  void setID_Facture(int);
		  void setDateLivraison(String^);
		  void setDatePaiment(String^);
		  void setMoyenPayment(String^);
		  void setDateSolde(String^);
		  void setRefCommande(String^);
		  void setMontantTVA(int);
		  void setMontantPayment(int);
		  void setRemise(int);
		  void setPrixUnitaire(int);
		  void setQuantitéArticle(int);
		  int getID_Article(void);
		  int getID_Facture(void);
		  String^ getDateLivraison(void);
		  String^ getMoyenPayment(void);
		  String^ getDateSolde(void);
		  int getQuantitéArticle(void);
		  int getMontantTVA(void);
		  int getPrixUnitaire(void);
		  String^ getDatePaiment(void);
		  String^ getRefCommande(void);
		  int getRemise(void);
		  int getMontantPayment(void);
	};
}
