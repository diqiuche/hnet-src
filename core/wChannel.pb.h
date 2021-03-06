// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: wChannel.proto

#ifndef PROTOBUF_wChannel_2eproto__INCLUDED
#define PROTOBUF_wChannel_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2004001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_reflection.h>
// @@protoc_insertion_point(includes)

namespace hnet {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_wChannel_2eproto();
void protobuf_AssignDesc_wChannel_2eproto();
void protobuf_ShutdownFile_wChannel_2eproto();

class wChannelOpen;
class wChannelClose;
class wChannelQuit;
class wChannelTerminate;

// ===================================================================

class wChannelOpen : public ::google::protobuf::Message {
 public:
  wChannelOpen();
  virtual ~wChannelOpen();
  
  wChannelOpen(const wChannelOpen& from);
  
  inline wChannelOpen& operator=(const wChannelOpen& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const wChannelOpen& default_instance();
  
  void Swap(wChannelOpen* other);
  
  // implements Message ----------------------------------------------
  
  wChannelOpen* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const wChannelOpen& from);
  void MergeFrom(const wChannelOpen& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required int32 pid = 1;
  inline bool has_pid() const;
  inline void clear_pid();
  static const int kPidFieldNumber = 1;
  inline ::google::protobuf::int32 pid() const;
  inline void set_pid(::google::protobuf::int32 value);
  
  // required int32 slot = 2;
  inline bool has_slot() const;
  inline void clear_slot();
  static const int kSlotFieldNumber = 2;
  inline ::google::protobuf::int32 slot() const;
  inline void set_slot(::google::protobuf::int32 value);
  
  // required int32 fd = 3;
  inline bool has_fd() const;
  inline void clear_fd();
  static const int kFdFieldNumber = 3;
  inline ::google::protobuf::int32 fd() const;
  inline void set_fd(::google::protobuf::int32 value);
  
  // @@protoc_insertion_point(class_scope:hnet.wChannelOpen)
 private:
  inline void set_has_pid();
  inline void clear_has_pid();
  inline void set_has_slot();
  inline void clear_has_slot();
  inline void set_has_fd();
  inline void clear_has_fd();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::google::protobuf::int32 pid_;
  ::google::protobuf::int32 slot_;
  ::google::protobuf::int32 fd_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];
  
  friend void  protobuf_AddDesc_wChannel_2eproto();
  friend void protobuf_AssignDesc_wChannel_2eproto();
  friend void protobuf_ShutdownFile_wChannel_2eproto();
  
  void InitAsDefaultInstance();
  static wChannelOpen* default_instance_;
};
// -------------------------------------------------------------------

class wChannelClose : public ::google::protobuf::Message {
 public:
  wChannelClose();
  virtual ~wChannelClose();
  
  wChannelClose(const wChannelClose& from);
  
  inline wChannelClose& operator=(const wChannelClose& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const wChannelClose& default_instance();
  
  void Swap(wChannelClose* other);
  
  // implements Message ----------------------------------------------
  
  wChannelClose* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const wChannelClose& from);
  void MergeFrom(const wChannelClose& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required int32 pid = 1;
  inline bool has_pid() const;
  inline void clear_pid();
  static const int kPidFieldNumber = 1;
  inline ::google::protobuf::int32 pid() const;
  inline void set_pid(::google::protobuf::int32 value);
  
  // required int32 slot = 2;
  inline bool has_slot() const;
  inline void clear_slot();
  static const int kSlotFieldNumber = 2;
  inline ::google::protobuf::int32 slot() const;
  inline void set_slot(::google::protobuf::int32 value);
  
  // @@protoc_insertion_point(class_scope:hnet.wChannelClose)
 private:
  inline void set_has_pid();
  inline void clear_has_pid();
  inline void set_has_slot();
  inline void clear_has_slot();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::google::protobuf::int32 pid_;
  ::google::protobuf::int32 slot_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];
  
  friend void  protobuf_AddDesc_wChannel_2eproto();
  friend void protobuf_AssignDesc_wChannel_2eproto();
  friend void protobuf_ShutdownFile_wChannel_2eproto();
  
  void InitAsDefaultInstance();
  static wChannelClose* default_instance_;
};
// -------------------------------------------------------------------

class wChannelQuit : public ::google::protobuf::Message {
 public:
  wChannelQuit();
  virtual ~wChannelQuit();
  
  wChannelQuit(const wChannelQuit& from);
  
  inline wChannelQuit& operator=(const wChannelQuit& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const wChannelQuit& default_instance();
  
  void Swap(wChannelQuit* other);
  
  // implements Message ----------------------------------------------
  
  wChannelQuit* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const wChannelQuit& from);
  void MergeFrom(const wChannelQuit& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required int32 pid = 1;
  inline bool has_pid() const;
  inline void clear_pid();
  static const int kPidFieldNumber = 1;
  inline ::google::protobuf::int32 pid() const;
  inline void set_pid(::google::protobuf::int32 value);
  
  // @@protoc_insertion_point(class_scope:hnet.wChannelQuit)
 private:
  inline void set_has_pid();
  inline void clear_has_pid();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::google::protobuf::int32 pid_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];
  
  friend void  protobuf_AddDesc_wChannel_2eproto();
  friend void protobuf_AssignDesc_wChannel_2eproto();
  friend void protobuf_ShutdownFile_wChannel_2eproto();
  
  void InitAsDefaultInstance();
  static wChannelQuit* default_instance_;
};
// -------------------------------------------------------------------

class wChannelTerminate : public ::google::protobuf::Message {
 public:
  wChannelTerminate();
  virtual ~wChannelTerminate();
  
  wChannelTerminate(const wChannelTerminate& from);
  
  inline wChannelTerminate& operator=(const wChannelTerminate& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const wChannelTerminate& default_instance();
  
  void Swap(wChannelTerminate* other);
  
  // implements Message ----------------------------------------------
  
  wChannelTerminate* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const wChannelTerminate& from);
  void MergeFrom(const wChannelTerminate& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required int32 pid = 1;
  inline bool has_pid() const;
  inline void clear_pid();
  static const int kPidFieldNumber = 1;
  inline ::google::protobuf::int32 pid() const;
  inline void set_pid(::google::protobuf::int32 value);
  
  // @@protoc_insertion_point(class_scope:hnet.wChannelTerminate)
 private:
  inline void set_has_pid();
  inline void clear_has_pid();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::google::protobuf::int32 pid_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];
  
  friend void  protobuf_AddDesc_wChannel_2eproto();
  friend void protobuf_AssignDesc_wChannel_2eproto();
  friend void protobuf_ShutdownFile_wChannel_2eproto();
  
  void InitAsDefaultInstance();
  static wChannelTerminate* default_instance_;
};
// ===================================================================


// ===================================================================

// wChannelOpen

// required int32 pid = 1;
inline bool wChannelOpen::has_pid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void wChannelOpen::set_has_pid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void wChannelOpen::clear_has_pid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void wChannelOpen::clear_pid() {
  pid_ = 0;
  clear_has_pid();
}
inline ::google::protobuf::int32 wChannelOpen::pid() const {
  return pid_;
}
inline void wChannelOpen::set_pid(::google::protobuf::int32 value) {
  set_has_pid();
  pid_ = value;
}

// required int32 slot = 2;
inline bool wChannelOpen::has_slot() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void wChannelOpen::set_has_slot() {
  _has_bits_[0] |= 0x00000002u;
}
inline void wChannelOpen::clear_has_slot() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void wChannelOpen::clear_slot() {
  slot_ = 0;
  clear_has_slot();
}
inline ::google::protobuf::int32 wChannelOpen::slot() const {
  return slot_;
}
inline void wChannelOpen::set_slot(::google::protobuf::int32 value) {
  set_has_slot();
  slot_ = value;
}

// required int32 fd = 3;
inline bool wChannelOpen::has_fd() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void wChannelOpen::set_has_fd() {
  _has_bits_[0] |= 0x00000004u;
}
inline void wChannelOpen::clear_has_fd() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void wChannelOpen::clear_fd() {
  fd_ = 0;
  clear_has_fd();
}
inline ::google::protobuf::int32 wChannelOpen::fd() const {
  return fd_;
}
inline void wChannelOpen::set_fd(::google::protobuf::int32 value) {
  set_has_fd();
  fd_ = value;
}

// -------------------------------------------------------------------

// wChannelClose

// required int32 pid = 1;
inline bool wChannelClose::has_pid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void wChannelClose::set_has_pid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void wChannelClose::clear_has_pid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void wChannelClose::clear_pid() {
  pid_ = 0;
  clear_has_pid();
}
inline ::google::protobuf::int32 wChannelClose::pid() const {
  return pid_;
}
inline void wChannelClose::set_pid(::google::protobuf::int32 value) {
  set_has_pid();
  pid_ = value;
}

// required int32 slot = 2;
inline bool wChannelClose::has_slot() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void wChannelClose::set_has_slot() {
  _has_bits_[0] |= 0x00000002u;
}
inline void wChannelClose::clear_has_slot() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void wChannelClose::clear_slot() {
  slot_ = 0;
  clear_has_slot();
}
inline ::google::protobuf::int32 wChannelClose::slot() const {
  return slot_;
}
inline void wChannelClose::set_slot(::google::protobuf::int32 value) {
  set_has_slot();
  slot_ = value;
}

// -------------------------------------------------------------------

// wChannelQuit

// required int32 pid = 1;
inline bool wChannelQuit::has_pid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void wChannelQuit::set_has_pid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void wChannelQuit::clear_has_pid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void wChannelQuit::clear_pid() {
  pid_ = 0;
  clear_has_pid();
}
inline ::google::protobuf::int32 wChannelQuit::pid() const {
  return pid_;
}
inline void wChannelQuit::set_pid(::google::protobuf::int32 value) {
  set_has_pid();
  pid_ = value;
}

// -------------------------------------------------------------------

// wChannelTerminate

// required int32 pid = 1;
inline bool wChannelTerminate::has_pid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void wChannelTerminate::set_has_pid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void wChannelTerminate::clear_has_pid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void wChannelTerminate::clear_pid() {
  pid_ = 0;
  clear_has_pid();
}
inline ::google::protobuf::int32 wChannelTerminate::pid() const {
  return pid_;
}
inline void wChannelTerminate::set_pid(::google::protobuf::int32 value) {
  set_has_pid();
  pid_ = value;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace hnet

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_wChannel_2eproto__INCLUDED
