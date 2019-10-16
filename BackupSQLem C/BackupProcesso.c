#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

static int exec_prog(const char **argv)
{
    pid_t   my_pid;
    int     status, timeout /* unused ifdef WAIT_FOR_COMPLETION */;

    if (0 == (my_pid = fork())) {
            if (-1 == execve(argv[0], (char **)argv , NULL)) {
                    perror("child process execve failed [%m]");
                    return -1;
            }
    }

#ifdef WAIT_FOR_COMPLETION
    timeout = 1000;

    while (0 == waitpid(my_pid , &status , WNOHANG)) {
            if ( --timeout < 0 ) {
                    perror("timeout");
                    return -1;
            }
            sleep(1);
    }

    printf("%s WEXITSTATUS %d WIFEXITED %d [status %d]\n",
            argv[0], WEXITSTATUS(status), WIFEXITED(status), status);

    if (1 != WIFEXITED(status) || 0 != WEXITSTATUS(status)) {
            perror("%s failed, halt system");
            return -1;
    }

#endif
    return 0;
}
*/

 int main()
 {	
 	int i;
 	char user[15]="",host[15]="",password[15]="",database[15]="",CaminhoMysqldump[100], CaminhoFinalBackup[100],help[100]="";
 	char comando[200];
 	FILE *file;
 	file = fopen("Documento.txt","r");
 	
 	//pega o usuario do arquivo
 	fgets(help,100,file);
 	user[0]='-';
	user[1]='u';
 	i=2;
 	while(help[i+3]!='\n' && i<15)
 	{
 		user[i]=help[i+3];
 		i++;
	}
	printf(user);
 	
//	pega o host do arquivo
 	fgets(help,100,file);
 	host[0]='-';
	host[1] = 'h';
 	i=2;
 	while(help[i+3]!='\n' && i<15)
 	{
 		host[i]=help[i+3];
 		i++;
	}
 	printf(host);
 	
// 	pega a senha do arquivo
 	fgets(help,100,file);
 	password[0]='-';
	password[1]='p';
 	i=2;
 	while(help[i+7]!='\n' && i<15)
 	{
 		password[i]=help[i+7];
 		i++;
	 }
	//printf(password);

 	
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
 	
 	int status = system("ls");
	printf("Executou ls, agora vai executar oi:\n");	
	const char    *my_argv[64] = {CaminhoMysqldump, user,password,host,database,CaminhoFinalBackup};
	int rc = exec_prog(my_argv);
 	
 
 	fclose(file);
   return 0;
 }





