#pragma once

#include <any>
#include <optional>
#include <regex>
#include <string>
#include <utility>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/range/algorithm/find_if.hpp>

#include <Utils/Logger.hpp>
#include <Database/Utils/KeyWithValue.hpp>

class Database
{
public:
   using ObjectType = std::string;  // to replace with string_view
   using KeyType = std::string;  // to replace with string_view
   using ValueType = std::vector<KeyWithValue>;

   Database(ValueType inMemory);
   Database(const Database&) = delete;
   Database(Database&&) = delete;

   Database& operator=(const Database&) = delete;
   Database operator=(Database&&) = delete;

   void updateObj(const KeyWithValue& inVal); 
   std::string generateUniqueKey(const KeyType& typeOrKey);
   void deleteObj(const KeyType& searchedKey);

   template <typename T>
   std::optional<T> getObj(const KeyType& searchedKey)
   {
      auto searchedIt = boost::range::find_if(memory_, [&searchedKey](const auto& it){
            return it.key ==  searchedKey; });
   
      if (memory_.end() != searchedIt)
      {
         LOG(debug) << searchedKey << " succeeded";
         try
         {
            return std::any_cast<T>(searchedIt->value);
         }
         catch (const std::bad_any_cast& e) {
             LOG(error) << e.what() << searchedKey;
         }
      } 
   
      LOG(info) << searchedKey << " failed";
      return {};
   }

   template <typename T>
   std::vector<std::pair<KeyType, T>> getObjectsByType(const KeyType& searchedType)
   {
      std::vector<std::pair<KeyType, T>> matchingElements;
      LOG(debug) << searchedType;

      for (const auto& it : memory_)
      {
         if (boost::contains(it.key, searchedType))
         {
            try
            {
               matchingElements.push_back({ it.key, std::any_cast<T>(it.value) });
            }
            catch (const std::bad_any_cast& e) {
                LOG(error) << e.what() << searchedType;
            }
         }
      }
      if (0 == matchingElements.size())
      {
         LOG(debug) << " DB doesn't contains " << searchedType;
      }

      return matchingElements; 
   }
  
private:
   std::regex dkRegexp_;
   ValueType memory_;
   std::vector<TypeWithInstanceId> nextFreeUniqueKeyId_;
};

