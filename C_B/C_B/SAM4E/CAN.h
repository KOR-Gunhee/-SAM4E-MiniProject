/*
 * CAN.h
 *
 * Created: 2018-01-05 오후 12:22:17
 *  Author: ghhan
 */ 


#ifndef CAN_H_
#define CAN_H_

#define GLOBAL_MAILBOX_MASK           0x000000ff

/** Define the mailbox mode. */
#define CAN_MB_DISABLE_MODE           0
#define CAN_MB_RX_MODE                1
#define CAN_MB_RX_OVER_WR_MODE        2
#define CAN_MB_TX_MODE                3
#define CAN_MB_CONSUMER_MODE          4
#define CAN_MB_PRODUCER_MODE          5

/** Define CAN mailbox transfer status code. */
#define CAN_MAILBOX_TRANSFER_OK       0     /**< Read from or write into mailbox
	                                           successfully. */
#define CAN_MAILBOX_NOT_READY         0x01  /**< Receiver is empty or
	                                           transmitter is busy. */
#define CAN_MAILBOX_RX_OVER           0x02  /**< Message overwriting happens or
	                                           there're messages lost in
	                                           different receive modes. */
#define CAN_MAILBOX_RX_NEED_RD_AGAIN  0x04  /**< Application needs to re-read
	                                           the data register in Receive with
	                                           Overwrite mode. */
#define My11Bit (2047UL)
#define can_reset 0x00000000

#define CAN_GET_STATUS(pcan) ((pcan)->CAN_SR)

#define CAN_ID(ch,id) CAN0->CAN_MB[ch].CAN_MID=CAN_MID_MIDvA(id)
#define CAN_IDreset(ch) CAN0->CAN_MB[ch].CAN_MID&=can_reset
#define CAN_TX(ch) CAN0->CAN_TCR=(1<<ch)
#define CAN_datal(ch,data) CAN0->CAN_MB[ch].CAN_MDL=data
#define CAN_datareset(ch) CAN0->CAN_MB[ch].CAN_MDL&=can_reset
#define datal_val(ch) CAN0->CAN_MB[ch].CAN_MDL

#define CAN_RST_RXSTATUS(pcan,ch) pcan->CAN_MB[ch].CAN_MCR=CAN_MCR_MTCR | CAN_MCR_MDLC(8);

extern uint8_t CAN_Buff[32];
extern int CAN_msg_lengh;

typedef struct {
	uint32_t ul_mb_idx;
	uint8_t uc_obj_type;  /**< Mailbox object type, one of the six different
	                         objects. */
	uint8_t uc_id_ver;    /**< 0 stands for standard frame, 1 stands for
	                         extended frame. */
	uint8_t uc_length;    /**< Received data length or transmitted data
	                         length. */
	uint8_t uc_tx_prio;   /**< Mailbox priority, no effect in receive mode. */
	uint32_t ul_status;   /**< Mailbox status register value. */
	uint32_t ul_id_msk;   /**< No effect in transmit mode. */
	uint32_t ul_id;       /**< Received frame ID or the frame ID to be
	                         transmitted. */
	uint32_t ul_fid;      /**< Family ID. */
	uint32_t ul_datal;
	uint32_t ul_datah;
} can_mb_conf_t;

uint32_t can_mailbox_get_status(Can *p_can, uint8_t uc_index);
uint32_t can_mailbox_read(Can *p_can, can_mb_conf_t *p_mailbox);
uint32_t can_mailbox_write(Can *p_can, can_mb_conf_t *p_mailbox);
uint32_t can_init(Can *p_can, uint32_t ul_mck, uint32_t ul_baudrate);
uint32_t can_get_status(Can *p_can);
void can_mailbox_send_transfer_cmd(Can *p_can, can_mb_conf_t *p_mailbox);
void can_global_send_transfer_cmd(Can *p_can, uint8_t uc_mask);
void can_mailbox_init(Can *p_can, can_mb_conf_t *p_mailbox);
void receive_init(Can *p_can, can_mb_conf_t *p_mailbox);
void can_enable(Can *p_can);
void can_reset_all_mailbox(Can *p_can);
void can_disable(Can *p_can);
void CAN_msgID(int ch, uint32_t id);
void CANBOARD();
void CAN_CheckID_send();
void Main_Init_receive();
void CAN_GETID_receive();
int CAN_Getmsg(uint8_t *data);
void CAN_Lowdata(int ch,uint32_t data);
void CAN_BoardID_send();
void CAN_CHID_send();
void CAN_ADCval_receive();

#endif /* CAN_H_ */