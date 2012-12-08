/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "remotedb.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

remotedb_out *
remotedbproc_1(remotedb_in *argp, CLIENT *clnt)
{
	static remotedb_out clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, REMOTEDBPROC,
		(xdrproc_t) xdr_remotedb_in, (caddr_t) argp,
		(xdrproc_t) xdr_remotedb_out, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

remotedb_out *
add_to_database_1(remotedb_in *argp, CLIENT *clnt)
{
	static remotedb_out clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, ADD_TO_DATABASE,
		(xdrproc_t) xdr_remotedb_in, (caddr_t) argp,
		(xdrproc_t) xdr_remotedb_out, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

remotedb_out *
remove_from_database_1(remotedb_in *argp, CLIENT *clnt)
{
	static remotedb_out clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, REMOVE_FROM_DATABASE,
		(xdrproc_t) xdr_remotedb_in, (caddr_t) argp,
		(xdrproc_t) xdr_remotedb_out, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

remotedb_out *
lookup_name_1(remotedb_in *argp, CLIENT *clnt)
{
	static remotedb_out clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, LOOKUP_NAME,
		(xdrproc_t) xdr_remotedb_in, (caddr_t) argp,
		(xdrproc_t) xdr_remotedb_out, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

remotedb_out *
list_1(remotedb_in *argp, CLIENT *clnt)
{
	static remotedb_out clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, LIST,
		(xdrproc_t) xdr_remotedb_in, (caddr_t) argp,
		(xdrproc_t) xdr_remotedb_out, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}