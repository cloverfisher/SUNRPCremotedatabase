struct remotedb_in {		/* input (argument) */
  string	arg1<128>;
};

struct remotedb_out {		/* output (result) */
  string	res1<128>;
};

struct remotedb_in2 {
	string	arg1<128>;
	string arg2<128>;
};

program REMOTEDB_PROG {
    version REMOTEDB_VERS {
	remotedb_out	REMOTEDBPROC(remotedb_in) = 1; /* procedure number = 1 */
	remotedb_out    ADD_TO_DATABASE(remotedb_in2) = 2;
	remotedb_out    REMOVE_FROM_DATABASE(remotedb_in) = 3;
	remotedb_out    LOOKUP_NAME(remotedb_in) = 4;
	remotedb_out    LIST(remotedb_in) = 5;
    } = 1;				/* version number */
} = 0x31230000;			/* program number */
