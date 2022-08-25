#ifndef ASS_THREE_SERVERTHREAD_H
#define ASS_THREE_SERVERTHREAD_H


/**
 * the method each thread will run.
 * it will run the server of a specific user.
 * @param arg - the argument sent to the thread,
 * it should be a pointer to a Server object.
 */
void *serverThread(void *arg);

#endif //ASS_THREE_SERVERTHREAD_H
