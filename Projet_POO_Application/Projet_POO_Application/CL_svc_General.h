#pragma once

#include "CL_CAD.h"

using namespace System::Data;
using namespace MySql::Data::MySqlClient;
using namespace System::Xml;
using namespace System;

namespace NS_Svc {
	ref class CL_svc_General
	{
	protected:
		NS_Composants::CL_CAD^ cad;
		DataSet^ ds;
		DataTable^ dt;
	public:
		CL_svc_General();
	};
}


