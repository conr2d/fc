#include <fc/crypto/public_key_point.hpp>

namespace fc { namespace crypto {

struct decompress_visitor : fc::visitor<public_key_point::storage_type> {
   template<typename PublicKey>
   public_key_point::storage_type operator()(const PublicKey& p)const {
      return public_key_point::storage_type(p.decompress());
   }
};

public_key_point::public_key_point( const public_key& key )
: _storage(key._storage.visit(decompress_visitor()))
{}

} }
