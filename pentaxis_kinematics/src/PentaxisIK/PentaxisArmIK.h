/**
 * @file PentaxisArmIK.h
 * @author Rasmus Hasle Andersen, Moises Estrada Casta/neda <moises@gmail.com>
 * @version 1.0
 *
 * @section LICENSE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * http://www.gnu.org/copyleft/gpl.html
 *
 * @section DESCRIPTION
 *
 * Interface for inverse kinematic solvers for the Pentaxis arm.
 * Implementations of the interface can e.g. be numerical or analytical IK solvers.
 */


#ifndef INVERSE_KINEMATICS_H
#define INVERSE_KINEMATICS_H

// ROS includes
#include <moveit_msgs/KinematicSolverInfo.h>
#include <moveit_msgs/GetKinematicSolverInfo.h>
#include <kdl/chainiksolver.hpp>
#include <urdf/model.h>

namespace pentaxis_kinematics
{

class PentaxisArmIK
{
	public:
		/**
		 * Dtor.
		 */
		virtual ~PentaxisArmIK() {}

		/**
		 * Perform the IK calculation.
		 *
		 * @param q_init The initial guess for the inverse kinematics solution.
		 * @param p_in A KDL::Frame representation of the position of the end-effector for which the IK is being solved.
		 * @param q_out A vector of inverse kinematic solutions (if it exists).
		 * @return < 0 if no solution is found
		 */
		virtual int CartToJnt(const KDL::JntArray& q_init, 
			const KDL::Frame& p_in, 
			std::vector<KDL::JntArray>& q_out) = 0;

		/**
		 * @brief A method to get chain information about the serial chain that the IK operates on 
		 * @param info This class gets populated with information about the joints that IK operates on, including joint names and limits.
		 */
		virtual void getSolverInfo(moveit_msgs::KinematicSolverInfo &info) = 0;
};

} /* namespace pentaxis_kinematics */
#endif
