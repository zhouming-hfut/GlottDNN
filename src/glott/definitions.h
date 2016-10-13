#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_

#include <gslwrap/vector_int.h>
#include <gslwrap/vector_double.h>
#include <gslwrap/matrix_double.h>

/* Enums */
enum DataType {ASCII, BINARY};
enum SignalPolarity {POLARITY_DEFAULT, POLARITY_INVERT, POLARITY_DETECT};
enum LpWeightingFunction {NONE, AME, STE};
enum WindowingFunctionType {HANN, HAMMING, BLACKMAN, COSINE};
enum ExcitationMethod {SINGLE_PULSE_EXCITATION, DNN_GENERATED_EXCITATION, PULSES_AS_FEATURES_EXCITATION};

/* Structures */
struct Param {
	Param();
	~Param();
public:
	int fs;
	int frame_length;
	int frame_length_long;
	int frame_shift;
	int number_of_frames;
	int signal_length;
	int lpc_order_vt;
	int lpc_order_glot;
	int hnr_order;
	bool use_external_f0;
	char *external_f0_filename;
	bool use_external_gci;
	char *external_gci_filename;
	DataType data_type;
	bool qmf_subband_analysis;
	SignalPolarity signal_polarity;
	double gif_pre_emphasis_coefficient;
	bool use_iterative_gif;
	LpWeightingFunction lp_weighting_function;
	int lpc_order_glot_iaif;
	double warping_lambda_vt;
	double ame_duration_quotient;
	double ame_position_quotient;
	WindowingFunctionType default_windowing_function;
	char *basename;
	double max_pulse_len_diff;
	int paf_pulse_length;
	bool use_pulse_interpolation;
	bool use_highpass_filtering;
	bool use_waveforms_directly;
	bool extract_f0 ;
	bool extract_gain ;
	bool extract_lsf_vt;
	bool extract_lsf_glot;
	bool extract_hnr;
	bool extract_infofile;
	bool extract_glottal_excitation;
	bool extract_gci_signal;
	bool extract_pulses_as_features;
	int lpc_order_vt_qmf1;
	int lpc_order_vt_qmf2;
	double f0_max;
	double f0_min;
	double voicing_threshold;
   double zcr_threshold;
   double relative_f0_threshold;
   double speed_scale;
   double pitch_scale;
   //double f0_check_range;
   ExcitationMethod excitation_method;
};



/* Define analysis data variable struct*/
struct AnalysisData {
	AnalysisData();
	~AnalysisData();
	int AllocateData(const Param &params);
	int SaveData(const Param &params);
public:
	gsl::vector signal;
	gsl::vector fundf;
	gsl::vector frame_energy;
	gsl::vector_int gci_inds;
	gsl::vector source_signal;
   gsl::vector source_signal_iaif;

	gsl::matrix poly_vocal_tract;
	gsl::matrix lsf_vocal_tract;
	gsl::matrix poly_glot;
	gsl::matrix lsf_glot;
	gsl::matrix excitation_pulses;
   gsl::matrix hnr_glot;


	/* QMF analysis specific */
	//gsl::matrix lsf_vt_qmf1;
	//gsl::matrix lsf_vt_qmf2;
	//gsl::vector gain_qmf;
};

/* Define analysis data variable struct*/
struct SynthesisData {
   SynthesisData();
   ~SynthesisData();
public:
   gsl::vector signal;
   gsl::vector fundf;
   gsl::vector frame_energy;
   gsl::vector excitation_signal;
  // gsl::vector excitation_pulse;

   gsl::matrix poly_vocal_tract;
   gsl::matrix lsf_vocal_tract;
   gsl::matrix poly_glot;
   gsl::matrix lsf_glot;
   gsl::matrix excitation_pulses;
   gsl::matrix hnr_glot;

   /* QMF analysis specific */
   //gsl::matrix lsf_vt_qmf1;
   //gsl::matrix lsf_vt_qmf2;
   //gsl::vector gain_qmf;
};






#endif
