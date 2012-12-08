//#include	"unpipc.h"
#include	"remotedb.h"
#include <stdio.h>
#include <stdlib.h>

remotedb_out *
remotedbproc_1_svc(remotedb_in *inp, struct svc_req *rqstp)
{
	static remotedb_out	out;

	out.res1 = inp->arg1;
	return(&out);
}


remotedb_out * add_to_database_1_svc(remotedb_in *inp, struct svc_req *rqstp)
{
	static remotedb_out	out;

	out.res1 = "add";
	return(&out);

}


remotedb_out * remove_from_database_1_svc(remotedb_in *inp, struct svc_req *rqstp)
{
	static remotedb_out	out;

	out.res1 = "remove";
	return(&out);
}


remotedb_out * lookup_name_1_svc(remotedb_in *inp, struct svc_req *rqstp)
{
	static remotedb_out	out;

	out.res1 = "lookup";
	return(&out);
}


remotedb_out * list_1_svc(remotedb_in *inp, struct svc_req *rqstp)
{
		static remotedb_out	out;

	out.res1 = "list";
	return(&out);
}



