/*
 * InverseFiltering.h
 *
 *  Created on: 3 Oct 2016
 *      Author: ljuvela
 */

#ifndef SRC_GLOTT_INVERSEFILTERING_H_
#define SRC_GLOTT_INVERSEFILTERING_H_

void GetLpWeight(const Param &params, const LpWeightingFunction &weight_type,
						const gsl::vector_int &gci_inds, const gsl::vector &frame,
						const size_t &frame_index, gsl::vector *weight_function);

//void ArAnalysis(const Param &params , const bool &use_iterative_gif,
//					   const double &warping_lambda_vt, const LpWeightingFunction weight_type, const gsl::vector &lp_weight,
//					   const gsl::vector &frame, const gsl::vector &pre_frame, gsl::vector *A)
void ArAnalysis(const int &lp_order,const double &warping_lambda, const LpWeightingFunction &weight_type,
                  const gsl::vector &lp_weight, const gsl::vector &frame, gsl::vector *A);

void WWLP(const gsl::vector &weight_function, const double &warping_lambda, const LpWeightingFunction weight_type,
		const int &lp_order, const gsl::vector &frame, gsl::vector *A);

void LPC(const gsl::vector &frame, const int &lpc_order, gsl::vector *A);

#endif /* SRC_GLOTT_INVERSEFILTERING_H_ */