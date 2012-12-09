//#include	"unpipc.h"
#include	"remotedb.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char*  add(char * name , char * num)
{
	char buff[64];
	char *temp;
	char temp1[128];
	int i = 1;
	strcat(name,"\n");
	strcat(num,"\n");
	char *ns;

//	temp = "a";
	FILE *input;
	input = fopen("database","r+");
	if(input == NULL)
		;
printf("add3\n");
	while((fgets(buff,64,input))!=NULL)
	{
		if(strcmp(buff,num)==0)
		{
			sprintf(temp1,"error %s is already in the database", num);
			temp  = strdup(temp1);
			fclose(input);
						return temp;
		}
		if(strcmp(buff,name)==0)
		{
			sprintf(temp1,"error %s is already in the database", name);
			temp  = strdup(temp1);
			fclose(input);
						return temp;
		}
		i++;
		printf("%d\n",i);
	}
	fputs(name,input);
	fputs(num,input);
	sprintf(temp1,"entries in database %d", (i+1)/2 );
	printf("temp %s\n",temp1);
	temp  = strdup(temp1);
	fclose(input);
	return temp;
}

char * delete(char *name)
{
	char buff[64];
	strcat(name,"\n");
	char *temp;
	char temp1[128];

	FILE *input;
	FILE *output;
	input = fopen("database","r");
	output = fopen("temp","w");
	int tag = 0;
	int tag2 = 0;
	int i = 0;
	if(input == NULL)
		;
	while((fgets(buff,64,input))!=NULL)
	{
		if(tag==1)
		{
			tag =0;
			continue;
		}

		if(strcmp(buff,name)==0)
		{
			tag = 1;
			tag2 = 1;
			continue;
		}
		fputs(buff,output);
		i++;
	}
	if(tag2 == 0)
	{
		sprintf(temp1,"error: %s        do not in the database", name);
		temp  = strdup(temp1);
		return temp;
	}
	fclose(input);
	fclose(output);
	remove("database");
	rename("temp","database");
	sprintf(temp1,"entries in database %d", (i+1)/2 );
	printf("temp %s\n",temp1);
	temp  = strdup(temp1);
	return temp;
}

char * query( char *name)
{
	FILE *input;
	char buff[64];
	char *temp;
	char mao[1024] = "";
	int i = 0 ;
	input = fopen("database","r");
//	printf("name%s\n",name);
		if(input == NULL)
		;
	while((fgets(buff,64,input))!=NULL)
	{
//		printf("buff %s",buff);
		for(i=0;i<strlen(name);i++)
		{
			if(i>strlen(buff))
				break;
			else
			{
				if(name[i] != buff[i])
					break;
			}
		}
		// memset(temp,0,strlen(temp));
		// memcpy(temp,buff,strlen(name));
		// printf("%s\n",temp);
//		printf("name%s\n",name);
//		printf("%d\n",i);
		if(i == strlen(name))
		{
			strcat(mao,buff);
			printf("query1\n");
			if((fgets(buff,64,input))!=NULL)
				strcat(mao,buff);
			printf("query2\n");
		}		
	}
	fclose(input);
	temp  = strdup(mao);
return temp;
}

char * list()
{
	FILE *input;
	input = fopen("database","r");

	char a[1024]="\n";
	char *temp;
		if(input == NULL)
		;
	char buff[64];
	while((fgets(buff,64,input))!=NULL)
	{
		strcat(a,buff);
		printf("%s",a);
	}
	fclose(input);
	temp = strdup(a);
	return temp;
}




remotedb_out *
remotedbproc_1_svc(remotedb_in *inp, struct svc_req *rqstp)
{
	static remotedb_out	out;
	if(strcmp(inp->arg1,"i5")==0)
		out.res1 = "rpc authorize\n";
	else
		out.res1 = "rpc not authrize\n";
	return(&out);
}


remotedb_out * add_to_database_1_svc(remotedb_in2 *inp2, struct svc_req *rqstp)
{
	static remotedb_out	out;
	out.res1 = add(inp2->arg2,inp2->arg1);
	printf("bbbbbbb");


	
//	out.res1 = "aaaaaaaa";
	return(&out);

}


remotedb_out * remove_from_database_1_svc(remotedb_in *inp, struct svc_req *rqstp)
{
	static remotedb_out	out;
	out.res1 = delete(inp->arg1);
	return(&out);
}


remotedb_out * lookup_name_1_svc(remotedb_in *inp, struct svc_req *rqstp)
{
	static remotedb_out	out;
	out.res1 = query(inp->arg1);
	return(&out);
}


remotedb_out * list_1_svc(remotedb_in *inp, struct svc_req *rqstp)
{
		static remotedb_out	out;

	out.res1 = list();
	return(&out);
}



