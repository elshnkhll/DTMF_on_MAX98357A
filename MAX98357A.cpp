#include "MAX98357A.h"

void SPKR_Start() {
  i2s_config_t i2s_config = {
    .mode                 = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX),
    .sample_rate          = SAMPLE_RATE,
    .bits_per_sample      = I2S_BITS_PER_SAMPLE_16BIT,
    .channel_format       = I2S_CHANNEL_FMT_ALL_RIGHT,                           //1-channels
    .communication_format = (i2s_comm_format_t)( I2S_COMM_FORMAT_I2S | I2S_COMM_FORMAT_I2S_LSB ),
    .intr_alloc_flags     = 0,
    .dma_buf_count        = 128,
    .dma_buf_len          = 64
  };

  i2s_pin_config_t pin_config = {
    .bck_io_num   = 26,
    .ws_io_num    = 25,
    .data_out_num = 19,
    .data_in_num  = -1   //Not used
  };
  i2s_driver_install((i2s_port_t)0, &i2s_config, 0, NULL);
  i2s_set_pin((i2s_port_t)0, &pin_config);
  i2s_set_clk((i2s_port_t)0, SAMPLE_RATE, (i2s_bits_per_sample_t)16, (i2s_channel_t)1);
  i2s_zero_dma_buffer((i2s_port_t)0);
}

void SPKR_Play_Sample( int data ) {
  size_t bytes_written = 0;
  while (bytes_written == 0) {
    i2s_write((i2s_port_t)0, (const char *)data, 2, &bytes_written, portMAX_DELAY);
  }
}

void SPKR_Stop() {
  i2s_stop((i2s_port_t)0);
  i2s_driver_uninstall((i2s_port_t)0);
}
