//----------------------------------*-C++-*----------------------------------//
/*!
 * \file   roots/cubic1_pt.cc
 * \author Kent Budge
 * \date   Wed Sep 15 10:04:02 MDT 2010
 * \brief  Solve a cubic equation assumed to have one real root
 * \note   Copyright (C) 2016 Los Alamos National Security, LLC.
 *         All rights reserved.
 */
//---------------------------------------------------------------------------//
// $Id$
//---------------------------------------------------------------------------//

#include "cubic1.i.hh"

namespace rtt_roots {

//---------------------------------------------------------------------------//
template DLL_PUBLIC_roots double cubic1(double const &a, double const &b,
                                        double const &c);

} // end namespace rtt_roots

//---------------------------------------------------------------------------//
// end of cubic1_pt.cc
//---------------------------------------------------------------------------//
