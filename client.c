//#include	"unpipc.h"		/* our header */
#include	"remotedb.h"		/* generated by rpcgen */
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
	// CLIENT *clnt_create(
	// 		char *host,
	// 		u_long prog, 
	// 		u_long vers,
	// 		char *proto);

int
main(/*int argc, char **argv*/)
{
	CLIENT		*cl;
	remotedb_in	in;
	remotedb_out	*outp;
	char c;
	int i;
	FILE *temp;
	char buff[128] = "";
	char *addstr = "add";
	char *deletestr = "delete";
	char *querystr = "query";
	char *liststr = "list";
//	XDR *xhandle;



	// if (argc != 3)
	// 	err_quit("usage: client <hostname> <integer-value>");

	cl = clnt_create("0.0.0.0", REMOTEDB_PROG, REMOTEDB_VERS, "tcp");
	fflush(stdin);
	gets(buff);
	printf("%s",buff);
	in.arg1 = buff;

	printf("%s\n",in.arg1);
//	getline(&in.arg1); 
	//in.arg1 = argv[2];
	//in.arg1 = 3;
//	gets(in.arg1);
	if ( (outp = remotedbproc_1(&in, cl)) == NULL)
		;//err_quit("%s", clnt_sperror(cl, argv[1]));

	printf("result: %s\n", outp->res1);

		if ( (outp = add_to_database_1(&in, cl)) == NULL)
		;//err_quit("%s", clnt_sperror(cl, argv[1]));

	printf("result: %s\n", outp->res1);

		if ( (outp = remove_from_database_1(&in, cl)) == NULL)
		;//err_quit("%s", clnt_sperror(cl, argv[1]));

	printf("result: %s\n", outp->res1);

		if ( (outp = lookup_name_1(&in, cl)) == NULL)
		;//err_quit("%s", clnt_sperror(cl, argv[1]));

	printf("result: %s\n", outp->res1);

		if ( (outp = list_1(&in, cl)) == NULL)
		;//err_quit("%s", clnt_sperror(cl, argv[1]));

	printf("result: %s\n", outp->res1);
	exit(0);
}