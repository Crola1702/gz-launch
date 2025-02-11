/*
 * Copyright (C) 2018 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include <gtest/gtest.h>
#include <gtest/gtest-death-test.h>

#include "Manager.hh"

std::string getConfig(const std::string &_pluginName)
{
  return
    "<ignition version='1.0'>"
    "  <plugin name='"  + _pluginName + "'"
    "          filename='" + std::string(bad_plugins_LIB) + "'>"
    "  </plugin>"
    "</ignition>";
}

bool runConfig(const std::string &_config)
{
  ignition::launch::Manager mgr;
  return mgr.RunConfig(_config);
}

TEST(PluginDeathTest, SegfaultOnLoad)
{
  auto config = getConfig("SegfaultOnLoad");
  EXPECT_EXIT(runConfig(config), testing::KilledBySignal(SIGSEGV), "");
}

