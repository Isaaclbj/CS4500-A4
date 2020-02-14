#include <stdlib.h>
#include <chrono>

#include "modified_dataframe.h"

//Spreadsheet containing two columns (Schema = "IB")
/*
class Spreadsheet : public Rower
{
public:
	size_t sum = 0;

	DataFrame* df_;

	Spreadsheet(DataFrame* df) : df_(df) {}

	/** This accept method adds the value of the int to the sum of the
		spreadsheet if the bool is true 
	bool accept(Row& r)
	{
		bool num = r.get_bool(1);

		if (num)
		{
			sum += (size_t)(r.get_int(0));
		}

		return num;
	}

	void join_delete(Rower* other)
	{
		sum += dynamic_cast<Spreadsheet*>(other)->sum;
		delete other;
	}
};

int main(int argc, char **argv)
{
	Schema ss_scm("IB");
	DataFrame df(ss_scm);

	Row r(df.get_schema());

	//Populate the dataframe with million lines
	for (size_t ii = 0; ii < 10; ii++)
	{
		r.set(0, (int)ii);
		r.set(1, (bool)(ii % 2));
		df.add_row(r);
	}
	//Create the rower
	Spreadsheet spst(&df);
	df.pmap(spst);
}
*/