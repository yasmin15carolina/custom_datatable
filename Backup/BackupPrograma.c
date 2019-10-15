#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 int main()
 {	
 	int i;
 	char user[15]="",host[15]="",password[15]="",database[15]="",CaminhoMysqldump[100], CaminhoFinalBackup[100],help[100]="";
 	char comando[200];
 	FILE *file;
 	file = fopen("Documento.txt","r");
 	
 	//pega o usuario do arquivo
 	fgets(help,100,file);
 	i=0;
 	while(help[i+5]!='\n' && i<15)
 	{
 		user[i]=help[i+5];
 		i++;
	}
 	
//	pega o host do arquivo
 	fgets(help,100,file);
 	i=0;
 	while(help[i+5]!='\n' && i<15)
 	{
 		host[i]=help[i+5];
 		i++;
	}
 	//help[100]="";
 	
// 	pega a senha do arquivo
 	fgets(help,100,file);
 	printf(password);
 	i=0;
 	while(help[i+9]!='\n' && i<15)
 	{
 		password[i]=help[i+9];
 		i++;
	 }
 	
// 	pega o nome do banco de dados do arquivo
 	fgets(help,100,file); 	
 	i=0;
 	while(help[i+9]!='\n' && i<15) 
 	{
 		database[i]=help[i+9];
 		i++;
	 }
 	
// 	pega o caminho do mysqldump no arquivo

 	fgets(help,100,file); 	
 	i=0;
 	while(help[i]!='\n' && i<100) 
 	{
 		CaminhoMysqldump[i]=help[i];
 		i++;
	 }
// 	pega o caminho de destino do backup no arquivo 	
 	fgets(help,100,file); 	
 	i=0;
 	while(help[i]!='\n'&& i<100) 
 	{
 		CaminhoFinalBackup[i]=help[i];
 		i++;
	 }
 	
 	strcat(comando,CaminhoMysqldump);
 	strcat(comando," -u ");
 	strcat(comando,user);
 
 	strcat(comando," -p");
 	strcat(comando,password);
 	
 	strcat(comando," -h ");
 	strcat(comando,host);
 	strcat(comando," ");
 	strcat(comando,database);
 	strcat(comando," > ");
 	strcat(comando,CaminhoFinalBackup);
 	printf("comando: %s \n",comando);
 	printf(" se nao houver senha clique enter\n");
 	system(comando);
 	fclose(file);
   return 0;
 }



