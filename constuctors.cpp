#include <iostream>

class DataHolder {
public:
  // Default constructor (might allocate memory for internal data)
  DataHolder() {
    std::cout << "Default constructor called (allocating internal data)" << std::endl;
  }

  // Copy constructor (copies internal data)
  DataHolder(const DataHolder& other) {
    std::cout << "Copy constructor called (copying internal data)" << std::endl;
    // Simulate copying internal data (could be memory allocation)
    internalData = new int[10];
    for (int i = 0; i < 10; i++) {
      internalData[i] = other.internalData[i];
    }
  }

  // Move constructor (steals resources)
  DataHolder(DataHolder&& other) noexcept {
    std::cout << "Move constructor called (stealing internal data)" << std::endl;
    internalData = other.internalData;
    other.internalData = nullptr; // Move source to a valid but empty state
  }

  // Destructor (deallocates internal data)
  ~DataHolder() {
    std::cout << "Destructor called (deallocating internal data)" << std::endl;
    delete[] internalData;
  }

private:
  int* internalData;
};

int main() {
  // Create a DataHolder object
  DataHolder originalData;

  // Copy constructor called (automatic copy during initialization)
  DataHolder copyData = originalData;  

  // Move constructor called (explicit move during function call)
  processDataFunction(std::move(originalData));

  return 0;
}

// Function to demonstrate move semantics (can take ownership of DataHolder)
void processDataFunction(DataHolder data) {
  std::cout << "processDataFunction using the internal data" << std::endl;
}

