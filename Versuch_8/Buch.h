#include "Medium.h"

class Buch : public Medium {
protected:
	std::string autor;
public:
	Buch(std::string initTitel, std::string initAutor);

	virtual ~Buch(void);

	void ausgabe() const override;
	bool ausleihen(Person person, Datum ausleihdatum);
};
