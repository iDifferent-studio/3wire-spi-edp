/**
 *  @filename   :   epd2in9_V2.cpp
 *  @brief      :   Implements for e-paper library
 *  @author     :  
 *
 *  Copyright (C) Waveshare     Nov 9 2020
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documnetation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to  whom the Software is
 * furished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <stdlib.h>
#include "epd2in9_V2.h"

unsigned char _WF_PARTIAL_2IN9[159] =
{
0x0,0x40,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x80,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x40,0x40,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0A,0x0,0x0,0x0,0x0,0x0,0x2,  
0x1,0x0,0x0,0x0,0x0,0x0,0x0,
0x1,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x22,0x22,0x22,0x22,0x22,0x22,0x0,0x0,0x0,
0x22,0x17,0x41,0xB0,0x32,0x36,
};

unsigned char WS_20_30[159] =
{											
0x80,	0x66,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x40,	0x0,	0x0,	0x0,
0x10,	0x66,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x20,	0x0,	0x0,	0x0,
0x80,	0x66,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x40,	0x0,	0x0,	0x0,
0x10,	0x66,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x20,	0x0,	0x0,	0x0,
0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,
0x14,	0x8,	0x0,	0x0,	0x0,	0x0,	0x1,					
0xA,	0xA,	0x0,	0xA,	0xA,	0x0,	0x1,					
0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,					
0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,					
0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,					
0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,					
0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,					
0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,					
0x14,	0x8,	0x0,	0x1,	0x0,	0x0,	0x1,					
0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x1,					
0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,					
0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	0x0,					
0x44,	0x44,	0x44,	0x44,	0x44,	0x44,	0x0,	0x0,	0x0,			
0x22,	0x17,	0x41,	0x0,	0x32,	0x36
};	

unsigned char Gray4[159] =			
{											
0x00,	0x60,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	//VS L0	 //2.28s			
0x20,	0x60,	0x10,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	//VS L1				
0x28,	0x60,	0x14,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	//VS L2				
0x2A,	0x60,	0x15,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	//VS L3 				
0x00,	0x90,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	//VS L4 				
0x00,	0x02,	0x00,	0x05,	0x14,	0x00,	0x00,						//TP, SR, RP of Group0				
0x1E,	0x1E,	0x00,	0x00,	0x00,	0x00,	0x01,						//TP, SR, RP of Group1				
0x00,	0x02,	0x00,	0x05,	0x14,	0x00,	0x00,						//TP, SR, RP of Group2				
0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,						//TP, SR, RP of Group3				
0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,						//TP, SR, RP of Group4				
0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,						//TP, SR, RP of Group5				
0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,						//TP, SR, RP of Group6				
0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,						//TP, SR, RP of Group7				
0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,						//TP, SR, RP of Group8				
0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,						//TP, SR, RP of Group9				
0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,						//TP, SR, RP of Group10				
0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,						//TP, SR, RP of Group11				
0x24,	0x22,	0x22,	0x22,	0x23,	0x32,	0x00,	0x00,	0x00,				//FR, XON				
0x22,	0x17,	0x41,	0xAE,	0x32,	0x28,							//EOPT VGH VSH1 VSH2 VSL VCOM				
};

unsigned char WF_FULL[159] =
{											
0x90,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	//VS L0	1.00S			
0x60,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	//VS L1				
0x90,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	//VS L2				
0x60,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	//VS L3 				
0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	//VS L4 				
0x19,	0x19,	0x00,	0x00,	0x00,	0x00,	0x00,						//TP, SR, RP of Group0				
0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,						//TP, SR, RP of Group1				
0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,						//TP, SR, RP of Group2				
0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,						//TP, SR, RP of Group3				
0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,						//TP, SR, RP of Group4				
0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,						//TP, SR, RP of Group5				
0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,						//TP, SR, RP of Group6				
0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,						//TP, SR, RP of Group7				
0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,						//TP, SR, RP of Group8				
0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,						//TP, SR, RP of Group9				
0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,						//TP, SR, RP of Group10				
0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,						//TP, SR, RP of Group11				
0x24,	0x42,	0x22,	0x22,	0x23,	0x32,	0x00,	0x00,	0x00,				//FR, XON				
0x22,	0x17,	0x41,	0xAE,	0x32,	0x38,							//EOPT VGH VSH1 VSH2 VSL VCOM				
};

Epd::~Epd() {
};

Epd::Epd() {
    reset_pin = RST_PIN;
    dc_pin = DC_PIN;
    cs_pin = CS_PIN;
    busy_pin = BUSY_PIN;
    width = EPD_WIDTH;
    height = EPD_HEIGHT;
};

int Epd::Init() {
  uint8_t data_buf[10];
    /* this calls the peripheral hardware interface, see epdif */
    if (IfInit() != 0) {
        return -1;
    }
	
	Reset();
	
    /* EPD hardware init start */
	WaitUntilIdle();   
	SendCommand(0x12);  //SWRESET
	WaitUntilIdle();   
	
	SendCommand(0x01); //Driver output control
  data_buf[0]=0x27;
  data_buf[1]=0x01;
  data_buf[2]=0x00;      
	SendData(data_buf, 3);
	
	SendCommand(0x11); //data entry mode
	data_buf[0]=0x03;
  SendData(data_buf, 1);

	SetMemoryArea(0, 0, width-1, height-1);

	SendCommand(0x21); //  Display update control
	data_buf[0]=0x00;
	data_buf[1]=0x80;	
  SendData(data_buf, 2);

	SetMemoryPointer(0, 0);
	WaitUntilIdle();
    SetLut_by_host(WS_20_30);
    /* EPD hardware init end */
    return 0;
}

int Epd::Init_Fast() {
  uint8_t data_buf[10];
    /* this calls the peripheral hardware interface, see epdif */
    if (IfInit() != 0) {
        return -1;
    }
	
	Reset();
	
    /* EPD hardware init start */
	WaitUntilIdle();   
	SendCommand(0x12);  //SWRESET
	WaitUntilIdle();   
	
	SendCommand(0x01); //Driver output control      
	data_buf[0]=0x27;
  data_buf[1]=0x01;
  data_buf[2]=0x00;      
	SendData(data_buf, 3);
	
	SendCommand(0x11); //data entry mode       
	data_buf[0]=0x03;
  SendData(data_buf, 1);

	SetMemoryArea(0, 0, width-1, height-1);

  SendCommand(0x3C);       
	data_buf[0]=0x05;
  SendData(data_buf, 1);

	SendCommand(0x21); //  Display update control
	data_buf[0]=0x00;
	data_buf[1]=0x80;	
  SendData(data_buf, 2);

	SetMemoryPointer(0, 0);
	WaitUntilIdle();

    SetLut_by_host(WF_FULL);
    /* EPD hardware init end */
    return 0;
}

int Epd::Init_4Gray() {
  uint8_t data_buf[10];
    /* this calls the peripheral hardware interface, see epdif */
    if (IfInit() != 0) {
        return -1;
    }
	
	Reset();
	
  /* EPD hardware init start */
	WaitUntilIdle();   
	SendCommand(0x12);  //SWRESET
	WaitUntilIdle();   
	
	SendCommand(0x01); //Driver output control      
	data_buf[0]=0x27;
  data_buf[1]=0x01;
  data_buf[2]=0x00;      
	SendData(data_buf, 3);
	
	SendCommand(0x11); //data entry mode       
	data_buf[0]=0x03;
  SendData(data_buf, 1);

	SetMemoryArea(8, 0, width, height-1);

	SendCommand(0x3C); 
	data_buf[0]=0x04;
  SendData(data_buf, 1);

	SetMemoryPointer(8, 0);
	WaitUntilIdle();

  SetLut_by_host(Gray4);
  /* EPD hardware init end */
  return 0;
}

/**
 *  @brief: basic function for sending commands
 */
union Bits
{
  uint16_t data;
  uint8_t buff[2];
};

void Epd::SendCommand(unsigned char command) {
    union Bits bits;
    bits.data = command;
    bits.data = bits.data << 7 + 0x0000;
    //DigitalWrite(dc_pin, LOW);
    DigitalWrite(cs_pin, LOW);
    SpiTransfer(bits.buff[1]);
    SpiTransfer(bits.buff[0]);
    DigitalWrite(cs_pin, HIGH);
}

/**
 *  @brief: basic function for sending data
 */
void Epd::SendData(uint8_t * data, uint32_t length) {
  uint8_t current_byte = 0;  
  size_t bit_index = 0;   

  current_byte |= (1 << 7);  
  bit_index++;

  DigitalWrite(cs_pin, LOW);

  for (size_t i = 0; i < length; i++) {
      uint8_t byte_to_send = data[i];

      for (int bit = 7; bit >= 0; bit--) {
          if (byte_to_send & (1 << bit)) {
              current_byte |= (1 << (7 - (bit_index % 8)));  
          }

          bit_index++;

          if (bit_index % 8 == 0) {
              SpiTransfer(current_byte);  
              current_byte = 0;      
          }
      }

      current_byte |= (1 << (7 - (bit_index % 8))); 
      bit_index++;

      if (bit_index % 8 == 0) {
          SpiTransfer(current_byte);  
          current_byte = 0;        
      }
  }

  if (bit_index % 8 != 0) {
      SpiTransfer(current_byte); 
  }

  DigitalWrite(cs_pin, HIGH);
}

/**
 *  @brief: Wait until the busy_pin goes LOW
 */
void Epd::WaitUntilIdle(void) {
	while(1) {	 //=1 BUSY
		if(DigitalRead(busy_pin)==LOW) 
			break;
		DelayMs(5);
	}
	DelayMs(5);
}

/**
 *  @brief: module reset.
 *          often used to awaken the module in deep sleep,
 *          see Epd::Sleep();
 */
void Epd::Reset(void) {
    DigitalWrite(reset_pin, HIGH);
    DelayMs(20);  
    DigitalWrite(reset_pin, LOW);                //module reset    
    DelayMs(5);
    DigitalWrite(reset_pin, HIGH); 
    DelayMs(20);  
}

/**
 *  @brief: put an image buffer to the frame memory.
 *          this won't update the display.
 */
void Epd::SetFrameMemory(
    const unsigned char* image_buffer,
    int x,
    int y,
    int image_width,
    int image_height
) {
    int x_end;
    int y_end;

    if (
        image_buffer == NULL ||
        x < 0 || image_width < 0 ||
        y < 0 || image_height < 0
    ) {
        return;
    }
    /* x point must be the multiple of 8 or the last 3 bits will be ignored */
    x &= 0xF8;
    image_width &= 0xF8;
    if (x + image_width >= this->width) {
        x_end = this->width - 1;
    } else {
        x_end = x + image_width - 1;
    }
    if (y + image_height >= this->height) {
        y_end = this->height - 1;
    } else {
        y_end = y + image_height - 1;
    }
    
    SetMemoryArea(x, y, x_end, y_end);
    SetMemoryPointer(x, y);
    SendCommand(0x24);
    /* send the image data */
    SendData((uint8_t *)image_buffer, (y_end-y)*((x_end-x+1)/8));
}
void Epd::SetFrameMemory_Partial(
    const unsigned char* image_buffer,
    int x,
    int y,
    int image_width,
    int image_height
) {
    int x_end;
    int y_end;

    if (
        image_buffer == NULL ||
        x < 0 || image_width < 0 ||
        y < 0 || image_height < 0
    ) {
        return;
    }
    /* x point must be the multiple of 8 or the last 3 bits will be ignored */
    x &= 0xF8;
    image_width &= 0xF8;
    if (x + image_width >= this->width) {
        x_end = this->width - 1;
    } else {
        x_end = x + image_width - 1;
    }
    if (y + image_height >= this->height) {
        y_end = this->height - 1;
    } else {
        y_end = y + image_height - 1;
    }

    DigitalWrite(reset_pin, LOW);
    DelayMs(2);
    DigitalWrite(reset_pin, HIGH);
    DelayMs(2);

	uint8_t cdata_buf[10];
	SetLut(_WF_PARTIAL_2IN9);
	SendCommand(0x37); 
	cdata_buf[0]=0x00;  
	cdata_buf[1]=0x00;  
	cdata_buf[2]=0x00;  
	cdata_buf[3]=0x00; 
	cdata_buf[4]=0x00;  	
	cdata_buf[5]=0x40;  
	cdata_buf[6]=0x00;  
	cdata_buf[7]=0x00;   
	cdata_buf[8]=0x00;  
	cdata_buf[9]=0x00;
  SendData(cdata_buf, 10);

	SendCommand(0x3C); //BorderWavefrom
	cdata_buf[0]=0x80;
  SendData(cdata_buf, 1);	

	SendCommand(0x22); 
	cdata_buf[0]=0xC0;
  SendData(cdata_buf, 1);	   
	SendCommand(0x20); 
	WaitUntilIdle();  

  SetMemoryArea(x, y, x_end, y_end);
  SetMemoryPointer(x, y);
  SendCommand(0x24);
  /* send the image data */
  SendData((uint8_t *)image_buffer, (y_end-y)*((x_end-x+1)/8));
}

/**
 *  @brief: put an image buffer to the frame memory.
 *          this won't update the display.
 *
 *          Question: When do you use this function instead of 
 *          void SetFrameMemory(
 *              const unsigned char* image_buffer,
 *              int x,
 *              int y,
 *              int image_width,
 *              int image_height
 *          );
 *          Answer: SetFrameMemory with parameters only reads image data
 *          from the RAM but not from the flash in AVR chips (for AVR chips,
 *          you have to use the function pgm_read_byte to read buffers 
 *          from the flash).
 */
void Epd::SetFrameMemory(const unsigned char* image_buffer) {
    size_t a_size = this->width / 8 * this->height;
    uint8_t data_buf[a_size];

    SetMemoryArea(0, 0, this->width - 1, this->height - 1);
    SetMemoryPointer(0, 0);
    SendCommand(0x24);
    /* send the image data */
    for (int i = 0; i < this->width / 8 * this->height; i++) {
        data_buf[i]=pgm_read_byte(&image_buffer[i]);
    }
    SendData(data_buf, a_size);
}
void Epd::SetFrameMemory_Base(const unsigned char* image_buffer) {
    size_t a_size = this->width / 8 * this->height;
    uint8_t data_buf[a_size];

    SetMemoryArea(0, 0, this->width - 1, this->height - 1);
    SetMemoryPointer(0, 0);
    SendCommand(0x24);
    /* send the image data */
    for (int i = 0; i < this->width / 8 * this->height; i++) {
        data_buf[i]=pgm_read_byte(&image_buffer[i]);
    }
    SendData(data_buf, a_size);
    SendCommand(0x26);
    /* send the image data */
    for (int i = 0; i < this->width / 8 * this->height; i++) {
        data_buf[i]=pgm_read_byte(&image_buffer[i]);
    }
    SendData(data_buf, a_size);
}

/**
 *  @brief: clear the frame memory with the specified color.
 *          this won't update the display.
 */
void Epd::ClearFrameMemory(unsigned char color) {
    size_t a_size = this->width / 8 * this->height;
    uint8_t data_buf[a_size];

    SetMemoryArea(0, 0, this->width - 1, this->height - 1);
    SetMemoryPointer(0, 0);
    SendCommand(0x24);
    /* send the color data */
    for (int i = 0; i < this->width / 8 * this->height; i++) {
        data_buf[i]=color;
    }
    SendData(data_buf, a_size);

    SendCommand(0x26);
    /* send the color data */
    for (int i = 0; i < this->width / 8 * this->height; i++) {
        data_buf[i]=color;
    }
    SendData(data_buf, a_size);
}

void Epd::Display4Gray(const unsigned char *Image)
{
    int i,j,k;
    unsigned char temp1,temp2,temp3;
    uint8_t data_buf[4736];

    SendCommand(0x24);	       
    for(i=0;i<4736;i++)	     
    {
        temp3=0;
        for(j=0;j<2;j++)	
        {
            temp1 = pgm_read_byte(&Image[i*2+j]);
            for(k=0;k<2;k++)	
            {
                temp2 = temp1&0xC0 ;
                if(temp2 == 0xC0)
                    temp3 |= 0x00;//white
                else if(temp2 == 0x00)
                    temp3 |= 0x01;  //black
                else if(temp2 == 0x80) 
                    temp3 |= 0x01;  //gray1
                else //0x40
                    temp3 |= 0x00; //gray2
                temp3 <<= 1;	
                
                temp1 <<= 2;
                temp2 = temp1&0xC0 ;
                if(temp2 == 0xC0)  //white
                    temp3 |= 0x00;
                else if(temp2 == 0x00) //black
                    temp3 |= 0x01;
                else if(temp2 == 0x80)
                    temp3 |= 0x01; //gray1
                else    //0x40
                        temp3 |= 0x00;	//gray2	
                if(j!=1 || k!=1)				
                    temp3 <<= 1;
                
                temp1 <<= 2;
            }
            
         }
        data_buf[i]=temp3;			
    }
    SendData(data_buf, 4736);
    // new  data
    SendCommand(0x26);	       
    for(i=0;i<4736;i++)	  
    {
        temp3=0;
        for(j=0;j<2;j++)	
        {
            temp1 = pgm_read_byte(&Image[i*2+j]);
            for(k=0;k<2;k++)	
            {
                temp2 = temp1&0xC0 ;
                if(temp2 == 0xC0)
                    temp3 |= 0x00;//white
                else if(temp2 == 0x00)
                    temp3 |= 0x01;  //black
                else if(temp2 == 0x80) 
                    temp3 |= 0x00;  //gray1
                else //0x40
                    temp3 |= 0x01; //gray2
                temp3 <<= 1;	
                
                temp1 <<= 2;
                temp2 = temp1&0xC0 ;
                if(temp2 == 0xC0)  //white
                    temp3 |= 0x00;
                else if(temp2 == 0x00) //black
                    temp3 |= 0x01;
                else if(temp2 == 0x80)
                    temp3 |= 0x00; //gray1
                else    //0x40
                    temp3 |= 0x01;	//gray2
                if(j!=1 || k!=1)					
                    temp3 <<= 1;
                
                temp1 <<= 2;
            }
            
         }
        data_buf[i]=temp3;		
    }
    SendData(data_buf, 4736);

    DisplayFrame();
}

/**
 *  @brief: update the display
 *          there are 2 memory areas embedded in the e-paper display
 *          but once this function is called,
 *          the the next action of SetFrameMemory or ClearFrame will 
 *          set the other memory area.
 */
void Epd::DisplayFrame(void) {
    uint8_t data_buf[1];

    SendCommand(0x22);
    data_buf[0]=0xc7;
    SendData(data_buf, 1);
    SendCommand(0x20);
    WaitUntilIdle();
}

void Epd::DisplayFrame_Partial(void) {
    uint8_t data_buf[1];

    SendCommand(0x22);
    data_buf[0]=0x0F;
    SendData(data_buf, 1);
    SendCommand(0x20);
    WaitUntilIdle();
}

void Epd::SetLut(unsigned char *lut) {       
	unsigned char count;
	SendCommand(0x32);
	// for(count=0; count<153; count++) 
	// 	SendData(lut[count]); 
  SendData(lut, 153);
	WaitUntilIdle();
}

void Epd::SetLut_by_host(unsigned char *lut) {
  uint8_t data_buf[10];

  SetLut((unsigned char *)lut);
	SendCommand(0x3f);
	data_buf[0]=*(lut+153);
  SendData(data_buf, 1);
	SendCommand(0x03);	// gate voltage
	data_buf[0]=*(lut+154);
  SendData(data_buf, 1);
	SendCommand(0x04);	// source voltage
	data_buf[0]=*(lut+155);	// VSH
	data_buf[1]=*(lut+156);	// VSH2
	data_buf[2]=*(lut+157);	// VSL
  SendData(data_buf, 3);
	SendCommand(0x2c);		// VCOM
	data_buf[0]=*(lut+158);
  SendData(data_buf, 1);
}

/**
 *  @brief: private function to specify the memory area for data R/W
 */
void Epd::SetMemoryArea(int x_start, int y_start, int x_end, int y_end) {
    uint8_t data_buf[10];

    SendCommand(0x44);
    /* x point must be the multiple of 8 or the last 3 bits will be ignored */
    data_buf[0]=(x_start >> 3) & 0xFF;
    data_buf[1]=(x_end >> 3) & 0xFF;
    SendData(data_buf, 2);
    SendCommand(0x45);
    data_buf[0]=y_start & 0xFF;
    data_buf[1]=(y_start >> 8) & 0xFF;
    data_buf[2]=y_end & 0xFF;
    data_buf[3]=(y_end >> 8) & 0xFF;
    SendData(data_buf, 4);
}

/**
 *  @brief: private function to specify the start point for data R/W
 */
void Epd::SetMemoryPointer(int x, int y) {
    uint8_t data_buf[10];

    SendCommand(0x4E);
    /* x point must be the multiple of 8 or the last 3 bits will be ignored */
    data_buf[0]=(x >> 3) & 0xFF;
    SendData(data_buf, 1);
    SendCommand(0x4F);
    data_buf[0]=y & 0xFF;
    data_buf[1]=(y >> 8) & 0xFF;
    SendData(data_buf, 2);
    WaitUntilIdle();
}

/**
 *  @brief: After this command is transmitted, the chip would enter the 
 *          deep-sleep mode to save power. 
 *          The deep sleep mode would return to standby by hardware reset. 
 *          You can use Epd::Init() to awaken
 */
void Epd::Sleep() {
    uint8_t data_buf[1];
    SendCommand(0x10);
    data_buf[0]=0x01;
    SendData(data_buf, 1);
    // WaitUntilIdle();
}

/* END OF FILE */
