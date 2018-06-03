#pragma once
#include <string>

template <typename T>
class Pair1
{
private:
	T m_first;
	T m_second;
public:
	Pair1(const T& first, const T& second) : m_first{ first }, m_second{ second }
	{

	}

	T& first() { return m_first; } 
	const T& first() const { return m_first; }

	T& second() { return m_second; }
	const T& second() const { return m_second; }
};

template <class T1, class T2> //class and typename are identical
class Pair 
{
private:
	T1 m_first;
	T2 m_second;
public:
	Pair(const T1& first, const T2& second) : m_first{ first }, m_second{ second }
	{

	}

	T1& first() { return m_first; }
	const T1& first() const { return m_first; }

	T2& second() { return m_second; }
	const T2& second() const { return m_second; }
};

template <typename T>
class StringValuePair : public Pair<std::string, T>
{
public:
	StringValuePair(const std::string& str, const T& value) : Pair<std::string, T>(str, value)
	{

	}
};