#include "MAX98357A.h"
#include "DTMF.h"


void setup() {

  Serial.begin(115200);
  Serial.println( "* SETUP *");

}



void loop() {

  delay(1000);

  Serial.println("****** START *****");
  SPKR_Start();
  delay(3000);




  for (int i = 0; i < 10; i++) {
    int k = random(0, 9);
    Serial.println( dtmf_key[ k ] );
    SPKR_Play_DTMF( k );
  }


  delay(2000);

  i2s_zero_dma_buffer((i2s_port_t)0);
  delay(3000);
  SPKR_Stop();
  Serial.println("****** STOP *****");

  delay(5000);

}
