#include <Database/Database.hpp>

#include <algorithm>
#include <sstream>
#include <regex>
#include <boost/algorithm/string.hpp>
#include <boost/range/algorithm_ext.hpp>

#include <Utils/Utils.hpp>

using namespace boost;
using namespace defaultVals;

Database::Database(ValueType inMemory)
   : dkRegexp_("/[a-z]+_[1-9]+", std::regex::extended|std::regex::icase)
   , memory_(inMemory) {}

void Database::updateObj(const KeyWithValue& inVal)
{
   const auto& searchedKey = inVal.key;
   auto searchedIt = range::find_if(memory_, [&searchedKey](const auto& it){
         return boost::contains(it.key, searchedKey); });

   if (memory_.end() != searchedIt)
   {
      searchedIt->value = inVal.value;
      LOG(debug) << "existing " << searchedKey << " succeeded";
   } 
   else
   {
      memory_.push_back(inVal);
      LOG(debug) << inVal.key << " succeeded";
   }
}

std::string Database::generateUniqueKey(const KeyType& typeOrKey)
{
   LOG(debug) << "for " << typeOrKey;

   if (std::regex_match(typeOrKey, dkRegexp_))
   {
      LOG(debug) << "Use " << typeOrKey << " as key";
      return typeOrKey;
   }

   std::string dk = defaultVals::FOR_STRING;
   auto searchedIt = boost::range::find_if(nextFreeUniqueKeyId_, [&typeOrKey]
         (const auto& it){ return it.type == typeOrKey; });

   if (nextFreeUniqueKeyId_.end() != searchedIt)
   {
      LOG(debug) << "Exists such object with type " << typeOrKey;
      dk = SLASH + typeOrKey + UNDERSCORE + std::to_string(searchedIt->id++);
   }
   else
   {
      LOG(debug) << "Not exists such object with type " << typeOrKey;
      dk = SLASH + typeOrKey + UNDERSCORE + std::to_string(ONE);
      nextFreeUniqueKeyId_.push_back({typeOrKey, TWO});
   }
   return dk;
}

void Database::deleteObj(const KeyType& searchedKey)
{
   range::remove_erase_if(memory_, [&searchedKey](const auto& it) {
      if (it.key == searchedKey)
      {
         LOG(debug) << "deleted " << searchedKey;
         return true;
      }

      LOG(info) << searchedKey << " not exists";
      return false;
   });
}

