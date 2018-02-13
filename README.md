# ECE-180 Assignment #3
Due: Feb 28, 11:15p (PST)

## Preface

We can all remember the simpler days (last week) when homework assignments involved building one simple class. That was fun, right?  Sadly, very few real-world software problems can be implemented so easily. Therefore, this assignment involves multiples classes that have to work together to accomplish the given task. 

## JobCo Plans to Go PUBLIC!

IPO! WOOT WOOT!  It's very exciting when your cool little startup grows up, and is ready to go public. Sure, lots of early employees stand to make a lot of money on their stock grants. But it's not all fun and games you know. The process of "going public" takes a tremendous amount of work, making sure that all of your internal processes are up to the standards necessary to meet public scrutiny. As it turns out, JobCo has more than a few problems, and you've been placed on the "going public" software team. Good luck!

### Calendrical Computations

"Ok everyone, settle down", Chloe says, smiling softly. "As you've all heard, JobCo is going public...", she begins, then stops abruptly as the room explodes into cheers and shouting. Waiting for nearly a minute, she finally continues, "Ok, ok, before you all rush out and buy yourself a Tesla, we have some work to do." 

## Assignment Details

In this assignment, you are going to build a series of classes that support calendrical computations. Dates, times, timezones, and intervals. Customer of your solution will use your classes to do things like creating timers in their own code, or performing timezone conversions within their application. 

At a minimum, you will implement five classes:

```
class Date;
class Time;
class DateTime;
class Timezone;
class Interval;
```

Note that you are free to create any other classes you need in order to support your solution. Presumably, if you add other classes it is to provide functionality to your solution that you have deemed "worthy" to be part of your solution. Totally up to you. Our testing framework will only interact with the five classes we have outlined above.

### About Your Classes
asdf

#### The Date Class 
asdf

#### The Time Class 
asdf

#### The DateTime Class 
asdf

#### The Timezone Class 
asdf

#### The Interval Class 
asdf

### The Testing Interface

In our last assignment, we provided you with a specific class interface. In this assignment, the interface is up to you. Instead, we are providing you with a "boilerplate" test-harness that you'll use to test your implementation. Once you turn in your work, Vlad-the-compiler will use your testing harness to perform operations that we can use to grade your work.  

The testing harness looks like this:

```

class SFString {
public:
  
  SFString();
  SFString(const SFString& aString);
  
  SFString&    operator=(const SFString& aString);
  
  operator const char*() const;
  
  char         operator[](int pos) const;

  SFString&    operator+=(const SFString &aString);
  
  bool         operator<(const SFString &aString);
  bool         operator<=(const SFString &aString);
  bool         operator>(const SFString &aString);
  bool         operator>=(const SFString &aString);
  bool         operator==(const SFString &aString);
  bool         operator!=(const SFString &aString);
  
  int          find(const SFString &aString, size_t offset=0);
  
  SFString&    insert(size_t aPos, const SFString &aString);
  SFString&    insert(size_t aPos, const char aChar);    
  SFString&    replace(size_t pos, size_t len, const SFString &aString);   
  SFString&    erase(size_t pos, size_t len);  
};

```
