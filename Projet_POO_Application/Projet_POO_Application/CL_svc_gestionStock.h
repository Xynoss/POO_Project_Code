#pragma once
#include "CL_CAD.h"
#include "CL_map__Stock.h"

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
		DataSet^ ds;
		DataTable^ dt;
	public:
		CL_svc_gestionStock(void);
		DataSet^ ListeArticle(String^);
		DataTable^ TableStock();
		int ajouter(String^, String^, String^, String^, double);
		void modifier(int, double, String^, String^, String^, String^);
		void supprimer(int);
	};
}
