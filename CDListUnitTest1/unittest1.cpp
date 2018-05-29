#include "stdafx.h"
#include "CppUnitTest.h"
extern "C" {
#include "cdlist.h"
}
#include "mylisttest.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void myfreeint(void* data)
{
	free(data);
}

	namespace CDListUnitTest1
	{
		TEST_CLASS(UnitTest1)
		{
		public:

			TEST_METHOD(TestMethod1)
			{
				// TODO: 在此输入测试代码
				CDList* mylist;
				int *i,*i2,*i3,*i4,i5;
				
				void(*freeint)(void*) = myfreeint;
				freeint = myfreeint;
				mylist = (CDList*)malloc(sizeof(CDList));
				Assert::IsNotNull(mylist);
				//cdlist_destroy(mylist);

				cdlist_init(mylist, freeint);

				//Assert::AreEqual(0, mylist->size);
				Assert::IsNull(mylist->head);
				i = (int *)malloc(sizeof(int));
				*i = 1;
				i2 = (int *)malloc(sizeof(int));
				*i2 = 2;
				i3 = (int *)malloc(sizeof(int));
				*i3 = 3;
				i4 = (int *)malloc(sizeof(int));
				cdlist_ins_next(mylist, mylist->head, (void*)i);
				Assert::IsTrue(mylist->head->next==mylist->head);
				Assert::IsTrue(mylist->head->data==i);
				cdlist_ins_next(mylist, mylist->head, (void*)i2);
				Assert::IsTrue(mylist->head->next->data == i2);
				Assert::IsTrue(mylist->head->prev->data == i2);
				Assert::IsTrue(mylist->head->next->next->data = i);
				cdlist_ins_prev(mylist, mylist->head, (void*)i3);
				Assert::IsTrue(mylist->head->prev->data == i3);
				Assert::IsTrue(mylist->head->prev->next == mylist->head);
				printf("mylist->head->prev->prev->data is %d", *(int*)mylist->head->prev->prev->data);
				Assert::IsTrue(mylist->head->prev->prev == mylist->head->next);
				Assert::AreEqual(cdlist_size(mylist), 3);
				cdlist_rem(mylist, mylist->head, (void **)&(i4));
				Assert::AreEqual(cdlist_size(mylist), 2);
				Assert::AreEqual(*i4, 1);
				cdlist_rem(mylist, mylist->head, (void **)&(i4));
				Assert::AreEqual(*i4, 2);
				cdlist_rem(mylist, mylist->head, (void **)&(i4));
				Assert::AreEqual(*i4, 3);
				Assert::AreEqual(cdlist_size(mylist), 0);
				i5 = cdlist_rem(mylist, mylist->head, (void **)&(i4));
				Assert::AreEqual(i5,-1);

				cdlist_destroy(mylist);
				Assert::IsTrue(mylist->head == NULL);
				Assert::IsTrue(mylist->destroy == NULL);
				Assert::IsTrue(mylist->size == 0);

				//Assert::AreEqual(mylist->head, mylist->head->next);
				//Assert::AreEqual(0,mylist->destroy);

			}

		};


	}


