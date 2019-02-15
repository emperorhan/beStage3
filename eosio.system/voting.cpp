/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#include "eosio.system.hpp"

#include <eosiolib/eosio.hpp>
#include <eosiolib/crypto.h>
#include <eosiolib/print.hpp>
#include <eosiolib/datastream.hpp>
#include <eosiolib/serialize.hpp>
#include <eosiolib/multi_index.hpp>
#include <eosiolib/privileged.hpp>
#include <eosiolib/singleton.hpp>
#include <eosiolib/transaction.hpp>
#include <eosio.token/eosio.token.hpp>


#include <algorithm>
#include <cmath>

namespace eosiosystem {
   using eosio::indexed_by;
   using eosio::const_mem_fun;
   using eosio::bytes;
   using eosio::print;
   using eosio::singleton;
   using eosio::transaction;

   /**
    *  This method will create a producer_config and producer_info object for 'producer'
    *
    *  @pre producer is not already registered
    *  @pre producer to register is an account
    *  @pre authority of producer to register
    *
    */
   // void system_contract::regproducer( const account_name producer, const eosio::public_key& producer_key, const std::string& url, uint16_t location ) {
   //    eosio_assert( url.size() < 512, "url too long" );
   //    eosio_assert( producer_key != eosio::public_key(), "public key should not be the default value" );
   //    require_auth( producer );

   //    auto prod = _producers.find( producer );

   //    if ( prod != _producers.end() ) {
   //       _producers.modify( prod, producer, [&]( producer_info& info ){
   //             info.producer_key = producer_key;
   //             info.is_active    = true;
   //             info.url          = url;
   //             info.location     = location;
   //          });
   //    } else {
   //       _producers.emplace( producer, [&]( producer_info& info ){
   //             info.owner         = producer;
   //             info.total_votes   = 0;
   //             info.producer_key  = producer_key;
   //             info.is_active     = true;
   //             info.url           = url;
   //             info.location      = location;
   //       });
   //    }
   // }

   // void system_contract::regproducer( const account_name producer, const eosio::public_key& producer_key, int64_t amount, std::string sym, double transfer_ratio, const std::string& url, uint16_t location ) {
   //    eosio_assert( transfer_ratio > 0, "transfer ratio must be positive integer" );
   //    eosio_assert( url.size() < 512, "url too long" );
   //    eosio_assert( producer_key != eosio::public_key(), "public key should not be the default value" );
   //    auto itr = _producers.find(producer);
   //    eosio_assert( itr == _producers.end(), "producer name is already exist" );
   //    require_auth( producer );
      
   //    symbol_type symbolvalue = string_to_symbol(4, sym.c_str());
   //    eosio::asset toCreate;
   //    toCreate.amount = amount * 1000;
   //    toCreate.symbol = symbolvalue;

   //    INLINE_ACTION_SENDER(eosio::token, create)( N(eosio.token), {producer,N(active)},
   //                                                  {producer, toCreate} );

   //    transfer_ratio *= 1000;
   //    int64_t tr = (int64_t)transfer_ratio;

   //    _producers.emplace( producer, [&]( producer_info& info ){
   //       info.owner           = producer;
   //       info.total_votes     = 0;
   //       info.maximum_supply  = toCreate;
   //       info.transfer_ratio  = asset(tr, toCreate.symbol);
   //       info.producer_key    = producer_key;
   //       info.is_active       = true;
   //       info.url             = url;
   //       info.location        = location;
   //    });
   // }

   // void token_create( account_name issuer,
   //                  asset        maximum_supply )
   // {
   //    require_auth( issuer );
   //    print("11\n");

   //    auto sym = maximum_supply.symbol;
   //    eosio_assert( sym.is_valid(), "invalid symbol name" );
   //    eosio_assert( maximum_supply.is_valid(), "invalid supply");
   //    eosio_assert( maximum_supply.amount > 0, "max-supply must be positive");
   //    print("22\n");
   //    stats statstable( issuer, sym.name() );
   //    auto existing = statstable.find( sym.name() );
   //    eosio_assert( existing == statstable.end(), "token with symbol already exists" );
   //    print("23\n");
   //    statstable.emplace( issuer, [&]( auto& s ) {
   //       s.supply.symbol = maximum_supply.symbol;
   //       s.max_supply    = maximum_supply;
   //       s.issuer        = issuer;
   //    });
   //    print("24\n");
   // }

   // void system_contract::regproducer( const account_name producer, const eosio::public_key& producer_key, int64_t amount, const std::string& sym, double transfer_ratio, const std::string& url, uint16_t location ) {
   //    eosio_assert( transfer_ratio > 0, "transfer ratio must be positive integer" );
   //    eosio_assert( url.size() < 512, "url too long" );
   //    eosio_assert( producer_key != eosio::public_key(), "public key should not be the default value" );
   //    auto itr = _producers.find(producer);
   //    eosio_assert( itr == _producers.end(), "producer name is already exist" );
   //    require_auth( producer );
      
   //    print("1\n");
   //    symbol_type symbolvalue = string_to_symbol(4, sym.c_str());
   //    eosio::asset toCreate;
   //    toCreate.amount = amount * 1000;
   //    toCreate.symbol = symbolvalue;
   //    print("2\n");
   //    token_create(producer, toCreate);
   //    print("3\n");
   //    transfer_ratio *= 1000;
   //    int64_t tr = (int64_t)transfer_ratio;
   //    print("4\n");
   //    _producers.emplace( producer, [&]( producer_info& info ){
   //       info.owner           = producer;
   //       info.total_votes     = 0;
   //       info.maximum_supply  = toCreate;
   //       info.transfer_ratio  = asset(tr, toCreate.symbol);
   //       info.producer_key    = producer_key;
   //       info.is_active       = true;
   //       info.url             = url;
   //       info.location        = location;
   //    });
   //    print("5\n");
   // }

   // void system_contract::updateprod( const account_name producer, const eosio::public_key& producer_key, double transfer_ratio, const std::string& url, uint16_t location ) {
   //    eosio_assert( transfer_ratio > 0, "transfer ratio must be positive integer" );
   //    eosio_assert( url.size() < 512, "url too long" );
   //    eosio_assert( producer_key != eosio::public_key(), "public key should not be the default value" );
   //    auto itr = _producers.find(producer);
   //    eosio_assert( itr != _producers.end(), "producer name is not exist" );
   //    // eosio_assert( itr->transfer_ratio.symbol == transfer_ratio.symbol, "Invalid DAPP symbol." );
   //    require_auth( producer );

   //    transfer_ratio *= 1000;
   //    int64_t tr = (int64_t)transfer_ratio;

   //    _producers.modify( itr, producer, [&]( producer_info& info ){
   //       info.producer_key          = producer_key;
   //       info.is_active             = true;
   //       info.url                   = url;
   //       info.location              = location;
   //       info.transfer_ratio.set_amount(tr);
   //    });
   // }

   void system_contract::regproducer( const account_name producer, const eosio::public_key& producer_key, asset transfer_ratio, const std::string& url, uint16_t location ) {
      eosio_assert( transfer_ratio.amount > 0, "transfer ratio must be positive integer" );
      eosio_assert( url.size() < 512, "url too long" );
      eosio_assert( producer_key != eosio::public_key(), "public key should not be the default value" );
      auto itr = _producers.find(producer);
      eosio_assert( itr == _producers.end(), "producer name is already exist" );
      require_auth( producer );
      print("reg1");
      auto sym = transfer_ratio.symbol;
      stats statstable( producer, sym.name() );
      const auto& st = statstable.find( sym.name() );
      eosio_assert( st != statstable.end(), "token with symbol is not exists" );
      eosio_assert( st->issuer == producer, "producer is not the issuer of the DAPP token" );
      eosio_assert( st->supply.amount > transfer_ratio.amount, "at least the minimum token must be issued" );
      print("reg2");
      _producers.emplace( producer, [&]( producer_info& info ){
         info.owner           = producer;
         info.total_votes     = 0;
         info.maximum_supply  = asset(st->max_supply);
         info.transfer_ratio  = asset(transfer_ratio);
         info.producer_key    = producer_key;
         info.is_active       = true;
         info.url             = url;
         info.location        = location;
      });
      print("reg3");
   }

   void system_contract::updateprod( const account_name producer, const eosio::public_key& producer_key, asset transfer_ratio, const std::string& url, uint16_t location ) {
      eosio_assert( transfer_ratio.amount > 0, "transfer ratio must be positive integer" );
      eosio_assert( url.size() < 512, "url too long" );
      eosio_assert( producer_key != eosio::public_key(), "public key should not be the default value" );
      auto itr = _producers.find(producer);
      eosio_assert( itr != _producers.end(), "producer name is not exist" );
      // eosio_assert( itr->transfer_ratio.symbol == transfer_ratio.symbol, "Invalid DAPP symbol." );
      require_auth( producer );

      auto sym = transfer_ratio.symbol;
      stats statstable( producer, sym.name() );
      const auto& st = statstable.find( sym.name() );
      eosio_assert( st != statstable.end(), "token with symbol is not exists" );
      eosio_assert( st->issuer == producer, "producer is not the issuer of the DAPP token" );
      eosio_assert( st->supply.amount > transfer_ratio.amount, "at least the minimum token must be issued" );

      _producers.modify( itr, producer, [&]( producer_info& info ){
         info.producer_key          = producer_key;
         info.is_active             = true;
         info.transfer_ratio        = asset(transfer_ratio);
         info.url                   = url;
         info.location              = location;
      });
   }

   // void system_contract::regproducer( const account_name producer, const eosio::public_key& producer_key, asset transfer_ratio, const std::string& url, uint16_t location ) {
   //    eosio_assert( transfer_ratio.amount > 0, "transfer ratio must be positive integer" );
   //    eosio_assert( url.size() < 512, "url too long" );
   //    eosio_assert( producer_key != eosio::public_key(), "public key should not be the default value" );
   //    auto itr = _producers.find(producer);
   //    eosio_assert( itr == _producers.end(), "producer name is already exist" );
   //    eosio_assert( itr->transfer_ratio.symbol == transfer_ratio.symbol, "Invalid DAPP symbol." );
   //    require_auth( producer );
      
   //    stats statstable( producer, transfer_ratio.symbol );
   //    const auto& st = *(statstable.find(transfer_ratio.symbol));

   //    _producers.emplace( producer, [&]( producer_info& info ){
   //       info.owner           = producer;
   //       info.total_votes     = 0;
   //       info.maximum_supply  = st.max_supply;
   //       info.transfer_ratio  = transfer_ratio;
   //       info.producer_key    = producer_key;
   //       info.is_active       = true;
   //       info.url             = url;
   //       info.location        = location;
   //    });
   // }

   // void system_contract::updateprod( const account_name producer, const eosio::public_key& producer_key, asset transfer_ratio, const std::string& url, uint16_t location ) {
   //    eosio_assert( transfer_ratio.amount > 0, "transfer ratio must be positive integer" );
   //    eosio_assert( url.size() < 512, "url too long" );
   //    eosio_assert( producer_key != eosio::public_key(), "public key should not be the default value" );
   //    auto itr = _producers.find(producer);
   //    eosio_assert( itr != _producers.end(), "producer name is not exist" );
   //    eosio_assert( itr->transfer_ratio.symbol == transfer_ratio.symbol, "Invalid DAPP symbol." );
   //    require_auth( producer );

   //    _producers.modify( itr, producer, [&]( producer_info& info ){
   //       info.producer_key          = producer_key;
   //       info.transfer_ratio        = transfer_ratio;
   //       info.is_active             = true;
   //       info.url                   = url;
   //       info.location              = location;
   //    });
   // }

   void system_contract::unregprod( const account_name producer ) {
      require_auth( producer );

      const auto& prod = _producers.get( producer, "producer not found" );

      _producers.modify( prod, 0, [&]( producer_info& info ){
            info.deactivate();
      });
   }

   void system_contract::update_elected_producers( block_timestamp block_time ) {
      _gstate.last_producer_schedule_update = block_time;

      if ((block_time.slot - _gstate.last_producer_vote_table_update.slot) > blocks_per_day){
         _gstate.last_producer_vote_table_update = block_time;
         
         for(auto& p : _producers){
            _producers.modify( p, 0, [&]( producer_info& info ){
               info.set_vote_weight(0);
            });
            if(p.decrease_vote_weight > 0){
               _gstate.total_producer_vote_weight -= p.decrease_vote_weight;
               _producers.modify( p, 0, [&]( producer_info& info ){
                  info.decrease_vote_weight = 0;
               });
            }
         }
      }

      auto idx = _producers.get_index<N(prototalvote)>();

      std::vector< std::pair<eosio::producer_key,uint16_t> > top_producers;
      top_producers.reserve(21);

      // for ( auto it = idx.cbegin(); it != idx.cend() && top_producers.size() < 21 && 0 < it->get_vote_weight() && it->active(); ++it ) {
      for ( auto it = idx.cbegin(); it != idx.cend() && top_producers.size() < 21 && 0 < it->total_votes && it->active(); ++it ) {
         top_producers.emplace_back( std::pair<eosio::producer_key,uint16_t>({{it->owner, it->producer_key}, it->location}) );
      }

      if ( top_producers.size() < _gstate.last_producer_schedule_size ) {
         return;
      }

      /// sort by producer name
      std::sort( top_producers.begin(), top_producers.end() );

      std::vector<eosio::producer_key> producers;

      producers.reserve(top_producers.size());
      for( const auto& item : top_producers )
         producers.push_back(item.first);

      bytes packed_schedule = pack(producers);

      if( set_proposed_producers( packed_schedule.data(),  packed_schedule.size() ) >= 0 ) {
         _gstate.last_producer_schedule_size = static_cast<decltype(_gstate.last_producer_schedule_size)>( top_producers.size() );
      }
   }

   std::string symbol_to_string(const asset val) {
      uint64_t v = val.symbol.value;
      v >>= 8;
      string result;
      while (v > 0) {
               char c = static_cast<char>(v & 0xFF);
               result += c;
               v >>= 8;
      }
      return result;
   }

   std::string asset_to_string(const asset val) {
      string sign = val.amount < 0 ? "-" : "";
      uint64_t abs_amount = static_cast<uint64_t>(std::abs(val.amount));
      auto precision = val.symbol.precision();

      string result = std::to_string( abs_amount);
      if( precision > 0 )
      {
               auto p = precision;
               uint64_t p10 = 1;
               while(p > 0) {
                     p10 *= 10;
                     p--;
               }

               result = std::to_string( static_cast<uint64_t>(abs_amount / p10));
               auto fract = abs_amount % p10;
               result += "." + std::to_string(p10 + fract).erase(0,1);
      }
      return sign + result + " " + symbol_to_string(val);
   }

   void system_contract::voteproducer( const account_name voter_name, const asset quantity, const std::vector<account_name>& producers ) {
      require_auth( voter_name );
      print("vote!!!");
      update_votes( voter_name, quantity, producers );
   }

   // void system_contract::voteproducer( const account_name voter_name, const std::vector<account_name>& producers ) {
   //    require_auth( voter_name );
   //    update_votes( voter_name, producers );
   // }

   // void system_contract::update_votes( const account_name burner, const std::vector<account_name>& producers ) {
   //    for( size_t i = 1; i < producers.size(); ++i ) {
   //       eosio_assert( producers[i-1] < producers[i], "producer votes must be unique and sorted" );
   //    }
   //    eosio_assert( producers.size() <= 30, "attempt to vote for too many producers" );
   //    // eosio_assert( quantity.is_valid(), "invalid quantity" );
   //    // eosio_assert( quantity.symbol == symbol_type(system_token_symbol), "this token is not system token" );
   //    // eosio_assert( quantity.amount > 0, "must burn positive quantity" );

   //    // int64_t vote_weight = quantity.amount;
   //    int64_t vote_weight = 10;
   //    auto burner_name = name{burner};
   //    // std::string quantity_string = asset_to_string(quantity);
   //    // INLINE_ACTION_SENDER(eosio::token, transfer)( N(eosio.token), {burner, N(active)}, 
   //    // { burner, N(eosio.burn), quantity, std::string(burner_name.to_string() + " transfer " + quantity_string + " for burn") } );

   //    for( const auto& pn : producers ) {
   //       auto pitr = _producers.find( pn );
   //       if( pitr != _producers.end() ) {
   //          _producers.modify( pitr, 0, [&]( auto& p ) {
   //             eosio_assert( p.active(), "producer is not currently registered" );
   //             // p.set_vote_weight(vote_weight);
   //             p.total_votes += vote_weight;
   //             // TODO: 30days가 지나면 _gstate의 total_producer_vote_weight도 감소시켜줘야함.
   //             _gstate.total_producer_vote_weight += vote_weight;
   //          });
   //       }
   //    }
   // }

   void system_contract::update_votes( const account_name burner, const asset quantity, const std::vector<account_name>& producers ) {
      for( size_t i = 1; i < producers.size(); ++i ) {
         eosio_assert( producers[i-1] < producers[i], "producer votes must be unique and sorted" );
      }
      eosio_assert( producers.size() <= 30, "attempt to vote for too many producers" );
      eosio_assert( quantity.is_valid(), "invalid quantity" );
      eosio_assert( quantity.symbol == symbol_type(system_token_symbol), "this token is not system token" );
      eosio_assert( quantity.amount > 0, "must burn positive quantity" );
      print("vote1");
      double vote_weight = quantity.amount / producers.size();
      print("vote2");
      for( const auto& pn : producers ) {
         auto pitr = _producers.find( pn );
         print("v");
         auto sym_name = pitr->transfer_ratio.symbol;
         stats statstable( N(eosio), sym_name );
         const auto& st = *(statstable.find(sym_name));
         print("o");
         eosio_assert( (pitr->transfer_ratio.amount * vote_weight) <= (st.max_supply.amount - st.supply.amount), "Dapp token exceeds available supply");
      }

      auto burner_name = name{burner};
      std::string quantity_string = asset_to_string(quantity);
      INLINE_ACTION_SENDER(eosio::token, transfer)( N(eosio.token), {burner, N(active)}, 
      { burner, N(eosio.burn), quantity, std::string(burner_name.to_string() + " transfer " + quantity_string + " for burn") } );

      for( const auto& pn : producers ) {
         auto pitr = _producers.find( pn );
         if( pitr != _producers.end() ) {
            _producers.modify( pitr, 0, [&]( auto& p ) {
               eosio_assert( p.active(), "producer is not currently registered" );
               p.set_vote_weight(vote_weight);
               _gstate.total_producer_vote_weight += vote_weight;
            });

            auto payment_token = asset(static_cast<int64_t>((double)pitr->transfer_ratio.amount * vote_weight), pitr->transfer_ratio.symbol);

            INLINE_ACTION_SENDER(eosio::token, issue)( N(eosio.token), {{N(eosio),N(active)}},
                                                    {burner, payment_token, std::string("issue tokens for CR burner")} );
         }
      }
   }

   // double stake2vote( int64_t staked ) {
   //    /// TODO subtract 2080 brings the large numbers closer to this decade
   //    double weight = int64_t( (now() - (block_timestamp::block_timestamp_epoch / 1000)) / (seconds_per_day * 7) )  / double( 52 );
   //    return double(staked) * std::pow( 2, weight );
   // }
   /**
    *  @pre producers must be sorted from lowest to highest and must be registered and active
    *  @pre if proxy is set then no producers can be voted for
    *  @pre if proxy is set then proxy account must exist and be registered as a proxy
    *  @pre every listed producer or proxy must have been previously registered
    *  @pre voter must authorize this action
    *  @pre voter must have previously staked some EOS for voting
    *  @pre voter->staked must be up to date
    *
    *  @post every producer previously voted for will have vote reduced by previous vote weight
    *  @post every producer newly voted for will have vote increased by new vote amount
    *  @post prior proxy will proxied_vote_weight decremented by previous vote weight
    *  @post new proxy will proxied_vote_weight incremented by new vote weight
    *
    *  If voting for a proxy, the producer votes will not change until the proxy updates their own vote.
    */
   // void system_contract::voteproducer( const account_name voter_name, const account_name proxy, const std::vector<account_name>& producers ) {
   //    require_auth( voter_name );
   //    update_votes( voter_name, proxy, producers, true );
   // }

   // void system_contract::update_votes( const account_name voter_name, const account_name proxy, const std::vector<account_name>& producers, bool voting ) {
   //    //validate input
   //    if ( proxy ) {
   //       eosio_assert( producers.size() == 0, "cannot vote for producers and proxy at same time" );
   //       eosio_assert( voter_name != proxy, "cannot proxy to self" );
   //       require_recipient( proxy );
   //    } else {
   //       eosio_assert( producers.size() <= 30, "attempt to vote for too many producers" );
   //       for( size_t i = 1; i < producers.size(); ++i ) {
   //          eosio_assert( producers[i-1] < producers[i], "producer votes must be unique and sorted" );
   //       }
   //    }

   //    auto voter = _voters.find(voter_name);
   //    eosio_assert( voter != _voters.end(), "user must stake before they can vote" ); /// staking creates voter object
   //    eosio_assert( !proxy || !voter->is_proxy, "account registered as a proxy is not allowed to use a proxy" );

   //    /**
   //     * The first time someone votes we calculate and set last_vote_weight, since they cannot unstake until
   //     * after total_activated_stake hits threshold, we can use last_vote_weight to determine that this is
   //     * their first vote and should consider their stake activated.
   //     */
   //    if( voter->last_vote_weight <= 0.0 ) {
   //       _gstate.total_activated_stake += voter->staked;
   //       if( _gstate.total_activated_stake >= min_activated_stake && _gstate.thresh_activated_stake_time == 0 ) {
   //          _gstate.thresh_activated_stake_time = current_time();
   //       }
   //    }

   //    auto new_vote_weight = stake2vote( voter->staked );
   //    if( voter->is_proxy ) {
   //       new_vote_weight += voter->proxied_vote_weight;
   //    }

   //    boost::container::flat_map<account_name, pair<double, bool /*new*/> > producer_deltas;
   //    if ( voter->last_vote_weight > 0 ) {
   //       if( voter->proxy ) {
   //          auto old_proxy = _voters.find( voter->proxy );
   //          eosio_assert( old_proxy != _voters.end(), "old proxy not found" ); //data corruption
   //          _voters.modify( old_proxy, 0, [&]( auto& vp ) {
   //                vp.proxied_vote_weight -= voter->last_vote_weight;
   //             });
   //          propagate_weight_change( *old_proxy );
   //       } else {
   //          for( const auto& p : voter->producers ) {
   //             auto& d = producer_deltas[p];
   //             d.first -= voter->last_vote_weight;
   //             d.second = false;
   //          }
   //       }
   //    }

   //    if( proxy ) {
   //       auto new_proxy = _voters.find( proxy );
   //       eosio_assert( new_proxy != _voters.end(), "invalid proxy specified" ); //if ( !voting ) { data corruption } else { wrong vote }
   //       eosio_assert( !voting || new_proxy->is_proxy, "proxy not found" );
   //       if ( new_vote_weight >= 0 ) {
   //          _voters.modify( new_proxy, 0, [&]( auto& vp ) {
   //                vp.proxied_vote_weight += new_vote_weight;
   //             });
   //          propagate_weight_change( *new_proxy );
   //       }
   //    } else {
   //       if( new_vote_weight >= 0 ) {
   //          for( const auto& p : producers ) {
   //             auto& d = producer_deltas[p];
   //             d.first += new_vote_weight;
   //             d.second = true;
   //          }
   //       }
   //    }

   //    for( const auto& pd : producer_deltas ) {
   //       auto pitr = _producers.find( pd.first );
   //       if( pitr != _producers.end() ) {
   //          eosio_assert( !voting || pitr->active() || !pd.second.second /* not from new set */, "producer is not currently registered" );
   //          _producers.modify( pitr, 0, [&]( auto& p ) {
   //             p.total_votes += pd.second.first;
   //             if ( p.total_votes < 0 ) { // floating point arithmetics can give small negative numbers
   //                p.total_votes = 0;
   //             }
   //             _gstate.total_producer_vote_weight += pd.second.first;
   //             //eosio_assert( p.total_votes >= 0, "something bad happened" );
   //          });
   //       } else {
   //          eosio_assert( !pd.second.second /* not from new set */, "producer is not registered" ); //data corruption
   //       }
   //    }

   //    _voters.modify( voter, 0, [&]( auto& av ) {
   //       av.last_vote_weight = new_vote_weight;
   //       av.producers = producers;
   //       av.proxy     = proxy;
   //    });
   // }

   /**
    *  An account marked as a proxy can vote with the weight of other accounts which
    *  have selected it as a proxy. Other accounts must refresh their voteproducer to
    *  update the proxy's weight.
    *
    *  @param isproxy - true if proxy wishes to vote on behalf of others, false otherwise
    *  @pre proxy must have something staked (existing row in voters table)
    *  @pre new state must be different than current state
    */
   // void system_contract::regproxy( const account_name proxy, bool isproxy ) {
   //    require_auth( proxy );

   //    auto pitr = _voters.find(proxy);
   //    if ( pitr != _voters.end() ) {
   //       eosio_assert( isproxy != pitr->is_proxy, "action has no effect" );
   //       eosio_assert( !isproxy || !pitr->proxy, "account that uses a proxy is not allowed to become a proxy" );
   //       _voters.modify( pitr, 0, [&]( auto& p ) {
   //             p.is_proxy = isproxy;
   //          });
   //       propagate_weight_change( *pitr );
   //    } else {
   //       _voters.emplace( proxy, [&]( auto& p ) {
   //             p.owner  = proxy;
   //             p.is_proxy = isproxy;
   //          });
   //    }
   // }

   // void system_contract::propagate_weight_change( const voter_info& voter ) {
   //    eosio_assert( voter.proxy == 0 || !voter.is_proxy, "account registered as a proxy is not allowed to use a proxy" );
   //    double new_weight = stake2vote( voter.staked );
   //    if ( voter.is_proxy ) {
   //       new_weight += voter.proxied_vote_weight;
   //    }

   //    /// don't propagate small changes (1 ~= epsilon)
   //    if ( fabs( new_weight - voter.last_vote_weight ) > 1 )  {
   //       if ( voter.proxy ) {
   //          auto& proxy = _voters.get( voter.proxy, "proxy not found" ); //data corruption
   //          _voters.modify( proxy, 0, [&]( auto& p ) {
   //                p.proxied_vote_weight += new_weight - voter.last_vote_weight;
   //             }
   //          );
   //          propagate_weight_change( proxy );
   //       } else {
   //          auto delta = new_weight - voter.last_vote_weight;
   //          for ( auto acnt : voter.producers ) {
   //             auto& pitr = _producers.get( acnt, "producer not found" ); //data corruption
   //             _producers.modify( pitr, 0, [&]( auto& p ) {
   //                   p.total_votes += delta;
   //                   _gstate.total_producer_vote_weight += delta;
   //             });
   //          }
   //       }
   //    }
   //    _voters.modify( voter, 0, [&]( auto& v ) {
   //          v.last_vote_weight = new_weight;
   //       }
   //    );
   // }

   // void system_contract::voteproducer( const account_name voter_name, const account_name target_producer, asset quantity ) {
   //    require_auth( voter_name );
   //    update_votes( voter_name, target_producer, quantity );
   // }

   // void system_contract::update_votes( const account_name burner, const std::vector<account_name>& producers, asset quantity ) {
   //    eosio_assert( is_account(burner), "burner account does not exist" );
   //    eosio_assert( quantity.is_valid(), "invalid quantity" );
   //    eosio_assert( quantity.symbol == symbol_type(system_token_symbol), "this token is not system token" );
   //    eosio_assert( quantity.amount > 0, "must burn positive quantity" );
   //    auto target = _producers.find(target_producer);
   //    eosio_assert( target != _producers.end(), "target producer does not exist" );
   //    eosio_assert( target->active(), "producer is not currently registered" );

   //    int64_t vote_weight = quantity.amount;

   //    auto burner_name = name{burner};
   //    std::string quantity_string = asset_to_string(quantity);
   //    INLINE_ACTION_SENDER(eosio::token, transfer)( N(eosio.token), {burner, N(active)}, 
   //    { burner, N(eosio.burn), quantity, std::string(burner_name.to_string() + " transfer " + quantity_string + " for burn") } );

   //    _producers.modify(target, 0, [&](auto& p) {
   //       p.total_votes += vote_weight;
   //       _gstate.total_producer_vote_weight += vote_weight;
   //    });
   // }
   
} /// namespace eosiosystem
