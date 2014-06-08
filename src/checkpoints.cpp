// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2012 Litecoin Developers
// Copyright (c) 2013 Elephancoin Developers
// Copyright (c) 2014 PizzaCoin Developer
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

	// no checkpoint now, can be added in later releases
    static MapCheckpoints mapCheckpoints =
            boost::assign::map_list_of
(0,        uint256("0x1a95c6e79c69baffe0627707662869233144c0ef7ba112fa76db6c75ffbbc6c9"))
(119,      uint256("0x0b310b4e8680e252e70a19507aaa51e46e9ce68817682412ff9ac41cdb7a5cd4"))
(26434,    uint256("0x5a83efc750432dcf4ccb674e36f888505e4f6d0a4d5f69b826fc47b7d52fa7b1"))
(88457,    uint256("0xc7c7a164b4bc93f7ca15c01bfe590e2b420c55f54ab6f835334174a9cb6f823e"))
(137503,   uint256("0x4cd90e0674c962d29be11308fdf4faa0569953be466021e8205e4484197818ef"))
(156946,   uint256("0x10259a37cf566875ea0be05759e894560b0c049eed4683e7e0537dd1d0050615"))
(185399,   uint256("0xb8d7d24fe7ece9fd378515c1c44d673334058083382d520724c50f36d2a24746"))
(223599,   uint256("0x33d94bdfea17310c53ff45061951e7236d38d3ae4471c3f38833c9fcdf392ea5"))
(253782,   uint256("0x260ca013586752b59ae2ad0a1547483f7a27975558d24bca514bbb7404d7b3e0"))
(280573,   uint256("0x3a5bcc0f358bd747c1ceace0f7b6a27b5c8e5697f1acdcae8108a273b0497ce5"))
(301450,   uint256("0x54463ebab6ec616b4c504762300bca45148b0f9ae0e13ed4eec8166bbba8e1d2"))
(326986,   uint256("0xf3160f774250eedd6a72b270b983687575d02a2d387b1a11d3e54b491059fa08")) // Block Time: June 8, 2014, 18:20:30

;


    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;
        return hash == i->second;
//return true;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;

        return mapCheckpoints.rbegin()->first;
//return 0;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
           return t->second;
//return NULL;
        }
        return NULL;
    }
}
