﻿#include <iostream>
#include <fstream>
#include <stdio.h>

// N < 256 и a_i < 256, для всех i=1..N
// .txt - массив данных в формате N и a_i, где i=1..N (ASCII)
// .bin - массив данных в формате N и a_i, где i=1..N (bin)

typedef unsigned char uint8_t;
class DataReader
{
protected:
	std::ifstream m_in;
	std::ofstream m_out;
	std::string m_filename;
	uint8_t* m_data;
	uint8_t m_n;

public:
	DataReader(const std::string& filename) : 
		m_filename(filename), m_n(0), m_data(nullptr)
	{

	}

	virtual ~DataReader() {}

	virtual bool Open() = 0;
	void Close()
	{
		m_in.close();
	}

	virtual void Read() = 0;
	virtual void Write(std::string filename) = 0;

	void GetData(uint8_t* buf, uint8_t& n)
	{
		n = m_n;
		for (int i = 0; i < m_n; i++)
			buf[i] = m_data[i];
	}

	void GetData(float* buf, unsigned int& n)
	{
		n = m_n;
		for (int i = 0; i < m_n; i++)
			buf[i] = m_data[i];
	}
};

class TxtReader : public DataReader
{
public:
	TxtReader(const std::string& filename) : DataReader(filename) {}
	virtual ~TxtReader() 
	{
		delete[] m_data;
	}

	bool Open() override
	{
		m_in.open(m_filename);
		if (!m_in.is_open())
			return false;
		return true;
	}

	void Read() override
	{
		int tmp;
		m_in >> tmp;
		m_n = tmp;
		m_data = new uint8_t[m_n];
		for (int i = 0; i < m_n; i++)
		{
			int tmp;
			m_in >> tmp;
			m_data[i] = tmp;
		}
	}

	void Write(std::string filename) override
	{
		m_out.open(filename);
		m_out << m_n << std::endl;
		for (uint8_t i = 0; i < m_n; i++){
			m_out << m_data[i] << ' ';
		}
		m_out.close();
	}
};

class BinReader : public DataReader
{
public:
	BinReader(const std::string& filename) : DataReader(filename) {}
	virtual ~BinReader()
	{
		delete[] m_data;
	}

	bool Open() override
	{
		m_in.open(m_filename, std::ios::binary);
		if (!m_in.is_open())
			return false;
		return true;
	}

	void Read() override
	{
		m_in.read((char*)&m_n, 1);
		m_data = new uint8_t[m_n];
		m_in.read((char*)m_data, m_n);
	}

	void Write(std::string filename) override
	{
		m_out.open(filename, std::ios::binary);
		m_out << m_n;
		for (uint8_t i = 0; i < m_n; i++){
			m_out << m_data[i];
		}
		m_out.close();
	}
};

class BinfReader : public DataReader
{
private:
	float* m_data;
	unsigned int m_n;
public:
	BinfReader(const std::string& filename) : DataReader(filename) {}
	virtual ~BinfReader()
	{
		delete[] m_data;
	}

	bool Open() override
	{
		m_in.open(m_filename, std::ios::binary);
		if (!m_in.is_open())
			return false;
		return true;
	}

	void Read() override
	{
		m_in.read((char*)&m_n, sizeof(float));
		std::cout << m_n << std::endl;
		m_data = new float[m_n];
		m_in.read((char*)m_data, m_n*sizeof(float));
	}

	void Write(std::string filename) override
	{
		FILE *f = fopen(filename.c_str(), "w");
		fwrite((void*)&m_n, sizeof(int), 1, f);
		for (unsigned int i = 0; i < m_n; i++){
			fwrite((void*)&m_data[i], sizeof(float), 1, f);
		}
		fclose(f);
	}
};

DataReader* Factory(const std::string& filename)
{
	std::string extension = filename.substr(filename.find_last_of('.') + 1);

	if (extension == "txt")
		return new TxtReader(filename);
	else if (extension == "bin")
		return new BinReader(filename);
	else if (extension == "binf")
		return new BinfReader(filename);
	return nullptr;
}

int main()
{
	unsigned int n;
	float buf[100];

	DataReader* Reader = Factory("file.binf");
	if (Reader == nullptr)
		return -1;
	Reader->Open();
	Reader->Read();
	Reader->GetData(buf, n);
	Reader->Write("output.binf");

	for (int i = 0; i < n; i++)
		std::cout << (int)buf[i] << std::endl;
	delete Reader;
	return 0;
}

