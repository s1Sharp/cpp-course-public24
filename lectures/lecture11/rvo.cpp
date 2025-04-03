#include <iostream>
#include <string>

// Helper class to trace methods
struct Tracer {
	Tracer() : m_name("empty") {
		std::cout << "default ctor" << std::endl;
	}

	explicit Tracer(const char* x_) : m_name(x_) {
		std::cout << "ctor " << m_name << std::endl;
	}

	Tracer(const Tracer& rhs) {
		std::cout << "copy ctor from " << rhs.m_name << " to " << m_name << std::endl;
		m_name = rhs.m_name;
	}

	~Tracer() {
		std::cout << "dtor " << m_name << std::endl;
	}

	Tracer& operator=(const Tracer& rhs) {
		std::cout << "copy assign from " << rhs.m_name << " to " << m_name << std::endl;
		m_name = rhs.m_name;
		return *this;
	}
private:
	std::string m_name;
};


// RVO simple
Tracer makeTracer(const char* name) {
	return Tracer{name};
}

// Expected implementation
// Tracer makeTracer(const char* name) {
// 	Tracer temporary(name); // 
// 	Tracer result;
// 	result = temporary;
// 	return result;
// }

// Possible implementation
// void makeTracer(void* result, const char* name) {
// 	Tracer((Tracer*)result, name);
// }

// int main(int argc, char* argv[]) {
// 	Tracer tracer = makeTracer("tracer1"); // original code
	
// 	Tracer tracer;
// 	makeTracer(&tracer, "tracer1"); // after RVO
// }	



// NRVO simple
Tracer makeTracer2(const char* name) {
	Tracer tracer{name};
	return tracer;
}


// Expected implementation
// Tracer makeTracer2(const char* name) {
// 	Tracer result;
// 	Tracer tracer{name};
// 	result = tracer;
// 	return result;
// }


// RVO medium
Tracer makeTracer3(const char* name, int fake) {
	if (fake % 2) {
		return Tracer{name};
	}
	return Tracer{"other"};
}

// NRO medium
Tracer makeTracer4(const char* name, int fake) {
	if (fake % 2) {
		Tracer result1{name};
		return result1;
	}
	else {
		Tracer result2{"other"};
		return result2;
	}
}

int main(int argc, char* argv[]) {

	// RVO simple example
	Tracer tracer = makeTracer("tracer1");

	// NRVO simple example
	Tracer tracer2 = makeTracer2("tracer2");

	// RVO medium
	Tracer tracer3 = makeTracer3("tracer3", argc);

	// NRVO medium
	Tracer tracer4 = makeTracer4("tracer4", argc);

	std::cout << "End of the main" << std::endl;

	return 0;
}

