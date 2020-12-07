#pragma once

using namespace System;
namespace NS_Composants
{
	ref class CL_map_Commande
	{
	private:
		int ID_Facture;
		int ID_Client;
		int ID_Article;
		int ID_Date;
		String^ RefCommande;
		String^ DateCommande;
		String^ DateLivraison;
		String^ DatePayement;
		String^ MoyenPayement;
		String^ DateSolde;
		String^ Remise;
		String^ QuantitéArticle;
		String^ MontantTVA;
		String^ MontantHT;
		String^ MontantHT2;
		String^ MontantTTC;
		String^ MontantPayement;
		String^ PrixUnitaire;
	public:
		CL_map_Commande(void);
		String^ SELECT(void);
		String^ SELECTCOM(void);
		String^ SELECTDGV(void);
		String^ INSERT(double HT, double TVA, double TTC);
		String^ INSERTCOMMANDE(int IDFACTURE);
		String^ INSERTDATE(int IDFACTURE, double TTC);
		String^ UPDATE(double HT, double TVA, double TTC);
		String^ UPDATEARTICLE(double HT, double TVA, double TTC);
		String^ DELETE(void);

		//setter
		void setIDfacture(int);
		void setReference(String^ Reference, String^ Prenom, String^ Nom, String^ annee, String^ Ville);
		void setDateCommande(String^);
		void setDateLivraison(String^);
		void setDatePayement(String^);
		void setMoyenPayement(String^);
		void setDateSolde(String^);
		void setRemise(String^);
		void setMontantTVA(double);
		void setMontantHT(double, double);
		void setMontantHT2(double);
		void setMontantTTC(double, double, double);
		void setIDClient(int);
		void setIDArticle(int);
		void setQuantitéArticle(String^);
		void setMontantPayment(String^);
		void setPrixUnitaire(String^);

		//getter
		int getIDFacture(void);
		int getIDClient(void);
		int getIDArticle(void);
		int getIDDate(void);
		String^ getRefCommande(void);
		String^ getDateCommande(void);
		String^ getDateLivraison(void);
		String^ getDatePayement(void);
		String^ getMoyenPayement(void);
		String^ getDateSolde(void);
		String^ getQuantitéArticle(void);
		String^ getRemise(void);
		String^ getMontantTVA(void);
		String^ getMontantHT(void);
		String^ getMontantHT2(void);
		String^ getMontantTTC(void);
		String^ getMontantPayment(void);
		String^ getPrixUnitaire(void);
	};
}
