#pragma once

#include <string>
#include <iostream>
#include <unordered_map>
#include <list>
#include <optional>

class Cache
{
    using IteratorType = std::list<std::pair<std::string, std::string>>::iterator;
    using KeyAndIterators = std::unordered_map<std::string, IteratorType>;
    using CacheList = std::list<std::pair<std::string, std::string>>;

public:
    Cache(size_t maxSize);
    std::optional<std::string> Get(const std::string& key, const std::string& value);
    void Print();

private:
    void DiscardLRUData();
    void Add(const std::pair<std::string, std::string>& data);

    KeyAndIterators m_map;
    CacheList m_list;
    size_t m_currentSize = 0;
    size_t m_maxSize = 0;
};
