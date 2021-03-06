/* Copyright 2016-present Facebook, Inc.
 * Licensed under the Apache License, Version 2.0 */
#pragma once
#include <utility>
namespace watchman {

// Remove key from the map. Returns true if any keys were removed.
template <typename Map, typename Key>
bool mapRemove(Map& map, Key& key) {
  return map.erase(key) > 0;
}

// Inserts Key->Value mapping if Key is not already present.
// Returns a boolean indicating whether insertion happened.
template <typename Map, typename Key, typename Value>
bool mapInsert(Map& map, const Key& key, const Value& value) {
  auto pair = map.insert(std::make_pair(key, value));
  return pair.second;
}

// Returns Map[Key] or if it isn't present, returns a default value.
// if the default isn't specified, returns a default-constructed value.
template <class Map, typename Key = typename Map::key_type>
typename Map::mapped_type mapGetDefault(
    const Map& map,
    const Key& key,
    const typename Map::mapped_type& dflt = typename Map::mapped_type()) {
  auto pos = map.find(key);
  return (pos != map.end() ? pos->second : dflt);
}

} // namespace watchman
