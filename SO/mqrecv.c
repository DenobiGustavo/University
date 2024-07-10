 // Arquivo mqrecv.c: recebe mensagens de uma fila de mensagens POSIX. 2 // Em Linux, compile usando: cc -Wall mqrecv.c -o mqrecv -lrt 
 
 #include <stdio.h> 
 #include <stdlib.h> 
 #include <mqueue.h> 
 #include <sys/stat.h> 
 
 #define QUEUE "/my_queue" 
 
 int main (int argc, char *argv[]) 
 { 
 mqd_t queue ; // descritor da fila de mensagens 
 struct mq_attr attr ; // atributos da fila de mensagens 
 int msg ; // as mensagens são números inteiros 
 
 // define os atributos da fila de mensagens 
 attr.mq_maxmsg = 10 ; // capacidade para 10 mensagens 
 attr.mq_msgsize = sizeof(msg) ; // tamanho de cada mensagem 
 attr.mq_flags = 0 ; 
 
 // abre ou cria a fila com permissoes 0666 
 if ((queue = mq_open (QUEUE, O_RDWR|O_CREAT, 0666, &attr)) < 0)
 { 
 perror ("mq_open") ; 
 exit (1) ; 
 } 
 
 // recebe cada mensagem e imprime seu conteudo 
 for (;;) 
 { 
 if ((mq_receive (queue, (void*) &msg, sizeof(msg), 0)) < 0) 
 { 
 perror("mq_receive:") ; 
 exit (1) ; 
 } 
 printf ("Received msg value %d\n", msg) ; 
 } 
 } 
