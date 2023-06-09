// C program that perform pipe system call in C

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MSGSIZE 50

void msg_pipe()
{
	char *msg1 = "Message 1";
	char *msg2 = "Message 2";
	char *msg3 = "Message 3";
	char *msg4 = "Message 4";
	char buf[MSGSIZE];
	int msg[3];

	if (pipe(msg) < 0)
		exit(1);
	else
	{
		//Write To pipe
		if (write(msg[1], msg1, MSGSIZE) < 0)
		{
			perror("[+]Fail To Send MSG1");
			exit(1);
		}
		if (write(msg[1], msg2, MSGSIZE) < 0)
		{
			perror("[+]Fail To Send MSG2");
			exit(1);
		}
		if (write(msg[1], msg3, MSGSIZE) < 0)
		{
			perror("[+]Fail To Send MSG3");
			exit(1);
		}
		if (write(msg[1], msg4, MSGSIZE) < 0)
		{
			perror("[+]Fail To Send MSG4");
			exit(1);
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (read(msg[0], buf, MSGSIZE) < 0) //Read to Pipe
		{
			perror("[+]Fail To Read MSGs");
			exit(1);
		}
		printf("%s\n", buf);
	}
}
