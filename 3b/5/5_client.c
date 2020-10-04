#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buffer {
    long msg_type;
    char msg[100];
} message;
int main() {
    key_t my_key;
    int msg_id;
    my_key = ftok("progfile", 65);
    msg_id = msgget(my_key, 0666 | IPC_CREAT);
    message.msg_type = 1;
    printf("Enter Command: ");
    fgets(message.msg, 100, stdin);
    msgsnd(msg_id, &message, sizeof(message), 0);
    msgrcv(msg_id, &message, sizeof(message), 1, 0);
    return 0;
}
