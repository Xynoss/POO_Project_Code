#pragma once

using namespace System;
namespace NS_Composants
{
	ref class CL_map_Commande
	{
	private:
		int ID_Facture;
		int ID_Client;
		int ID_Date;
		String^ RefCommande;
		String^ DateCommande;
		String^ DateLivraison;
		String^ DatePayement;
		String^ MoyenPayement;
		String^ DateSolde;
		String^ Remise;
		String^ Quantit�Article;
		double MontantTVA;
		double MontantHT;
		double MontantTTC;
		String^ MontantPayement;
		double PrixUnitaire;
	public:
		CL_map_Commande(void);
		String^ SELECT(void);
		String^ INSERT(void);
		String^ INSERTDATE(void);
		String^ UPDATE(void);
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
		void setMontantHT(double);
		void setMontantTTC(double, double);
		void setIDClient(int);
		void setQuantit�Article(String^);
		void setMontantPayment(String^);
		//void setPrixUnitaire();

		//getter
		int getIDFacture(void);
		int getIDClient(void);
		int getIDDate(void);
		String^ getRefCommande(void);
		String^ getDateCommande(void);
		String^ getDateLivraison(void);
		String^ getDatePayement(void);
		String^ getMoyenPayement(void);
		String^ getDateSolde(void);
		String^ getQuantit�Article(void);
		String^ getRemise(void);
		double getMontantTVA(void);
		double getMontantHT(void);
		double getMontantTTC(void);
		String^ getMontantPayment(void);
		//double getPrixUnitaire(void);
	};
}
