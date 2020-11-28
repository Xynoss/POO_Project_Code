#pragma once

#include "CL_CAD.h"
#include "CL_map_TBPERSONNE.h"

using namespace System::Data;
using namespace MySql::Data::MySqlClient;
using namespace System::Xml;
using namespace System;

namespace NS_Svc
{
	ref class CL_svc_gestionPersonnes
	{
	private:
		NS_Composants::CL_CAD^ cad;
		NS_Composants::CL_map_TBPERSONNE^ personne;
		DataSet^ ds;
		DataTable^ dt;
	public:
		CL_svc_gestionPersonnes(void);
		DataSet^ listePersonnes(String^);
		DataTable^ TablePersonnes();
		int ajouter(String^, String^);
		void modifier(int, String^, String^);
		void supprimer(int);
	};
}