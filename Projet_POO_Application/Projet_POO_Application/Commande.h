#pragma once

using namespace System;
namespace NS_Composants
{
	ref class CL_map_Commande
	{
	private:String^ Reference;
		   String^ DateCommande;
		   String^ DateLivraison;
		   String^ DatePayement;
		   String^ MoyenPayement;
		   String^ DateSolde;
		   int MontantHT;
		   int MontantTVA;
		   int MontantTTC;
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
		void setMontantHT(int);
		void setMontantTVA(int);
		void setMontantTTC(int);
		String^ getReference(void);
		String^ getDateCommande(void);
		String^ getDateLivraison(void);
		String^ getDatePayement(void);
		String^ getMoyenPayement(void);
		String^ getDateSolde(void);
		int getMontantHT(void);
		int getMontantTVA(void);
		int getMontantTTC(void);
	};
}
