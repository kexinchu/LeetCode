#include "reverse_kgroup_list.h"
#include <gtest/gtest.h>
#include <vector>
#include <tuple>

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    // 顺序执行下述所有以TEST/TEST_F/TEST_P开头的UT用例
    return RUN_ALL_TESTS();
}

namespace goodcoder
{
    /**
 * @brief
*/
    class TestReverseKgroupList : public ::testing::Test
    {
    protected:
        ReverseKGroupList *testObj;
        TestReverseKgroupList(){};
        virtual ~TestReverseKgroupList(){};
        // TestReverseKgroupList 的每个case运行前运行，用于统一初始化构造函数
        virtual void SetUp()
        {
            testObj = new ReverseKGroupList();
        }

        // TestReverseKgroupList 的每个case运行前运行，用于统一清理数据
        virtual void TearDown()
        {
            delete testObj;
        }
    };

    /**
 * @brief
 * 通过vector生成链表
*/
    TEST_F(TestReverseKgroupList, test_createByArray)
    {
        std::vector<int> testVec(3, 5);
        Node head = testObj->createByArray(testVec);
        while (head != NULL)
        {
            ASSERT_EQ(5, head->data);
            head = head->next;
        }

        std::vector<int> testVec1;
        head = testObj->createByArray(testVec1);
        ASSERT_EQ(NULL, head);
    }

    /**
 * @brief
 * 链表 -> string
*/
    TEST_F(TestReverseKgroupList, test_listToStr)
    {
        Node head = NULL;
        ASSERT_EQ("", testObj->listToStr(head));

        std::vector<int> testVec(3, 5);
        head = testObj->createByArray(testVec);
        ASSERT_EQ("5->5->5", testObj->listToStr(head));
    }

    /**
 * @brief
 * reverse
*/
    TEST_F(TestReverseKgroupList, test_reverse)
    {
        std::vector<int> testVec{1, 2, 3, 4, 5};
        Node head = testObj->createByArray(testVec);
        Node tail = head->next->next;
        std::tie(head, tail) = testObj->reverse(head, tail);
        ASSERT_EQ("3->2->1", testObj->listToStr(head));
    }

    /**
 * @brief
 * reverseKGroup
*/
    TEST_F(TestReverseKgroupList, test_reverseKGroup)
    {
        std::vector<int> testVec{1, 2, 3, 4, 5};
        Node head = testObj->createByArray(testVec);
        Node headNew = testObj->reverseKGroup(head, 3);
        ASSERT_EQ("3->2->1->4->5", testObj->listToStr(headNew));

        head = testObj->createByArray(testVec);
        headNew = testObj->reverseKGroup(head, 2);
        ASSERT_EQ("2->1->4->3->5", testObj->listToStr(headNew));
    }
} // namespace goodcoder