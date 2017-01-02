// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: message.proto

#ifndef PROTOBUF_message_2eproto__INCLUDED
#define PROTOBUF_message_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3001000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3001000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
namespace Test {
class Config;
class ConfigDefaultTypeInternal;
extern ConfigDefaultTypeInternal _Config_default_instance_;
}  // namespace Test

namespace Test {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_message_2eproto();
void protobuf_InitDefaults_message_2eproto();

// ===================================================================

class Config : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Test.Config) */ {
 public:
  Config();
  virtual ~Config();

  Config(const Config& from);

  inline Config& operator=(const Config& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Config& default_instance();

  static inline const Config* internal_default_instance() {
    return reinterpret_cast<const Config*>(
               &_Config_default_instance_);
  }

  void Swap(Config* other);

  // implements Message ----------------------------------------------

  inline Config* New() const PROTOBUF_FINAL { return New(NULL); }

  Config* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Config& from);
  void MergeFrom(const Config& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output)
      const PROTOBUF_FINAL {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(Config* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string name = 1;
  void clear_name();
  static const int kNameFieldNumber = 1;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // int32 number = 2;
  void clear_number();
  static const int kNumberFieldNumber = 2;
  ::google::protobuf::int32 number() const;
  void set_number(::google::protobuf::int32 value);

  // bool reuse = 3;
  void clear_reuse();
  static const int kReuseFieldNumber = 3;
  bool reuse() const;
  void set_reuse(bool value);

  // repeated float elem = 4;
  int elem_size() const;
  void clear_elem();
  static const int kElemFieldNumber = 4;
  float elem(int index) const;
  void set_elem(int index, float value);
  void add_elem(float value);
  const ::google::protobuf::RepeatedField< float >&
      elem() const;
  ::google::protobuf::RepeatedField< float >*
      mutable_elem();

  // @@protoc_insertion_point(class_scope:Test.Config)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedField< float > elem_;
  mutable int _elem_cached_byte_size_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::int32 number_;
  bool reuse_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_message_2eproto_impl();
  friend void  protobuf_AddDesc_message_2eproto_impl();
  friend const ::google::protobuf::uint32* protobuf_Offsets_message_2eproto();
  friend void protobuf_ShutdownFile_message_2eproto();

};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// Config

// string name = 1;
inline void Config::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Config::name() const {
  // @@protoc_insertion_point(field_get:Test.Config.name)
  return name_.GetNoArena();
}
inline void Config::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Test.Config.name)
}
#if LANG_CXX11
inline void Config::set_name(::std::string&& value) {
  
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Test.Config.name)
}
#endif
inline void Config::set_name(const char* value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Test.Config.name)
}
inline void Config::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Test.Config.name)
}
inline ::std::string* Config::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:Test.Config.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Config::release_name() {
  // @@protoc_insertion_point(field_release:Test.Config.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Config::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:Test.Config.name)
}

// int32 number = 2;
inline void Config::clear_number() {
  number_ = 0;
}
inline ::google::protobuf::int32 Config::number() const {
  // @@protoc_insertion_point(field_get:Test.Config.number)
  return number_;
}
inline void Config::set_number(::google::protobuf::int32 value) {
  
  number_ = value;
  // @@protoc_insertion_point(field_set:Test.Config.number)
}

// bool reuse = 3;
inline void Config::clear_reuse() {
  reuse_ = false;
}
inline bool Config::reuse() const {
  // @@protoc_insertion_point(field_get:Test.Config.reuse)
  return reuse_;
}
inline void Config::set_reuse(bool value) {
  
  reuse_ = value;
  // @@protoc_insertion_point(field_set:Test.Config.reuse)
}

// repeated float elem = 4;
inline int Config::elem_size() const {
  return elem_.size();
}
inline void Config::clear_elem() {
  elem_.Clear();
}
inline float Config::elem(int index) const {
  // @@protoc_insertion_point(field_get:Test.Config.elem)
  return elem_.Get(index);
}
inline void Config::set_elem(int index, float value) {
  elem_.Set(index, value);
  // @@protoc_insertion_point(field_set:Test.Config.elem)
}
inline void Config::add_elem(float value) {
  elem_.Add(value);
  // @@protoc_insertion_point(field_add:Test.Config.elem)
}
inline const ::google::protobuf::RepeatedField< float >&
Config::elem() const {
  // @@protoc_insertion_point(field_list:Test.Config.elem)
  return elem_;
}
inline ::google::protobuf::RepeatedField< float >*
Config::mutable_elem() {
  // @@protoc_insertion_point(field_mutable_list:Test.Config.elem)
  return &elem_;
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)


}  // namespace Test

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_message_2eproto__INCLUDED
