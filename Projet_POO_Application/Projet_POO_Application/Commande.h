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
		int Remise;
		int MontantTVA;
	public:
		CL_map_Commande(void);
		String^ SELECT(void);
		String^ INSERT(void);
		String^ UPDATE(void);
		String^ DELETE(void);
		void setReference(String^);
		void setDateCommande(String^);
		void setDateLivraison(String^);
		void setDatePayement(String^);
		void setMoyenPayement(String^);
		void setDateSolde(String^);
		void setRemise(int);
		void setMontantTVA(int);
		void setIDClient(int);
		int getIDFacture(void);
		int getIDClient(void);
		int getIDDate(void);
		String^ getRefCommande(void);
		String^ getDateCommande(void);
		String^ getDateLivraison(void);
		String^ getDatePayement(void);
		String^ getMoyenPayement(void);
		String^ getDateSolde(void);
		int getRemise(void);
		int getMontantTVA(void);
	};
}
