#include <cstdint>
#include <iostream>
#include <fstream>

// N < 256 и a_i < 256, для всех i=1..N
// .txt - массив данных в формате N и a_i, где i=1..N (ASCII)
// .bin - массив данных в формате N и a_i, где i=1..N (bin)

class DataReader
{
protected:
	std::ifstream m_in;
	std::ofstream m_out;
	std::string m_filename;
	uint8_t* m_data;
	uint8_t m_n;
	float* m_dataf;
	uint32_t m_nf;

public:
	DataReader(const std::string& filename) : 
		m_filename(filename), m_n(0), m_data(nullptr), m_nf(0), m_dataf(nullptr)
	{

	}

	virtual ~DataReader() {}

	virtual bool Open() = 0;
	void Close()
	{
		m_in.close();
	}

	virtual void Read() = 0;

	void GetData(uint8_t* buf, uint8_t& n)
	{
		n = m_n;
		for (uint8_t i = 0; i < m_n; i++)
			buf[i] = m_data[i];
	}

	void GetData(float* buf, uint32_t& n)
	{
		n = m_nf;
		for (uint32_t i = 0; i < m_nf; i++)
			buf[i] = m_dataf[i];
	}
	virtual void Write(std::string filename) = 0;
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
public:
	BinfReader(const std::string& filename) : DataReader(filename) {};
	virtual ~BinfReader()
	{
		delete[] m_dataf;
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
		m_in.read((char*)&m_nf, sizeof(uint32_t));
		m_dataf = new float[m_nf];
		m_in.read((char*)m_dataf, m_nf*sizeof(float));
	}

	

	void Write(std::string filename) override
	{
		m_out.open(filename, std::ios::binary);
		m_out.write((char*)&m_nf, sizeof(uint32_t));
		for (uint32_t i = 0; i < m_nf; i++) {
			m_out.write((char*)&m_dataf[i], sizeof(float));
		}
		m_out.close();
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
	uint32_t n;
	float buf[100];
	std::cout << sizeof(uint8_t) << ' ' << sizeof(uint32_t) << std::endl;
	DataReader* Reader = Factory("file.binf");
	if (Reader == nullptr)
		return -1;
	Reader->Open();
	Reader->Read();
	Reader->GetData(buf, n);
	std::cout << n << std::endl;
	for (int i = 0; i < n; i++)
		std::cout << (float)buf[i] << ' ';
	std::cout << std::endl;
	Reader->Write("output.binf");

	delete Reader;
	system("pause");
	return 0;
}

