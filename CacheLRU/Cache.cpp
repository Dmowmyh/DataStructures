#include "Cache.h"
#include <optional>

Cache::Cache(size_t maxSize) : m_maxSize(maxSize)
{

}

std::optional<std::string> Cache::Get(const std::string& key, const std::string& value)
{
    auto key_and_iterator = m_map.find(key);
    if (key_and_iterator != m_map.end())
    {
        m_list.emplace_back(*key_and_iterator->second);
        m_list.erase(key_and_iterator->second);

        auto key_and_data = --m_list.end();
        key_and_iterator->second = key_and_data;
        return key_and_data->second;
    }
    else
    {
        Add(std::make_pair(key, value));
    }
    return {};
}

void Cache::DiscardLRUData()
{
    auto front_element = m_list.front();
    std::string key = front_element.first;
    m_map.erase(key);
    m_list.pop_front();
}

void Cache::Add(const std::pair<std::string, std::string>& data)
{
    std::string key = data.first;
    std::string value = data.second;

    m_currentSize++;
    if (m_currentSize > m_maxSize)
    {
        DiscardLRUData();
    }
    m_list.emplace_back(data);
    auto iter = --m_list.end();
    m_map.emplace(std::make_pair(key, iter));
}

void Cache::Print()
{
    for (const auto& val: m_list)
    {
        std::cout << "Key " << val.first << std::endl;
        std::cout << "Value " << val.second << std::endl;
    }
    std::cout << "MAP size " << m_map.size() << std::endl;
    std::cout << "LIST size " << m_list.size() << std::endl;
}
