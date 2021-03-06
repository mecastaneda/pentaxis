/**
 * @file Kinematicshelper.h
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
 * 
 * 
 */

#ifndef KINEMATICSHELPER_H_
#define KINEMATICSHELPER_H_

#include <urdf/model.h>
#include <Eigen/Core>
#include <kdl/chainiksolver.hpp>
#include <kdl/frames.hpp>
#include <kdl/jntarray.hpp>
#include <kdl/tree.hpp>
#include <kdl_parser/kdl_parser.hpp>
#include <moveit_msgs/KinematicSolverInfo.h>
namespace pentaxis_kinematics
{

namespace kinematics_helper
{

Eigen::Matrix4f KDLToEigenMatrix(const KDL::Frame &p);
double  computeEuclideanDistance(const std::vector<double> &array_1, const KDL::JntArray &array_2);
double  computeEuclideanDistance(const KDL::JntArray &array_1, const KDL::JntArray &array_2);
void    getKDLChainInfo(const KDL::Chain &chain, moveit_msgs::KinematicSolverInfo &chain_info);
bool    getKDLChain(const urdf::ModelInterface& model, const std::string &root_name,
                      const std::string &tip_name, KDL::Chain &kdl_chain);

} /* namespace kinematics_helper */

} /* namespace pentaxis_kinematics */

#endif /* KINEMATICSHELPER_H_ */
