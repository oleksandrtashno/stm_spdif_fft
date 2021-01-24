/* dsp.h - Project specific digital signal processing */

/* Includes */
#include "stdint.h"
#include "arm_math.h"
#include "dsp.h"

/* Static variables */

// Init FFT
static arm_rfft_fast_instance_f32	fft_handler;

/* Function implementaions */

/*!
	@brief Hamming window function
*/
void dsp_hamming(float32_t *x, uint16_t len) {
	float32_t w = 2.0 * PI / (len - 1.0);

	for (uint16_t n = 0; n < len; n++) {
		x[n] = (0.54 - 0.46 * arm_cos_f32(w * n)) * x[n];
	}
}

/*!
	@brief array int32_t to float32_t 
*/
void dsp_int2float(int32_t *in, float32_t *out, uint16_t len) {
	for(uint16_t i = 0; i < len; i++) {
		out[i] = (float)in[i];
	}
}

/*!
	@brief Init fft 
*/
void dsp_fft_init(uint16_t fft_len) {
	arm_rfft_fast_init_f32(&fft_handler, fft_len);
}

/*!
	@brief Perform fft
*/
void dsp_fft(float32_t *td, float32_t *fd) {
	// Perform fft
	arm_rfft_fast_f32(&fft_handler, td, fd, 0);

	// compute frequency domain magnitudes (gets rid of imaginary parts)		
	arm_cmplx_mag_f32(fd, fd, fft_handler.fftLenRFFT / 2);
}

/*!
	@brief frequency to index
*/
uint16_t dsp_f2i(float32_t f, uint16_t sample_rate, uint16_t fft_len) {
	return ((float32_t)fft_len * f) / ((float32_t)sample_rate * 2.0);
}

/*!
	@brief index to frequency
*/
float32_t dsp_i2f(uint16_t i, uint16_t sample_rate, uint16_t fft_len) {
	return (2.0 *i * (float32_t)sample_rate) / (float32_t)fft_len;
}


	


	
	