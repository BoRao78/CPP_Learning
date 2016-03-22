class Time {
private:

public:
	Time(int h, int m, int s) { hour = h; minute = m; second = s; };
	Time(Time const &x) { hour = x.hour; minute = x.minute; second = x.second; };
	~Time() {};
	void set(int h,int m,int s);
	Time & increment();
	void virtual display();
	bool equal(Time const &x);
	bool less_than(Time const &x);

	Time & operator =(Time const &x);
	operator int();
	Time (int x);
	void Time_vaildate();
	bool operator ==(Time const &x);bool operator <(Time const &x);
	Time operator +(int n); Time operator -(int n);
	Time operator ++(int); Time operator --(int);
	int operator -(Time const &x);

	Time getTime();
protected:
	int hour;
	int minute;
	int second;
};

class ExtTime : public Time {
private:
	int timezone;
public:
	ExtTime(int t, int h, int m, int s):Time(h,m,s) { timezone = t; };
	void set(int t, int h, int m, int s);
	bool operator ==(ExtTime const &x); 
	bool operator <(ExtTime const &x);
	void display();
protected:

};