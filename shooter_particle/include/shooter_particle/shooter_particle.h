#ifndef SHOOTER_PARTICLE_H
#define SHOOTER_PARTICLE_H

#include <gazebo/common/Plugin.hh>
#include <ros/ros.h>
#include <cmath>
#include <math.h>

#include <gazebo/physics/World.hh>
#include <gazebo/physics/Model.hh>
#include <gazebo/physics/Link.hh>
#include <gazebo/physics/physics.hh>

#include <unistd.h>

#include <boost/bind.hpp>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <stdio.h>


#include <ignition/math/Pose3.hh>
#include <ignition/math/Vector3.hh>
#include <ignition/math/Quaternion.hh>

#define deg2rad (M_PI / 180.0)
#define rad2deg (180.0 / M_PI)

class ParticleShooterPlugin
{
	private:
		// ROS NodeHandle
		ros::NodeHandle nh_;
		ros::NodeHandle nh_priv_;

		// ROS Parameters 

		// ROS Topic Publishers

		// ROS Topic Subscribers
		ros::Subscribers angle;

	public:
		// Variables
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

		// Function prototypes
		void Load(physics::WorldPtr _world, sdf::ElementPtr _sdf);
		void Reset();
		void OnUpdate();
		void WaitForseconds(float seconds_to_wait);
		void UpdateParticles(int model_to_update_index);
		void GetParticles();
		void OutputParticleList();
		void MoveParticle(boost::shared_ptr<gazebo::physics::Model> model);
		void SetForceParticle(boost::shared_ptr<gazebo::physics::Model> model);

}
