class Time {
private:
	int hour;
	int minute;
	int second;
public:
	Time(int h, int m, int s) { hour = h; minute = m; second = s; };
	~Time() {};
	void set(int h, int m, int s);
	Time & increment();
	void display();
	bool equal(Time const &x);
	bool less_than(Time const &x);
protected:

};
