#include <iostream>
#include <string>


class CDataBuffer
{

protected:
    unsigned char* m_dataBuf;
    unsigned int m_DataLength;
    unsigned int m_BufSize;
};

class Loader
{
    virtual CDataBuffer Load() = 0;
};
class Saver
{
    virtual bool Save(const CDataBuffer& buf) = 0;
};

class FileLoader : public Loader
{
public:
    FileLoader(const std::string& filename) {}
    virtual CDataBuffer Load() { return CDataBuffer(); }
};

class FileSaver : public Saver
{
public:
    FileSaver(const std::string& filename) {}
    virtual bool Save(const CDataBuffer& buf) { return true;};
};

class SocketLoader : public Loader
{
public:
    SocketLoader(const std::string& ip, int port) {}
    virtual CDataBuffer Load() { return CDataBuffer(); }
};

class SocketSaver : public Saver
{
public:
    SocketSaver(const std::string& ip, int port) {}
    virtual bool Save(const CDataBuffer& buf) { return true;};
};


int main()
{
    //From socket, to file
    SocketLoader net_loader("192.168.1.11", 80);
    FileSaver file_saver("/home/code/abc.dat");
    CDataBuffer buf = net_loader.Load();
    file_saver.Save(buf);

    //From file, to socket
    FileLoader file_loader("/home/code/abc.dat");
    SocketSaver net_saver("192.168.1.11", 80);
    CDataBuffer buf1 = file_loader.Load();
    net_saver.Save(buf1);
}


