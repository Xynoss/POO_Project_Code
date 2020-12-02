#pragma once
using namespace System;
namespace NS_Composants {
	ref class CL_map_Stock
	{
	private:
		int ID_Article;
		int PrixUnitaire;
		String^ NatureArticle;
		String^ NomArticle;
		String^ RefArtcicle;
		String^ CouleurArticle;
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
		int getIDArticle();
		int getNombreStock();
		String^ getNomArticle(void);
		String^ getRefArticle(void);
		String^ getNatureArticle(void);
		String^ getCouleurArticle(void);
	};
}
