#pragma once
#include "CL_CAD.h"
#include "CL_map_Stock.h"

using namespace System::Data;
using namespace MySql::Data::MySqlClient;
using namespace System::Xml;
using namespace System;
namespace NS_Svc {
	ref class CL_svc_gestionStock
	{
	private:
		NS_Composants::CL_CAD^ cad;
		NS_Composants::CL_map_Stock^ Stock;
		DataSet^ DS;
		DataTable^ DT;
	public:
		CL_svc_gestionStock(void);
		DataSet^ ListeArticle(String^);
		DataTable^ TableStock();
		int ajouter(String^, String^, String^, int, int);
		void modifier(int, int, String^, String^, String^);
		void supprimer(String^);
	};
}
