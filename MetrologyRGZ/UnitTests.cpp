#pragma once
//#include "stdafx.h"
#include "CppUnitTest.h"
#include "user.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTest_int)
	{
	public:

		TEST_METHOD(TestMethod_constructor)
		{
			Tset<int> t;
			Assert::IsTrue(t.empty());
		}
		TEST_METHOD(TestMethod_clear)
		{
			Tset<int> t;
			t.insert(1);
			t.clear();
			Assert::IsTrue(t.empty());
		}
		TEST_METHOD(TestMethod_insert)
		{
			Tset<int> t;
			t.insert(1);
			Assert::IsTrue(t.contains(1));
		}
		TEST_METHOD(TestMethod_insert_equals)
		{
			Tset<int> t;
			t.insert(1);
			t.insert(1);
			Assert::AreEqual(1, t.size());
			Assert::IsTrue(t.contains(1));
		}

		TEST_METHOD(TestMethod_erase)
		{
			Tset<int> t;
			t.insert(1);
			t.insert(2);
			t.erase(1);
			Assert::AreEqual(1, t.size());
			Assert::IsFalse(t.contains(1));
			Assert::IsTrue(t.contains(2));
		}

		TEST_METHOD(TestMethod_erase_empty)
		{
			Tset<int> t;
			t.erase(1);
			Assert::IsTrue(t.empty());
		}

		TEST_METHOD(TestMethod_erase_not_contains)
		{
			Tset<int> t;
			t.insert(1);
			t.insert(2);
			t.erase(3);
			Assert::AreEqual(2, t.size());
			Assert::IsTrue(t.contains(1));
			Assert::IsTrue(t.contains(2));
		}

		TEST_METHOD(TestMethod_empty_true)
		{
			Tset<int> t;
			Assert::IsTrue(t.empty());
		}

		TEST_METHOD(TestMethod_empty_false)
		{
			Tset<int> t;
			t.insert(1);
			Assert::IsFalse(t.empty());
		}

		TEST_METHOD(TestMethod_contains_true)
		{
			Tset<int> t;
			t.insert(1);
			Assert::IsTrue(t.contains(1));
		}
		TEST_METHOD(TestMethod_contains_false)
		{
			Tset<int> t;
			t.insert(1);
			Assert::IsFalse(t.contains(2));
		}
		TEST_METHOD(TestMethod_union_empty_with_empty)
		{
			Tset<int> t1, t2;
			Tset<int> res = t1.Union(t2);
			Assert::IsTrue(res.empty());
		}
		TEST_METHOD(TestMethod_union_empty_with_notEmpty)
		{
			Tset<int> t1, t2;
			t2.insert(1);
			Tset<int> res = t1.Union(t2);
			Assert::IsTrue(res.contains(1));
		}
		TEST_METHOD(TestMethod_union_notEmpty_with_notEmpty)
		{
			Tset<int> t1, t2;
			t1.insert(1);
			t2.insert(2);
			Tset<int> res = t1.Union(t2);
			Assert::AreEqual(2, res.size());
			Assert::IsTrue(res.contains(1));
			Assert::IsTrue(res.contains(2));
		}
		TEST_METHOD(TestMethod_substract_empty_from_empty)
		{
			Tset<int> t1, t2;
			Tset<int> res = t1.substract(t2);
			Assert::IsTrue(res.empty());
		}
		TEST_METHOD(TestMethod_substract_Empty_from_notEmpty)
		{
			Tset<int> t1, t2;
			t1.insert(1);
			Tset<int> res = t1.substract(t2);
			Assert::IsTrue(res.contains(1));
		}

		TEST_METHOD(TestMethod_substract_notEmpty_from_notEmpty_notEquals)
		{
			Tset<int> t1, t2;
			t1.insert(1);
			t2.insert(2);
			Tset<int> res = t1.substract(t2);
			Assert::IsTrue(res.contains(1));
			Assert::IsFalse(res.contains(2));
		}

		TEST_METHOD(TestMethod_substract_notEmpty_from_notEmpty_Equals)
		{
			Tset<int> t1, t2;
			t1.insert(1);
			t1.insert(2);
			t2.insert(2);
			Tset<int> res = t1.substract(t2);
			Assert::IsTrue(res.contains(1));
			Assert::IsFalse(res.contains(2));
		}

		TEST_METHOD(TestMethod_mult_empty_with_empty)
		{
			Tset<int> t1, t2;
			Tset<int> res = t1.mult(t2);
			Assert::IsTrue(res.empty());
		}

		TEST_METHOD(TestMethod_mult_notEmpty_with_empty)
		{
			Tset<int> t1, t2;
			t1.insert(1);
			Tset<int> res = t1.mult(t2);
			Assert::IsTrue(res.empty());
		}

		TEST_METHOD(TestMethod_mult_notEmpty_with_notEmpty_notInstersect)
		{
			Tset<int> t1, t2;
			t1.insert(1);
			t1.insert(2);
			t2.insert(5);
			t2.insert(6);
			Tset<int> res = t1.mult(t2);
			Assert::IsTrue(res.empty());
		}
		TEST_METHOD(TestMethod_mult_notEmpty_with_notEmpty_Instersect)
		{
			Tset<int> t1, t2;
			t1.insert(1);
			t1.insert(2);
			t2.insert(2);
			t2.insert(3);
			Tset<int> res = t1.mult(t2);
			Assert::IsTrue(res.contains(2));
			Assert::IsFalse(res.contains(1));
			Assert::IsFalse(res.contains(3));
		}
		TEST_METHOD(TestMethod_size_is_zero)
		{
			Tset<int> t;
			Assert::AreEqual(0, t.size());
		}
		TEST_METHOD(TestMethod_size_is_1)
		{
			Tset<int> t;
			t.insert(1);
			Assert::AreEqual(1, t.size());
		}
		TEST_METHOD(TestMethod_getValue)
		{
			Tset<int> t;
			t.insert(1);
			t.insert(2);
			t.insert(3);
			int res = t.getValue(1);
			Assert::AreEqual(2, res);
		}
		TEST_METHOD(TestMethod_getValue_IndexOutOfRange)
		{
			Tset<int> t;
			try
			{
				int res = t.getValue(1);
			}
			catch (std::out_of_range)
			{
				return;
			}
			catch (...)
			{
				wchar_t Message[200] = L"";
				_snwprintf_s(Message, 200, 35, L"Incorrect exceprion for Tset::getValue");
				Assert::Fail(Message, LINE_INFO());
			}
		}
	};
}
