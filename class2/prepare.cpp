class CFileWriter
{
public:
    CFileWriter(const std::string& filename);
    CFileWriter() = delete;
    ~CFileWriter();

    int WriteAtBegin(void* data, int length) {
        std::cout << "Write " << length << " bytes at file begin" << std::endl;
        return length;
    }
    int WriteAt(int pos, void* data, int length) {
        std::cout << "Write " << length << " bytes at " << pos << std::endl;
        return length;
    }
    int WriteAtEnd(void* data, int length) {
        std::cout << "Write " << length << " bytes at file end" << std::endl;
        return length;
    }

private:

};

class CClient final
{
public:
    CClient(CFileWriter* writer) : m_writer(writer) {}
    CClient() = delete;
    ~CClient() {}

    bool DoProcess() {
        char buf[64] = { 0 };

        memset(buf, 'A', 64);
        m_writer->WriteAtBegin(buf, 64);
        memset(buf, 'B', 32);
        m_writer->WriteAt(16, buf, 32);
        memset(buf, 'C', 64);
        m_writer->WriteAtEnd(buf, 64);
    }
private:
    CFileWriter *m_writer;
};

int main()
{
    CFileWriter writer("filename");
    CClient c(&writer);

    c.DoProcess();
}
