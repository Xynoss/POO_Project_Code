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
		String^ MontantTVA;
		double MontantHT;
		double MontantTTC;
		String^ MontantPayement;
	public:
		CL_map_Commande(void);
		String^ SELECT(void);
		String^ INSERT(void);
		String^ INSERTDATE(void);
		String^ UPDATE(void);
		String^ DELETE(void);
		void setIDfacture(int);
		void setReference(String^/*, String^, String^, String^, String^*/);
		void setDateCommande(String^);
		void setDateLivraison(String^);
		void setDatePayement(String^);
		void setMoyenPayement(String^);
		void setDateSolde(String^);
		void setRemise(String^);
		void setMontantTVA(String^);
		void setMontantHT(double, double);
		void setMontantTTC(double, double);
		void setIDClient(int);
		void setQuantit�Article(String^);
		void setMontantPayment(String^);
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
		String^ getMontantTVA(void);
		String^ getMontantHT(void);
		String^ getMontantTTC(void);
		String^ getMontantPayment(void);
	};
}
