/*----------------------------------*-C++-*----------------------------------------------*/
/*!
 * \file   parser/Debug_Options.hh
 * \author Kent Grimmett Budge
 * \brief
 * \note   Copyright (C) 2014-2016 Los Alamos National Security, LLC.
 *         All rights reserved.
 */
/*---------------------------------------------------------------------------------------*/
/* $Id: template.h 7388 2014-01-22 16:02:07Z kellyt $ */
/*---------------------------------------------------------------------------------------*/

#ifndef parser_Debug_Options_hh
#define parser_Debug_Options_hh

#include "Token_Stream.hh"

namespace rtt_parser {
//---------------------------------------------------------------------------------------//
//! Enumeration of debug flag bits

enum Debug_Options {
  DEBUG_ALGORITHM = 1,     // Report on behavior of the algorithm.
  DEBUG_TIMESTEP = 2,      // Report on what is limiting the time step.
  DEBUG_TIMING = 4,        // Report CPU times for various code regions.
  DEBUG_BALANCE = 8,       // Report on energy balance.
  DEBUG_GMV_DUMP = 16,     // Produce a GMV dump of the solution.
  DEBUG_MEMORY = 32,       // Report on memory usage.
  DEBUG_RESET_TIMING = 64, // Reset all timings to zero.

  DEBUG_SILENT_MASK = ~(DEBUG_GMV_DUMP | DEBUG_RESET_TIMING)
  // Options producing no terminal output
};

//---------------------------------------------------------------------------------------//
//! Parse debug options in uniform way
DLL_PUBLIC_parser unsigned parse_debug_options(rtt_parser::Token_Stream &);

//---------------------------------------------------------------------------------------//
//! Write debug options in a manner that can be parsed
DLL_PUBLIC_parser std::string debug_options_as_text(unsigned debug_options);

} // namespace rtt_parser

#endif /* parser_Debug_Options_hh */

/*---------------------------------------------------------------------------*/
/* end of parser/Debug_Options.hh */
/*---------------------------------------------------------------------------*/
