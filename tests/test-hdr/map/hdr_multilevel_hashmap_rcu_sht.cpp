//$$CDS-header$$

#include "map/hdr_multilevel_hashmap.h"
#include <cds/urcu/signal_threaded.h>
#include <cds/container/multilevel_hashmap_rcu.h>
#include "unit/print_multilevel_hashset_stat.h"

namespace map {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
    namespace {
        typedef cds::urcu::gc< cds::urcu::signal_threaded<>> rcu_type;
    } // namespace
#endif

    void MultiLevelHashMapHdrTest::rcu_sht_nohash()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef cc::MultiLevelHashMap< rcu_type, size_t, Item > map_type;

        test_rcu<map_type>(4, 2);
#endif
    }

    void MultiLevelHashMapHdrTest::rcu_sht_stdhash()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        struct traits : public cc::multilevel_hashmap::traits {
            typedef std::hash<size_t> hash;
        };
        typedef cc::MultiLevelHashMap< rcu_type, size_t, Item, traits > map_type;

        test_rcu<map_type>(4, 2);
#endif
    }

    void MultiLevelHashMapHdrTest::rcu_sht_hash128()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        struct traits : public cc::multilevel_hashmap::traits {
            typedef hash128::make hash;
            typedef hash128::less less;
        };
        typedef cc::MultiLevelHashMap< rcu_type, size_t, Item, traits > map_type;
        test_rcu<map_type>(4, 2);

        typedef cc::MultiLevelHashMap< rcu_type, size_t, Item,
            typename cc::multilevel_hashmap::make_traits<
                co::hash< hash128::make >
                , co::less< hash128::less >
            >::type
        > map_type2;
        test_rcu<map_type2>(4, 2);
#endif
    }

    void MultiLevelHashMapHdrTest::rcu_sht_nohash_stat()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        struct traits : public cc::multilevel_hashmap::traits {
            typedef cc::multilevel_hashmap::stat<> stat;
        };
        typedef cc::MultiLevelHashMap< rcu_type, size_t, Item, traits > map_type;
        test_rcu<map_type>(4, 2);

        typedef cc::MultiLevelHashMap< rcu_type, size_t, Item,
            typename cc::multilevel_hashmap::make_traits<
            co::stat< cc::multilevel_hashmap::stat<>>
            >::type
        > map_type2;
        test_rcu<map_type2>(4, 2);
#endif
    }

    void MultiLevelHashMapHdrTest::rcu_sht_stdhash_stat()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        struct traits : public cc::multilevel_hashmap::traits {
            typedef std::hash<size_t> hash;
            typedef cc::multilevel_hashmap::stat<> stat;
        };
        typedef cc::MultiLevelHashMap< rcu_type, size_t, Item, traits > map_type;
        test_rcu<map_type>(4, 2);

        typedef cc::MultiLevelHashMap< rcu_type, size_t, Item,
            typename cc::multilevel_hashmap::make_traits<
                co::stat< cc::multilevel_hashmap::stat<>>
                ,co::hash<std::hash<size_t>>
            >::type
        > map_type2;
        test_rcu<map_type2>(4, 2);
#endif
    }

    void MultiLevelHashMapHdrTest::rcu_sht_hash128_stat()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        struct traits : public cc::multilevel_hashmap::traits {
            typedef cc::multilevel_hashmap::stat<> stat;
            typedef hash128::make hash;
            typedef hash128::cmp compare;
        };
        typedef cc::MultiLevelHashMap< rcu_type, size_t, Item, traits > map_type;
        test_rcu<map_type>(4, 2);

        typedef cc::MultiLevelHashMap< rcu_type, size_t, Item,
            typename cc::multilevel_hashmap::make_traits<
                co::stat< cc::multilevel_hashmap::stat<>>
                , co::hash< hash128::make >
                , co::compare< hash128::cmp >
            >::type
        > map_type2;
        test_rcu<map_type2>(4, 2);
#endif
    }

    void MultiLevelHashMapHdrTest::rcu_sht_nohash_5_3()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef cc::MultiLevelHashMap< rcu_type, size_t, Item > map_type;

        test_rcu<map_type>(5, 3);
#endif
    }

    void MultiLevelHashMapHdrTest::rcu_sht_stdhash_5_3()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        struct traits : public cc::multilevel_hashmap::traits {
            typedef std::hash<size_t> hash;
        };
        typedef cc::MultiLevelHashMap< rcu_type, size_t, Item, traits > map_type;

        test_rcu<map_type>(5, 3);
#endif
    }

    void MultiLevelHashMapHdrTest::rcu_sht_nohash_5_3_stat()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        struct traits : public cc::multilevel_hashmap::traits {
            typedef cc::multilevel_hashmap::stat<> stat;
            typedef cds::backoff::empty back_off;
        };
        typedef cc::MultiLevelHashMap< rcu_type, size_t, Item, traits > map_type;
        test_rcu<map_type>(5, 3);

        typedef cc::MultiLevelHashMap< rcu_type, size_t, Item,
            typename cc::multilevel_hashmap::make_traits<
            co::stat< cc::multilevel_hashmap::stat<>>
            , co::back_off< cds::backoff::empty >
            >::type
        > map_type2;
        test_rcu<map_type2>(5, 3);
#endif
    }

    void MultiLevelHashMapHdrTest::rcu_sht_stdhash_5_3_stat()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        struct traits : public cc::multilevel_hashmap::traits {
            typedef cc::multilevel_hashmap::stat<> stat;
            typedef cds::backoff::empty back_off;
            typedef std::hash<size_t> hash;
        };
        typedef cc::MultiLevelHashMap< rcu_type, size_t, Item, traits > map_type;
        test_rcu<map_type>(5, 3);

        typedef cc::MultiLevelHashMap< rcu_type, size_t, Item,
            typename cc::multilevel_hashmap::make_traits<
                co::stat< cc::multilevel_hashmap::stat<>>
                ,co::back_off< cds::backoff::empty >
                ,co::hash< std::hash<size_t>>
            >::type
        > map_type2;
        test_rcu<map_type2>(5, 3);
#endif
    }

    void MultiLevelHashMapHdrTest::rcu_sht_hash128_4_3()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        struct traits : public cc::multilevel_hashmap::traits {
            typedef hash128::make hash;
            typedef hash128::less less;
        };
        typedef cc::MultiLevelHashMap< rcu_type, size_t, Item, traits > map_type;
        test_rcu<map_type>(4, 3);

        typedef cc::MultiLevelHashMap< rcu_type, size_t, Item,
            typename cc::multilevel_hashmap::make_traits<
                co::hash< hash128::make >
                , co::less< hash128::less >
            >::type
        > map_type2;
        test_rcu<map_type2>(4, 3);
#endif
    }

    void MultiLevelHashMapHdrTest::rcu_sht_hash128_4_3_stat()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        struct traits : public cc::multilevel_hashmap::traits {
            typedef hash128::make hash;
            typedef hash128::less less;
            typedef cc::multilevel_hashmap::stat<> stat;
            typedef co::v::sequential_consistent memory_model;
        };
        typedef cc::MultiLevelHashMap< rcu_type, size_t, Item, traits > map_type;
        test_rcu<map_type>(4, 3);

        typedef cc::MultiLevelHashMap< rcu_type, size_t, Item,
            typename cc::multilevel_hashmap::make_traits<
                co::hash< hash128::make >
                , co::less< hash128::less >
                , co::stat< cc::multilevel_hashmap::stat<>>
                , co::memory_model< co::v::sequential_consistent >
            >::type
        > map_type2;
        test_rcu<map_type2>(4, 3);
#endif
    }

} // namespace map