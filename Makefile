

PROGS =	remotedb server

all:	${PROGS}

remotedb.h remotedb_clnt.c remotedb_svc.c remotedb_xdr.c:	remotedb.x
			rpcgen -C remotedb.x

remotedb_clnt.o: remotedb_clnt.c remotedb.h

remotedb_svc.o: remotedb_svc.c remotedb.h

remotedb:	remotedb.h client.o remotedb_clnt.o remotedb_xdr.o
			${CC} ${CFLAGS} -o $@ client.o remotedb_clnt.o remotedb_xdr.o \
				${LIBS} ${LIBS_RPC}

server:	remotedb.h server.o remotedb_svc.o remotedb_xdr.o
			${CC} ${CFLAGS} -o $@ server.o remotedb_svc.o remotedb_xdr.o \
				${LIBS} ${LIBS_RPC}

clean:
		rm -f ${PROGS} ${CLEANFILES} *_clnt.c *_svc.c *_xdr.c remotedb.h
