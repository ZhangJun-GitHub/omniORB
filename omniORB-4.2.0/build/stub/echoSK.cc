// This file is generated by omniidl (C++ backend)- omniORB_4_2. Do not edit.

#include "echo.hh"
#include <omniORB4/IOP_S.h>
#include <omniORB4/IOP_C.h>
#include <omniORB4/callDescriptor.h>
#include <omniORB4/callHandle.h>
#include <omniORB4/objTracker.h>


OMNI_USING_NAMESPACE(omni)

static const char* _0RL_library_version = omniORB_4_2;



Echo_ptr Echo_Helper::_nil() {
  return ::Echo::_nil();
}

::CORBA::Boolean Echo_Helper::is_nil(::Echo_ptr p) {
  return ::CORBA::is_nil(p);

}

void Echo_Helper::release(::Echo_ptr p) {
  ::CORBA::release(p);
}

void Echo_Helper::marshalObjRef(::Echo_ptr obj, cdrStream& s) {
  ::Echo::_marshalObjRef(obj, s);
}

Echo_ptr Echo_Helper::unmarshalObjRef(cdrStream& s) {
  return ::Echo::_unmarshalObjRef(s);
}

void Echo_Helper::duplicate(::Echo_ptr obj) {
  if (obj && !obj->_NP_is_nil())  omni::duplicateObjRef(obj);
}

Echo_ptr
Echo::_duplicate(::Echo_ptr obj)
{
  if (obj && !obj->_NP_is_nil())  omni::duplicateObjRef(obj);
  return obj;
}

Echo_ptr
Echo::_narrow(::CORBA::Object_ptr obj)
{
  if (!obj || obj->_NP_is_nil() || obj->_NP_is_pseudo()) return _nil();
  _ptr_type e = (_ptr_type) obj->_PR_getobj()->_realNarrow(_PD_repoId);
  return e ? e : _nil();
}


Echo_ptr
Echo::_unchecked_narrow(::CORBA::Object_ptr obj)
{
  if (!obj || obj->_NP_is_nil() || obj->_NP_is_pseudo()) return _nil();
  _ptr_type e = (_ptr_type) obj->_PR_getobj()->_uncheckedNarrow(_PD_repoId);
  return e ? e : _nil();
}

Echo_ptr
Echo::_nil()
{
#ifdef OMNI_UNLOADABLE_STUBS
  static _objref_Echo _the_nil_obj;
  return &_the_nil_obj;
#else
  static _objref_Echo* _the_nil_ptr = 0;
  if (!_the_nil_ptr) {
    omni::nilRefLock().lock();
    if (!_the_nil_ptr) {
      _the_nil_ptr = new _objref_Echo;
      registerNilCorbaObject(_the_nil_ptr);
    }
    omni::nilRefLock().unlock();
  }
  return _the_nil_ptr;
#endif
}

const char* Echo::_PD_repoId = "IDL:Echo:1.0";


_objref_Echo::~_objref_Echo() {
  
}


_objref_Echo::_objref_Echo(omniIOR* ior, omniIdentity* id) :
   omniObjRef(::Echo::_PD_repoId, ior, id, 1)
   
   
{
  _PR_setobj(this);
}

void*
_objref_Echo::_ptrToObjRef(const char* id)
{
  if (id == ::Echo::_PD_repoId)
    return (::Echo_ptr) this;
  
  if (id == ::CORBA::Object::_PD_repoId)
    return (::CORBA::Object_ptr) this;

  if (omni::strMatch(id, ::Echo::_PD_repoId))
    return (::Echo_ptr) this;
  
  if (omni::strMatch(id, ::CORBA::Object::_PD_repoId))
    return (::CORBA::Object_ptr) this;

  return 0;
}


//
// Code for Echo::echoString

// Proxy call descriptor class. Mangled signature:
//  _cstring_i_cstring
class _0RL_cd_01531d3e51c81a80_00000000
  : public omniCallDescriptor
{
public:
  inline _0RL_cd_01531d3e51c81a80_00000000(LocalCallFn lcfn, const char* op_, size_t oplen, _CORBA_Boolean upcall=0)
    : omniCallDescriptor(lcfn, op_, oplen, 0, _user_exns, 0, upcall)
  {
    
  }
  
  void marshalArguments(cdrStream&);
  void unmarshalArguments(cdrStream&);

  void unmarshalReturnedValues(cdrStream&);
  void marshalReturnedValues(cdrStream&);
  
  
  static const char* const _user_exns[];

  ::CORBA::String_var arg_0_;
  const char* arg_0;
  ::CORBA::String_var result;
};

void _0RL_cd_01531d3e51c81a80_00000000::marshalArguments(cdrStream& _n)
{
  _n.marshalString(arg_0,0);

}

void _0RL_cd_01531d3e51c81a80_00000000::unmarshalArguments(cdrStream& _n)
{
  arg_0_ = _n.unmarshalString(0);
  arg_0 = arg_0_.in();

}

void _0RL_cd_01531d3e51c81a80_00000000::marshalReturnedValues(cdrStream& _n)
{
  _n.marshalString(result,0);

}

void _0RL_cd_01531d3e51c81a80_00000000::unmarshalReturnedValues(cdrStream& _n)
{
  result = _n.unmarshalString(0);

}

const char* const _0RL_cd_01531d3e51c81a80_00000000::_user_exns[] = {
  0
};

// Local call call-back function.
static void
_0RL_lcfn_01531d3e51c81a80_10000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_01531d3e51c81a80_00000000* tcd = (_0RL_cd_01531d3e51c81a80_00000000*)cd;
  _impl_Echo* impl = (_impl_Echo*) svnt->_ptrToInterface(Echo::_PD_repoId);
  tcd->result = impl->echoString(tcd->arg_0);


}

char* _objref_Echo::echoString(const char* mesg)
{
  _0RL_cd_01531d3e51c81a80_00000000 _call_desc(_0RL_lcfn_01531d3e51c81a80_10000000, "echoString", 11);
  _call_desc.arg_0 = mesg;

  _invoke(_call_desc);
  return _call_desc.result._retn();


}

_pof_Echo::~_pof_Echo() {}


omniObjRef*
_pof_Echo::newObjRef(omniIOR* ior, omniIdentity* id)
{
  return new ::_objref_Echo(ior, id);
}


::CORBA::Boolean
_pof_Echo::is_a(const char* id) const
{
  if (omni::ptrStrMatch(id, ::Echo::_PD_repoId))
    return 1;
  
  return 0;
}

const _pof_Echo _the_pof_Echo;

_impl_Echo::~_impl_Echo() {}


::CORBA::Boolean
_impl_Echo::_dispatch(omniCallHandle& _handle)
{
  const char* op = _handle.operation_name();

  if (omni::strMatch(op, "echoString")) {

    _0RL_cd_01531d3e51c81a80_00000000 _call_desc(_0RL_lcfn_01531d3e51c81a80_10000000, "echoString", 11, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }


  return 0;
}

void*
_impl_Echo::_ptrToInterface(const char* id)
{
  if (id == ::Echo::_PD_repoId)
    return (::_impl_Echo*) this;
  
  if (id == ::CORBA::Object::_PD_repoId)
    return (void*) 1;

  if (omni::strMatch(id, ::Echo::_PD_repoId))
    return (::_impl_Echo*) this;
  
  if (omni::strMatch(id, ::CORBA::Object::_PD_repoId))
    return (void*) 1;
  return 0;
}

const char*
_impl_Echo::_mostDerivedRepoId()
{
  return ::Echo::_PD_repoId;
}

POA_Echo::~POA_Echo() {}

