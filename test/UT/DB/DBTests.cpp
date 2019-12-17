#include <TestUtils/Fixtures/BaseFixtureWithDB.hpp>

#include <Database/Objects/IOPaths.hpp>
#include <TestUtils/Hardcodes.hpp>
#include <TestUtils/ObjectTypes.hpp>
#include <TestUtils/UniqueKeys.hpp>

using namespace hardcodes::IOPaths;

class DBShould: public BaseFixtureWithDB
{
protected:
   DBShould() : BaseFixtureWithDB({})
   {}
};

TEST_F(DBShould, getObj_NotExisting_IOPaths2_template)
{
   const auto& searchedObj = db_.getObj<IOPaths>(IOPATHS_2_UK);

   ASSERT_FALSE(searchedObj);
}

TEST_F(DBShould, updateObj_NotExisting_IOPaths2)
{
   db_.updateObj({IOPATHS_2_UK, IOPaths{BUFFER_TO_SEND_VAL_1}});
   const auto& searchedObj = db_.getObj<IOPaths>(IOPATHS_2_UK);

   ASSERT_TRUE(searchedObj);
   ASSERT_TRUE(searchedObj->bufferToSend);
   ASSERT_EQ(BUFFER_TO_SEND_VAL_1, searchedObj->bufferToSend);
}

TEST_F(DBShould, createObj_WithGenerationOfUK_FromUK)
{
   const auto IOPaths1UK = db_.generateUniqueKey(IOPATHS_1_UK);
   db_.updateObj({IOPaths1UK, IOPaths{BUFFER_TO_SEND_VAL_1}});

   const auto IOPaths2UK = db_.generateUniqueKey(IOPATHS_2_UK);
   db_.updateObj({IOPaths2UK, IOPaths{BUFFER_TO_SEND_VAL_2}});

   const auto IOPaths1UKGeneratedByDB = db_.generateUniqueKey(IOPATHS_OT);
   db_.updateObj({IOPaths1UKGeneratedByDB, IOPaths{BUFFER_TO_SEND_VAL_3}});

   const auto& searchedObj1 = db_.getObj<IOPaths>(IOPATHS_1_UK);
   const auto& searchedObj2 = db_.getObj<IOPaths>(IOPATHS_2_UK);
   const auto& searchedObj3 = db_.getObj<IOPaths>(IOPATHS_3_UK);

   ASSERT_TRUE(searchedObj1);
   ASSERT_TRUE(searchedObj1->bufferToSend);
   ASSERT_EQ(BUFFER_TO_SEND_VAL_3, searchedObj1->bufferToSend);

   ASSERT_TRUE(searchedObj2);
   ASSERT_FALSE(searchedObj3);
}

TEST_F(DBShould, createObj_WithGenerationOfUK_ThreeTimes)
{
   const auto IOPaths1UK = db_.generateUniqueKey(IOPATHS_OT);
   db_.updateObj({IOPaths1UK, IOPaths{BUFFER_TO_SEND_VAL_1}});

   const auto IOPaths2UK = db_.generateUniqueKey(IOPATHS_OT);
   db_.updateObj({IOPaths2UK, IOPaths{BUFFER_TO_SEND_VAL_2}});

   const auto IOPaths3UK = db_.generateUniqueKey(IOPATHS_OT);
   db_.updateObj({IOPaths3UK, IOPaths{BUFFER_TO_SEND_VAL_3}});

   db_.generateUniqueKey(IOPATHS_OT);
   const auto IOPaths5UK = db_.generateUniqueKey(IOPATHS_OT);
   db_.updateObj({IOPaths5UK, IOPaths{BUFFER_TO_SEND_VAL_3}});

   auto searchedObj1 = db_.getObj<IOPaths>(IOPATHS_1_UK);
   auto searchedObj2 = db_.getObj<IOPaths>(IOPATHS_2_UK);
   auto searchedObj3 = db_.getObj<IOPaths>(IOPATHS_3_UK);
   auto searchedObj5 = db_.getObj<IOPaths>(IOPATHS_5_UK);

   ASSERT_TRUE(searchedObj1);
   ASSERT_TRUE(searchedObj2);
   ASSERT_TRUE(searchedObj3);
   ASSERT_TRUE(searchedObj5);
}

TEST_F(DBShould, updateObj_Existing_IOPaths2)
{
// CREATE
   db_.updateObj({ IOPATHS_2_UK, IOPaths{BUFFER_TO_SEND_VAL_2} });
   auto searchedObj = db_.getObj<IOPaths>(IOPATHS_2_UK);

   ASSERT_TRUE(searchedObj->bufferToSend);
   ASSERT_EQ(BUFFER_TO_SEND_VAL_2, searchedObj->bufferToSend);

// UPDATE 
   db_.updateObj({ IOPATHS_2_UK, IOPaths{BUFFER_TO_SEND_VAL_3} });
   searchedObj = db_.getObj<IOPaths>(IOPATHS_2_UK);

   ASSERT_TRUE(searchedObj->bufferToSend);
   ASSERT_EQ(BUFFER_TO_SEND_VAL_3, searchedObj->bufferToSend);
}

TEST_F(DBShould, delete_Existing_IOPaths1)
{
   db_.deleteObj(IOPATHS_1_UK);

   auto searchedObj = db_.getObj<IOPaths>(IOPATHS_1_UK);
   ASSERT_FALSE(searchedObj);
}

TEST_F(DBShould, delete_NotExisting_IOPaths2)
{
   db_.deleteObj(IOPATHS_2_UK);

   auto searchedObj = db_.getObj<IOPaths>(IOPATHS_2_UK);
   ASSERT_FALSE(searchedObj);
}

