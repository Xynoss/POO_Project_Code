#pragma once
using namespace System;
namespace NS_Composants {
	ref class CL_map_Stock
	{
	private:
		int TauxTVA;
		int TVA;
		int PrixUnitaire;
		int nmbArticle;
		int SeuilApprovisionnement;
		String^ NatureArticle;
		String^ NomArticle;
		String^ ReferenceArtcicle;
	public:
		CL_map_Stock(void);
		String^ SELECT(void);
		String^ INSERT(void);
		String^ UPDATE(void);
		String^ DELETE(void);
		String^ SELECT_STOCK(void);
		void setTauxTVA(int);
		void setTVA(int);
		void setPrixUnitaire(int);
		void setnmbArticle(int);
		void setSeuilApprovisionnement(int);
		void setNomArticle(String^);
		void setNatureArticle(String^);
		void setReferenceArticle(String^);
		int getTauxTVA();
		int getTVA();
		int getPrixUnitaire();
		int getSeuilApprovisionnement();
		int getnmbArticle();
		String^ getNomArticle(void);
		String^ getReferenceArticle(void);
		String^ getNatureArticle(void);
	};
}
