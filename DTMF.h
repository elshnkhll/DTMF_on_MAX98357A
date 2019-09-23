int sampleRate = 8000;
float amplitude = 10.0;
int dtmf[16][2] = {
  {941, 1336}, // 0
  {697, 1209}, // 1
  {697, 1336}, // 2
  {697, 1477}, // 3
  {770, 1209}, // 4
  {770, 1336}, // 5
  {770, 1477}, // 6
  {852, 1209}, // 7
  {852, 1336}, // 8
  {852, 1477}, // 9
  {697, 1633}, // A
  {770, 1633}, // B
  {852, 1633}, // C
  {941, 1633}, // D
  {941, 1209}, // *
  {941, 1477}  // #
};

char dtmf_key[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', '*', '#'};


void SPKR_Play_DTMF(int tone) {
  int samplesCount = 2000; // between 100 AND 500 ms
  float w1 = 2.0 * 3.14159265359 * (float)dtmf[tone][1] / (float)sampleRate;
  float w2 = 2.0 * 3.14159265359 * (float)dtmf[tone][2] / (float)sampleRate;
  for (int n = 0; n < samplesCount; n++) {
    int smpl = amplitude * ( sin( (float)n * w1 ) + sin( (float)n * w2 ) );
    byte c_1 = smpl >> 8;
    byte c_2 = (byte)smpl;
    char smpl_16_b[2] = {c_1, c_2};
    SPKR_Play_Sample( (int) smpl_16_b );
  }
}

