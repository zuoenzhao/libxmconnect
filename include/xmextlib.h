
#ifndef __XMEXT_LIB_H__
#define __XMEXT_LIB_H__




#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */


typedef struct tagSYSTEM_TIME
{
	int  year;		///< �ꡣ   
	int  month;		///< �£�January = 1, February = 2, and so on.   
	int  day;		///< �ա�   
	int  wday;		///< ���ڣ�Sunday = 0, Monday = 1, and so on   
	int  hour;		///< ʱ��   
	int  minute;	///< �֡�   
	int  second;	///< �롣   
	int  isdst;		///< ����ʱ��ʶ��   
} SYSTEM_TIME;

typedef struct Queue
{
	void *mutex_lock;
	size_t res;
	unsigned char *buf;
	unsigned char *head;
	unsigned char *tail;
	unsigned char *buf_start_point;
	unsigned char *buf_end_point;
}Queue;

typedef unsigned char  Type;



/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@�����ⲿ�⺯��@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

/*********************************************
**��������			����ȡ���ʣ������
**param [in]	��state ���״̬ 0 : δ���  1 : ����� 2 : �ѳ���
**param[out]	��pCap ����ʣ�������ٷֱ�
**����ֵ			��0 �ɹ�		<0 ��ʧ��
**********************************************/
extern int GetSystemPowerCap(unsigned char * pCap, int state);



/*********************************************
**��������			����ȡ����״̬
**param [in]	����
**param[out]	����
**����ֵ			����     11:������ 10������û��� 01���������� 00��������ǳ��
**********************************************/
extern void HI_HAL_MCUHOST_Power_Poll(void);



/*********************************************
**��������			��uart���ݽ�β�ַ�����
**param [in]	��inBuf �����������ַ���			inLen �����ַ����ĳ���
**param[out]	����
**����ֵ		����     
**********************************************/
extern unsigned char XOR_Inverted_Check(unsigned char* inBuf, unsigned char inLen);
	
	
/*********************************************
**��������			�����Ƶ�Ƭ��led����
**param [in]	��ledstate {02, 5, 100, 00, 5, 100}��������Σ�ÿ��100*10ms,��Ʋ���
**param[out]	����
**����ֵ			����     
**********************************************/	
extern void HI_HAL_MCUHOST_LedState_Control(char *ledstate);


/*********************************************
**��������			���͵�Ƭ������
**param [in]	����
**param[out]	����
**����ֵ			����     
**********************************************/	
extern void HI_HAL_MCUHOST_KeepAlive_Set(void);


/*********************************************
**��������			��ʹ�ܵ�Ƭ�����������������
**param [in]	��Pirflag �Ƿ�ʹ��		 Pirtime ������
**param[out]	����
**����ֵ			����     
**********************************************/		
extern void HI_HAL_MCUHOST_Set_PIR_Time(bool Pirflag,unsigned short *Pirtime);


/*********************************************
**��������			�����ú����Ӧ����ʱ��
**param [in]	��Pirtime ����ʱ��
**param[out]	����
**����ֵ			����     
**********************************************/	
extern void HI_HAL_MCUHOST_Set_PIR_CheckTime(unsigned char *Pirtime);
	

/*********************************************
**��������			�����õ�Ƭ��rtcʱ��
**param [in]	����
**param[out]	����
**����ֵ			����     
**********************************************/	
extern void HI_HAL_MCUHOST_Rtc_Sync(void);


/***********************************************

**��������			�����ö�ʱ��������

	
	wakeupReason:�����¼�:\
		_DHCP_CONNECT = 0//����ʱ����������
		_APPOINTMENT_POWERUP = 1,//ԤԼ���� 
		_SERVER_SYNCHRONIZATION_POWERUP = 2,//ͬ����������һ��12��Сʱһ�ζ�ʱ���� 					
		_INTERVAL_WAKE = 3,//�������
		 = 4,////��ʱ����
	pStartTime:��ʱ����ʱ��
	wakeupSwitch:
		1��ʾ������ʱ��0��ʾ�ر�
	doowBellSwitch:
		1��ʾ������ʱ����ʱͬʱ����433���壬0��ʾ����������
	Parameter:	 ��
	Return: 	  ��
*************************************************/
extern void HI_HAL_MCUHOST_Set_Wakeup_Time(unsigned char wakeupSwitch,unsigned char wakeReason,SYSTEM_TIME *pStartTime, unsigned char doowBellSwitch);


/*********************************************
**��������			���͵�Ƭ��ͨ�ŷ��ͺ���
**param [in]	��fd ���ڱ�ʶ sbuf �����͵�����
**param[out]	����
**����ֵ			��0 �ɹ�    
**********************************************/	
extern int USART_Send_Data(int fd, unsigned char* sbuf);


/*********************************************
**��������			����ȡ���߶�������
**param [in]	����
**param[out]	����
**����ֵ			��Queue * �ṹ��    
**********************************************/	
extern Queue* GetWifiQueue(void);



extern int queue_init(Queue **queue);
extern int En_Queue(Queue *queue, Type *data);
extern int De_Queue(Queue *queue, Type *buf);
extern int is_empty(Queue *queue);
extern int is_full(Queue *queue);
extern void display_queue(Queue *queue);
extern void destroy_queue(Queue *queue);
extern void LibDvr_Clean_queue(Queue *queue);

typedef int(*fYUVCallBack) (long lYuvHandle, char* pBuffer, int nBufLen);
extern int HiCap_CaptureYUVStart(int VpssGrp, int exChn, int width, int height, fYUVCallBack fun);
extern int HiCap_CaptureYUVStop(int VpssGrp, int exChn);












#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */






#endif



















