#pragma once
#include "CL_CAD.h"
#include "CL_map_Personnel.h"

using namespace System::Data;
using namespace MySql::Data::MySqlClient;
using namespace System::Xml;
using namespace System;
namespace NS_Svc {
	ref class CL_svc_gestionPersonnel
	{
	private:
		NS_Composants::CL_CAD^ cad;
		NS_Composants::CL_map_Personnel^ Personnel;
		DataSet^ DS;
		DataTable^ DT;
	public:
		CL_svc_gestionPersonnel(void);
		DataTable^ TablePersonnel();
		int ajouter(int, String^, String^, String^, String^);
		void modifier(int, int, String^, String^, String^, String^);
		void supprimer(int);
	};
}


