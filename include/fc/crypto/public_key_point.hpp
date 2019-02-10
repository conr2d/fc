#pragma once
#include <fc/crypto/public_key.hpp>
#include <fc/crypto/elliptic.hpp>
#include <fc/crypto/elliptic_r1.hpp>
#include <fc/reflect/reflect.hpp>
#include <fc/reflect/variant.hpp>
#include <fc/static_variant.hpp>

namespace fc { namespace crypto {

class public_key_point {
public:
   using storage_type = static_variant<ecc::public_key_point_shim, r1::public_key_point_shim>;

   public_key_point() = default;
   public_key_point( public_key_point&& ) = default;
   public_key_point( const public_key_point& ) = default;
   public_key_point& operator= (const public_key_point& ) = default;

   public_key_point( const public_key& key );

private:
   storage_type _storage;

   public_key_point( storage_type&& other_storage )
   :_storage(forward<storage_type>(other_storage))
   {}

   friend struct reflector<public_key_point>;
};

} }

FC_REFLECT(fc::crypto::public_key_point, (_storage))
