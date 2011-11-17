//----------------------------------*-C++-*----------------------------------//
/*!
 * \file   ds++/UnitTest.hh
 * \author Kelly Thompson
 * \date   Thu May 18 15:46:19 2006
 * \brief  Provide some common functions for unit testing within Draco
 * \note   Copyright � 2006-2011 Los Alamos National Security, LLC.
 */
//---------------------------------------------------------------------------//
// $Id$
//---------------------------------------------------------------------------//

#ifndef dsxx_UnitTest_hh
#define dsxx_UnitTest_hh

#include "Assert.hh"
#include <string>
#include <list>
#include <iostream>
#include <map>

namespace rtt_dsxx
{

//===========================================================================//
/*!
 * \class UnitTest
 * \brief Object to encapsulate unit testing of Draco classes and functions. 
 *
 * This is a virtual class.  You should use one of the following UnitTest
 * classes in your test appliation:
 *
 * \li ScalarUnitTest      - Used for testing code that does not use parallel
 *                       communication (rtt_c4).
 * \li ParallelUnitTest    - Used for testing code that does use parallel
 *                       communications (rtt_c4). 
 * \li ApplicationUnitTest - Used for testing applications that run in
 *                       parallel. The unit test code is run in scalar-mode
 *                       and calls mpirun to run the specified application.
 *
 *
 * \sa UnitTest.cc for additional details.
 *
 * \par Code Sample:
 *
 * Scalar UnitTests should have the following syntax.
 * \code

#define PASSMSG(m) ut.passes(m)
#define FAILMSG(m) ut.failure(m)
#define ITFAILS    ut.failure( __LINE__, __FILE__ )
 
int main(int argc, char *argv[])
{
    try
    {
        // Test ctor for ScalarUnitTest (also tests UnitTest ctor)
        rtt_utils::ScalarUnitTest ut( argc, argv, release );
        tstOne(ut);
        ut.status();
    }
    catch( rtt_dsxx::assertion &err )
    {
        std::string msg = err.what();
        if( msg != std::string( "Success" ) )
        { cout << "ERROR: While testing " << argv[0] << ", "
               << err.what() << endl;
            return 1;
        }
        return 0;
    }
    catch (exception &err)
    {
        cout << "ERROR: While testing " << argv[0] << ", "
             << err.what() << endl;
        return 1;
    }
    catch( ... )
    {
        cout << "ERROR: While testing " << argv[0] << ", "
             << "An unknown exception was thrown" << endl;
        return 1;
    }
    return 0;
}  
 * \endcode
 *
 * \test All of the member functions of this class are tested by
 * ds++/test/tstScalarUnitTest.cc, including the early exit caused by 
 * \c --version on the command line.
 */
                                                            
/*!
 * \example ds++/test/tstScalarUnitTest.cc 
 * This unit test demonstrates how to use the ScalarUnit object to simply
 * create a new unit test.
 */
//===========================================================================//

class DLL_PUBLIC UnitTest 
{
  public:

    // NESTED CLASSES AND TYPEDEFS

    //! Typedef for function pointer to this package's release function.
    typedef std::string const (*string_fp_void)(void);
    
    // CREATORS
        
    //! Default constructors.
    UnitTest( int    & argc,
              char **& argv,
              string_fp_void   release_,
              std::ostream   & out_ = std::cout );

    //! The copy constructor is disabled.
    UnitTest( UnitTest const &rhs );

    //! Destructor is virtual because this class will be inherited from.
    virtual ~UnitTest(void){/*empty*/};

    // MANIPULATORS    

    //! The assignment operator is disabled.
    UnitTest& operator=( UnitTest const &rhs );

    //! Change the target for output
    // void setostream( std::ostream out_ ) { out = out_; return; };
    
    // ACCESSORS
    bool failure(int line);
    bool failure(int line, char const *file);
    bool failure( std::string const &failmsg );
    bool passes(  std::string const &failmsg );
    //! This pure virtual function must be provided by the inherited class.
    //It should provide output concerning the status of UnitTest.
    void status(void) const { out << resultMessage() << std::endl; return; }
    //! Reset the pass and fail counts to zero.
    void reset() { numPasses=0;numFails=0; return; }

    // DATA
    //! The number of passes found for this test.
    unsigned numPasses;
    //! The number of failures found for this test.
    unsigned numFails;

    // Features
    static std::map< std::string, unsigned >
    get_word_count( std::ostringstream const & data, bool verbose=false );
    static std::map< std::string, unsigned >
    get_word_count( std::string const & filename, bool verbose=false );
    
  protected:

    // IMPLEMENTATION
    std::string resultMessage(void) const;

    // DATA
    
    //! The name of this unit test.
    std::string const testName;
    //! Relative path to the unit test.
    std::string const testPath;

    //! Function pointer this package's release(void) function
    string_fp_void release;

    //! Where should output be sent (default is std::cout)
    std::ostream & out;
};

} // end namespace rtt_dsxx

#endif // dsxx_UnitTest_hh

//---------------------------------------------------------------------------//
//              end of ds++/UnitTest.hh
//---------------------------------------------------------------------------//
