#include "Medium.h"

class Magazin : public Medium {
protected:
	Datum datumAusgabe;
	std::string sparte;
public:
	Magazin(std::string initTitel, Datum initDatumAusgabe ,std::string initSparte);

	virtual ~Magazin(void);

	void ausgabe(std::ostream& output) const override;
	bool ausleihen(Person person, Datum ausleihdatum) override;
};


