#pragma once
using namespace System;
namespace NS_Composants {
	ref class CL_map_Stock
	{
	private:
		int ID_Article;
		String^ PrixUnitaire;
		String^ NatureArticle;
		String^ NomArticle;
		String^ RefArtcicle;
		String^ CouleurArticle;
		String^ RefArticle;
		int NombreStock;
	public:
		CL_map_Stock(void);
		String^ SELECT(void);
		String^ INSERT(void);
		String^ UPDATE(void);
		String^ DELETE(void);
		void setIDArticle(int);
		void setNombreStock(int);
		void setNomArticle(String^);
		void setNatureArticle(String^);
		void setRefArticle(String^);
		void setCouleurArticle(String^);
		void setPrixUnitaire(String^);
		int getIDArticle();
		int getNombreStock();
		String^ getNomArticle(void);
		String^ getRefArticle(void);
		String^ getNatureArticle(void);
		String^ getCouleurArticle(void);
		String^ getPrixUnitaire(void);
	};
}
