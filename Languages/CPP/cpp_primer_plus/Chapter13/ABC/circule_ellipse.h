#ifndef _BASE_ELLIPSE_H_
#define _BASE_ELLIPSE_H_

/* Abstract base class for Circule and Ellipse */
class BaseEllipse {
 public:
 	// Constructor function and destruct function
 	BaseEllipse(double x = 0.0, double y = 0.0): x_(x), y_(y) {}
 	virtual ~BaseEllipse() {}
	 
	// Virtual functions
	virtual double Area() const = 0; // Pure virtual function for showing the area
	virtual void Show() const;		
	
	// Other functions
	void Move(double, double);
 	
 private:
 	double x_;
 	double y_;
};

/* Class Ellipse */
class Ellipse: public BaseEllipse {
 public:
 	// Constructor function and destruct function
 	Ellipse(double x, double y, double a, double b)
 			: BaseEllipse(x, y), a_(a), b_(b) {}
 	virtual ~Ellipse() {}
 	
 	// Virtual functions
 	virtual double Area() const;
 	virtual void Show() const;
 	 	
 private:
  double a_;
	double b_;	
};

class Circule: public BaseEllipse {
 public:
 	// Constructor function and destruct function
 	Circule(double x, double y, double r)
 			: BaseEllipse(x, y), r_(r) {}
 	virtual ~Circule() {}
 	
 	// Virtual functions
 	virtual double Area() const;
 	virtual void Show() const;
 	
 private:
 	double r_;	
};

#endif // _BASE_ELLIPSE_H_ ends 
