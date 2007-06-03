#include <options/options.h>

#include "csm_all.h"


void sm_options(struct sm_params*p, struct option*ops) {
	
	options_double(ops, "max_angular_correction_deg", &(p->max_angular_correction_deg),
		90.0, "Maximum angular displacement between scans");

	options_double(ops, "max_linear_correction", 
		&(p->max_linear_correction), 2.0,
		"Maximum translation between scans (m)");

	options_int(ops, "max_iterations", 
		&(p->max_iterations), 1000,
		"When we had enough");

	options_double(ops, "epsilon_xy", 
		&(p->epsilon_xy), 0.0001,
		"A threshold for stopping");

	options_double(ops, "epsilon_theta",
		&(p->epsilon_theta),  0.0001, /* = 0.005 deg */
		"A threshold for stopping");

	options_double(ops, "max_correspondence_dist", 
		&(p->max_correspondence_dist), 2.0,
		"dubious parameter");
		
	options_double(ops, "sigma", 
		&(p->sigma), 0.01,
		"Noise in the scan");

	options_int(ops, "use_corr_tricks", 
		&(p->use_corr_tricks), 1,
		"Use smart tricks for finding correspondences.");

	options_int(ops, "restart", 
		&(p->restart), 1,
		"Restart: Restart if error is over threshold");

	options_double(ops, "restart_threshold_mean_error",
		&(p->restart_threshold_mean_error),  0.01,
		"Restart: Threshold for restarting.");

	options_double(ops, "restart_dt", 
		&(p->restart_dt), 0.01,
		"Restart: displacement for restarting.");

	options_double(ops, "restart_dtheta",
		&(p->restart_dtheta),  deg2rad(1.5),
		"Restart: displacement for restarting.");

	options_double(ops, "clustering_threshold",
		&(p->clustering_threshold),  0.05,
		"Max distance for staying in the same clustering");

	options_int(ops, "orientation_neighbourhood",
		&(p->orientation_neighbourhood),  3,
		"Number of neighbour rays used to estimate the orientation.");

	options_int(ops, "do_alpha_test",
		&(p->do_alpha_test),  0,
		"Discard correspondences based on the angles");

	options_int(ops, "use_point_to_line_distance",
		&(p->use_point_to_line_distance),  1,
		"Use gpc");

	options_double(ops, "do_alpha_test_thresholdDeg", 
		&(p->do_alpha_test_thresholdDeg), 20.0, "");

	options_double(ops, "outliers_maxPerc", 
		&(p->outliers_maxPerc), 0.95, "");

	options_double(ops, "outliers_adaptive_order", 
		&(p->outliers_adaptive_order), 0.7, "");
	options_double(ops, "outliers_adaptive_mult", 
		&(p->outliers_adaptive_mult), 2.0, "");

	options_int(ops, "do_visibility_test", 
		&(p->do_visibility_test), 0,
		" ... ");

	options_int(ops, "do_compute_covariance", 
		&(p->do_compute_covariance), 0,
		" ... ");
	
}
