#pragma once
#ifdef __cplusplus
extern "C" {
#endif 

//socket init
void *socketclient_init();

//socket send
int socketclient_send(void *handle, unsigned char *buf, int buflen);

//socket rev
int socketclient_rev(void *handle, unsigned char *buf, int *buflen);

//socket free
void socketclient_destory(void *handle);




//socket init
int socketclient_init2(void **Handle);

//socket send
int socketclient_send2(void *handle, unsigned char *buf, int buflen);

//socket rev
int socketclient_rev2(void *handle, unsigned char **buf, int *buflen);

//socket free
void socketclient_destory2(void **handle);

#ifdef __cplusplus
}
#endif