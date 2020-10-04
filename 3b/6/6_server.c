#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>



struct msg_buffer {
    long msg_type;
    char msg[100];
    struct stat sat;
} message;
int main() {
    key_t my_key;
    int msg_id;
    int c,s,ret;
    char path[100];
    my_key = ftok("progfile", 65);
    msg_id = msgget(my_key, 0666 | IPC_CREAT);
    msgrcv(msg_id, &message, sizeof(message), 1, 0);
    printf("Enter source file path: ");
    scanf("%s", path);
    printf("Received Command is : %s \n", message.msg);
    stat(path,&satS);

    printf("\nFile size: %ld", satS.st_size);
    msgsnd(msg_id, &message, sizeof(message), 0);
    return 0;
