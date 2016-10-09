/* Program to show the progress done by child process 
 * in main parent process.
 */

#include <stdio.h>
#include <sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include <stdlib.h>
#include <string.h>


void child_process()
{
	/* Start here 	
	 */

	int shmid;
	key_t key;
	char  *s=0; int *shm=0,*res =0;
	long int j;
	
	key = 9876;
	
	shmid = shmget(key, 100, IPC_CREAT | 0666);
	if(shmid < 0)
	{
		perror("shmget");
		exit(1);
	}

	shm = (int *)shmat(shmid, NULL, 0);

	if (shm == (int *)-1)
	{
		perror("shmat");
		exit(1);
	}

	for(j=1;j<=100000000;j++)
	{
          res = &j;
	  if(j> 9999 && j%10000 == 0)
	  memcpy(shm,res,4);
	}


        


        *res = -1;
	memcpy(shm, res, 4);	
/*
	s = shm;
	s += 11;

	*s = 0;

	while(*shm != '*')
		sleep(1);
*/

 return;
}


void parent_process()
{

        int shmid;
        key_t key;
        char  *s; int *shm =0;
	char   buf[100];
        key = 9876;
	int re =0 ;

        shmid = shmget(key, 100, IPC_CREAT | 0666);
        if(shmid < 0)
        {
                perror("shmget");
                exit(1);
        }

        shm = (int *)shmat(shmid, NULL, 0);

        if (shm == (int *) -1)
        {
                perror("shmat");
                exit(1);
        }
/*
	for(s=shm; *s != 0; s++)
	{
		sprintf(buf, "%c", *s);
                write(1, buf, strlen(buf));
	}

        write(1, "\n", strlen(buf));
	*shm = '*';
*/

	//s = shm;

       while(1) {
          re = (int)*shm;	
	  printf("\nProgress:%d\n ",re);
          if(re == -1) break;
       }	

 return;
}


int main()
{
	pid_t pid;

	pid = fork();
	if(pid == 0)
		child_process();
	else
		parent_process();	

	return 0;
}


