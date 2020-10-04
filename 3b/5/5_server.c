#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<unistd.h>
#include <sys/wait.h>

struct msg_buffer {
    long msg_type;
    char msg[100];
} message;
int main() {
    key_t my_key;
    int msg_id;
    int c,s,ret;
    my_key = ftok("progfile", 65);
    msg_id = msgget(my_key, 0666 | IPC_CREAT);
    msgrcv(msg_id, &message, sizeof(message), 1, 0);
    printf("Received Command is : %s \n", message.msg);
    c=fork();
    if(c==0)
        s=execl("/bin/sh","sh","-c",message.msg,NULL);
    else {
        waitpid(c, &ret, 0);
        return 0;
    }
}
