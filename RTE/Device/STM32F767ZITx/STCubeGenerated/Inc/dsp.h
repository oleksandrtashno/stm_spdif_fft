/* dsp.h - Project specific digital signal processing */

/*!
	@brief array int32_t to float32_t 
*/
void dsp_int2float(int32_t *in, float32_t *out, uint16_t len);

/*!
	@brief Hamming window function
*/
void dsp_hamming(float32_t *x, uint16_t len);

/*!
	@brief Init fft 
*/
void dsp_fft_init(uint16_t fft_len);

/*!
	@brief Perform fft
*/
void dsp_fft(float32_t *td, float32_t *fd);

/*!
	@brief frequency to index
*/
uint16_t dsp_f2i(float32_t f, uint16_t sample_rate, uint16_t fft_len);

/*!
	@brief index to frequency
*/
float32_t dsp_i2f(uint16_t i, uint16_t sample_rate, uint16_t fft_len);
