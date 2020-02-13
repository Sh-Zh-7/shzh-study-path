#ifndef _WORKER_H_
#define _WORKER_H_

#include<string>

// Abstract base class
class Worker {
 public:
 	Worker(): fullname_("No one"), id_(0L) {}
 	Worker(const std::string& fullname, long id): fullname_(fullname), id_(id) {}
	virtual ~Worker() = 0;
	
	virtual void Set();
	virtual void Show() const;
 
 private:
 	std::string fullname_;
 	long id_;
};

class Waiter: public Worker {
 public:
 	Waiter(): Worker(), panache_(0) {}
 	Waiter(const std::string& fullname, long id, int panache)
			: Worker(fullname, id), panache_(panache) {}
	Waiter(const Worker& worker, int panache): Worker(worker), panache_(panache) {}
	virtual ~Waiter() {} 
	
	virtual void Set();
	virtual void Show() const;

 private:
 	int panache_;
};


class Singer: public Worker {
 public:
 	Singer(): Worker(), voice_(kOther) {}
 	Singer(const std::string& fullname, long id, int v = kOther)
 			: Worker(fullname, id), voice_(v) {}
 	explicit Singer(const Worker& worker, int v = kOther)
 			: Worker(worker), voice_(v) {}
 	virtual ~Singer() {}
	 		
 	virtual void Set();
 	virtual void Show() const;
 	
 private:
 	static const int kTypes = 7;
 	static const int kOther = 0;	
 	static const char *pv[kTypes];
 	
	int voice_;
};

#endif 	// _WORKER_H_ ends
