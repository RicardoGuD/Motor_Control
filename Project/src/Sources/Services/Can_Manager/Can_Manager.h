/*~A*/
/*~+:Module Header*/
/*******************************************************************************/
/**
\file       Can_Manager.h
\brief      Provide Can Services
\author     Francisco Martinez
\version    1.0
\date       16/08/2015
*/
/*******************************************************************************/
/*~E*/
#ifndef __CAN_MANAGER
#define __CAN_MANAGER
/*~A*/
/*~+:Imports*/
#include "Can.h"
/*~E*/
/*~A*/
/*~+:Exported Interfaces*/
extern void Can_Manager_PduHandler0(CAN_MessageDataType CanMessage);
extern void SM_CANreceiver(void);
extern void CanManager_SendMsg(void);
extern void CanManager_SendResponse(void);

extern uint8_t Flag;
/*~E*/
#endif /* __CAN_MANAGER */
