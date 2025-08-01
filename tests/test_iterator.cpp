#include "doctest/doctest.h"
#include "src/DoublyLinkedList.h"

TEST_SUITE("DoublyLinkedList Iterator")
{
    TEST_CASE("Iteration over DoublyLinkedList")
    {
        DoublyLinkedList<int> list;
        list.insertAtTail(10);
        list.insertAtTail(20);
        list.insertAtTail(30);

        int expected[] = {10, 20, 30};

        SUBCASE("Forward iteration using Iterator")
        {
            int idx = 0;
            for (auto it = list.begin(); it != list.end(); ++it)
            {
                CHECK(*it == expected[idx++]);
            }
            CHECK(idx == 3);
        }

        SUBCASE("Range-based for iteration")
        {
            int idx = 0;
            for (int x : list)
            {
                CHECK(x == expected[idx++]);
            }
            CHECK(idx == 3);
        }
    }

    // TODO add test case
    TEST_CASE("Iterator on empty list")
    {
        DoublyLinkedList<int> list;

        int count = 0;
        for (auto it = list.begin(); it != list.end(); ++it)
        {
            count++;
        }

        CHECK(count == 0);
    }
    TEST_CASE("Iterator after reverse")
    {
        DoublyLinkedList<int> list;
        for (int i = 1; i <= 4; ++i)
            list.insertAtTail(i);  // [1, 2, 3, 4]

        list.reverse(); // [4, 3, 2, 1]
        int expected[] = {4, 3, 2, 1};

        int idx = 0;
        for (int x : list)
        {
            CHECK(x == expected[idx++]);
        }
        CHECK(idx == 4);
    }
    TEST_CASE("Iterator after removing head")
    {
        DoublyLinkedList<int> list;
        list.insertAtTail(1);
        list.insertAtTail(2);
        list.insertAtTail(3);
        list.deleteAt(0); // [2, 3]
        int expected[] = {2, 3};
        int idx = 0;
        for (int x : list)
        {
            CHECK(x == expected[idx++]);
        }
        CHECK(idx == 2);
    }

    TEST_CASE("Iterator after removing tail")
    {
        DoublyLinkedList<int> list;
        list.insertAtTail(5);
        list.insertAtTail(6);
        list.insertAtTail(7);
        list.deleteAt(2); // [5, 6]
        int expected[] = {5, 6};
        int idx = 0;
        for (int x : list)
        {
            CHECK(x == expected[idx++]);
        }
        CHECK(idx == 2);
    }

    TEST_CASE("Iterator after clearing list")
    {
        DoublyLinkedList<int> list;
        list.insertAtTail(1);
        list.insertAtTail(2);
        list.deleteAt(0);
        list.deleteAt(0);
        int count = 0;
        for (auto it = list.begin(); it != list.end(); ++it)
        {
            count++;
        }
        CHECK(count == 0);
    }

    TEST_CASE("Iterator with single element")
    {
        DoublyLinkedList<int> list;
        list.insertAtTail(42);
        int count = 0;
        for (int x : list)
        {
            CHECK(x == 42);
            count++;
        }
        CHECK(count == 1);
    }

    TEST_CASE("Multiple iterators on same list")
    {
        DoublyLinkedList<int> list;
        list.insertAtTail(1);
        list.insertAtTail(2);
        auto it1 = list.begin();
        auto it2 = list.begin();
        CHECK(*it1 == 1);
        CHECK(*it2 == 1);
        ++it1;
        CHECK(*it1 == 2);
        CHECK(*it2 == 1);
    }

    TEST_CASE("Iterator after inserting at head")
    {
        DoublyLinkedList<int> list;
        list.insertAtHead(3);
        list.insertAtHead(2);
        list.insertAtHead(1); // [1, 2, 3]
        int expected[] = {1, 2, 3};
        int idx = 0;
        for (int x : list)
        {
            CHECK(x == expected[idx++]);
        }
        CHECK(idx == 3);
    }

    TEST_CASE("Iterator after inserting at tail")
    {
        DoublyLinkedList<int> list;
        list.insertAtTail(1);
        list.insertAtTail(2);
        list.insertAtTail(3); // [1, 2, 3]
        int expected[] = {1, 2, 3};
        int idx = 0;
        for (int x : list)
        {
            CHECK(x == expected[idx++]);
        }
        CHECK(idx == 3);
    }

    TEST_CASE("Iterator after multiple reverses")
    {
        DoublyLinkedList<int> list;
        for (int i = 1; i <= 3; ++i)
        list.insertAtTail(i); // [1, 2, 3]
        list.reverse(); // [3, 2, 1]
        list.reverse(); // [1, 2, 3]
        int expected[] = {1, 2, 3};
        int idx = 0;
        for (int x : list)
        {
            CHECK(x == expected[idx++]);
        }
        CHECK(idx == 3);
    }
}