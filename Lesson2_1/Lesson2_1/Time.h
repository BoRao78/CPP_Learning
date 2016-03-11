class Time {
private:
	int hour;
	int minute;
	int second;
public:
	Time(int, int, int) {};
	~Time() {};
	void set(int h,int m,int s);
	Time & increment();
	void display();
	bool equal(Time const &x);
	bool less_than(Time const &x);
protected:

};
