/*
	Name: worker_mi.h 
	Copyright: No copyright
	Author: Greg Shen
	Date: 23/05/19 14:00
	Description: ...
*/

#ifndef _WORKER_MI_H_
#define _WORKER_MI_H_

#include<string>

namespace worker {

using std::string;

// Abstract base class	
class Worker {
 public:
 	// Constructor and destructor functions
 	Worker(): fullname_("NULL"), id_(0L) {}
	Worker(const string& fullname, long id): fullname_(fullname), id_(id) {} 
	Worker(const Worker& worker): fullname_(worker.fullname_), id_(worker.id_) {}
	virtual ~Worker() = 0;
	
	// Other functions
	virtual void Set() = 0;
	virtual void Show() const = 0;
	
 protected:
	virtual void Data() const;
	virtual void Get();
	
 private:
 	string fullname_;
 	long id_;
};

// A class to descirbe waiter
class Waiter: virtual public Worker {
 public:
	// Constructor and destructor functions
	Waiter(): Worker(), panache_(0) {}
	Waiter(const string& fullname, int id, int panache = 0)
			: Worker(fullname, id), panache_(panache) {} 
	Waiter(const Worker& worker, int panache = 0)
			: Worker(worker), panache_(panache) {}
	virtual ~Waiter() {}
	
	// Other functions
	virtual void Show() const;
	virtual void Set();
	
 protected:
 	virtual void Get();
 	virtual void Data() const;
	
 private:
	int panache_;
};

// A class to descirbe singer
class Singer: virtual public Worker {
 public:
 	// Construtor and destructor functions
 	Singer(): Worker(), voice_(0) {}
	Singer(const string& fullname,long id, int voice = 0)
			: Worker(fullname, id), voice_(voice) {}
  Singer(const Worker& worker, int voice = 0)
			: Worker(worker), voice_(voice) {}
	virtual ~Singer() {}
	
	// Other functions
	virtual void Set();
	virtual void Show() const;
	
 protected:
 	virtual void Data() const;
 	virtual void Get();
			
 private:
 	static const int kNumOfTypes = 7;
 	static const char* kPv[kNumOfTypes];
 	int voice_;
};

// A class to describe singer and waiter at the same time
class SingerWaiter: public Waiter, public Singer {
 public:
 	// Constructor and destructor function
 	SingerWaiter() {}
  SingerWaiter(const string& fullname, long id, int p = 0, int v = 0)
			: Worker(fullname, id), 
				Waiter(fullname, id, p), 
				Singer(fullname, id, v) {}
  SingerWaiter(const Worker& worker, int p = 0, int v = 0)
			: Worker(worker), Waiter(worker, p), Singer(worker, v) {}
  SingerWaiter(const Waiter& waiter, int v = 0)
			: Worker(waiter), Waiter(waiter), Singer(waiter, v) {}
  SingerWaiter(const Singer& singer, int p = 0)
			: Worker(singer), Waiter(singer, p), Singer(singer) {}
	virtual ~SingerWaiter() {}
	
	// Other functions
	virtual void Show() const;
	virtual void Set();
	
 protected:
 	virtual void Data() const;
 	virtual void Get();
};
	
} 	// Namespace worker ends 

#endif 	// _WORKER_MI_H_ ends 
