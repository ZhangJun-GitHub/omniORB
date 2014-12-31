// This file is generated by omniidl (C++ backend)- omniORB_4_2. Do not edit.
#ifndef __omniConnectionData_hh__
#define __omniConnectionData_hh__

#ifndef __CORBA_H_EXTERNAL_GUARD__
#include <omniORB4/CORBA.h>
#endif

#ifndef  USE_stub_in_nt_dll
# define USE_stub_in_nt_dll_NOT_DEFINED_omniConnectionData
#endif
#ifndef  USE_core_stub_in_nt_dll
# define USE_core_stub_in_nt_dll_NOT_DEFINED_omniConnectionData
#endif
#ifndef  USE_dyn_stub_in_nt_dll
# define USE_dyn_stub_in_nt_dll_NOT_DEFINED_omniConnectionData
#endif






#ifdef USE_stub_in_nt_dll
# ifndef USE_core_stub_in_nt_dll
#  define USE_core_stub_in_nt_dll
# endif
# ifndef USE_dyn_stub_in_nt_dll
#  define USE_dyn_stub_in_nt_dll
# endif
#endif

#ifdef _core_attr
# error "A local CPP macro _core_attr has already been defined."
#else
# ifdef  USE_core_stub_in_nt_dll
#  define _core_attr _OMNIORB_NTDLL_IMPORT
# else
#  define _core_attr
# endif
#endif

#ifdef _dyn_attr
# error "A local CPP macro _dyn_attr has already been defined."
#else
# ifdef  USE_dyn_stub_in_nt_dll
#  define _dyn_attr _OMNIORB_NTDLL_IMPORT
# else
#  define _dyn_attr
# endif
#endif



_CORBA_MODULE omniConnectionData

_CORBA_MODULE_BEG

  struct ComponentData {
    typedef _CORBA_ConstrType_Fix_Var<ComponentData> _var_type;

    
    ::CORBA::Octet version;

    ::CORBA::UShort flags;

    ::CORBA::ULong connection_id;

    ::CORBA::ULong max_connections;

    ::CORBA::ULong max_threads;

  

    void operator>>= (cdrStream &) const;
    void operator<<= (cdrStream &);
  };

  typedef ComponentData::_var_type ComponentData_var;

  typedef ComponentData& ComponentData_out;

  _CORBA_MODULE_VARINT const ::CORBA::UShort COMP_DATA_BATCH _init_in_decl_( = 1 );

  _CORBA_MODULE_VARINT const ::CORBA::UShort COMP_PERMIT_INTERLEAVED _init_in_decl_( = 2 );

  _CORBA_MODULE_VARINT const ::CORBA::UShort COMP_SERVER_HOLD_OPEN _init_in_decl_( = 4 );

  _CORBA_MODULE_VARINT const ::CORBA::ULong TAG_RESTRICTED_CONNECTION _init_in_decl_( = 1096045572U );

  struct ServiceData {
    typedef _CORBA_ConstrType_Fix_Var<ServiceData> _var_type;

    
    ::CORBA::Octet version;

    ::CORBA::UShort flags;

    ::CORBA::ULong connection_id;

    ::CORBA::ULong max_threads;

  

    void operator>>= (cdrStream &) const;
    void operator<<= (cdrStream &);
  };

  typedef ServiceData::_var_type ServiceData_var;

  typedef ServiceData& ServiceData_out;

  _CORBA_MODULE_VARINT const ::CORBA::UShort SVC_HOLD_OPEN _init_in_decl_( = 1 );

  _CORBA_MODULE_VARINT const ::CORBA::ULong SVC_RESTRICTED_CONNECTION _init_in_decl_( = 1096045572U );

_CORBA_MODULE_END



_CORBA_MODULE POA_omniConnectionData
_CORBA_MODULE_BEG

_CORBA_MODULE_END



_CORBA_MODULE OBV_omniConnectionData
_CORBA_MODULE_BEG

_CORBA_MODULE_END





#undef _core_attr
#undef _dyn_attr





#ifdef   USE_stub_in_nt_dll_NOT_DEFINED_omniConnectionData
# undef  USE_stub_in_nt_dll
# undef  USE_stub_in_nt_dll_NOT_DEFINED_omniConnectionData
#endif
#ifdef   USE_core_stub_in_nt_dll_NOT_DEFINED_omniConnectionData
# undef  USE_core_stub_in_nt_dll
# undef  USE_core_stub_in_nt_dll_NOT_DEFINED_omniConnectionData
#endif
#ifdef   USE_dyn_stub_in_nt_dll_NOT_DEFINED_omniConnectionData
# undef  USE_dyn_stub_in_nt_dll
# undef  USE_dyn_stub_in_nt_dll_NOT_DEFINED_omniConnectionData
#endif

#endif  // __omniConnectionData_hh__
