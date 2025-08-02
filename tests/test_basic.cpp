#include "doctest/doctest.h"
#include "src/DoublyLinkedList.h"

TEST_SUITE("DoublyLinkedList Basic Operations")
{

    TEST_CASE("Insert at head and tail")
    {
        DoublyLinkedList<int> list;

        SUBCASE("Insert at head")
        {
            list.insertAtHead(2);
            list.insertAtHead(1);
            CHECK(list.size() == 2);
            CHECK(list.get(0) == 1);
            CHECK(list.get(1) == 2);
        }

        SUBCASE("Insert at tail")
        {
            list.insertAtTail(1);
            list.insertAtTail(2);
            CHECK(list.size() == 2);
            CHECK(list.get(0) == 1);
            CHECK(list.get(1) == 2);
        }
    }

    TEST_CASE("Delete and reverse")
    {
        DoublyLinkedList<int> list;
        list.insertAtTail(1);
        list.insertAtTail(2);
        list.insertAtTail(3); // [1, 2, 3]

        SUBCASE("Delete middle element")
        {
            list.deleteAt(1); // remove 2
            CHECK(list.size() == 2);
            CHECK(list.get(0) == 1);
            CHECK(list.get(1) == 3);
        }

        SUBCASE("Reverse list")
        {
            list.reverse(); // should become [3, 2, 1]
            CHECK(list.get(0) == 3);
            CHECK(list.get(2) == 1);
        }
    }
}

TEST_SUITE("DoublyLinkedList<Point> Operations")
{
    std::string pointToString(Point & p)
    {
        return "(" + std::to_string(int(p.getX())) + "," + std::to_string(int(p.getY())) + ")";
    }

    TEST_CASE("Insert and get Point")
    {
        DoublyLinkedList<Point> list;

        SUBCASE("Insert at head")
        {
            list.insertAtHead(Point(1, 2));
            list.insertAtHead(Point(3, 4));
            CHECK(list.size() == 2);
            CHECK(list.get(0) == Point(3, 4));
            CHECK(list.get(1) == Point(1, 2));
        }
    }

    TEST_CASE("To string of list<Point>")
    {
        DoublyLinkedList<Point> list;
        list.insertAtTail(Point(9, 0));
        list.insertAtTail(Point(8, 1));
        std::string str = list.toString(pointToString);
        CHECK(str == "[(9,0), (8,1)]");
    }
}

TEST_SUITE("DoublyLinkedList Additional Tests")
{
    TEST_CASE("Insert and delete at boundaries")
    {
        DoublyLinkedList<int> list;
        list.insertAtTail(10);
        list.insertAtTail(20);
        list.insertAtTail(30); // [10, 20, 30]

        SUBCASE("Delete at head")
        {
            list.deleteAt(0);
            CHECK(list.size() == 2);
            CHECK(list.get(0) == 20);
        }

        SUBCASE("Delete at tail")
        {
            list.deleteAt(2);
            CHECK(list.size() == 2);
            CHECK(list.get(1) == 20);
        }
    }

    TEST_CASE("Clear list")
    {
        DoublyLinkedList<int> list;
        list.insertAtHead(5);
        list.insertAtHead(6);
        list.deleteAt(0);
        list.deleteAt(0);
        CHECK(list.size() == 0);
    }

    TEST_CASE("Get throws on out of bounds")
    {
        DoublyLinkedList<int> list;
        list.insertAtTail(1);
        CHECK_THROWS_AS(list.get(1), std::out_of_range);
    }
    TEST_CASE("Get throws on out of bounds")
    {
        DoublyLinkedList<int> list;
        list.insertAtTail(1);
        CHECK_THROWS_AS(list.get(3), std::out_of_range);
    }

    TEST_CASE("Reverse empty and single element list")
    {
        DoublyLinkedList<int> list;
        list.reverse();
        CHECK(list.size() == 0);

        list.insertAtHead(42);
        list.reverse();
        CHECK(list.get(0) == 42);
    }

    TEST_CASE("Insert and delete Point at tail")
    {
        DoublyLinkedList<Point> list;
        list.insertAtTail(Point(7, 8));
        list.insertAtTail(Point(9, 10));
        CHECK(list.size() == 2);
        list.deleteAt(1);
        CHECK(list.size() == 1);
        CHECK(list.get(0) == Point(7, 8));
    }
}
