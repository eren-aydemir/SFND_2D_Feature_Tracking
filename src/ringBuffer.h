#ifndef ringBuffer_h
#define ringBuffer_h

#include <vector>
using namespace std;

class Buffer{
public:
    Buffer(unsigned size);
    void write(double input);
    double read();
private:
    vector<int> buffer;
    unsigned readIndex;
    unsigned writeIndex;
};

Buffer::Buffer(unsigned size) : buffer(size){
    readIndex = 0;
    writeIndex = size - 1;
}
 
void Buffer::write(double input){
    buffer[writeIndex++] = input;
    if(writeIndex &gt;= buffer.size())
        writeIndex = 0;
}
 
double Buffer::read(){
    double val = buffer[readIndex++];
    if(readIndex &gt;= buffer.size())
        readIndex = 0;
    return val;
}


#endif /* dataStructures_h */
