#include "shooter_particle/shooter_particle.h"

ParticleShooter::ParticleShooter()
	: nh_priv_("~")
{

	//Init gazebo ros shooter_particle node
	ROS_INFO("Shooter Particle Node Init");
	auto ret = init();
	ROS_ASSERT(ret);
}

ParticleShooter::~ParticleShooterAngle()
{
	updatecommandAngle(10.0);
	ros::shutdown();
}

/*******************************************************************************
* Init function
*******************************************************************************/
bool ParticleShooter::init()
{
	// initialize ROS parameter
	std::string alpha_angle_topic_name = nh_.param<std::string>("alpha_angle_topic_name", "");

	// initialise variables
	// Update Loop frequency, rate at which we restart the positions and apply force to particles
	double reset_frequency = 2.0;
	// Time Memory
	double old_secs;
	// Force Direction
	double x_axis_force = 0.0;
	double y_axis_force = 0.0;
	double z_axis_force = 0.0;
	double x_origin = 0.0;
	double y_origin = 0.0;
	double z_origin = 1.5;
	  
	double random_range = 0.0;

	double angle = 0.0;

	// Reseting Flag
	bool reseting_plugin = false;
	  
	int modelIDToName_size = 0;
	int model_to_update_index_now = 0;
	  
	std::string particle_base_name = "particle";

	// initialise subscribers
	alpha_angle_sub = nh_.subscriber("alpha_angle", 10, &ParticleShooter::)

}