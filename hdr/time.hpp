#ifndef TIME_HPP
	#define TIME_HPP

	#include "int.hpp"
	#include "flt.hpp"
	#include "void.hpp"


		//point in time
	class Time
	{
		private:

		public:

			Time();
			Time(Time const&);
			Time& operator=(Time const&);
			~Time();

				//-inf...inf
			IntHuge year() const;
			Void year(IntHuge);

				//0..11
			UInt month() const;
			Void month(UInt);

				//0..[28, 29, 30, 31]
			UInt day() const;
			Void day(UInt);

				//0..23
			UInt hour() const;
			Void hour(UInt);

				//0..59
			UInt minute() const;
			Void minute(UInt);

				//seconds 0..59.(9)
			FltLong second() const;
			Void second(FltLong);
	};


		//vector in time
	class TimeSpan
	{
		private:

		public:

			TimeSpan();
			TimeSpan(TimeSpan const&);
			TimeSpan& operator=(TimeSpan const&);
			~TimeSpan();


			FltLong days() const; //...
			FltLong hours() const; //...
			FltLong minutes() const; //...
			FltLong seconds() const; //...

			IntLong full_days() const; //...
			Int full_hours() const; //...
			Int full_minutes() const; //...
			IntLong full_seconds() const; //...
	};

	inline TimeSpan days(FltLong t);
	inline TimeSpan hours(FltLong t);
	inline TimeSpan minutes(FltLong t);
	inline TimeSpan seconds(FltLong t);



#endif //TIME_HPP
