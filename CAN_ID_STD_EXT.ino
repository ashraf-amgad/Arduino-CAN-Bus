/*********************************************************************************************************
  START FILE
*********************************************************************************************************/
#include <mcp_can.h>
#include <SPI.h>


MCP_CAN CAN0(10);     // Set CS to pin 10


#define massage_numbers   15             

//To mark an ID as extended 29-bits ID, OR the ID with 0x80000000

#define msg_1_ID      (0x0CEBF010 | 0x80000000)          
#define msg_2_ID      (0x0CEBF020 | 0x80000000)           
#define msg_3_ID      (0x0CECF030 | 0x80000000)         
#define msg_4_ID      (0x0CECF040 | 0x80000000)        
#define msg_5_ID      (0x0CF00050 | 0x80000000)      
#define msg_6_ID      (0x0CFF0060 | 0x80000000) 
#define msg_7_ID      (0x0CFF1070 | 0x80000000) 
#define msg_8_ID      (0x123) 
#define msg_9_ID      (0x1ff) 
#define msg_10_ID     (0x0AB) 
#define msg_11_ID     (0x0CFF10B0 | 0x80000000) 
#define msg_12_ID     (0x0CFF10C0 | 0x80000000) 
#define msg_13_ID     (0x046) 
#define msg_14_ID     (0x0CFF90E0 | 0x80000000) 
#define msg_15_ID     (0x1f2) 

/*message IDs from 16 to 30*/
#define msg_16_ID     (0x1fffffff | 0x80000000) 
#define msg_17_ID     (0x1fffffff | 0x80000000) 
#define msg_18_ID     (0x1fffffff | 0x80000000)  
#define msg_19_ID     (0x1fffffff | 0x80000000) 
#define msg_20_ID     (0x1fffffff | 0x80000000) 
#define msg_21_ID     (0x1fffffff | 0x80000000) 
#define msg_22_ID     (0x1fffffff | 0x80000000) 
#define msg_23_ID     (0x1fffffff | 0x80000000) 
#define msg_24_ID     (0x1fffffff | 0x80000000) 
#define msg_25_ID     (0x1fffffff | 0x80000000) 
#define msg_26_ID     (0x1fffffff | 0x80000000) 
#define msg_27_ID     (0x1fffffff | 0x80000000) 
#define msg_28_ID     (0x1fffffff | 0x80000000) 
#define msg_29_ID     (0x1fffffff | 0x80000000) 
#define msg_30_ID     (0x1fffffff | 0x80000000) 


byte msg_data_1[8]  = {0x01, 0x20, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF};
byte msg_data_2[8]  = {0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08};
byte msg_data_3[8]  = {0x03, 0x14, 0x64, 0x80, 0xFF, 0xFF, 0xFF, 0xFF};
byte msg_data_4[8]  = {0xB5, 0x49, 0x40, 0x10, 0x31, 0xB9, 0x32, 0x83};
byte msg_data_5[8]  = {0x0E, 0xFA, 0x5B, 0xB9, 0x01, 0x3F, 0x1F, 0x1F};
byte msg_data_6[8]  = {0x0E, 0xBC, 0x5B, 0x9A, 0x01, 0x3F, 0x1F, 0x1F};
byte msg_data_7[8]  = {0x03, 0x8B, 0x00, 0xBC, 0x28, 0x7D, 0x05, 0x90};
byte msg_data_8[8]  = {0x00, 0x58, 0x41, 0x02, 0x00, 0x00, 0x00, 0x01};
byte msg_data_9[8]  = {0x8A, 0x38, 0x1A, 0x90, 0x00, 0x00, 0x0F, 0x0A};
byte msg_data_10[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
byte msg_data_11[8] = {0x00, 0x00, 0x00, 0x00, 0x8B, 0x7E, 0x00, 0x10};
byte msg_data_12[8] = {0x54, 0xFF, 0x92, 0x29, 0x0D, 0x2F, 0x00, 0x00};
byte msg_data_13[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
byte msg_data_14[8] = {0x00, 0x6F, 0xFF, 0xFF, 0x09, 0xC4, 0x00, 0x12};
byte msg_data_15[8] = {0x00, 0x00, 0x06, 0xDD, 0x03, 0xE8, 0x00, 0x00};

/* message data from 15 to 30 */
byte msg_data_16[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
byte msg_data_17[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
byte msg_data_18[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
byte msg_data_19[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
byte msg_data_20[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
byte msg_data_21[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
byte msg_data_22[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
byte msg_data_23[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
byte msg_data_24[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
byte msg_data_25[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
byte msg_data_26[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
byte msg_data_27[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
byte msg_data_28[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
byte msg_data_29[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
byte msg_data_30[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/

long unsigned int CAN_IDs[30] = {msg_1_ID, msg_2_ID, msg_3_ID, msg_4_ID, msg_5_ID, msg_6_ID, msg_7_ID, msg_8_ID, msg_9_ID, msg_10_ID,\
                          msg_11_ID, msg_12_ID, msg_13_ID, msg_14_ID, msg_15_ID, msg_16_ID, msg_17_ID, msg_18_ID, msg_19_ID, msg_20_ID,\
                          msg_21_ID, msg_22_ID, msg_23_ID, msg_24_ID, msg_25_ID, msg_26_ID, msg_27_ID, msg_28_ID, msg_29_ID, msg_30_ID};

                         
unsigned char* msgs_data_array[30] = {msg_data_1 ,msg_data_2, msg_data_3, msg_data_4, msg_data_5, msg_data_6, msg_data_7, msg_data_8, msg_data_9, msg_data_10,\
                            msg_data_11 ,msg_data_12 ,msg_data_13, msg_data_14, msg_data_15, msg_data_16, msg_data_17, msg_data_18, msg_data_19, msg_data_20,\
                            msg_data_21 ,msg_data_22 ,msg_data_23, msg_data_24, msg_data_25, msg_data_26, msg_data_27, msg_data_28, msg_data_29, msg_data_30}; 

                  


void setup()
{
  Serial.begin(115200);

  /* Initialize MCP2515 running at 16MHz with a baudrate of 500kb/s and the masks and filters disabled. */
  if(CAN0.begin(MCP_ANY, CAN_250KBPS, MCP_8MHZ) == CAN_OK) Serial.println("MCP2515 Initialized Successfully!");
  else Serial.println("Error Initializing MCP2515...");

  CAN0.setMode(MCP_NORMAL);   // Change to normal mode to allow messages to be transmitted
}



void loop()
{
  /* send data:  ID = 0x100, Standard CAN Frame, Data length = 8 bytes, 'data' = array of data bytes to send */
  char counter=0;
  char EXTENDED_STANDARD_ID=0;
  
  for(counter=0 ; counter < massage_numbers ; counter++)
  {

     if((CAN_IDs[counter] & 0x80000000) == 0x80000000)
     {
        EXTENDED_STANDARD_ID=1;
     }
     else
     {
        EXTENDED_STANDARD_ID=0;
     }

      byte sndStat = CAN0.sendMsgBuf( CAN_IDs[counter], EXTENDED_STANDARD_ID, 8, msgs_data_array[counter] );
      
      if(sndStat == CAN_OK)
      {
         Serial.println("Message Sent Successfully!");
      } 
      
      else 
      {
          Serial.println("Error Sending Message...");
      }
      
      delay(15);   // send data per 15 ms
  }
  
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
