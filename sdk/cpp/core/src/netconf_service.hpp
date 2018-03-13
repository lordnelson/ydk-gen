//
// @file crud_service.hpp
// @brief The main ydk public header.
//
// YANG Development Kit
// Copyright 2016 Cisco Systems. All rights reserved
//
////////////////////////////////////////////////////////////////
// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.
//
//////////////////////////////////////////////////////////////////

#ifndef NETCONF_SERVICE_HPP
#define NETCONF_SERVICE_HPP

#include <map>
#include <memory>
#include <string>
#include "netconf_provider.hpp"
#include "types.hpp"

using namespace std;

namespace ydk
{

namespace core
{
class DataNode;

}

class Entity;

enum class DataStore {
    candidate,
    running,
    startup,
    url,
    na
};

class NetconfService
{
    public:
        NetconfService();
        virtual ~NetconfService();

        bool cancel_commit(NetconfServiceProvider& provider, int persist_id = -1);

        bool close_session(NetconfServiceProvider& provider);

        bool commit(NetconfServiceProvider& provider, bool confirmed = false,
            int confirm_timeout = -1, int persist = -1, int persist_id = -1);

        bool copy_config(NetconfServiceProvider& provider, DataStore target, DataStore source, string url = "");

        bool copy_config(NetconfServiceProvider& provider, DataStore target, Entity& source_config);

        bool copy_config(NetconfServiceProvider& provider, DataStore target, vector<Entity*>& source_list);

        bool delete_config(NetconfServiceProvider& provider, DataStore target, string url = "");

        bool discard_changes(NetconfServiceProvider& provider);

        bool edit_config(NetconfServiceProvider& provider, DataStore target, Entity& config,
            string default_operation = "", string test_option = "", string error_option = "");

        bool edit_config(NetconfServiceProvider& provider, DataStore target, vector<Entity*>& config,
            string default_operation = "", string test_option = "", string error_option = "");

        shared_ptr<Entity> get_config(NetconfServiceProvider& provider, DataStore source, Entity& filter);

        vector<shared_ptr<Entity>> get_config(NetconfServiceProvider& provider, DataStore source, vector<Entity*>& filter_list);

        shared_ptr<Entity> get(NetconfServiceProvider& provider, Entity& filter);

        vector<shared_ptr<Entity>> get(NetconfServiceProvider& provider, vector<Entity*> & filter_list);

        bool kill_session(NetconfServiceProvider& provider, unsigned int session_id);

        bool lock(NetconfServiceProvider& provider, DataStore target);

        bool unlock(NetconfServiceProvider& provider, DataStore target);

        bool validate(NetconfServiceProvider& provider, DataStore source, string url = "");

        bool validate(NetconfServiceProvider& provider, Entity& source_config);
};

}

#endif /* NETCONF_SERVICE_HPP */
