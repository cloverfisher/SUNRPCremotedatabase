/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _REMOTEDB_H_RPCGEN
#define _REMOTEDB_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct remotedb_in {
	char *arg1;
};
typedef struct remotedb_in remotedb_in;

struct remotedb_out {
	char *res1;
};
typedef struct remotedb_out remotedb_out;

#define REMOTEDB_PROG 0x31230000
#define REMOTEDB_VERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define REMOTEDBPROC 1
extern  remotedb_out * remotedbproc_1(remotedb_in *, CLIENT *);
extern  remotedb_out * remotedbproc_1_svc(remotedb_in *, struct svc_req *);
#define ADD_TO_DATABASE 2
extern  remotedb_out * add_to_database_1(remotedb_in *, CLIENT *);
extern  remotedb_out * add_to_database_1_svc(remotedb_in *, struct svc_req *);
#define REMOVE_FROM_DATABASE 3
extern  remotedb_out * remove_from_database_1(remotedb_in *, CLIENT *);
extern  remotedb_out * remove_from_database_1_svc(remotedb_in *, struct svc_req *);
#define LOOKUP_NAME 4
extern  remotedb_out * lookup_name_1(remotedb_in *, CLIENT *);
extern  remotedb_out * lookup_name_1_svc(remotedb_in *, struct svc_req *);
#define LIST 5
extern  remotedb_out * list_1(remotedb_in *, CLIENT *);
extern  remotedb_out * list_1_svc(remotedb_in *, struct svc_req *);
extern int remotedb_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define REMOTEDBPROC 1
extern  remotedb_out * remotedbproc_1();
extern  remotedb_out * remotedbproc_1_svc();
#define ADD_TO_DATABASE 2
extern  remotedb_out * add_to_database_1();
extern  remotedb_out * add_to_database_1_svc();
#define REMOVE_FROM_DATABASE 3
extern  remotedb_out * remove_from_database_1();
extern  remotedb_out * remove_from_database_1_svc();
#define LOOKUP_NAME 4
extern  remotedb_out * lookup_name_1();
extern  remotedb_out * lookup_name_1_svc();
#define LIST 5
extern  remotedb_out * list_1();
extern  remotedb_out * list_1_svc();
extern int remotedb_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_remotedb_in (XDR *, remotedb_in*);
extern  bool_t xdr_remotedb_out (XDR *, remotedb_out*);

#else /* K&R C */
extern bool_t xdr_remotedb_in ();
extern bool_t xdr_remotedb_out ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_REMOTEDB_H_RPCGEN */
