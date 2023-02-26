#ifndef TAH00_
#define TAH00_

#include <iostream>

namespace ecm5 {

	class Ta
	{
	private:
		int * ta;

	public:
		unsigned int hf(int num) const;
		void add(int num);
		void search(int num) const;
		void print() const;

		Ta();
		~Ta();
	};

}

#endif

