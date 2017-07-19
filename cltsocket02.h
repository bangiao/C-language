
//第二套api函数
#ifndef _CLT_SOCKET2_H__
#define _CLT_SOCKET2_H__

//客户端初始化环境
int cltSocket_init2(void **handle); //5day

//客户端发报文
int cltSocket_senddata2(void *handle, unsigned char *buf, int buflen);

//客户端收报文
int cltSocket_resvdata2(void *hanle , unsigned char **buf, int *buflen);
//为什么这个地方换成了一个二级指针，而且又增加了一个接口 4day
int cltSocket_resvdata_Free2(unsigned char *buf); 

//4 客户端销毁环境
//为什么这个地方又加了一个* 4day
int cltSocket_destory2(void **handle);


#endif //_CLT_SOCKET2_H__