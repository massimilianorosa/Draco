//----------------------------------*-C++-*----------------------------------//
/*!
 * \file   sf/F4.hh
 * \author Kent Budge
 * \date   Tue Sep 21 09:20:10 2004
 * \brief  Fermi-Dirac integral of second order.
 * \note   Copyright (C) 2016 Los Alamos National Security, LLC.
 *         All rights reserved.
 */
//---------------------------------------------------------------------------//
// $Id$
//---------------------------------------------------------------------------//

#ifndef sf_F4_hh
#define sf_F4_hh

#include "ds++/config.h"

namespace rtt_sf {
//! Calculate Fermi-Dirac integral of index 4.
DLL_PUBLIC_special_functions double F4(double eta);

} // end namespace rtt_sf

#endif // sf_F4_hh

//---------------------------------------------------------------------------//
// end of sf/F4.hh
//---------------------------------------------------------------------------//
