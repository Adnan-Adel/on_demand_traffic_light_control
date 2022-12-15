/*
 * Bit_Masking.h
 *
 * Created: 12/7/2022 9:59:05 PM
 *  Author: Adnan
 */ 


#ifndef BIT_MASKING_H_
#define BIT_MASKING_H_

#define SET_BIT(PORT_NUM,PIN_NUM)         PORT_NUM |= (1 << PIN_NUM)
#define CLEAR_BIT(PORT_NUM,PIN_NUM)       PORT_NUM &= ~(1 << PIN_NUM)
#define TOGGLE_BIT(PORT_NUM,PIN_NUM)      PORT_NUM ^= (1 << PIN_NUM)
#define READ_BIT(PORT_NUM,PIN_NUM)        ((PORT_NUM >> PIN_NUM) & 0X01)




#endif /* BIT_MASKING_H_ */