#pragma once
#include <cassert>
#include <initializer_list>
class IntArray {
private:
	int m_length;
	int *m_data;
public:
	IntArray() : m_length{ 0 }, m_data{ nullptr }
	{
	}

	IntArray(int length) : m_length{ length }
	{
		assert(length >= 0);
		if (length > 0)
			m_data = new int[length];
		else
			m_data = nullptr;
	}

	IntArray(const std::initializer_list<int> &list) : IntArray(list.size())
	{
		int i = 0;
		for (const auto &el : list) //We can't access initializer_list by subscript :(
		{
			m_data[i] = el;
			++i;
		}
	}

	~IntArray()
	{
		delete[] m_data;
	}

	void erase()
	{
		delete[] m_data;
		m_length = 0;
		m_data = nullptr;
	}

	int& operator[](int index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}
	IntArray& operator=(const std::initializer_list<int> &list)
	{
		if (list.size() != m_length)
			reallocate(list.size());
		int i = 0;
		for (const auto &el : list) //We can't access initializer_list by subscript :(
		{
			m_data[i] = el;
			++i;
		}
		return *this;
	}

	int getLength() { return m_length; }

	// reallocate will resize the array.  Any existing elements will be destroyed.  This function operates quickly.
	void reallocate(int newLength)
	{
		erase();
		if (newLength <= 0)
			return;
		m_data = new int[newLength];
		m_length = newLength;
	}
	void resize(int newLength)
	{
		if (newLength == m_length)
			return;
		if (newLength <= 0)
		{
			erase();
			return;
		}

		int* data = new int[newLength];
		if (m_length > 0)
		{
			int smallerLen = m_length < newLength ? m_length : newLength;
			for (int i = 0; i < smallerLen; ++i)
				data[i] = m_data[i];
		}
		delete[] m_data;
		m_data = data;
		m_length = newLength;

	}

	void insertBefore(int value, int index)
	{
		assert(index >= 0 && index <= m_length);

		int *newData = new int[m_length + 1];
		for (int i = 0; i < index; ++i) 
			newData[i] = m_data[i];
		newData[index] = value;
		for (int i = index + 1; i < m_length+1; ++i)
			newData[i] = m_data[i-1];
		delete[] m_data;
		m_data = newData;
		++m_length;
	}

	void remove(int index)
	{
		assert(index >= 0 && index < m_length);
		if (m_length == 1)
		{
			erase();
			return;
		}
		int *data = new int[m_length - 1];
		for (int i = 0; i < index; ++i)
			data[i] = m_data[i];
		for (int i = index; i < m_length - 1; ++i)
			data[i] = m_data[i + 1];

		delete[] m_data;
		m_data = data;
		--m_length;
	}

	void insertAtBeginning(int value) { insertBefore(value, 0); }
	void insertAtEnd(int value) { insertBefore(value, m_length); }

};
